#include "page.h"
/*
bool sersh (int *vetor, int n, int x){
    for (int i=0; i<n; i++){
        if (vetor[i] == x){
            return true;
        }
    }
    return false;
}
*/



bool Pages::sersh (Page pagina, int x){
    for (int i=0; i < pagina.numero_pais; i++){
        if (pagina.pais[i] == x){
            return true;
        }
    }
    return false;
}


void Pages::gerate() {
    for (int i=0; i<this->numero_paginas; i++){
        for (int j=0; j<this->numero_paginas; j++){
            cout << this->Grafo[i][j] << " ";
        }
        cout << endl;
    }
}


void Pages::inserir(int id, int numero_filhos, float probabilidade, int *pais, int numero_pais) { 
    //criando nova pagina
    Page nova_pagina; // = new Page; // = (Page*) malloc(sizeof(Page));
    nova_pagina.id = id;
    nova_pagina.numero_filhos = numero_filhos;
    nova_pagina.probabilidade = probabilidade;
    nova_pagina.pais = pais;
    nova_pagina.numero_pais = numero_pais;

    //inserindo nova pagina
    numero_paginas++;
    Page *aux = new Page[numero_paginas];
    if (numero_paginas > 1 ){
        for (int i = 0; i < numero_paginas -1; i++) {
            //if (paginas[i].id) {
            //    cout << "oi" << paginas[i].id << endl;
            aux[i] = paginas[i];
        };
    };

    aux[numero_paginas - 1] = nova_pagina;
    paginas = aux;
};

void Pages::imprimir() {
    cout << "paginas: " << "PageRank" << endl;
    for (int i = 0; i < this->numero_paginas; i++) {
        cout << this->paginas[i].id << ": ";
        cout << this->paginas[i].probabilidade << " ";
        cout << endl;
        //cout << this->paginas[i].pais[0] << endl;
    };
};

void Pages::Google(float D) {
    this->Grafo = new float*[this->numero_paginas];
    for (int i=0; i<this->numero_paginas; i++){
        this->Grafo[i] = new float[this->numero_paginas];
        for (int j=0; j<this->numero_paginas; j++){
            if (sersh(this->paginas[i], this->paginas[j].id)){
                this->Grafo[i][j] = D*1.0/this->paginas[j].numero_filhos + (1-D)*1.0/this->numero_paginas;
            }
            else{
                this->Grafo[i][j] = 0 + (1-D)*1.0/this->numero_paginas;
            }
        }
    }
    //this->Grafo[numero_paginas][numero_paginas];
}

void Pages::padronizar() {
    float probabilidade = 1.0/this->numero_paginas;
    for (int i=0; i<this->numero_paginas; i++){
        this->paginas[i].probabilidade = probabilidade;
    }
}


void Pages::ajust(float delta, float D) {
    float aux = 0.0;
    float *temporario = new float[this->numero_paginas];
    float dif = 10;
    int contador = 0;

    
    
    padronizar();
    Google(D);
    

    while (dif > delta){
        contador++;
        //cout << contador << endl;
        //cout << "oi" << endl;

        temporario = new float[this->numero_paginas];
        Page *novas_paginas = new Page[this->numero_paginas];

        for (int i = 0; i < this->numero_paginas; i++) {
            novas_paginas[i].probabilidade = 0.0;
            for (int j = 0; j < this->numero_paginas; j++) {
                novas_paginas[i].probabilidade += this->Grafo[i][j] * this->paginas[j].probabilidade;
            }
        };

        for (int i=0; i<this->numero_paginas; i++){
            temporario[i] = novas_paginas[i].probabilidade - this->paginas[i].probabilidade;
        }

        aux = 0.0;
        for (int i=0; i<this->numero_paginas; i++){
            aux += pow(temporario[i], 2) ;
        }
        dif = sqrt(aux);

        //cout << dif << " " << aux << endl;
        //dif--;

        for (int i=0; i<this->numero_paginas; i++){
            this->paginas[i].probabilidade = novas_paginas[i].probabilidade;
        }

    }

    for (int i=0; i<this->numero_paginas; i++){
        for (int j=0; j<this->numero_paginas; j++){
            this->Grafo[i][j] += delta;
        }
    }

}
