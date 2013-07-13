#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arvores.cpp"

#define MAX 40

typedef struct informacao {
    int codigo;
    char nomeDoCurso[80];
    int local;
};

informacao informacoes[MAX];
TNo_Codigo *arvore_codigos;
TNo_Nome *arvore_nomes;
TNo_Local *arvore_locais;


void controi_arvores() {

    FILE *arquivoDeTexto;
    int codigo, local;
    char disciplina[80];

    arquivoDeTexto = fopen("cursos_codigo_local.txt", "rt");

    for (int identificador = 0; identificador < MAX; identificador++) {

        fscanf(arquivoDeTexto, "%d ", &codigo);
        fscanf(arquivoDeTexto, "%s ", disciplina);
        fscanf(arquivoDeTexto, "%d ", &local);

        informacoes[identificador].codigo = codigo;
        inserirArvoreCodigo(arvore_codigos,codigo,identificador);
        
        informacoes[identificador].local = local;
        inserirArvoreNome(arvore_nomes,disciplina,identificador);
        
        strcpy(informacoes[identificador].nomeDoCurso, disciplina);
        inserirArvoreLocal(arvore_locais,local,identificador);
        
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

void retorna_dados(int identificador){
    if(identificador==-1){
        printf("Nao foi encontrado\n");
        return;
    }
    printf("Codigo: %d\n",informacoes[identificador].codigo);
    printf("Disciplina: %s\n",informacoes[identificador].nomeDoCurso);
    printf("Local: %d\n",informacoes[identificador].local);   
    system("pause");
}

int main(){
    int opcao,codigoDePesquisa,localDePesquisa;
    char nomeDePesquisa[80];
    controi_arvores();
    
    travessia(arvore_codigos);
    for(;;){
        system("cls");
        menu();
        
        scanf("%d", &opcao);
        
        
        switch(opcao){
                
            case 1:
                printf("\nInforme o codigo : ");
                scanf("%d",&codigoDePesquisa);
                retorna_dados( busca_por_codigo(arvore_codigos,codigoDePesquisa));
                break;
            case 2:
                printf("\nInforme o nome do curso : ");
                gets(nomeDePesquisa);
                retorna_dados( busca_por_disciplina(arvore_nomes,nomeDePesquisa));
                break;
            case 3:
                printf("\nInforme o local : ");
                scanf("%d",&localDePesquisa);
                retorna_dados( busca_por_local(arvore_locais,localDePesquisa));
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