#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "quadtree.h"
#include "listaPontos.h"

typedef struct ponto{
    double x;
    double y;
}Ponto;

typedef struct no{
    struct ponto p;
    void *elemento;
    struct no *ant;
    struct no *prox;
}No;

typedef struct lista{
    No *primeiro;
    No *ultimo;
}Lista;

listaStruct criaLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

listaStruct insertElemento(listaStruct lista, tipo elemento){
    Lista *list = (Lista*)lista;

    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;

        if(list->primeiro == NULL){ /*se a lista esta vazia*/
            node->ant = NULL; /*o anterior aponta para null*/
            list->primeiro = node; /*o primeiro elemento da lista é node*/
        }
        else{ /*senao*/
            list->ultimo->prox = node; /*o prox do ultimo elemento adicionado aponta para o novo node*/
            node->ant = list->ultimo; /*o ponteiro de anterior aponta pro ultimo elemento adicionado*/
        }

        node->prox = NULL;
        list->ultimo = node;
    return list; 
}

listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2){
    Lista *list = (Lista*)lista;

    No* node = (No*)malloc(sizeof(No));
    node->elemento = elemento;

    No* inicio = list->primeiro;
    No *aux_1;
    No *aux_2;

        while (inicio != NULL){
                    if(inicio == elemento_2){
                            if(inicio == list->primeiro){
                                aux_1 = inicio;
                                aux_1->ant = node;
                                node->prox = aux_1;
                                node->ant = NULL;
                                list->primeiro = node;
                                return list; 
                            }
                        else if(inicio!= list->primeiro){
                                aux_1 = inicio;
                                aux_2 = inicio->ant;
                                node->ant = aux_2;
                                node->prox = aux_1;
                                aux_1->ant = node;
                                aux_2->prox = node;
                                return list; 
                        }
                    }
                    inicio = inicio->prox;
        }
    return NULL;
}

listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2){
     Lista *list = (listaStruct)lista;
    
         No* node = (No*)malloc(sizeof(No));
         node->elemento = elemento;
         
         No *inicio = list->primeiro;
         No *aux_1; 
         No *aux_2;
            while(inicio != NULL){
                if(inicio == elemento_2){
                        if(inicio == list->ultimo){
                            aux_1 = inicio;
                            aux_1->prox = node;
                            node->prox = NULL;
                            node->ant = aux_1;
                            list->ultimo = node;
                            return list; 
                        }
                        else if(inicio!= list->ultimo){
                            aux_1 = inicio;
                            aux_2 = inicio->prox;
                            aux_1->prox = node;
                            aux_2->ant = node;
                            node->ant = aux_1;
                            node->prox = aux_2;
                            return list; 
                        }
                }
                inicio = inicio->prox;
            }
    return NULL;
}

void removeNode(listaStruct l, Node elemento){

    Lista* lista = (Lista*) l;
    No *aux = (No*)elemento;
    No *aux2;
    aux = lista->primeiro;

    while (aux != NULL){
        if(aux->elemento == elemento){
            if (aux==lista->primeiro){
                lista->primeiro = aux->prox;
                lista->primeiro->ant = NULL;
            }
            else if(aux==lista->ultimo){
                lista->ultimo = aux->ant;
                lista->ultimo->prox = NULL;
            }
            else{
                aux2 = aux->prox;
                aux2->ant = aux->ant;
                //aux2->prox->ant = aux2; 
                if(aux->ant!=NULL){
                    aux->ant->prox = aux2;
                }     
            }
            //free(aux);
            break;
         }
        aux = aux->prox;
    }
}

void removeElemento(listaStruct l, Node elemento){
   Lista* lista = (Lista*) l;
    No *aux = (No*)elemento;
    No *aux2;
    aux = lista->primeiro;
    
    while (aux != NULL){
        if(aux->elemento == elemento){
            if (aux==lista->primeiro){
                lista->primeiro = aux->prox;
                lista->primeiro->ant = NULL;
            }
            if(aux==lista->ultimo){
                lista->ultimo = aux->ant;
                lista->ultimo->prox = NULL;
            }
            else{
                aux2 = aux->prox;
                aux2->ant = aux->ant;
                aux2->prox->ant = aux2; 
                if(aux->ant!=NULL){
                    aux->ant->prox = aux2;
                }     
            }
            free(aux->elemento);
            free(aux);
            break;
         }
        aux = aux->prox;
    }
}

