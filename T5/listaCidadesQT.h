#ifndef LISTACIDADESQT_H_
#define LISTACIDADESQT_H_

#include "quadtree.h"
#include "envoltoria.h"
#include "lista.h"
#include "listaPontos.h"

/*define listaCidadeQt como pointer void*/
typedef void *listaCidadeQT;

/*cria uma lista de quadtrees para cada lista da ListaCidades*/
listaCidadeQT iniciaListaQTCidade();

/*retorna o ponteiro para a QuadtreeFormas*/
listaCidadeQT getQuadtreeFormas(listaCidadeQT lista);

/*retorna o ponteiro para a QuadtreeObjetos*/
listaCidadeQT getQuadtreeObjetos(listaCidadeQT qt);

/*retorna o ponteiro para a QuadtreePostos*/
listaCidadeQT getQuadtreePostos(listaCidadeQT qt);

/*retorna o ponteiro para a QuadtreeRegioes*/
listaCidadeQT getQuadtreeRegioes(listaCidadeQT qt);

/*retorna o ponteiro para a QuadtreCasosCovid*/
listaCidadeQT getQuadtreeCasosCovid(listaCidadeQT qt);

/*retorna o ponteiro para a QuadtreeQuadras*/
listaCidadeQT getQuadtreeQuadras(listaCidadeQT qt);

#endif
