#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"
#include "lista.h"

#define TAMANHO 1001

typedef struct nodehash{
    Node nodeHstable;
    int key;
}NodeHashtable;

int getKey(char *string){
    int k = 0;
    int tamanhoString = strlen(string);

    for(int i = 0; i < tamanhoString; i++){
        k = k + string[i];
    }
    return k%TAMANHO;
}

hstable iniciaHashtable(){
    int i = 0;
    NodeHashtable *hash = (NodeHashtable*)malloc(sizeof(NodeHashtable) * TAMANHO);
    while(i < TAMANHO){
        hash[i].key = i + 1;
        hash[i].nodeHstable = NULL;
        i = i + 1;
    }
    return hash;
}

void insereHashtable(hstable hash, char *elementoKey, Node *elemento){
    NodeHashtable *arrayHash = (NodeHashtable*)hash; /*aqui especifica qual hashtable estou trabalhando com*/
    int posHash = getKey(elementoKey);
    arrayHash[posHash].nodeHstable = insertElemento(arrayHash[posHash].nodeHstable, elemento);
}

int removeHashtable(hstable hash, char *string, int (*op)){
    int posHash = getKey(string);
    NodeHashtable *arrayHash = (NodeHashtable*)hash;
    Node elementoLista = arrayHash[posHash].nodeHstable;

    if(elementoLista == NULL){
        return;
    }

}

void imprimeHashtable(){
    
}