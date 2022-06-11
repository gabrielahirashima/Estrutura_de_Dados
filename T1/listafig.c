#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structfig.h"

listaStruct *iniciaLista(){
    return NULL;
}

listaStruct *insereElemento(listaStruct *inicio, int id, char tipo){
  listaStruct *aux1, *aux2;

    if(inicio == NULL){  /*Caso seja o primeiro elemento a ser inserido*/
        inicio = (listaStruct*)malloc(sizeof(listaStruct)); /*aloca o elemento de lista*/
        inicio->i = id;   /*o nó de inicio recebe o id;*/
        inicio->tipo = tipo; /*o nó de inicio recebe o tipo da figura;*/
        inicio->prox = NULL; /* o nó de inicio agora aponta para NULL;*/
        inicio->forma = NULL; /*o nó de inicio que aponta para outras structs de formas agora aponta para NULL;*/
        }

    else{
      aux1 = inicio; /*elemento auxiliar recebe o endereço do inicio da lista*/

        while(aux1->prox != NULL){ /*enquanto o elemento auxiliar não for o que aponta para NULL, ou seja, o ultimo;*/
          aux1 = aux1->prox;/*aux1 recebe o endereço do próximo aux;*/
        }

          aux2 = (listaStruct*)malloc(sizeof(listaStruct));
            aux2->i = id; /*elemento aux2 recebe o id*/
            aux2->tipo = tipo; /*elemento aux2 recebe o tipo;*/
                aux2->prox = NULL; /*elemento aux2 agora aponta para NULL;*/
                aux2->forma = NULL; /*forma do elemento aux 2 agora aponta para NULL;*/
                aux1->prox = aux2; /*o ultimo elemento anterior agora aponta para aux 2;*/
    }
  return inicio; /*retorna o inicio da lista*/
}

void insereCirculo(listaStruct *inicio, double r, double x, double y, char *corb, char *corp){
    while(inicio->prox != NULL){
        inicio = inicio->prox;
    }

    inicio->forma = (Forma*)malloc(sizeof(Forma));
    inicio->forma->circulo.r = r;
    inicio->forma->circulo.x = x;
    inicio->forma->circulo.y = y;
    strcpy(inicio->forma->circulo.corb, corb);
    strcpy(inicio->forma->circulo.corp, corp);
}/*Insere um círculo junto ao insereElemento*/

void insereRetangulo(listaStruct *inicio, double w, double h, double x, double y, char *corb, char *corp){
    while(inicio->prox != NULL){
        inicio = inicio->prox;
    }

    inicio->forma = (Forma*)malloc(sizeof(Forma));
    inicio->forma->retangulo.w = w;
    inicio->forma->retangulo.h = h;
    inicio->forma->retangulo.x = x;
    inicio->forma->retangulo.y = y;
    strcpy(inicio->forma->retangulo.corb, corb);
    strcpy(inicio->forma->retangulo.corp, corp);
}/*Insere um retangulo junto ao insereElemento*/

void insereTexto(listaStruct *inicio, double x, double y, char *corb, char *corp, char *text){
    while(inicio->prox != NULL){
        inicio = inicio->prox;
    }

    inicio->forma = (Forma*)malloc(sizeof(Forma));
    inicio->forma->texto.x = x;
    inicio->forma->texto.y = y;
    strcpy(inicio->forma->texto.corb, corb);
    strcpy(inicio->forma->texto.corp, corp);
    strcpy(inicio->forma->texto.text, text);
}/*Insere um Texto junto ao insereElemento*/

void insereLinha(listaStruct *inicio, double x, double y, double x2, double y2, char *cor){
    while(inicio->prox != NULL){
        inicio = inicio->prox;
    }

    inicio->forma = (Forma*)malloc(sizeof(Forma));
    inicio->forma->linha.x = x;
    inicio->forma->linha.y = y;
    inicio->forma->linha.x2 = x2;
    inicio->forma->linha.y2 = y2;
    strcpy(inicio->forma->linha.cor, cor);
}/*Insere uma linha junto ao insereElemento*/

listaStruct *buscaElemento(listaStruct *inicio, int id){
    listaStruct *aux;

        aux = inicio;
        while(aux!=NULL){
            if (aux->i == id){
                return aux;
            }
            aux = aux->prox;
        }

        return NULL;
}/*Busca um elemento pelo id fornecido*/

void imprimeLista(listaStruct *inicio){ /*função para eventuais testes de erros*/
    listaStruct *aux;
      aux = inicio;

      while(aux != NULL){
          printf("\n%d %c", aux->i, aux->tipo);
          if(aux->tipo == 'c'){
          printf("\n%lf %lf %lf %s %s", aux->forma->circulo.r, aux->forma->circulo.x, aux->forma->circulo.y, aux->forma->circulo.corb, aux->forma->circulo.corp);
          }
          else if (aux->tipo == 'r'){
            printf("\n%lf %lf %lf %lf %s %s", aux->forma->retangulo.w, aux->forma->retangulo.h, aux->forma->retangulo.x, aux->forma->retangulo.y, aux->forma->retangulo.corb, aux->forma->retangulo.corp);
          }
          else if(aux->tipo == 't'){
              printf("\n%lf l%f %s %s %s", aux->forma->texto.x, aux->forma->texto.y, aux->forma->texto.corb, aux->forma->texto.corp, aux->forma->texto.text);
          }
          else if(aux->tipo == 'l'){
              printf("\n%lf %lf %lf %lf %s", aux->forma->linha.x, aux->forma->linha.y, aux->forma->linha.x2, aux->forma->linha.y2, aux->forma->linha.cor);
          }
          aux = aux->prox;
      }
}/*Imprime a lista encadeada para obter informações*/

void liberaLista(listaStruct *inicio){
    listaStruct *aux;
        while(inicio!=NULL){
            aux = inicio;
            inicio = inicio->prox;
            free(aux);
            free(aux->forma);
        }
}/*Libera toda a lista encadeada*/

listaStruct *liberaElemento(listaStruct *inicio, int id){
    listaStruct *aux = inicio, *aux2 = NULL;

        while(aux != NULL){/*enquanto aux não aponta para null*/
            if(aux->i == id){ /*se aux->i for igual a ID*/
                if(aux==inicio){
                    inicio = inicio->prox;
                    free(aux->forma);
                    free(aux);
                }
                else{
                    aux2->prox = aux->prox;
                    free(aux->forma);
                    free(aux);
                }
                if(aux->tipo == 't'){
                    free(aux->forma->texto.text);
                }
            return inicio;
            }
        aux2 = aux;
        aux = aux->prox;
    }
    return 0;
}/*Libera apenas um elemento e sua respectiva figura da lista encadeada*/
