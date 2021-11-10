#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int d[4];
    char nome[200];
} datanome;

/**
 * @brief Faz a troca de duas structs do tipo datanome;
 * 
 * @param x Struct 1
 * @param y Struct 2
 */
void swap(datanome * x, datanome * y);

/**
 * @brief Faz a ordenação da data que está contida dentro de cada struct do vetor do tipo datanome;
 * 
 * @param list_name Vetor do tipo datanome;
 * @param n tamanho do vetor;
 */
void ordena_data(datanome * list_name, int n);

int main(){
    int i, k, z;
    datanome * list_name = NULL;
    scanf("%d", &z);
    list_name = (datanome *) malloc(z*sizeof(datanome));
    for (i=0; i<z; i++){
        for (k=0; k<4; k++){
            scanf("%d%*c", &(list_name[i].d[k]));
        }
        scanf("%[^\n]%*c", list_name[i].nome);
    }
    ordena_data(list_name, z);
    for (i=0; i<z; i++) printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", list_name[i].d[0], list_name[i].nome, list_name[i].d[1], list_name[i].d[2], list_name[i].d[3]);
    free(list_name);
    return 0;
}

void swap(datanome * x, datanome * y){
    datanome temp = *x;
    *x = *y;
    *y = temp;
}

void ordena_data(datanome * list_name, int n){
    int i, k;
    for (i=0; i<n ; i++)
        for(k=i+1; k<n ; k++)
            if (list_name[i].d[3] < list_name[k].d[3]) swap(&list_name[i], &list_name[k]);

    for (i=0; i<n ; i++)
        for(k=i+1; k<n ; k++)
            if ((list_name[i].d[2] < list_name[k].d[2]) && (list_name[i].d[3] == list_name[k].d[3])) swap(&list_name[i], &list_name[k]);

    for (i=0; i<n ; i++)
        for(k=i+1; k<n ; k++)
            if (list_name[i].d[1] < list_name[k].d[1] && (list_name[i].d[3] == list_name[k].d[3]) && (list_name[i].d[2] == list_name[k].d[2])) swap(&list_name[i], &list_name[k]);
}