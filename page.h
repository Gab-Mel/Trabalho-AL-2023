#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <vector>
#include <string.h>
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
*/

#include <list>
using namespace std;


struct Page {
    int id; // chave
    int *pais; // Paginas pais
    int numero_pais; // Número de páginas pais
    int numero_filhos; // Número de páginas filhos
    float probabilidade; //probabilidade da página
};

class Pages{
        
    public:
        Page *paginas;
        int numero_paginas;
        float **Grafo;
        
        //Google probablilidades_condicionais;
        Pages(int n){
            numero_paginas = n;
            paginas = new Page[n];
            //this->probablilidades_condicionais = Google(*this);
        };
        void inserir(int id, int numeros_filhos, float probabilidade, int *pais = nullptr, int numero_pais = 0);
        void imprimir();
        
        void Google();

        bool sersh (Page pagina, int x);
        //void inserir(int id, int id_pai, float probabilidade);
        void gerate();
        
};


class Google {

        
    public:
        int numero_paginas;
        float **Grafo; // matrix de adjacencia
        Google(Pages paginas) {
            cout << "numero_paginas: " << paginas.numero_paginas << endl;
            this->numero_paginas = paginas.numero_paginas;
            this->Grafo = new float*[paginas.numero_paginas];
            for (int i=0; i<paginas.numero_paginas; i++){
                cout << "i: " << i << endl;
                this->Grafo[i] = new float[paginas.numero_paginas];
                cout << "i: " << i << endl;
                for (int j=0; j<paginas.numero_paginas; j++){
                    if (sersh(paginas.paginas[i], paginas.paginas[j].id)){
                        cout << paginas.paginas[i].pais << " ";
                        this->Grafo[i][j] = 1.0/paginas.paginas[j].numero_filhos;
                        cout << "|" << i << j <<paginas.paginas[j].numero_filhos << "|" << endl;
                        cout << 1.0/2 << endl;
                    }
                    else{
                        this->Grafo[i][j] = 0;
                    }
                }
            }
            //this->Grafo[numero_paginas][numero_paginas];
        }

        bool sersh (Page pagina, int x);
        //void inserir(int id, int id_pai, float probabilidade);
        void gerate();

        
};



#include "page.hpp"
#endif