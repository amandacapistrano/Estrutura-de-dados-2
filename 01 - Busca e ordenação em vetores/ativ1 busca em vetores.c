#include<stdio.h>
int buscaLinear(int *vetor, int n, int elem);
int buscaOrdenada(int *vetor, int n, int elem);
int buscaBinaria(int *vetor, int n, int elem);


int main(){
    int vOrd[] = {15, 26, 37, 48, 59, 61, 75, 86, 97, 108};
    int vDes[] = {61, 75, 86, 26, 97, 48, 108, 15, 37, 59};
    int n = 10;
    int elem = 59;
    int i;

    printf("Vetor ordenado: ");
    for(i = 0; i < 10; i++){
        printf("%d, ", vOrd[i]);
    }
    printf("\nVetor desordenado: ");
    for(i = 0; i < 10; i++){
        printf("%d, ", vDes[i]);
    }
    printf("\n\nBusca linear:");
    int linear = buscaLinear(vDes, n, elem);
    printf("\nIndice: %d, v = %d\n", linear, vDes[linear]);

    printf("\nBusca Ordenada:\n");
    int ordenada = buscaOrdenada(vOrd, n, elem);
    printf("Indice: %d, v = %d\n", ordenada, vOrd[ordenada]);

    printf("\nBusca binária:\n");
    int binaria = buscaBinaria(vOrd, n, elem);
    printf("Indice: %d, v = %d\n", binaria, vOrd[binaria]);


}

//Busca Linear
int buscaLinear (int *vetor, int n, int elem){
    int i;
    for(i = 0; i < n; i++){
        if(elem == vetor[i]){
            return i;
        }
    }
    return -1;
}
//Busca Ordenada
int buscaOrdenada(int *vetor, int n, int elem){
    int i;
    for(i = 0; i < n; i++){
        if(elem == vetor[i]){
            return i;
        }else{
            if(elem < vetor[i]){
                return -1;
            }
        }
    }
    return -1;
}
//Busca Binaria
int buscaBinaria(int *vetor, int n, int elem){
    int i, inicio, meio, fim;
    inicio = 0;
    fim = n - 1;

    while(inicio <= fim){
        meio = (inicio + fim)/ 2;
        if(elem < vetor[meio]){
            fim = meio -1;
        }else{
            if(elem > vetor[meio]){
                inicio = meio + 1;
            }else{
                return meio;
            }
        }
    }
    return -1;
}

