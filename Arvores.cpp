#include <string.h>

typedef struct TNo_Codigo {
    int codigo;
    int id;
    struct TNo_Codigo *esquerda;
    struct TNo_Codigo *direita;
};

typedef struct TNo_Nome {
    char nome[80];
    int id;
    struct TNo_Nome *esquerda;
    struct TNo_Nome *direita;
};

typedef struct TNo_Local {
    char local;
    int id;
    struct TNo_Local *esquerda;
    struct TNo_Local *direita;
};

void inserirArvoreCodigo(TNo_Codigo *no, int codigo_inserido, int identificador) {

    if (no == NULL) {
        no = (TNo_Codigo*) malloc(sizeof (TNo_Codigo));
        no->direita = NULL;
        no->esquerda = NULL;
        no->codigo = codigo_inserido;
        no->id=identificador;
        return;
    } else if (no->codigo > codigo_inserido) {
        inserirArvoreCodigo(no->esquerda, codigo_inserido, identificador);
        return;
    }
    else {
        inserirArvoreCodigo(no->direita, codigo_inserido, identificador);
        return;
    }
}

void inserirArvoreNome(TNo_Nome *no, char nomeDoCurso[], int identificador) {

    if (no == NULL) {
        no = (TNo_Nome*) malloc(sizeof (TNo_Nome));
        no->direita = NULL;
        no->esquerda = NULL;
        strcpy(nomeDoCurso, no->nome);
        no->id=identificador;
    }
    else if ((strcmp(no->nome,nomeDoCurso))==1)
       inserirArvoreNome(no->esquerda,nomeDoCurso,identificador);
    else inserirArvoreNome(no->direita,nomeDoCurso,identificador);
}

void inserirArvoreLocal(TNo_Local *no, int localDoCurso, int identificador) {

    if (no == NULL) {
        no = (TNo_Local*) malloc(sizeof (TNo_Local));
        no->direita = NULL;
        no->esquerda = NULL;
        no->local = localDoCurso;
        no->id=identificador;
        
    } else if (no->local > localDoCurso) {
        inserirArvoreLocal(no->esquerda, localDoCurso, identificador);
        return;
    }
    else {
        inserirArvoreLocal(no->direita, localDoCurso, identificador);
        return;
    }
}

int busca_por_codigo(TNo_Codigo *raizDaArvore, int codigo)
{
	TNo_Codigo *noDeBusca = raizDaArvore;
	
	while (noDeBusca)
	{
		if (codigo == noDeBusca->codigo)
			return noDeBusca->id;
		else if (codigo < noDeBusca->codigo)
			noDeBusca = noDeBusca->esquerda;
		else 
			noDeBusca = noDeBusca->direita;
	}
	
	return -1;
}
int busca_por_disciplina(TNo_Nome *raizDaArvore, char disciplina[])
{
	TNo_Nome *noDeBusca = raizDaArvore;
	
	while (noDeBusca)
	{
		if ((strcmp(noDeBusca->nome,disciplina))==0)
			return noDeBusca->id;
		else if ((strcmp(noDeBusca->nome,disciplina))==1)
			noDeBusca = noDeBusca->esquerda;
		else 
			noDeBusca = noDeBusca->direita;
	}
	
	return -1;
}
int busca_por_local(TNo_Local *raizDaArvore, int local)
{
	TNo_Local *noDeBusca = raizDaArvore;
	
	while (noDeBusca)
	{
		if (local == noDeBusca->local)
			return noDeBusca->id;
		else if (local < noDeBusca->local)
			noDeBusca = noDeBusca->esquerda;
		else 
			noDeBusca = noDeBusca->direita;
	}
	
	return -1;
}

void travessia(TNo_Codigo *node)
{
    printf("Travessia");
	if (node)
	{
            printf("\nCodigo : %d\n",node->codigo);
		travessia(node->esquerda);
		travessia(node->direita);
	}
}
