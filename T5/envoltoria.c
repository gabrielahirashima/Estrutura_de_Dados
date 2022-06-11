#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "envoltoria.h"

listaStruct envoltoriaConvexa(listaStruct listaPontos, listaPonto envoltoriaConvexa){

    if (tamanhoLista(listaPontos) < 3){
        return NULL;
    }

    Node menorPonto, aux;
    Node a, b, c;
    tipo elementoMenorPonto, elemento;
    int pos = 0;
    int tamanho = tamanhoLista(listaPontos);
    
    menorPonto = getFirst(listaPontos);
    elementoMenorPonto = getElemento(menorPonto);

    for(int i = 0; i < tamanho; i++){
        aux = getFirst(listaPontos);
            for(int k = 0; k < i; k++){
                aux = getNext(aux);
            }
            elemento = getElemento(aux);
            if(getYLista(elementoMenorPonto) == getYLista(elemento)){
                if(getXLista(elementoMenorPonto) > getXLista(elemento)){
                    menorPonto = aux;
                    elementoMenorPonto = getElemento(menorPonto);
                    pos = i;
                }
            }
            else if(getYLista(elementoMenorPonto) > getYLista(elemento)){
                menorPonto = aux;
                elementoMenorPonto = getElemento(menorPonto);
                pos = i;
            }
    }
    
    swap(listaPontos, pos);

    quicksort(listaPontos, getNext(getFirst(listaPontos)),getLast(listaPontos));

    listaStruct listaAux = criaLista();

    aux = getFirst(listaPontos);
    elemento = getElemento(aux);
    insertElemento(listaAux, elemento);

    for (int i = 2; i < tamanhoLista(listaPontos); i++){
        a = getFirst(listaPontos);
        for (int k = 0; k < i; k++){
            a = getNext(a);
        }  
        b = getPrevious(a);
        c = getPrevious(getPrevious(a));

        if((orientacaoPolar(getElemento(c), getElemento(b), getElemento(a)) != 0)){
            elemento = getElemento(b);
            insertElemento(listaAux, elemento);
        }
    }
    aux = getLast(listaPontos);
    elemento = getElemento(aux);
    insertElemento(listaAux, elemento);

    tamanho = tamanhoLista(listaAux);

    if(tamanho < 3){
        return NULL;
    }

    Node i;
    int j;
    
    for( i = getFirst(listaAux), j=0 ; j< 3; j++, i = getNext(i)){
        elemento = getElemento(i);
        insertElemento(envoltoriaConvexa, elemento);
    }

    while(i != NULL){
        a = getLast(envoltoriaConvexa);
        b = getPrevious(a);
        c = i; 

        while(orientacaoPolar(getElemento(b), getElemento(a), getElemento(c)) != 1){
            removeNode(envoltoriaConvexa, getElemento(a));
            a = getLast(envoltoriaConvexa);
            b = getPrevious(a);
            c = i; 
        }
        elemento = getElemento(i);
        insertElemento(envoltoriaConvexa, elemento);
        i = getNext(i);
    }
    /*printf("\nLista Convexa:\n");
    imprimeLista(envoltoriaConvexa, 'p');*/

    liberaListaNaoTotal(listaAux);
    printf("\nnPontos:%d\n", tamanhoLista(listaPontos));

    return envoltoriaConvexa;
    
}