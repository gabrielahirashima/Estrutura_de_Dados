#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listToQuad.h"

void transformaListaForma(listaCidade listaF, QuadTree qtF){
    listaPonto listapontos = criaLista();
    listaPonto listaenvoltoria = criaLista();
    listaStruct stackenvoltoria = criaLista();
    Node i, j;

    double x, y;
    tipo elemento;

    if(listaF == NULL){
        return;
    }

    for(i = getFirst(listaF); i != NULL; i = getNext(i)){
        x = getXFormas(getElemento(i));
        y = getYFormas(getElemento(i));
        elemento = criaPonto(x, y);
        insertElemento(listapontos, elemento);
    }

    while(tamanhoLista(listapontos) > 3){
        envoltoriaConvexa(listapontos, listaenvoltoria);
        // imprimeLista(listapontos, 'p');
        // printf("\n---");
        // imprimeLista(listaenvoltoria, 'p');
        // printf("\n\n");
        
        if(listaenvoltoria != NULL){
            // imprimeLista(listaenvoltoria, 'p');
            for(i = getFirst(listaenvoltoria); i != NULL; i = getNext(i)){
                for( j = getFirst(listapontos); j != NULL ; j = getNext(j)){
                    if(getXPonto(getElemento(i)) == getXPonto(getElemento(j)) && getYPonto(getElemento(i)) == getYPonto(getElemento(j))){
                            elemento = getElemento(j);
                            insertElemento(stackenvoltoria, elemento);
                            removeNode(listapontos, elemento);
                    }
                }
            }
            listaenvoltoria = criaLista();
            liberaListaNaoTotal(listaenvoltoria);
        }
        
    }
    liberaLista(listapontos);
    liberaLista(stackenvoltoria);
}

void transformaListaQuadras(listaCidade lista, QuadTree qt){
    
       if(lista == NULL){
        return;
        }

    Node i, aux, maior, menor, medio;
    maior = getElemento(getFirst(lista));

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYQuadra(getElemento(i)) > getYQuadra(maior)){
            maior = getElemento(i);
        }

        if(getYQuadra(getElemento(i)) == getYQuadra(maior)){
            if(getXQuadra(getElemento(i)) < getXQuadra(maior)){
                maior = getElemento(i);
            }
        }
    }

    menor = getElemento(getFirst(lista));

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYQuadra(getElemento(i)) < getYQuadra(menor)){
            menor = getElemento(i);
        }

        if(getYQuadra(getElemento(i)) == getYQuadra(menor)){
            if(getXQuadra(getElemento(i)) < getXQuadra(menor)){
                menor = getElemento(i);
            }
        }
    }

    medio = menor;
        for(i = getFirst(lista); i != NULL; i = getNext(i)){
            if(getYQuadra(getElemento(i)) <= (getYQuadra(maior)/1.8) && getYQuadra(getElemento(i)) > getYQuadra(menor)) {
               if(getYQuadra(getElemento(i)) > getYQuadra(medio)){
                   medio = getElemento(i);
                   aux = i;
               }
            }
        }

    swapElemento(getFirst(lista), aux);
    double x, y;

    for(i = getFirst(lista); i != NULL; i = getNext(i)){
        x = getXQuadra(getElemento(i));
        y = getYQuadra(getElemento(i));
        insereElementoQT(qt, getElemento(i), x, y);
    }

}

void transformaListaFormas(listaCidade lista, QuadTree qt){
    
    Node i, maior, menor, medio;
    maior = getElemento(getFirst(lista));

    if(lista == NULL){
        return;
    }

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYFormas(getElemento(i)) > getYFormas(maior)){
            maior = getElemento(i);
        }

        if(getYFormas(getElemento(i)) == getYFormas(maior)){
            if(getXFormas(getElemento(i)) < getXFormas(maior)){
                maior = getElemento(i);
            }
        }
    }
    menor = getElemento(getFirst(lista));

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYFormas(getElemento(i)) < getYFormas(menor)){
            menor = getElemento(i);
        }

        if(getYFormas(getElemento(i)) == getYFormas(menor)){
            if(getXFormas(getElemento(i)) < getXFormas(menor)){
                menor = getElemento(i);
            }
        }
    }

    medio = menor;

        for(i = getFirst(lista); i != NULL; i = getNext(i)){
            if(getYFormas(getElemento(i)) <= (getYFormas(maior)) && getYFormas(getElemento(i)) > getYFormas(menor)) {
               if(getYFormas(getElemento(i)) > getYFormas(medio)){
                   medio = getElemento(i);
               }
            }
        }
    //printf("\n%lf-- %lf", getYFormas(medio),getXFormas(medio));

    //swapElemento(getFirst(lista), aux);
    double x, y;

    for(i = getFirst(lista); i != NULL; i = getNext(i)){
        x = getXFormas(getElemento(i));
        y = getYFormas(getElemento(i));
        insereElementoQT(qt, getElemento(i), x, y);
    }

}

