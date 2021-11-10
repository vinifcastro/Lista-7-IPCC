#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int a, b;
} tRacional;
 
/**
Recebe um racional e retorna o seu negativo (-r).
@param r numero racional
@return
*/
tRacional negativo(tRacional r);
 
/**
Recebe dois inteiros a e b e retorna o racional
@param a numerador
@param b denominador
@return
*/
tRacional racional(int a, int b);
 
/**
Calcula o MDC de x e y
@param x
@param y
@return
*/
int MDC(int x, int y);
 
/**
Recebe dois racionais e retorna a adição de ambos (r1 + r2).
@param r1 fator esquerdo da soma
@param r2 fator direito da soma
@return
*/
tRacional soma( tRacional r1,  tRacional r2);
 
/**
Recebe dois racionais e retorna o produto de ambos (r1 * r2).
@param r1 primeiro fator do produto
@param r2 segundo fator do produto
@return
*/
tRacional mult( tRacional r1,  tRacional r2);
 
/**
Recebe dois racionais e retorna o quociente de ambos (r1/r2).
@param r1 numerador
@param r2 denominador
@return
*/
tRacional divide( tRacional r1,  tRacional r2);
 
/**
Recebe um racional e reduz a fração ao máximo.
@param r o número racional a ser reduzido
*/
void reduzFracao(  tRacional * r);
 
int findGCD(int a, int b);
 
int main(){
    tRacional q1, q2, q3;
    tRacional resultado;
    int x, y, a, b;
    char signal;
    while(scanf("%d %d %c %d %d", &x, &y, &signal, &a, &b)!=EOF){
        q1 = racional(x, y);
        q2 = racional(a, b);
        switch(signal){
            case ('+'): 
                resultado = soma( q1,  q2);
            break;
            case ('-'):
                q3 = negativo(q2);
                resultado = soma( q1, q3);
            break;
            case ('*'):
                resultado = mult( q1,  q2);
            break;
            case ('/'):
                resultado = divide( q1,  q2);
            break;
            default:
                break;
        }
        reduzFracao(  &resultado );
        printf("%d %d\n", resultado.a, resultado.b);
    }
    return 0;
}
 
tRacional racional(int a, int b){
    tRacional x;
    x.a = a;
    x.b = b;
    return x;
}
 
int MDC(int x, int y){
    int MDC;
    MDC = x*y;
    return MDC;
}
 
tRacional negativo(tRacional r){
    tRacional a = r;
    a.a*=-1;
    return a;
}
 
tRacional soma( tRacional r1,  tRacional r2){
    tRacional result;
    result.b = MDC(r1.b,r2.b);
    result.a = ( ( (r1.a*(result.b/r1.b)) ) + ( (r2.a*(result.b/r2.b)) ) );
    return result;
}
 
tRacional mult( tRacional r1,  tRacional r2){
    tRacional result;
    result.a = r1.a*r2.a;
    result.b = r1.b*r2.b;
    return result;
}
 
tRacional divide( tRacional r1,  tRacional r2){
    tRacional result;
    result.a = r1.a*r2.b;
    result.b = r1.b*r2.a;
    return result;
}
 
void reduzFracao(  tRacional * r){
    int i, gcdd, x=0, y=0;
    tRacional a = *r;
    if (a.a<0) {
        a.a*=-1;
        x=1;
    }
    if (a.b<0) {
        a.b*=-1;
        y=1;
    }
    gcdd = findGCD(a.a,a.b);
    a.a = a.a/gcdd;
    a.b = a.b/gcdd;
    if (x==1) a.a*=-1;
    if (y==1) a.b*=-1;
    *r = a;
}
 
int findGCD(int a, int b){
    if(b==0)
        return a;
    findGCD(b,a%b);
}