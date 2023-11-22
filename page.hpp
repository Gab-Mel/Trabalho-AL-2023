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

bool Google::sersh (Page pagina, int x){
    for (int i=0; i < pagina.numero_pais; i++){
        cout << pagina.pais[i] << " ";
        if (pagina.pais[i] == x){
            return true;
        }
    }
    cout << endl;
    return false;
}


bool Pages::sersh (Page pagina, int x){
    for (int i=0; i < pagina.numero_pais; i++){
        if (pagina.pais[i] == x){
            return true;
        }
    }
    return false;
}


void Google::gerate() {
    for (int i=0; i<this->numero_paginas; i++){
        for (int j=0; j<this->numero_paginas; j++){
            cout << this->Grafo[i][j];
        }
        cout << endl;
    }
}


void Pages::gerate() {
    for (int i=0; i<this->numero_paginas; i++){
        for (int j=0; j<this->numero_paginas; j++){
            cout << this->Grafo[i][j];
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
    for (int i = 0; i < this->numero_paginas; i++) {
        cout << this->paginas[i].id << endl;
        cout << this->paginas[i].numero_filhos << endl;
        cout << this->paginas[i].probabilidade << endl;
        cout << this->paginas->pais[0] << endl;
    };
};

void Pages::Google() {
    this->numero_paginas = this->numero_paginas;
    this->Grafo = new float*[this->numero_paginas];
    for (int i=0; i<this->numero_paginas; i++){
        this->Grafo[i] = new float[this->numero_paginas];
        for (int j=0; j<this->numero_paginas; j++){
            if (sersh(this->paginas[i], this->paginas[j].id)){
                this->Grafo[i][j] = 1.0/this->paginas[j].numero_filhos;
            }
            else{
                this->Grafo[i][j] = 0;
            }
        }
    }
    //this->Grafo[numero_paginas][numero_paginas];

}
