#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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
    private:
        float **Grafo; //matriz M

        void padronizar(); //padonizar probabilidades
        bool sersh(Page pagina, int x);
        void gerar_matrix(float D); //gerar matriz M
    public:
        Page *paginas; //lista de paginas
        int numero_paginas; 
        
        Pages(int n){ //construtor
            numero_paginas = n;
            paginas = new Page[n];
        };

        void inserir(int id, int numeros_filhos, int *pais = nullptr, int numero_pais = 0, float probabilidade = 0.0); //inserir pagina
        void imprimir_pagerank(); //imprimir PagRank
        void ajust(float delta, float D); //ajustar probabilidades
        void imprimir_matriz(); //printar matriz M
        
};


#include "page.hpp"
#endif