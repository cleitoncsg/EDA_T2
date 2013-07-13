typedef struct TNo_Codigo {
    int codigo;
    struct TNo_Codigo *esquerda;
    struct TNo_Codigo *direita;
};

typedef struct TNo_Nome {
    char nome[80];
    struct TNo_Nome *esquerda;
    struct TNo_Nome *direita;
};

typedef struct TNo_Local {
    char local;
    struct TNo_Local *esquerda;
    struct TNo_Local *direita;
};

void inserirArvoreCodigo(TNo_Codigo *no, int codigo_inserido, int identificardo) {

    if (no == NULL) {
        no = (TNo_Codigo*) malloc(sizeof (TNo_Codigo));
        no->direita = NULL;
        no->esquerda = NULL;
        no->codigo = codigo_inserido;
    }

    void inserirArvoreCodigo(TNo_Nome *no, char nomeDoCurso[], int identificardo) {

        if (no == NULL) {
            no = (TNo_Codigo*) malloc(sizeof (TNo_Nome));
            no->direita = NULL;
            no->esquerda = NULL;
            no->nome = nomeDoCurso;
        }
    }

    void inserirArvoreCodigo(TNo_Local *no, int localDoCurso, int identificardo) {

        if (no == NULL) {
            no = (TNo_Local*) malloc(sizeof (TNo_Local));
            no->direita = NULL;
            no->esquerda = NULL;
            no->local = localDoCurso;
        }
    }
}
