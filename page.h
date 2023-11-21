#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


struct Page {
    int id; // chave
    //vector<int> pais; // Paginas pais
    int numero_filhos; // Número de páginas filhos
    float probabilidade; //probabilidade da página
};



class Pages{
        int numero_paginas;
        Page *paginas;
    public:
        
        //Google probablilidades_condicionais;
        Pages(int n){
            numero_paginas = n;
            paginas = new Page[n];
            //this->probablilidades_condicionais = Google(*this);
        };
        void inserir(int id, int numeros_filhos, float probabilidade);
        void imprimir();
};

/*
class Google {

        
    public:
        int numero_paginas;
        float **Grafo; // matrix de adjacencia
        Google(Pages paginas) {
            this->numero_paginas = paginas.numero_paginas;
            for (int i=0; i<paginas.numero_paginas; i++){
                this->Grafo[i] = new float[paginas.numero_paginas];
                for (int j=0; j<paginas.numero_paginas; j++){
                    this->Grafo[i][j] = 0;
                }
            }
            //this->Grafo[numero_paginas][numero_paginas];
        }
        //void inserir(int id, int id_pai, float probabilidade);
        void gerate();

        
};

*/

#include "page.hpp"
#endif