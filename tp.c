#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fila.h"



int main(){

    srand(time(NULL));

    int QTDdecola; //armazena quantos decolam
    int QTDaterrissa; //armazena quantos pousam
    int i; //variaveis diversas

    Fila *decola1 = criaFila();
    Fila *aterrissa1 = criaFila();
    Fila *decola2 = criaFila();
    Fila *aterrissa2 = criaFila();
    Fila *decola3 = criaFila();
    Aviao *aux;

    while(1) {

        if(decola1->qtd > 0){ //verifica se a fila esta vazia
            printf("Avião %d decolou\n", consultaFila(decola1)->ID);
            removeFila(decola1);//faz o aviao decolar
        }

        if(decola2->qtd > 0){ //verifica se a fila esta vazia
            printf("Avião %d decolou\n", consultaFila(decola2)->ID);
            removeFila(decola2);//faz o aviao decolar
        }

        if(decola3->qtd > 0){ //verifica se a fila esta vazia
            printf("Avião %d decolou\n", consultaFila(decola1)->ID);
            removeFila(decola3);//faz o aviao decolar
        }

        if(aterrissa1->qtd > 0) { //verifica se a fila esta vazia
            printf("Avião %d pousou\n", consultaFila(aterrissa1)->ID);
            removeFila(aterrissa1);//faz o aviao decolar
        }

        if(aterrissa2->qtd > 0){ //verifica se a fila esta vazia
            printf("Avião %d pousou\n", consultaFila(aterrissa2)->ID);
            removeFila(aterrissa2);//faz o aviao decolar
        }

        aux = consultaFila(aterrissa1); //manda o nmovo primeiro elemento da fila
        for(i = 0 ; i<aterrissa1->qtd ; i++){

            aux->combustivel --;
            if(aux->combustivel <= 5){
                printf("Pouso de emergencia avião %d\n",aux->ID);
                removeFilaMeio(aterrissa1, i);
            }

        }
        aux = consultaFila(aterrissa2); //manda o nmovo primeiro elemento da fila
        for(i = 0 ; i<aterrissa2->qtd ; i++){

            aux->combustivel --;
            if(aux->combustivel <= 5){
                printf("Pouso de emergencia avião %d\n",aux->ID);
                removeFilaMeio(aterrissa2, i);
            }

        }


        QTDdecola = rand()%4;
        QTDaterrissa = rand()%4;

        for( i = 0 ; i<QTDdecola ; i++){

            if(decola1->qtd > decola2->qtd){
                if(decola2->qtd > decola3->qtd){
                    insereFila(decola3, (rand()%100)*2, rand()%21); //faz o ID ser par e o numero combustivel ser menor que 20
                }
                else{
                    insereFila(decola2, (rand()%100)*2, rand()%21); //faz o ID ser par e o numero combustivel ser menor que 20
                }
            }
            else if(decola1->qtd > decola3->qtd)
                insereFila(decola3, (rand()%100)*2, rand()%21); //faz o ID ser par e o numero combustivel ser menor que 20
            else
                insereFila(decola1, (rand()%100)*2, rand()%21); //faz o ID ser par e o numero combustivel ser menor que 20
            printf("Fila de decolagem 1 tem %d Aviões\n", decola1->qtd);
            printf("Fila de decolagem 2 tem %d Aviões\n", decola2->qtd);
            printf("Fila de decolagem 3 tem %d Aviões\n", decola3->qtd);
        }

        for(i = 0 ; i<QTDaterrissa ; i++){

            if(aterrissa1->qtd > aterrissa2->qtd){
                insereFila(aterrissa2, (rand()%100)*2+1, rand()%21); //faz o ID ser ímpar e o numero combustivel ser menor que 20
            }
            else
                insereFila(aterrissa1, (rand()%100)*2+1, rand()%21); //faz o ID ser ímpar e o numero combustivel ser menor que 20
            printf("Fila de pouso 1 tem %d Aviões\n", aterrissa1->qtd);
            printf("Fila de pouso 2 tem %d Aviões\n", aterrissa2->qtd);
        }

    }
}