void liberaLista(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
    No *aux;
        while(node != NULL){
            aux = node->prox;
                free(node->elemento);
                free(node);
            node = aux;
        }
    free(lista);
}

void liberaListaNaoTotal(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
    No *aux;
        while(node != NULL){
            aux = node->prox;
            free(node);
            node = aux;
        }
    free(lista);
}

Node getFirst(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->primeiro;
        if(list->primeiro == NULL){
            return NULL;
        }
    return node;
}

Node getLast(listaStruct lista){
    Lista *list = (Lista*)lista;
    No *node = list->ultimo;
        if(list->ultimo == NULL){
            return NULL;
        }
        
    return node;
}

Node getPrevious(Node elemento){

    if(elemento == NULL)
        return NULL;

    No* node = (No*)elemento;

    return node->ant;
}

Node getNext(Node elemento){

    if(elemento == NULL)
        return NULL;

    No* node = (No*)elemento;

    return node->prox;
}

tipo getElemento(Node elemento){

    if(elemento == NULL)
        return NULL;

    No *node = (No*)elemento;

    return node->elemento; 

}

int tamanhoLista(listaStruct lista){
 Lista *list = (Lista*)lista;
 int tamanho = 0;
    No *node = list->primeiro;
        while(node != NULL){
            tamanho += 1;
            node = node->prox;
        }
    return tamanho;
}

void imprimeLista(listaStruct l, char c){
    Lista *list = (Lista*)l;
    No *node = list->primeiro;
        while(node != NULL){
            if(c == 'b'){
                printf("%s, %lf, %lf, %s, %s\n", getIdObjetos(getElemento(node)), getXObjetos(getElemento(node)), getYObjetos(getElemento(node)), getCorpObjetos(getElemento(node)), getCorbObjetos(getElemento(node)));
            }
            else if(c == 'h'){
                printf("%s, %lf, %lf, %s, %s\n", getIdObjetos(getElemento(node)), getXObjetos(getElemento(node)), getYObjetos(getElemento(node)), getCorpObjetos(getElemento(node)), getCorbObjetos(getElemento(node)));
            }
            else if(c == 'q'){
                printf("%s, %lf, %lf, %lf, %lf,%s, %s\n", getCepQuadra(getElemento(node)), getXQuadra(getElemento(node)), getYQuadra(getElemento(node)),  getWQuadra(getElemento(node)),  getHQuadra(getElemento(node)), getCorpQuadra(getElemento(node)), getCorbQuadra(getElemento(node)));
            }
            else if(c == 's'){
                printf("%s, %lf, %lf, %s, %s\n", getIdObjetos(getElemento(node)), getXObjetos(getElemento(node)), getYObjetos(getElemento(node)), getCorpObjetos(getElemento(node)), getCorbObjetos(getElemento(node)));
            }
            else if(c == 'c'){
                printf("%d, %lf, %lf, %lf, %s, %s\n", getIdFormas(getElemento(node)), getRFormas(getElemento(node)), getXFormas(getElemento(node)), getYFormas(getElemento(node)), getCorbFormas(getElemento(node)), getCorpFormas(getElemento(node)));
            }
            else if(c == 'r'){
                printf("%d, %lf, %lf, %lf, %lf, %s, %s\n", getIdFormas(getElemento(node)), getWFormas(getElemento(node)), getHFormas(getElemento(node)), getXFormas(getElemento(node)), getYFormas(getElemento(node)), getCorbFormas(getElemento(node)), getCorpFormas(getElemento(node)));
            }
            else if(c == 't'){
                printf("%d, %lf, %lf, %s, %s, %s\n", getIdFormas(getElemento(node)), getXFormas(getElemento(node)), getYFormas(getElemento(node)), getCorbFormas(getElemento(node)), getCorpFormas(getElemento(node)), getTextFormas(getElemento(node)));
            }
            else if(c == 'p'){
                printf("%lf, %lf\n", getXPonto(getElemento(node)),getYPonto(getElemento(node)));
            }
            node = node->prox;
        }
}
 
