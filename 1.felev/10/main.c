#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
 
typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;
 
int hossza(ListaElem* lista){
    int hossz = 0;
    while(lista != NULL){
        hossz++;
        lista = lista->kov;
    }
    return hossz;
}

void felszabadit(ListaElem* le){
    ListaElem* kovetkezo = le;
    while(kovetkezo != NULL){
        kovetkezo = kovetkezo->kov;
        free(le);
        le = kovetkezo;
    }
}

ListaElem* lista_elejere_beszur(ListaElem* eleje, int a){
    ListaElem* uj = (ListaElem*)malloc(sizeof(ListaElem));
    uj->adat = a;
    uj->kov = eleje;

    return uj;
}

ListaElem* lista_vegere_beszur(ListaElem* eleje, int a){
    ListaElem* lista = eleje;
    if(eleje){
        while(eleje->kov != NULL){
        eleje = eleje->kov;
        }
    }
    ListaElem* uj = (ListaElem*)malloc(sizeof(ListaElem));
    uj->adat = a;
    uj->kov = NULL;
    if(eleje){
        eleje->kov = uj;
    }else{
        lista = uj;
    }

    return lista;
}

int main(void) {
    ListaElem *eleje = NULL, *lista = NULL;

    lista = lista_elejere_beszur(lista, 101);
    lista = lista_elejere_beszur(lista, 102);
    lista = lista_elejere_beszur(lista, 103);
    lista = lista_vegere_beszur(lista, 1);
    lista = lista_vegere_beszur(lista, 2);
    lista = lista_vegere_beszur(lista, 3);

    int hossz = hossza(lista);    
    printf("%d\n", hossz);
    
    eleje = lista;
    while(eleje != NULL){
        printf("%d ", eleje->adat);
        eleje = eleje->kov;
    }

    felszabadit(lista);

    return 0;   
}