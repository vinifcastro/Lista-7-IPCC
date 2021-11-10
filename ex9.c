#include <stdio.h>

typedef struct {
    int num, den;
} fracao;

/**
 * @brief Realiza o teste de equivalencia entre duas frações
 * 
 * @param x Ponteiro para vetor do tipo struct fracao.
 * @param z quantidade de frações
 * @return int seq, que é a quantidade de equivalencias realizadas.
 */
int equivalence(fracao * x, int z);

int main(){
    int n, k, z, teste=1, seq;
    double g, h;
    char a;
    fracao x[50];
    scanf("%d", &n);
    while (n>0){
        a = ' ';
        z = 0;
        while (a!='\n'){ 
            scanf("%d/%d%c", &( x[z].num ), &( x[z].den ), &a);
            z++;
        }
        printf("Caso de teste %d\n", teste);
        seq = equivalence(x, z);
        if (seq == 0) printf("Nao ha fracoes equivalentes na sequencia\n");
        n--;
        teste++;
    }
    return 0;
}

int equivalence(fracao * x, int z){
    int i, k, seq = 0;
    double g, h;
    for (i=0;i<z;i++){
        for (k=i+1;k<z;k++){
            g = x[i].num/(double)x[i].den;
            h = x[k].num/(double)x[k].den;
            if (  g == h ){
                printf("%d/%d equivalente a %d/%d\n", x[i].num, x[i].den, x[k].num, x[k].den);
                seq++;
            }
            else if ( h == g ){
                printf("%d/%d equivalente a %d/%d\n", x[k].num, x[k].den, x[i].num, x[i].den);
                seq++;
            }
        }
    }
    return seq;
}