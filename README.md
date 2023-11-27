# Trabalho-AL-2023

## Requisitos:
É necessario um compilador c++ para rodar modificações da main;
recomendavel utilização de sistemas linux para isso e para rodar a main, mas pode optar por utilizar wsl;


### Instalação do wsl:
Caso ainda não possua wsl basta gigitar no powershell o seguinte comando: `wsl --install`

### Compilação
Para compilar basta utilizar os seguintes comandos no terminal linux (ou wsl) : `g++ main.cpp -o main`

### Para rodar
Para rodar o codigo basta digitar: `./main arquivo.txt`
é possível rodar apenas com ./main caso queira adicionar alguma modificação

#### Os arquivos
Eles devem seguir a seguinte estrutura: 
- Cada linha corresponde a um nó;
- Toda linha deve terminar com `' ;'`;
- A ultima linha deve conter `$`;
- Cada elemento é separado por virgula seguido de espaço `, `;
- Os elemetros: `id, numero_de_filhos, numero_de_pais, pais`;
- Os pais devem ser seguidos por hífem e sem nenhuma outra separação, ex.: `1-2-3-4-`;
- Os hífens podem ser substituidos por pontos sem perdas;
- O arquivo é limitado a `8,000,000` caracteres.

#### Sobre os arquivos pré disponiveis
O arquivo database002.txt possui o vetor R tendendo a zero propositalmente, pois **1** é sorvedouro o que implica que a coluna j=1 é nula.
