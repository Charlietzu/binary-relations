#include <stdio.h>
#include <stdlib.h>

int tamanhoMatriz, *vetorAux, **matrizPrincipal, NUMERO_DE_LINHAS, NUMERO_DE_COLUNAS;
FILE *arquivo_entrada, *arquivo_saida;
int valorAux, valorLinha, valorColuna;

int matrizReflexiva = 0, matrizSimetrica = 0, matrizTransitiva = 0, matrizAntissimetrica = 0, matrizIrreflexiva = 0;

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

//Verifica se a matriz principal é reflexiva
void verificaReflexiva(){
    int count = 0;
    //Iteração pela diagonal da matriz
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(i == j){
                if(matrizPrincipal[i][j] == 1){
                    count++;
                }
            }
          
        }
    }
    //Para ser reflexiva, o contador ter sido somado em todas as posições da diagonal (que é o mesmo número de linhas ou colunas)
    if(count == NUMERO_DE_LINHAS){
        printf("1. Reflexiva: V\n");
        fprintf(arquivo_saida, "1. Reflexiva: V\n");
        matrizReflexiva = 1;
    } else {
        printf("1. Reflexiva: F\n");
        fprintf(arquivo_saida, "1. Reflexiva: F\n");
        matrizReflexiva = 0;
        //Caso não seja reflexiva, irei printar os pares que fazem com que essa condição não seja aceita.
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if(i == j){
                    if(matrizPrincipal[i][j] != 1){
                        printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                        fprintf(arquivo_saida, "(%d, %d); ", vetorAux[i], vetorAux[j]);
                    }
                }
            }
        }
        fprintf(arquivo_saida, "\n");
    }
}

//Verifica se a matriz principal é irreflexiva
void verificarIrreflexiva(){
    int count = 0;
    //Iteração pela diagonal da matriz
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(i == j){
                if(matrizPrincipal[i][j] != 1){
                    count++;
                }
            }
          
        }
    }

    //Para ser irreflexiva, o contador NÃO pode ter sido somado em todas as posições da diagonal (que é o mesmo número de linhas ou colunas)
    if(count == NUMERO_DE_LINHAS){
        printf("2. Irreflexiva: V\n");
        fprintf(arquivo_saida, "2. Irreflexiva: V\n");
        matrizIrreflexiva = 1;
    } else {
        //Caso não seja irreflexiva, irei printar os pares que fazem com que essa condição não seja aceita.
        printf("2. Irreflexiva: F\n");
        fprintf(arquivo_saida, "2. Irreflexiva: F\n");
        matrizIrreflexiva = 0;
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if(i == j){
                    if(matrizPrincipal[i][j] == 1){
                        printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                        fprintf(arquivo_saida, "(%d, %d); ", vetorAux[i], vetorAux[j]);
                    }
                }
            }
        }
        printf("\n");
        fprintf(arquivo_saida, "\n");
    }
}

//Verifica se a matriz principal é simetrica
void verificaSimetrica(){
    int count = 1;
    //Comparar se a matriz principal é igual a matriz transposta (propriedades de matrizes)
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
        fprintf(arquivo_saida, "Simetrica: V\n");
        matrizSimetrica = 1;
    } else {
        printf("Simetrica: F\n");
        fprintf(arquivo_saida, "Simetrica: F\n");
        matrizSimetrica = 0;
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if (matrizPrincipal[i][j] == 0 && matrizPrincipal[j][i] == 1) {
                    printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                    fprintf(arquivo_saida, "(%d, %d); ", vetorAux[i], vetorAux[j]);
                    break;
                }
            }
        }
        printf("\n");
        fprintf(arquivo_saida, "\n");
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
        fprintf(arquivo_saida, "Anti-simetrica: V\n");
        matrizAntissimetrica = 1;
    } else {
        printf("Anti-simetrica: F\n");
        fprintf(arquivo_saida, "Anti-simetrica: F\n");
        matrizAntissimetrica = 0;
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = i; j < NUMERO_DE_COLUNAS; j++){
                if(matrizPrincipal[i][j] == 1 && matrizPrincipal[j][i] == 1 && (i!=j)){
                    printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                    fprintf(arquivo_saida,"(%d, %d); ", vetorAux[i], vetorAux[j]);
                    printf("(%d, %d); ", vetorAux[j], vetorAux[i]);
                    fprintf(arquivo_saida, "(%d, %d); ", vetorAux[j], vetorAux[i]);
                }
            }
        }
        printf("\n");
        fprintf(arquivo_saida, "\n");
    }
}

void verificaAssimetrica(){
    if(matrizIrreflexiva == 1 && matrizAntissimetrica == 1){
        printf("Assimetrica: V\n");
        fprintf(arquivo_saida, "Assimetrica: V\n");
    } else {
        printf("Assimetrica: F\n");
        fprintf(arquivo_saida, "Assimetrica: F\n");
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
        fprintf(arquivo_saida, "Transitiva: V\n");
        matrizTransitiva = 1;
    } else {
        printf("Transitiva: F\n");
        fprintf(arquivo_saida, "Transitiva: F\n");
        matrizTransitiva = 0;
        for(int i= 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if((i != j) && matrizPrincipal[i][j] == 1){
                    for(int k = 0; k < NUMERO_DE_LINHAS; k++){
                        if((j != k) && matrizPrincipal[j][k] == 1 && matrizPrincipal[i][k] != 1){   
                            printf("(%d, %d); ", vetorAux[i], vetorAux[k]);
                            fprintf(arquivo_saida, "(%d, %d); ", vetorAux[i], vetorAux[k]);
                            matrizPrincipal[i][k] = 1;
                        }
                    }
                }
            }
        } 
        printf("\n");
        fprintf(arquivo_saida, "\n");
    }
}

void verificaRelacaoEquivalencia(){
    if(matrizReflexiva == 1 && matrizSimetrica == 1 && matrizTransitiva == 1){
        printf("Relacao de equivalencia: V\n");
        fprintf(arquivo_saida, "Relacao de equivalencia: V\n");
    } else {
        printf("Relacao de equivalencia: F\n");
        fprintf(arquivo_saida, "Relacao de equivalencia: F\n");
    }
}

void verificaRelacaoOrdemParcial(){
     if(matrizReflexiva == 1 && matrizAntissimetrica == 1 && matrizTransitiva == 1){
        printf("Relacao de ordem parcial: V\n");
        fprintf(arquivo_saida, "Relacao de ordem parcial: V\n");
    } else {
        printf("Relacao de ordem parcial: F\n");
        fprintf(arquivo_saida, "Relacao de ordem parcial: F\n");
    }
}

void verificaFechoTransitivo(){
    printf("Fecho transitivo da relacao: ");
    fprintf(arquivo_saida, "Fecho transitivo da relacao: ");
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(matrizPrincipal[i][j] == 1){
                printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                fprintf(arquivo_saida, "(%d, %d); ", vetorAux[i], vetorAux[j]);
            }
        }
    }
}

int main(){
    arquivo_entrada = fopen("ex1.txt", "rt"); //Leitura do arquivo
    arquivo_saida = fopen("sd_teste.txt", "w"); //Criando arquivo modo escrita
    defineValoresAuxiliares();

    alocaMatrizPrincipal();
    iniciaMatrizPrincipal();
    preencheMatrizPrincipal();

    verificaReflexiva();
    verificarIrreflexiva();

    verificaSimetrica(); // TODO: consertar ordem de print
    verificaAntiSimetrica();
    verificaAssimetrica();

    verificaTransitiva();

    verificaRelacaoEquivalencia();
    verificaRelacaoOrdemParcial();

    verificaFechoTransitivo();
}