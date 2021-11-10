#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod;
    double credito;
    char curso[100];
} tabelacursos;

typedef struct {
    char aluno[500];
    int cod, qtdcred;
} alunos;

int main(){
    int i, k, z, x;
    tabelacursos * cursos = NULL;
    alunos * alun = NULL;
    scanf("%d%*c", &z);
    cursos = (tabelacursos *) malloc(z*sizeof(tabelacursos));
    for(i=0;i<z;i++){
        scanf("%d%*c", &(cursos[i].cod));
        scanf("%lf%*c", &(cursos[i].credito));
        scanf("%[^\n]%*c", cursos[i].curso);
    }
    scanf("%d%*c", &x);
    alun = (alunos *) malloc(x*sizeof(alunos));
    for(i=0;i<x;i++){
        scanf("%[^\n]%*c", alun[i].aluno);
        scanf("%d%*c", &(alun[i].cod));
        scanf("%d%*c", &(alun[i].qtdcred));
    }
    for(i=0;i<x;i++){
        for(k=0;k<z;k++){
            if (alun[i].cod == cursos[k].cod){
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n", alun[i].aluno, cursos[k].curso, alun[i].qtdcred, cursos[k].credito, (cursos[k].credito*alun[i].qtdcred));
                k=z;
            }
        }
    }
    free(cursos);
    free(alun);
    return 0;
}