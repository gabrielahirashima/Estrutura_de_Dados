#ifndef LISTTOQUAD_H_
#define LISTTOQUAD_H_

#include "quadtree.h"
#include "lista.h"
#include "envoltoria.h"
#include "listaPontos.h"
#include "listaCidadesQT.h"
#include "listaCasosCovid.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaPostos.h"
#include "listaQuadras.h"
#include "listaRegioes.h"

/*As funcoes "transformaLista..." transformam uma lista passada como 
parametro para sua respectiva quadtree, realizando o processo de 
insercao de nodes ja em seu processo*/
void transformaListaQuadras(listaCidade lista, QuadTree qt);

void transformaListaFormas(listaCidade lista, QuadTree qt);

void transformaListaObjetos(listaCidade lista, QuadTree qt);

void transformaListaRegioes(listaCidade lista, QuadTree qt);

void transformaListaPostos(listaCidade lista, QuadTree qt);

void transformaListaCovid(listaCidade lista, QuadTree qt);

#endif