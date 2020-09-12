#include <stdio.h>
#include <stdlib.h>

int tamanhoMatriz, *vetorAux, **matrizPrincipal, NUMERO_DE_LINHAS, NUMERO_DE_COLUNAS;
FILE *arquivo_entrada;
int valorAux, valorLinha, valorColuna;

//Analisar os valores da primeira linha.
void defineValoresAuxiliares(){
    fscanf(arquivo_entrada, "%d", &tamanhoMatriz); //Recebe o primeiro valor da primeira linha
    NUMERO_DE_COLUNAS = NUMERO_DE_LINHAS = tamanhoMatriz;
    vetorAux = malloc(tamanhoMatriz * sizeof(int)); //O vetor auxiliar contem os valores após o primeiro valor da primeira linha
    //Preencher vetor auxiliar com os valores restantes da primeira linha
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
    while(!feof(arquivo_entrada)){
        //Ler o par ordenado de cada linha e armazenar
        fscanf(arquivo_entrada, "%d", &valorLinha);
        fscanf(arquivo_entrada, "%d", &valorColuna);
        int linhaAux, colunaAux;
        //Percorre vetor auxiliar e compara a posição dos valores dos pares
        for(int i = 0; i < tamanhoMatriz; i++){
            if(valorLinha == vetorAux[i]){
                linhaAux = i;
            }
            if(valorColuna == vetorAux[i]){
                colunaAux = i;
            }
        }
        matrizPrincipal[linhaAux][colunaAux] = 1;
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

//Preenche matriz principal preenchendo com 0, para evitar erros
void iniciaMatrizPrincipal(){
     for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            matrizPrincipal[i][j] = 0;
        }
    }
}

//Imprimir vetor auxiliar para teste
void imprimeVetorAux(){
    for(int i = 0; i < tamanhoMatriz; i++){
        printf("%d", vetorAux[i]);
    }
}

int main(){
    arquivo_entrada = fopen("ex1.txt", "rt"); //Leitura do arquivo
    defineValoresAuxiliares();
    alocaMatrizPrincipal();
    iniciaMatrizPrincipal();
    preencheMatrizPrincipal();
    imprimeMatrizPrincipal();
}