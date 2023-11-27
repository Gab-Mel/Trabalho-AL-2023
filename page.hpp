#include "page.h"

bool Pages::sersh (Page pagina, int x){ //verificar se x é pai de pagina
    for (int i=0; i < pagina.numero_pais; i++){
        if (pagina.pais[i] == x){
            return true;
        }
    }
    return false;
}

void Pages::imprimir_matriz() { //printar matriz M
    cout << "\nMatriz M:" << endl;
    for (int i=0; i<this->numero_paginas; i++){
        for (int j=0; j<this->numero_paginas; j++){
            cout << this->Grafo[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Pages::inserir(int id, int numero_filhos, int *pais, int numero_pais, float probabilidade) { 
    //criando nova pagina
    Page nova_pagina; 
    nova_pagina.id = id;
    nova_pagina.numero_filhos = numero_filhos;
    nova_pagina.probabilidade = probabilidade;
    nova_pagina.pais = pais;
    nova_pagina.numero_pais = numero_pais;

    numero_paginas++;
    Page *aux = new Page[numero_paginas];
    if (numero_paginas > 1 ){
        for (int i = 0; i < numero_paginas -1; i++) { //copiando paginas para aux
            aux[i] = paginas[i];
        };
    };

    aux[numero_paginas - 1] = nova_pagina; //adicionando nova pagina
    paginas = aux;
};

void Pages::imprimir_pagerank() { //printar PageRank
    cout << "\npaginas: " << "PageRank" << endl;
    for (int i = 0; i < this->numero_paginas; i++) {
        cout << this->paginas[i].id << ": ";
        cout << this->paginas[i].probabilidade << " ";
        cout << endl;
    };
    cout << endl;
};

void Pages::gerar_matrix(float D) { //gerar matriz M
    this->Grafo = new float*[this->numero_paginas];
    for (int i=0; i<this->numero_paginas; i++){
        this->Grafo[i] = new float[this->numero_paginas];
        for (int j=0; j<this->numero_paginas; j++){
            if (sersh(this->paginas[i], this->paginas[j].id)){
                this->Grafo[i][j] = D*1.0/this->paginas[j].numero_filhos + (1-D)*1.0/this->numero_paginas; // D*M + (1-D)*1/n
            }
            else{
                this->Grafo[i][j] = 0 + (1-D)*1.0/this->numero_paginas; // D*M + (1-D)*1/n
            }
        }
    }
}

void Pages::padronizar() { //padronizar probabilidades
    float probabilidade = 1.0/this->numero_paginas; // 1/n todas iguais de inicio
    for (int i=0; i<this->numero_paginas; i++){
        this->paginas[i].probabilidade = probabilidade;
    }
}

void Pages::ajust(float delta, float D) { //ajustar pagerank
    float aux = 0.0;
    float *temporario = new float[this->numero_paginas];
    float dif = 10;
    int contador = 0;

    padronizar(); //calcular probabilidades iniciais
    gerar_matrix(D); //calcular M
    

    while (dif > delta){ //enquanto a diferença for maior que delta
        contador++;

        temporario = new float[this->numero_paginas];
        Page *novas_paginas = new Page[this->numero_paginas];

        for (int i = 0; i < this->numero_paginas; i++) { //multiplicar matriz M por PageRank
            novas_paginas[i].probabilidade = 0.0;
            for (int j = 0; j < this->numero_paginas; j++) {
                novas_paginas[i].probabilidade += this->Grafo[i][j] * this->paginas[j].probabilidade;
            }
        };

        for (int i=0; i<this->numero_paginas; i++){ //calcular diferença
            temporario[i] = novas_paginas[i].probabilidade - this->paginas[i].probabilidade;
        }

        aux = 0.0;
        for (int i=0; i<this->numero_paginas; i++){
            aux += pow(temporario[i], 2) ;
        }
        dif = sqrt(aux);

        for (int i=0; i<this->numero_paginas; i++){ //atualizar PageRank
            this->paginas[i].probabilidade = novas_paginas[i].probabilidade;
        }

    }
}
