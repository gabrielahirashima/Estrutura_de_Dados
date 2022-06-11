#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCidadesQT.h"

typedef struct listaqt{
    QuadTree QtFormas;
    QuadTree QtObjetos;
    QuadTree QtQuadras;
    QuadTree QtRegioes;
    QuadTree QtPostos;
    QuadTree QtCovid;
}ListaQtStruct;

listaCidadeQT iniciaListaQTCidade(){
    ListaQtStruct *listaQt;
    listaQt = (ListaQtStruct*)malloc(sizeof(ListaQtStruct));

    listaQt->QtFormas = criaQuadTree("f");
    listaQt->QtObjetos = criaQuadTree("o");
    listaQt->QtQuadras = criaQuadTree("q");
    listaQt->QtRegioes = criaQuadTree("r");
    listaQt->QtPostos= criaQuadTree("p");
    listaQt->QtCovid = criaQuadTree("c");
    return listaQt; 
}

listaCidadeQT getQuadtreeFormas(listaCidadeQT lista){
    ListaQtStruct* list = (ListaQtStruct*)lista;
    return list->QtFormas;
}

listaCidadeQT getQuadtreeObjetos(listaCidadeQT qt){
    ListaQtStruct* list = (ListaQtStruct*)qt;
    return list->QtObjetos;
}

listaCidadeQT getQuadtreePostos(listaCidadeQT qt){
    ListaQtStruct* list = (ListaQtStruct*)qt;
    return list->QtPostos;
}

listaCidadeQT getQuadtreeRegioes(listaCidadeQT qt){
    ListaQtStruct* list = (ListaQtStruct*)qt;
    return list->QtRegioes;
}

listaCidadeQT getQuadtreeCasosCovid(listaCidadeQT qt){
    ListaQtStruct* list = (ListaQtStruct*)qt;
    return list->QtCovid;
}

listaCidadeQT getQuadtreeQuadras(listaCidadeQT qt){
    ListaQtStruct* list = (ListaQtStruct*)qt;
    return list->QtCovid;
}