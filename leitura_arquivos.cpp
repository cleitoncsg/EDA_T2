#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arvores.cpp"

#define MAX 41

struct informacao {
    int codigo;
    char nomeDoCurso[80];
    int local;
};

struct informacao informacoes[MAX];

void ler_arquivo() {

    FILE *arquivoDeTexto;
    int codigo, local;
    char disciplina[80];

    arquivoDeTexto = fopen("cursos_codigo_local.txt", "rt");

    for (int identificador = 0; identificador < 40; identificador++) {

        fscanf(arquivoDeTexto, "%d ", &codigo);
        fscanf(arquivoDeTexto, "%s ", disciplina);
        fscanf(arquivoDeTexto, "%d ", &local);

        informacoes[identificador].codigo = codigo;
        informacoes[identificador].local = local;
        strcpy(informacoes[identificador].nomeDoCurso, disciplina);
    }
    
    fclose(arquivoDeTexto);
}

void menu(){
    printf("\t\t\t____________________________\n");
    printf("\t\t\tDIGITE UMA OPCAO, POR FAVOR:\n");
    printf("\t\t\t____________________________\n\n");

    printf("\t\t  _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("\t\t -_-\t 1) Procurar por codigo          -_-\n");
    printf("\t\t-_-\t 2) Procura por discplina            -_-\n");
    printf("\t\t-_-\t 3) Procura por local              -_-\n");
    printf("\t\t-_-\t 4) Excluir turma                   -_-\n");
    printf("\t\t  -_-\t 6) Sair do programa               -_-\n");
    printf("\t\t   -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");

}

int main(){
    int opcao;
    
    for(;;){
        menu();
        
        scanf("%d", &opcao);
        
        switch(opcao){
                
            case 1:
                ler_arquivo();
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!");
                break; 
        }
        
        
    }
    //sgetchar();
    return 0;
}

