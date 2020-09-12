#include <stdio.h>
#include <stdlib.h> 

int main(){
    FILE *file;
    file = fopen("ex1.txt", "rt");
    int NUMERO_DE_LINHAS, NUMERO_DE_COLUNAS;
    char Linha[100];
    char *result;
    int linhaAtual = 0;

    while(!feof(file)){
        result = fgets(Linha, 100, file);
        if(linhaAtual == 0){
            //Definindo o número de linhas e número de colunas pelo 1º dígito do arquivo.
            int linhaPraInt = Linha[0];
            NUMERO_DE_LINHAS = linhaPraInt - '0';
            NUMERO_DE_COLUNAS = NUMERO_DE_LINHAS;
        }
        linhaAtual++;
    } 
    return 0;
}