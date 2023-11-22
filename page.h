#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
/*
#include <stdio.h>
#include <stdlib.h>

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
        void padronizar();
        void imprimir();
        
        void Google(float D);

        bool sersh(Page pagina, int x);
        //void inserir(int id, int id_pai, float probabilidade);

        void ajust(float delta, float D);
        void gerate();
        
};


#include "page.hpp"
#endif