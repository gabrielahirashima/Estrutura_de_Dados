#ifndef ENVOLTORIA_H_
#define ENVOLTORIA_H_

#include "lista.h"
#include "listaPontos.h"

/*faz o calculo da envoltoria convexa a partir de uma lista passada com parametro e a insere
na lista de envoltoria convexa, tambem passada como parametro*/
listaStruct envoltoriaConvexa(listaStruct listaPontos, listaPonto envoltoriaConvexa);

#endif
