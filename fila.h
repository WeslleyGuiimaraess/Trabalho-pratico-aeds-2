#include <stdio.h>
#include <stdlib.h>

struct TAviao {
    int combustivel;
    int ID;
    struct TAviao *prox;
};

struct TFila {
    struct TAviao *inicio;
    struct TAviao *final;
    int qtd;
};

typedef struct TAviao Aviao;
typedef struct TFila Fila;

Fila* criaFila();

int insereFila(Fila* f, int ID, int combustivel);

Aviao* consultaFila(Fila* f);

int removeFila(Fila* f);

int removeFilaMeio(Fila* f, int n);
