#include <stdio.h>
#include <stdlib.h>

int tamanhoMatriz, *vetorAux, **matrizPrincipal, NUMERO_DE_LINHAS, NUMERO_DE_COLUNAS;
FILE *arquivo_entrada;
int valorAux, valorLinha, valorColuna;

int matrizReflexiva = 0, matrizSimetrica = 0, matrizTransitiva = 0, matrizAntissimetrica = 0, matrizIrreflexiva = 0;

void defineValoresAuxiliares(){
    fscanf(arquivo_entrada, "%d", &tamanhoMatriz);
    NUMERO_DE_COLUNAS = NUMERO_DE_LINHAS = tamanhoMatriz;
    vetorAux = malloc(tamanhoMatriz * sizeof(int));
    for(int i = 0; i < tamanhoMatriz; i++){
        fscanf(arquivo_entrada, "%d", &vetorAux[i]);
    }
}

void alocaMatrizPrincipal(){
    matrizPrincipal = (int **) malloc (sizeof(int *) * NUMERO_DE_LINHAS);
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        matrizPrincipal[i] = (int *) malloc (sizeof(int) * NUMERO_DE_COLUNAS);
    }
}

void preencheMatrizPrincipal(){
    while(!feof(arquivo_entrada)){
        fscanf(arquivo_entrada, "%d", &valorLinha);
        fscanf(arquivo_entrada, "%d", &valorColuna);
        int linhaAux, colunaAux;
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

void iniciaMatrizPrincipal(){
     for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            matrizPrincipal[i][j] = 0;
        }
    }
}

void verificaReflexiva(){
    int count = 0;
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(i == j){
                if(matrizPrincipal[i][j] == 1){
                    count++;
                }
            }
          
        }
    }
    
    if(count == NUMERO_DE_LINHAS){
        printf("1. Reflexiva: V\n");
        matrizReflexiva = 1;
    } else {
        printf("1. Reflexiva: F\n");
        matrizReflexiva = 0;
        
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if(i == j){
                    if(matrizPrincipal[i][j] != 1){
                        printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                    }
                }
            }
        }
        printf("\n");
    }
}

void verificarIrreflexiva(){
    int count = 0;
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(i == j){
                if(matrizPrincipal[i][j] != 1){
                    count++;
                }
            }
          
        }
    }

    
    if(count == NUMERO_DE_LINHAS){
        printf("2. Irreflexiva: V\n");
        matrizIrreflexiva = 1;
    } else {
        
        printf("2. Irreflexiva: F\n");
        matrizIrreflexiva = 0;
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if(i == j){
                    if(matrizPrincipal[i][j] == 1){
                        printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                    }
                }
            }
        }
        printf("\n");
    }
}

void verificaSimetrica(){
    int count = 1;
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
           if(matrizPrincipal[i][j] != matrizPrincipal[j][i]){
              count++;
              break;
           }
        }
    }
    int ignora = 1;
    if(count == 1){
        printf("Simetrica: V\n");
        matrizSimetrica = 1;
    } else {
        printf("Simetrica: F\n");
        matrizSimetrica = 0;
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if (matrizPrincipal[i][j] == 0 && matrizPrincipal[j][i] == 1) {
                    printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                    break;
                }
            }
        }
        printf("\n");
    }
}

void verificaAntiSimetrica(){
    int count = 0;

    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(i != j){  
                if(matrizPrincipal[i][j] == 1 && matrizPrincipal[j][i] == 1){
                    count = 1;
                }
            }
        }
    }

    if(count == 0){
        printf("Anti-simetrica: V\n");
        matrizAntissimetrica = 1;
    } else {
        printf("Anti-simetrica: F\n");
        matrizAntissimetrica = 0;
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = i; j < NUMERO_DE_COLUNAS; j++){
                if(matrizPrincipal[i][j] == 1 && matrizPrincipal[j][i] == 1 && (i!=j)){
                    printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                    printf("(%d, %d); ", vetorAux[j], vetorAux[i]);
                }
            }
        }
        printf("\n");
    }
}

void verificaAssimetrica(){
    if(matrizIrreflexiva == 1 && matrizAntissimetrica == 1){
        printf("Assimetrica: V\n");
    } else {
        printf("Assimetrica: F\n");
    }
}

void verificaTransitiva(){
    int count = 0;
    for(int i= 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if((i != j) && matrizPrincipal[i][j] == 1){
                for(int k = 0; k < NUMERO_DE_LINHAS; k++){
                    if((j != k) && matrizPrincipal[j][k] == 1 && matrizPrincipal[i][k] != 1){
                        count = 1;
                    }
                }
            }
        }
    }

    if(count == 0){
        printf("Transitiva: V\n");
        matrizTransitiva = 1;
    } else {
        printf("Transitiva: F\n");
        matrizTransitiva = 0;
        for(int i= 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if((i != j) && matrizPrincipal[i][j] == 1){
                    for(int k = 0; k < NUMERO_DE_LINHAS; k++){
                        if((j != k) && matrizPrincipal[j][k] == 1 && matrizPrincipal[i][k] != 1){   
                            printf("(%d, %d); ", vetorAux[i], vetorAux[k]);
                            matrizPrincipal[i][k] = 1;
                        }
                    }
                }
            }
        } 
        printf("\n");
    }
}

void verificaRelacaoEquivalencia(){
    if(matrizReflexiva == 1 && matrizSimetrica == 1 && matrizTransitiva == 1){
        printf("Relacao de equivalencia: V\n");
    } else {
        printf("Relacao de equivalencia: F\n");
    }
}

void verificaRelacaoOrdemParcial(){
     if(matrizReflexiva == 1 && matrizAntissimetrica == 1 && matrizTransitiva == 1){
        printf("Relacao de ordem parcial: V\n");
    } else {
        printf("Relacao de ordem parcial: F\n");
    }
}

void verificaFechoTransitivo(){
    printf("Fecho transitivo da relacao: ");
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(matrizPrincipal[i][j] == 1){
                printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
            }
        }
    }
}

int main(){
    arquivo_entrada = fopen("ex9.txt", "rt"); //Leitura do arquivo, troque o primeiro parmêtro pelo nome do arquivo desejado.
    defineValoresAuxiliares();

    alocaMatrizPrincipal();
    iniciaMatrizPrincipal();
    preencheMatrizPrincipal();

    verificaReflexiva();
    verificarIrreflexiva();

    verificaSimetrica();
    verificaAntiSimetrica();
    verificaAssimetrica();

    verificaTransitiva();

    verificaRelacaoEquivalencia();
    verificaRelacaoOrdemParcial();

    verificaFechoTransitivo();
}