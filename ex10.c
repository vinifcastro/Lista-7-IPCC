#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double k;
    int pot;
} poly;

int indicemaior(poly * a, poly * b, int ta, int tb);

poly * scanpoly(int * b);

int main(){
    poly * pol1 = NULL;
    poly * pol2 = NULL;
    int tpol1, tpol2, n, im, i;
    char signal;
    double * polyop = NULL;
    scanf("%d%*c", &n);
    while (n--){
        scanf("%c%*c", &signal);
        pol1 = scanpoly(&tpol1);
        pol2 = scanpoly(&tpol2);
        im = indicemaior(pol1, pol2, tpol1, tpol2);
        polyop = (double *) calloc((im+1), sizeof(double));
        for (i=0; i<tpol1; i++) polyop[(pol1[i].pot)] = pol1[i].k;
        for (i=0; i<tpol2; i++){
            if (signal == '+'){
                polyop[(pol2[i].pot)] += pol2[i].k;
            }
            else{
                polyop[(pol2[i].pot)] -= pol2[i].k;
            }
        }
        for(i=im; i>=0; i--){
            if (polyop[i]!=0){
                if (i!=0){
                    if (polyop[i]>0)  printf("+%.2lfX^%d", polyop[i], i);
                    else  printf("%.2lfX^%d", polyop[i], i);
                }
                else if (i == 0) {
                    if (polyop[i]>0)  printf("+%.2lf\n", polyop[i]);
                    else  printf("%.2lf\n", polyop[i]);
                }
            }
            else continue;
        }
        free(pol1);
        free(pol2);
        free(polyop);
    }
    return 0;
}

poly * scanpoly(int * b){
    int n, i;
    poly * a = NULL;
    scanf("%d%*c", &n);
    *b = n;
    a = (poly *) malloc(n*sizeof(poly));
    for (i=0; i<n; i++){
        scanf("%lf %d%*c", &a[i].k, &a[i].pot);
    }
    return a;
}

int indicemaior(poly * a, poly * b, int ta, int tb){
    int i, im=-1;
    for (i=0; i<ta; i++){
        if (a[i].pot > im) im=a[i].pot;
    }
    for (i=0; i<tb; i++){
        if (b[i].pot > im) im=b[i].pot;
    }
    return im;
}

