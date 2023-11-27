#include "page.h"
#include <iostream>
#include <vector>
#include <string>
//#include <stdio.h>



using std::cout;
using std::endl;

using std::cout; using std::cin;
using std::endl; using std::string;
//using std::vector;

int main( int argc, char** argv ) {
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
    if( argc > 1 ){
        

        char separator = '\n';
        char separator2 = ',';
        int i = 0;
        int j = 1;
        bool first_line = true;
        int k = 0;
        int id = 0;
        int n_filhos = 0;
        int n_pais = 0;
        int *pais;
        float probabilidade = 0;
        int aux = 0;


        FILE *pf;
        char conteudo[1000];
        pf = fopen(argv[1], "rb");
        fread(&conteudo, sizeof(char), 100,pf);
        fclose(pf);
        string s;
        string s2;
        string s3;
        while (conteudo[i] != '$') {
          if (conteudo[i] != separator) {
              // Append the char to the temp string.
              s += conteudo[i]; 
          } else {

            
            j = 0;
            string s2 = "";
            k = 0;
            
            while(s[j] != ';'){
              //cout << "ois ";
              if (s[j] != separator2 && s[j] != ' '){
                s2 += s[j];
              } else {
                
                if (k == 0){
                  //cout << "oi" << endl;
                  id = atoi(s2.c_str());
                  //s2.clear();
                  //cout << id << endl;
                } else if (k == 2){
                  //cout << s << endl;
                  //cout << s2 << endl;
                  n_filhos = atol(s2.c_str());
                  
                } else if (k == 4){
                  probabilidade = atol(s2.c_str());
                  
                } else if (k == 6){
                  n_pais = atol(s2.c_str());
                  
                }
                  else if (k == 8){
                  //cout << s << endl;
                  pais = new int[n_pais];
                  aux = 0;
                  for (int l=0; l < n_pais*2 - 1; l++){
                    if (s2[l] != '-'){
                      s3 = s2[l];
                      //cout << s3 << endl;
                      pais[aux] = atol(s3.c_str());
                      aux++;
                    }
                    
                    //cout << pais[l] << endl;
                  }
                  //cout << pais[0] << endl;
                  
                  }

                
                k++;
              s2.clear();
              }
              j++;
              
              

            }
            pag.inserir(id, n_filhos, probabilidade, pais, n_pais);
            //cout << s << endl;
            
          s.clear();
          }
          i++;
          
        
        }
        
    }else{
        printf("Informe o arquivo. Ex.: ./program arquivo.txt\n");
    }


    
    // Temporary string used to split the string.
    pag.ajust(0.00000000001, 0.85);
    //pag.gerate();




 

    pag.imprimir();
    


    
    /*
    Pages pag(0);
    
    pag.inserir(1, 2, 0.33, []() -> int* {int *a = new int[3]{1,2,3}; return a;}(), 3);
    pag.inserir(2, 1, 0.33, []() -> int* {int *a = new int[1]{3}; return a;}(), 1);
    pag.inserir(3, 2, 0.33, []() -> int* {int *a = new int[1]{1}; return a;}(), 1);
    pag.ajust(0.00000000001, 0.85);

    pag.gerate();




 

    pag.imprimir();
    */
};