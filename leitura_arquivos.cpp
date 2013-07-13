#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arvores.cpp"

#define MAX 40

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

    for (int identificador = 0; identificador < MAX; identificador++) {

        fscanf(arquivoDeTexto, "%d ", &codigo);
        fscanf(arquivoDeTexto, "%s ", disciplina);
        fscanf(arquivoDeTexto, "%d ", &local);

        informacoes[identificador].codigo = codigo;
        informacoes[identificador].local = local;
        strcpy(informacoes[identificador].nomeDoCurso, disciplina);
    }
    
    fclose(arquivoDeTexto);
}

void imprimi_matriz_informacoes(){    
        system("cls");
        for(int identificador = 0 ; identificador<MAX; identificador++){
        printf("\tCódigo : %d", informacoes[identificador].codigo);
        printf("\tCurso : %s", informacoes[identificador].nomeDoCurso);
        printf("\tLocal : %d\n", informacoes[identificador].local);
    }
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
    printf("\t\t -_-\t 5)Listar todas as turmas          -_-\n");
    printf("\t\t  -_-\t 6) Sair do programa               -_-\n");
    printf("\t\t   -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");

}

int main(){
    int opcao;
    ler_arquivo();
    
    for(;;){
        menu();
        
        scanf("%d", &opcao);
        
        switch(opcao){
                
            case 1:
                
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                imprimi_matriz_informacoes();
                break;
            case 6:
                return 0;
            default:
                printf("Opcao invalida!");
                break;
        }
        
        
    }
    return 0;
}

