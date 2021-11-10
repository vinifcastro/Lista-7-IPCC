#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double x[4];
} coords;

/**
 * @brief FAZ A TROCA DE DUAS STRUCTS
 * 
 * @param x STRUCT 1
 * @param y STRUCT 2
 */
void swap(coords * x, coords * y);

/**
 * @brief CALCULA O MODULO DE UM VETOR QUE POSSUI SUAS COORDS ARMAZENADAS EM UMA STRUCT
 * 
 * @param a STRUCT QUE CONTEM AS COORDS DOS VETORES
 * @return RETORNA O VALOR DO MODULO
 */
double modulo(coords a);

int main(){
    coords * a = NULL;
    double * module;
    int n, i, k;
    scanf("%d", &n);
    a = (coords *) malloc(n*sizeof(coords));
    for (i=0; i<n; i++){
        for (k=0; k<4; k++){
            scanf("%lf", &( a[i].x[k] ));
        }
    }

    for (i=0; i<n ; i++)
        for(k=i+1; k<n ; k++)
            if (modulo(a[i]) > modulo(a[k])) swap(&a[i], &a[k]);
      

    for (i=0; i<n; i++){
        printf("Vetor: (");
        for (k=0; k<4; k++){
            if (k!=3) printf("%.2lf, ", ( a[i].x[k] ));
            else printf("%.2lf", ( a[i].x[k] ));
        }
        printf(") Norma: ");
        printf("%.2lf\n", modulo(a[i]));
    }
    
    free(a);
    return 0;
}

double modulo(coords a){
    double module;
    module = sqrt( pow(a.x[0], 2) + pow(a.x[1], 2) + pow(a.x[2], 2) + pow(a.x[3], 2) );
    return module;
}

void swap(coords * x, coords * y){
    coords temp = *x;
    *x = *y;
    *y = temp;
}