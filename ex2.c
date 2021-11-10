#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fruta[15];
    double preco;
    int qtd;
} fruit;

int main(){
    int n, z, i, j, k, tempqtd;
    char frutatemp[15];
    double total;
    fruit * compras = NULL;
    scanf("%d", &n);
    while (n>0){
        total = 0;
        scanf("%d", &z);
        compras = (fruit *) calloc(z, sizeof(fruit));
        for (i=0; i<z; i++){
            scanf("%s %lf", compras[i].fruta , &( compras[i].preco ));
        }
        scanf("%d", &j);
        for (i=0; i<j; i++){
            scanf("%s %d", frutatemp, &tempqtd);
            for (k=0; k<z; k++){
                if (strcmp(compras[k].fruta, frutatemp) == 0){
                    compras[k].qtd = tempqtd;
                    k=z;
                }
            }
        }
        for (i=0; i<z; i++){
            total += (compras[i].preco*(double)compras[i].qtd);
        }
        printf("R$ %.2lf\n", total);
        free(compras);
        n--;
    }
    return 0;
}