double getXLista(Node no){
    No* node = (No*)no;

    return node->p.x;
}

double getYLista(Node no){
    No* node = (No*)no;

    return node->p.y;
}

void quicksort(listaStruct lista, Node first, Node last){
    if(last != NULL && getNext(last) != first && first != last){
        Node pivo = partition(lista, first, last);
        quicksort(lista, first, getPrevious(pivo));
        quicksort(lista, getNext(pivo), last);
    }
}

Node partition(listaStruct lista, Node first, Node last){
    Node aux = getPrevious(first);

    for(Node i = first; i != last; i = getNext(i)){
        if(comparaPontos( (getElemento(getFirst(lista))), getElemento(first), getElemento(last) ) ){
            if(aux == NULL){
                aux = first;
            }
            else{
                aux = getNext(aux);
            }
        }
        swapElemento(aux, i);
    }
    if(aux == NULL){
        aux = first;
    }
    else{
        aux = getNext(aux);
    }
    swapElemento(aux, last);
    return aux;

}

/*void quicksort(listaStruct lista, int tamanho, int inicio){
    int i = inicio;
    int j = tamanho - 1;
    No *aux1, *aux2, *aux3, *pivo;
    tipo *elemento1, *elemento2;
    aux3 = (No*)malloc(sizeof(No*));

    pivo = getFirst(lista);

    for(int k = 0; k < (i + tamanho)/2 ; k++){
        pivo = getNext(pivo);
    } 

    elemento1 = getElemento(pivo);

    while(i <= j) { 
        aux1 = getFirst(lista);
        for(int k = 0; k < i; k++){
            aux1 = getNext(aux1);
        }
            elemento2 = getElemento(aux1);

        while(comparaPontos((getElemento(getFirst(lista))), elemento1, elemento2) > 0 && i < tamanho){
            aux1 = getNext(aux1);
            elemento2 = getElemento(aux1);
            i++;
        }

            aux1 = getFirst(lista);

        for (int k = 0; k < j; k++){
            aux1 = getNext(aux1);
        }
            elemento2 = getElemento(aux1);

        while(comparaPontos((getElemento(getFirst(lista))), elemento1, elemento2) > 0 && j > inicio){
            aux1 = getPrevious(aux1);
            elemento2 = getElemento(aux1);
            j--;
        }
        
        if (i <= j){
            aux2 = getFirst(lista);
                for (int k = 0; k < j; k++){
                    aux2 = getNext(aux2);
                }

                    aux1 = getFirst(lista);

                for (int k = 0; k < i; k++){
                    aux1 = getNext(aux1);
                }

                    aux3->elemento = aux1->elemento;
                    aux1->elemento = aux2->elemento;
                    aux2->elemento = aux3->elemento;
                    j--;
                    i++;
        }
        
    }
    if (inicio < j){
        quicksort(lista, j + 1 , inicio);
    }
    if (tamanho > i){
        quicksort(lista, tamanho, i);
    }

    free(aux3);

}*/

void swap(listaStruct lista, int pos){
    No *node1, *node2;
    tipo *elemento;

    node1 = getFirst(lista);

    for(int i = 0; i < pos; i++){
        node1 = getNext(node1);
    }

     node2 = getFirst(lista);

    elemento = node2->elemento;
    node2->elemento = node1->elemento;
    node1->elemento = elemento;
}

void swapElemento(Node *node1, Node *node2){
    No* no1 = (No*)node1;
    No* no2 = (No*)node2;
    tipo *elemento;
    
    elemento = no1->elemento;
    no1->elemento = no2->elemento;
    no2->elemento = elemento;

}
