#include "page.h"
#include <iostream>
//#include <stdio.h>



using std::cout;
using std::endl;

using std::cout; using std::cin;
using std::endl; using std::string;
//using std::vector;

int main() {
    /*
    Google G(10);

    //G.gerate();
    cout << G.Grafo[0][0] << endl;

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
          cout << G.Grafo[i][j];
        }
        cout << endl;
    }
    */

    

    Pages pag(0);
    
    pag.inserir(1, 1, 0.33, []() -> int* {int *a = new int[2]{2,3}; return a;}(), 2);
    
    
    
    pag.inserir(2, 1, 0.33, []() -> int* {int *a = new int[1]{3}; return a;}(), 1);
    pag.inserir(3, 2, 0.33, []() -> int* {int *a = new int[1]{1}; return a;}(), 1);
    pag.ajust(0.0000001, 0.85);

    pag.gerate();




 

    pag.imprimir();
};