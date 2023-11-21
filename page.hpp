#include "page.h"

/*
void Google::gerate() {
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            Grafo[i][j] = 0;
            cout << Grafo[i][j];
        }
        cout << endl;
    }
}
*/

void Pages::inserir(int id, int numero_filhos, float probabilidade) {
    cout << "###########################################" << endl;
    cout << "aaaaaa: " << this->paginas[0].id << endl;

    Page nova_pagina;
    nova_pagina.id = id;
    nova_pagina.numero_filhos = numero_filhos;
    nova_pagina.probabilidade = probabilidade;

    cout << "*newpage: " << nova_pagina.id << endl;
    numero_paginas++;
    cout << "numero de paginas: " << numero_paginas << endl;
    Page *aux = new Page[numero_paginas];
    cout << "numero_paginas: " << numero_paginas << endl;
    if (numero_paginas > 1 ){
        for (int i = 0; i < numero_paginas -1; i++) {
            cout << "numero de paginas: i : " << numero_paginas << endl;
            cout << "i: " << i << endl;
            cout << "this->paginas[i].id: " << paginas[i].id << endl;
            aux[i] = paginas[i];
            cout << "aux[i]->id: " << aux[i].id << endl;
            cout << "numero de paginas: i : " << numero_paginas << endl;
        };
    };
    

    cout << nova_pagina.id << endl;
    cout << "numero de paginas: " << numero_paginas << endl;

    aux[numero_paginas - 1] = nova_pagina;
    paginas = aux;
    

    cout << "this->paginas[0].id: " << paginas[0].id << endl;
    cout << "this->paginas[0].numero_filhos: " << paginas[0].numero_filhos << endl;
    cout << "this->paginas[0].ptobabilidade: " << paginas[0].probabilidade << endl;

    cout << "numero de paginas: " << numero_paginas << endl;
    cout << "this->paginas[1].id: " << paginas[1].id << endl;
    cout << "this->paginas[1].numero_filhos: " << paginas[1].numero_filhos << endl;
    cout << "this->paginas[1].ptobabilidade: " << paginas[1].probabilidade << endl;

    cout << "this->paginas[2].id: " << paginas[2].id << endl;
    cout << "this->paginas[2].numero_filhos: " << paginas[2].numero_filhos << endl;
    cout << "this->paginas[2].ptobabilidade: " << paginas[2].probabilidade << endl;
};

void Pages::imprimir() {
    for (int i = 0; i < this->numero_paginas; i++) {
        cout << this->paginas[i].id << endl;
    };
};