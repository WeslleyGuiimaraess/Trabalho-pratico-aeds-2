#include "fila.h"

Fila *criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->final = NULL;
    f->qtd = 0;
    return f;
}

int insereFila(Fila* f, int ID, int combustivel) {
    if (f == NULL) return 0;
    Aviao *e = (Aviao*) malloc(sizeof(Aviao));
    e->ID = ID ;
    e->combustivel = combustivel ;
    //Inserção do Aviao no final da fila
    if (f->final != NULL) //Já tenho pelo menos um Aviao na fila
    {
       f->final->prox = e;
    }
    else //Fila está vazia
    {
       f->inicio = e;
       f->final = e;
    }
    f->qtd++;
    return 1;
}

Aviao* consultaFila(Fila* f) {
    return f->inicio;
}

int removeFila(Fila* f) {
    if (f->inicio!=NULL)
    {
       Aviao *p = f->inicio;
       f->inicio = f->inicio->prox;
       free(p);
       return 1;
     }
     return 0;
}

int removeFilaMeio(Fila* f, int n) {

    int i;
    Aviao *aux = consultaFila(f), *e;

    for(i = 0; i<n-1 ; i++){
        aux = aux->prox;
    }
    e=aux->prox;
    aux->prox = aux->prox->prox;
    free(e);

}
