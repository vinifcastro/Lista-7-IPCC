#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct {
    int cod;
    double credito;
    char * curso;
} tabelacursos;

typedef struct {
    char * aluno;
    int cod, qtdcred;
} alunos;

int main(){
    int i, k, z, x;
    char aa[200];
    tabelacursos * cursos = NULL;
    alunos * alun = NULL;
    scanf("%d%*c", &z);
    cursos = (tabelacursos *) malloc(z*sizeof(tabelacursos));
    for(i=0;i<z;i++){
        scanf("%d%*c", &(cursos[i].cod));
        scanf("%lf%*c", &(cursos[i].credito));
        cursos[i].curso = NULL;
        scanf("%[^\n]%*c", aa);
        cursos[i].curso = (char *) malloc((strlen(aa)+1)*sizeof(char));
        strcpy(cursos[i].curso, aa);
    }
    scanf("%d%*c", &x);
    alun = (alunos *) malloc(x*sizeof(alunos));
    for(i=0;i<x;i++){
        alun[i].aluno = NULL;
        scanf("%[^\n]%*c", aa);
        alun[i].aluno = (char *) malloc((strlen(aa)+1)*sizeof(char));
        strcpy(alun[i].aluno, aa);
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
    for(i=0;i<x;i++) free(alun[i].aluno);
    for(i=0;i<z;i++) free(cursos[i].curso);
    free(cursos);
    free(alun);
    return 0;
}