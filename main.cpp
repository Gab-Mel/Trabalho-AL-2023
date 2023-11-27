#include "page.h"
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;

using std::cout; using std::cin;
using std::endl; using std::string;
//using std::vector;

int main( int argc, char** argv ) {

    Pages pag(0); //criando lista de paginas

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
        int l = 0;


        FILE *pf;
        char conteudo[8000000];
        pf = fopen(argv[1], "rb"); //lendo arquivo
        fread(&conteudo, sizeof(char), 8000000,pf);
        fclose(pf);
        string s;
        string s2;
        string s3;
        while (conteudo[i] != '$') {
          if (conteudo[i] != separator) {
              s += conteudo[i]; 
          } else {
            j = 0;
            string s2 = "";
            k = 0;
            
            while(s[j] != ';'){
              if (s[j] != separator2 && s[j] != ' '){
                s2 += s[j];
              } else {
                
                if (k == 0){
                  id = atoi(s2.c_str());
                } else if (k == 2){
                  n_filhos = atoi(s2.c_str());
                } else if (k == 4){
                  n_pais = atoi(s2.c_str());
                }
                  else if (k == 6){
                  pais = new int[n_pais];
                  aux = 0;
                  l = 0;
                  while (s2[l] != '\0'){
                    if (s2[l] != '-' && s2[l] != '.'){
                      s3 += s2[l];
                      
                    } else {
                      pais[aux] = atoi(s3.c_str());
                      aux++;
                      s3.clear();
                    }
                    l++;
                  }
                  }
                k++;
              s2.clear();
              }
              j++;
              
            } 
            pag.inserir(id, n_filhos, pais, n_pais); //inserindo pagina
          s.clear();
          }
          i++;
        }
        
    }else{
        printf("Informe o arquivo. Ex.: ./program arquivo.txt\n");
    }

    pag.ajust(0.00000000001, 0.85); //ajustando pagerank
    pag.imprimir_matriz(); //printando matriz M
    pag.imprimir_pagerank(); //printando pagerank
    
};