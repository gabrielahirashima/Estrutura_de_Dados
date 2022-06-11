#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "listaPontos.h"

typedef struct ponto{
    double x;
    double y;
}Ponto;

listaPonto criaPonto(double x, double y){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

double getXPonto(Node no){
    Ponto* node = (Ponto*)no;

    return node->x;
}

double getYPonto(Node no){
    Ponto* node = (Ponto*)no;

    return node->y;
}

double distanciaPontos(double x1, double y1, double x2, double y2){
    double deltaX, deltaY, resultado;
    deltaY = y2 - y1;
    deltaX = x2 - x1;

    resultado = sqrt((deltaX * deltaX) + (deltaY + deltaY));
    return resultado;
}

int orientacaoPolar(Node a, Node b, Node c){
     Ponto* p1 = (Ponto*)a;
     Ponto* p2 = (Ponto*)b;
     Ponto* p3 = (Ponto*)c;

    if(a == NULL || b == NULL || c == NULL){
        return 0;
    }

    double res;
    res = (getXPonto(p3) - getXPonto(p2)) * (getYPonto(p2) - getYPonto(p1)) - (getYPonto(p3) - getYPonto(p2)) * (getXPonto(p2) - getXPonto(p1));

    if(res > 1){ /*horario*/
        return -1;
    }
    else if( res < 1){
        return 1; /*antihorario*/
    }
    return 0; /*colinear*/

}

int comparaPontos(Node a, Node b, Node c){
    Ponto* p1 = (Ponto*)a;
    Ponto* p2 = (Ponto*)b;
    Ponto* p3 = (Ponto*)c;

    double res = orientacaoPolar(a, b, c);

    if(res == 0){
        return(distanciaPontos(getXPonto(p1), getYPonto(p1), getXPonto(p3), getYPonto(p3)) < distanciaPontos(getXPonto(p1), getYPonto(p1), getXPonto(p2), getYPonto(p2)));
    }
    return res == 1;
}