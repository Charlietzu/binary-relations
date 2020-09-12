#include <stdio.h>
#include <stdlib.h>

int tamanhoMatriz, *vetorAux, **matrizPrincipal, NUMERO_DE_LINHAS, NUMERO_DE_COLUNAS;
FILE *arquivo_entrada;
int valorAux, valorLinha, valorColuna;

//Analisar os valores da primeira linha.
void defineValoresAuxiliares(){
    fscanf(arquivo_entrada, "%d", &tamanhoMatriz); //Recebe o primeiro valor da primeira linha
    NUMERO_DE_COLUNAS = NUMERO_DE_LINHAS = tamanhoMatriz;
    vetorAux = malloc(tamanhoMatriz * sizeof(int));
    //Preencher matriz auxiliar com os valores restantes da primeira linha
    for(int i = 0; i < tamanhoMatriz; i++){
        fscanf(arquivo_entrada, "%d", &vetorAux[i]);
    }
}

//Alocação da matriz principal dinamicamente com base nos valores da defineValoresAuxiliares()
void alocaMatrizPrincipal(){
    matrizPrincipal = (int **) malloc (sizeof(int *) * NUMERO_DE_LINHAS);
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        matrizPrincipal[i] = (int *) malloc (sizeof(int) * NUMERO_DE_COLUNAS);
    }
}

//Preencher matriz principal com base nos pares ordenados do arquivo de entrada
void preencheMatrizPrincipal(){
 /*    int *aux = (int *) malloc (sizeof(int) * NUMERO_DE_LINHAS * 2);
    int count = 0;
    while(!feof(arquivo_entrada)){
        fscanf(arquivo_entrada, "%d", &valorAux);
        aux[count] = valorAux; 
        count++;
    }
    for(int i = 0; i < NUMERO_DE_LINHAS * 2; i++){
        if(i % 2 != 0){

        }
    } */
    while(!feof(arquivo_entrada)){
        fscanf(arquivo_entrada, "%d", &valorLinha);
        fscanf(arquivo_entrada, "%d", &valorColuna);

   /*      for(int i = 0; i < tamanhoMatriz; tamanhoMatriz++){
            if(valorLinha == tamanhoMatriz[i]){

            }
        } */
    }
}

//Imprimir matriz principal para teste
void imprimeMatrizPrincipal(){
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            printf("%d", matrizPrincipal[i][j]);
        }
        printf("\n");
    }
}

//Imprimir vetor auxiliar para teste
void imprimeVetorAux(){
    for(int i = 0; i < tamanhoMatriz; i++){
        printf("%d", vetorAux[i]);
    }
}

int main(){
    arquivo_entrada = fopen("ex6.txt", "rt"); //Leitura do arquivo
    defineValoresAuxiliares();
    alocaMatrizPrincipal();
    preencheMatrizPrincipal();
    imprimeVetorAux();
}