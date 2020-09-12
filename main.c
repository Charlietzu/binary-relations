#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int numerosMatriz, *matrizAux;
FILE *file_inputed;


void getValues(){
    fscanf(file_inputed, "%d", &numerosMatriz);
    matrizAux = malloc(numerosMatriz * sizeof(int));
    for(int i = 0; i < numerosMatriz; i++){
        fscanf(file_inputed, "%d", &matrizAux[i]);
        printf(matrizAux[i]);
    }
}

int main(){
    //Variáveis leitura de arquivo
    *file_inputed = fopen("ex6.txt", "rt"); //Leitura do arquivo
    char Linha[100];
    char *result;
    char *primeiraLinha;
    int length;

    //Variáveis da matriz
    int NUMERO_DE_LINHAS, NUMERO_DE_COLUNAS;
    int linhaAtual = 0;
    int ** matriz;
    int ** elementos;

    int counter = 0;

    //Iteração para definição da matriz
    while(!feof(file)){
        result = fgets(Linha, 100, file);
        if(linhaAtual == 0){
            //Definindo o número de linhas e número de colunas pelo 1º dígito do arquivo.
            int linhaPraInt = Linha[0];
            NUMERO_DE_LINHAS = linhaPraInt - '0'; //Conversão pra int
            NUMERO_DE_COLUNAS = NUMERO_DE_LINHAS;

            elementos = (int **) malloc (sizeof(int *) * NUMERO_DE_LINHAS);
            for(int i = 0; i < NUMERO_DE_LINHAS; i++){
                elementos[i] = (int *) malloc (sizeof(int) * NUMERO_DE_COLUNAS);
            }

            length = strlen(result);
            for(int i = 1; i < length; i++){
                if(result[i] != ' '){
                    if(result[i+1] == ' '){
                        printf("%c", result[i]);
                        printf("\n");

                    } else {
                        printf("%c", result[i]);

                    }

                }
            }
        }
        linhaAtual++;
    }

    //Alocação dinâmica da matriz;
    matriz = (int **) malloc (sizeof(int *) * NUMERO_DE_LINHAS);
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        matriz[i] = (int *) malloc (sizeof(int) * NUMERO_DE_COLUNAS);
    }

    //Iteração para preencher matriz

    return 0;
}