void transformaListaObjetos(listaCidade lista, QuadTree qt){
    
    Node i, maior, menor, medio;
    maior = getElemento(getFirst(lista));

    if(lista == NULL){
        return;
    }

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYObjetos(getElemento(i)) > getYObjetos(maior)){
            maior = getElemento(i);
        }

        if(getYObjetos(getElemento(i)) == getYObjetos(maior)){
            if(getXObjetos(getElemento(i)) < getXObjetos(maior)){
                maior = getElemento(i);
            }
        }
    }

    menor = getElemento(getFirst(lista));

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYObjetos(getElemento(i)) < getYObjetos(menor)){
            menor = getElemento(i);
        }

        if(getYObjetos(getElemento(i)) == getYObjetos(menor)){
            if(getXObjetos(getElemento(i)) < getXObjetos(menor)){
                menor = getElemento(i);
            }
        }
    }

    medio = menor;
        for(i = getFirst(lista); i != NULL; i = getNext(i)){
            if(getYObjetos(getElemento(i)) <= (getYObjetos(maior)) && getYObjetos(getElemento(i)) > getYObjetos(menor)) {
               if(getYObjetos(getElemento(i)) > getYObjetos(medio)){
                   medio = getElemento(i);
               }
            }
        }

    //swapElemento(getFirst(lista), aux);
    double x, y;

    for(i = getFirst(lista); i != NULL; i = getNext(i)){
        x = getXObjetos(getElemento(i));
        y = getYObjetos(getElemento(i));
        insereElementoQT(qt, getElemento(i), x, y);
    }

}

void transformaListaRegioes(listaCidade lista, QuadTree qt){
    
    Node i, maior, menor, medio;
    maior = getElemento(getFirst(lista));

    if(lista == NULL){
        return;
    }

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYRegiao(getElemento(i)) > getYRegiao(maior)){
            maior = getElemento(i);
        }

        if(getYRegiao(getElemento(i)) == getYRegiao(maior)){
            if(getXRegiao(getElemento(i)) < getXRegiao(maior)){
                maior = getElemento(i);
            }
        }
    }

    menor = getElemento(getFirst(lista));

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYRegiao(getElemento(i)) < getYRegiao(menor)){
            menor = getElemento(i);
        }

        if(getYRegiao(getElemento(i)) == getYRegiao(menor)){
            if(getXRegiao(getElemento(i)) < getXRegiao(menor)){
                menor = getElemento(i);
            }
        }
    }

    medio = menor;
        for(i = getFirst(lista); i != NULL; i = getNext(i)){
            if(getYRegiao(getElemento(i)) <= (getYRegiao(maior)) && getYRegiao(getElemento(i)) > getYRegiao(menor)) {
               if(getYRegiao(getElemento(i)) > getYRegiao(medio)){
                   medio = getElemento(i);
               }
            }
        }

    //swapElemento(getFirst(lista), aux);
    double x, y;

    for(i = getFirst(lista); i != NULL; i = getNext(i)){
        x = getXRegiao(getElemento(i));
        y = getYRegiao(getElemento(i));
        insereElementoQT(qt, getElemento(i), x, y);
    }

}

void transformaListaPostos(listaCidade lista, QuadTree qt){
    
    Node i, maior, menor, medio;
    maior = getElemento(getFirst(lista));

    if(lista == NULL){
        return;
    }

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYPosto(getElemento(i)) > getYPosto(maior)){
            maior = getElemento(i);
        }

        if(getYPosto(getElemento(i)) == getYPosto(maior)){
            if(getXPosto(getElemento(i)) < getXPosto(maior)){
                maior = getElemento(i);
            }
        }
    }

    menor = getElemento(getFirst(lista));

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYPosto(getElemento(i)) < getYPosto(menor)){
            menor = getElemento(i);
        }

        if(getYPosto(getElemento(i)) == getYPosto(menor)){
            if(getXPosto(getElemento(i)) < getXPosto(menor)){
                menor = getElemento(i);
            }
        }
    }

    medio = menor;
        for(i = getFirst(lista); i != NULL; i = getNext(i)){
            if(getYPosto(getElemento(i)) <= (getYPosto(maior)) && getYPosto(getElemento(i)) > getYPosto(menor)) {
               if(getYPosto(getElemento(i)) > getYPosto(medio)){
                   medio = getElemento(i);
               }
            }
        }

    //swapElemento(getFirst(lista), aux);
    double x, y;

    for(i = getFirst(lista); i != NULL; i = getNext(i)){
        x = getXPosto(getElemento(i));
        y = getYPosto(getElemento(i));
        insereElementoQT(qt, getElemento(i), x, y);
    }

}

void transformaListaCovid(listaCidade lista, QuadTree qt){
    
    Node i, maior, menor, medio;
    maior = getElemento(getFirst(lista));


    if(lista == NULL){
        return;
    }

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYCasosCovid(getElemento(i)) > getYCasosCovid(maior)){
            maior = getElemento(i);
        }

        if(getYCasosCovid(getElemento(i)) == getYCasosCovid(maior)){
            if(getXCasosCovid(getElemento(i)) < getXCasosCovid(maior)){
                maior = getElemento(i);
            }
        }
    }

    menor = getElemento(getFirst(lista));

    for(i = getNext(getFirst(lista)); i != NULL; i = getNext(i)){
        if(getYCasosCovid(getElemento(i)) < getYCasosCovid(menor)){
            menor = getElemento(i);
        }

        if(getYCasosCovid(getElemento(i)) == getYCasosCovid(menor)){
            if(getXCasosCovid(getElemento(i)) < getXCasosCovid(menor)){
                menor = getElemento(i);
            }
        }
    }

    medio = menor;
        for(i = getFirst(lista); i != NULL; i = getNext(i)){
            if(getYCasosCovid(getElemento(i)) <= (getYCasosCovid(maior)) && getYCasosCovid(getElemento(i)) > getYCasosCovid(menor)) {
               if(getYCasosCovid(getElemento(i)) > getYCasosCovid(medio)){
                   medio = getElemento(i);
               }
            }
        }

    //swapElemento(getFirst(lista), aux);
    double x, y;

    for(i = getFirst(lista); i != NULL; i = getNext(i)){
        x = getXCasosCovid(getElemento(i));
        y = getYCasosCovid(getElemento(i));
        insereElementoQT(qt, getElemento(i), x, y);
    }

}