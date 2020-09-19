#include <stdio.h>
#include <stdlib.h>

int tamanhoMatriz, *vetorAux, **matrizPrincipal, **matrizTransposta, NUMERO_DE_LINHAS, NUMERO_DE_COLUNAS;
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
//Alocação da matriz transposta da mesma forma que a matriz principal, a usaremos para comparações
void alocaMatrizTransposta(){
    matrizTransposta = (int **) malloc (sizeof(int *) * NUMERO_DE_LINHAS);
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        matrizTransposta[i] = (int *) malloc (sizeof(int) * NUMERO_DE_COLUNAS);
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

//Armazena cada linha da matriz principal na coluna da matriz transposta (propriedades de matrizes)
void preencheMatrizTransposta(){
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            matrizTransposta[j][i] = matrizPrincipal[i][j];
        }
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

//Imprimir matriz transposta para teste
void imprimeMatrizTransposta(){
    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            printf("%d", matrizTransposta[i][j]);
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

//Preenche matriz transposta preenchendo com 0, para evitar erros
void iniciaMatrizTransposta(){
     for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            matrizTransposta[i][j] = 0;
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
    } else {
        printf("1. Reflexiva: F\n");
        //Caso não seja reflexiva, irei printar os pares que fazem com que essa condição não seja aceita.
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
    } else {
        //Caso não seja irreflexiva, irei printar os pares que fazem com que essa condição não seja aceita.
        printf("2. Irreflexiva: F\n");
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
    int ignora = 0;
    if(count == 1){
        printf("Simetrica: V\n");
    } else {
        printf("Simetrica: F\n");
        for(int i = 0; i < NUMERO_DE_LINHAS; i++){
            for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
                if(matrizPrincipal[i][j] != matrizPrincipal[j][i]){
                    if(ignora == 0){
                        ignora++;
                    } else {
                        printf("(%d, %d); ", vetorAux[i], vetorAux[j]);
                        ignora++;
                    }
                    break;
                } 
            }
        }
        printf("\n");
    }
}

void verificaAntiSimetrica(){
    int count = 1;

    for(int i = 0; i < NUMERO_DE_LINHAS; i++){
        for(int j = 0; j < NUMERO_DE_COLUNAS; j++){
            if(i != j){  
                if(matrizPrincipal[i][j] == 1 && matrizPrincipal[j][i] == 1){
                    count = 0;
                }
            }
        }
    }

    if(count == 1){
        printf("Anti-simetrica: V\n");
    } else {
        printf("Anti-simetrica: F\n");
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



int main(){
    arquivo_entrada = fopen("ex5.txt", "rt"); //Leitura do arquivo
    defineValoresAuxiliares();

    alocaMatrizPrincipal();
    alocaMatrizTransposta();

    iniciaMatrizPrincipal();
    iniciaMatrizTransposta();

    preencheMatrizPrincipal();
    preencheMatrizTransposta();

    imprimeMatrizPrincipal();
    printf("\n");
    imprimeMatrizTransposta();

    verificaReflexiva();
    verificarIrreflexiva();

    verificaSimetrica();
    verificaAntiSimetrica();
}