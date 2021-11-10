#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    double coord[4];
} coords;

coords * scancoord(int n);

double dist(coords a, coords b);

int main(){
    int n, i;
    coords * pontos = NULL;
    scanf("%d", &n);
    pontos = scancoord(n);
    for (i=0; i<(n-1); i++){
        printf("%.2lf\n", dist(pontos[i], pontos[i+1]));
    }
    free(pontos);
    return 0;
}

double dist(coords a, coords b){
    double distancia = 0;
    int i;
    for (i=0; i<4; i++) distancia += pow((a.coord[i]-b.coord[i]),2);
    distancia = sqrt(distancia);
    return distancia;
}

coords * scancoord(int n){
    int i, k;
    coords * a = NULL;
    a = (coords *) malloc(n*sizeof(coords));
    for (i=0;i<n;i++)
        for (k=0;k<4;k++) 
            scanf("%lf", &(a[i].coord[k]));
    return a;
}