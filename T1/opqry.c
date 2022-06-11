#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structfig.h"
#include "listafig.h"

float max(float n1, float n2){
    if(n1 > n2){
        return n1;
    }
    return n2;
}

float min(float n1, float n2){
    if(n1 > n2){
        return n2;
    }
    return n1;
}

void sobrepoeCirculoRetangulo(listaStruct *inicio, FILE *arq, Circulo circulo, Retangulo retangulo){

    double deltaX, deltaY, x, y, h, w;

    deltaX = ((circulo.x) - max(retangulo.x, min(circulo.x, retangulo.x + retangulo.w)));
    deltaY = ((circulo.y) - max(retangulo.y, min(circulo.y, retangulo.y + retangulo.h)));

    x = min(retangulo.x, (circulo.x - circulo.r));
    y = min((retangulo.y), (circulo.y - circulo.r));
    w = max((retangulo.x + retangulo.w), (circulo.x + circulo.r)) - x;
    h = max((retangulo.y + retangulo.h), (circulo.y + circulo.r)) - y;

        if (((deltaX * deltaX) + (deltaY * deltaY)) <= (circulo.r * circulo.r)){
            inicio = insereElemento(inicio, 0, 'r');
            insereRetangulo(inicio, w, h, x, y, "black", "transparent");
            fprintf(arq, " SIM\n\n");
        }
        else
        {
            inicio = insereElemento(inicio, 0, 'x');
            insereRetangulo(inicio, w, h, x, y, "black", "transparent");
            fprintf(arq, " NAO\n\n");
        }
}

void sobrepoeCirculoCirculo(listaStruct *inicio, FILE *arq, Circulo circulo1, Circulo circulo2){
    double distancia, x, y, w, h;

    distancia = sqrt(pow(circulo1.x - circulo2.x, 2)+ pow(circulo1.y - circulo2.y, 2));

    x = min(circulo1.x - circulo1.r, circulo2.x - circulo2.r);
    y = min(circulo1.y - circulo1.r, circulo2.y - circulo2.r);
    w = max(circulo1.x + circulo1.r, circulo2.x + circulo2.r) - x;
    h = max(circulo1.y + circulo1.r, circulo2.y + circulo2.r) - y;

    if (distancia <= (circulo1.r + circulo2.r)){
        inicio = insereElemento(inicio, 0, 'r');
        insereRetangulo(inicio, w, h, x, y, "black", "transparent");
        fprintf(arq, " SIM\n\n");
    }
    else{
        inicio = insereElemento(inicio, 0, 'x');
        insereRetangulo(inicio, w, h, x, y, "black", "transparent");
        fprintf(arq, " NAO\n\n");
    }
}

void sobrepoeRetanguloRetangulo(listaStruct *inicio, FILE *arq, Retangulo retangulo1, Retangulo retangulo2){
    double x, y, w, h;

    x = min(retangulo1.x, retangulo2.x);
    y = min(retangulo1.y, retangulo2.y);
    w = max(retangulo1.x + retangulo1.w, retangulo2.x + retangulo2.w) - x;
    h = max(retangulo1.y + retangulo1.h, retangulo2.y + retangulo2.h) - y;
    if((retangulo1.w + retangulo2.w) >= w && (retangulo1.h + retangulo2.h) >= h){
        inicio = insereElemento(inicio, 0, 'r');

        insereRetangulo(inicio, w, h, x, y, "black", "transparent");
        fprintf(arq, " SIM\n\n");
    }
        else{
            inicio = insereElemento(inicio, 0, 'x');
            insereRetangulo(inicio, w, h, x, y, "black", "transparent");
            fprintf(arq, " NAO\n\n");
        }
}

void sobreposicao(int i, int k, listaStruct *inicio, FILE *saida){
    listaStruct *aux1 = buscaElemento(inicio, i);
    listaStruct *aux2 = buscaElemento(inicio, k);

        if(aux1->tipo == 'c'){
            if(aux2->tipo == 'c'){
                sobrepoeCirculoCirculo(inicio, saida, aux1->forma->circulo, aux2->forma->circulo);
            }
            else if(aux2->tipo == 'r'){
                sobrepoeCirculoRetangulo(inicio, saida, aux1->forma->circulo, aux2->forma->retangulo);
            }
        }
        else if(aux1->tipo == 'r'){
            if(aux2->tipo == 'r'){
                sobrepoeRetanguloRetangulo(inicio, saida, aux1->forma->retangulo, aux2->forma->retangulo);
            }
            else if(aux2->tipo == 'c'){
                sobrepoeCirculoRetangulo(inicio, saida, aux2->forma->circulo, aux1->forma->retangulo);
            }
        }
}

void pontoInterno(int j, double x, double y, listaStruct *inicio, FILE *saida){
    
    char cor[8];
    listaStruct *aux = buscaElemento(inicio, j);

    if(aux->tipo == 'c'){
        fprintf(saida, "%d: circulo", aux->i);
        if(pow(x - aux->forma->circulo.x, 2) + pow(y - aux->forma->circulo.y, 2) <= (pow(aux->forma->circulo.r, 2))){
            strcpy(cor, "blue");
            inicio = insereElemento(inicio, 0, 'c');
            insereCirculo(inicio, 1, x, y, cor, cor);
            inicio = insereElemento(inicio, 0, 'l');
            insereLinha(inicio, x, y, aux->forma->circulo.x, aux->forma->circulo.y, cor);
            fprintf(saida, " INTERNO\n\n");
        }
        else{
            strcpy(cor, "magenta");
            inicio = insereElemento(inicio, 0, 'c');
            insereCirculo(inicio, 1, x, y, cor, cor);
            inicio = insereElemento(inicio, 0, 'l');
            insereLinha(inicio, x, y, aux->forma->circulo.x, aux->forma->circulo.y, cor);
            fprintf(saida, " NAO INTERNO\n\n");
        }
    }
    else{
            fprintf(saida, "%d: retangulo", aux->i);
            if((x >= aux->forma->retangulo.x && x<= (aux->forma->retangulo.x + aux->forma->retangulo.w))&&(y >= aux->forma->retangulo.y && y <= (aux->forma->retangulo.y + aux->forma->retangulo.h))){
                strcpy(cor, "blue");
                inicio = insereElemento(inicio, 0, 'c');
                insereCirculo(inicio, 1, x, y, cor, cor);
                inicio = insereElemento(inicio, 0, 'l');
                insereLinha(inicio, x, y, (aux->forma->retangulo.w)/2, (aux->forma->retangulo.h)/2, cor);
                fprintf(saida, " INTERNO\n\n");
            }
            else{
                strcpy(cor, "magenta");
                inicio = insereElemento(inicio, 0, 'c');
                insereCirculo(inicio, 1, x, y, cor, cor);
                inicio = insereElemento(inicio, 0, 'l');
                insereLinha(inicio, x, y, (aux->forma->retangulo.w)/2, (aux->forma->retangulo.h)/2, cor);
                fprintf(saida, " NAO INTERNO\n\n");
            }
        }
}

void pnt(int j, char novoCorb[], char novoCorp[], listaStruct *inicio, FILE *saida){

    listaStruct *aux = buscaElemento(inicio, j);

    if(aux->tipo == 'c'){
        strcpy(aux->forma->circulo.corb, novoCorb);
        strcpy(aux->forma->circulo.corp, novoCorp);
        fprintf(saida, "%lf %lf\n\n", aux->forma->circulo.x, aux->forma->circulo.y);
    }
        else if (aux->tipo == 'r'){
            strcpy(aux->forma->retangulo.corb, novoCorb);
            strcpy(aux->forma->retangulo.corp, novoCorp);
            fprintf(saida, "%lf %lf\n\n", aux->forma->retangulo.x, aux->forma->retangulo.y);
        }
            else if (aux->tipo == 't'){
                strcpy(aux->forma->texto.corb, novoCorb);
                strcpy(aux->forma->texto.corp, novoCorp);
                fprintf(saida, "%lf %lf\n\n", aux->forma->texto.x, aux->forma->texto.y);
            }

}

listaStruct *delf(int j,listaStruct *inicio, FILE *saida){

    listaStruct *aux = buscaElemento(inicio, j);

    if(aux->tipo == 'c'){
        fprintf(saida, "%d: CIRCULO x:%lf y:%lf r:%lf corb:%s corp:%s\n\n", aux->i, aux->forma->circulo.x, aux->forma->circulo.y, aux->forma->circulo.r, aux->forma->circulo.corb, aux->forma->circulo.corp);
    }
    else if(aux->tipo == 'r'){
        fprintf(saida, "%d: RETANGULO x:%lf y:%lf w:%lf h:%lf corb:%s corp:%s\n\n", aux->i, aux->forma->retangulo.x, aux->forma->retangulo.y, aux->forma->retangulo.w, aux->forma->retangulo.h, aux->forma->retangulo.corb, aux->forma->retangulo.corp);     
    }
    else if(aux->tipo == 't'){
        fprintf(saida, "%d: TEXTO x:%lf y:%lf corb:%s corp:%s texto:%s\n\n", aux->i, aux->forma->texto.x, aux->forma->texto.y,aux->forma->texto.corb, aux->forma->texto.corp, aux->forma->texto.text);     
    }

    inicio = liberaElemento(inicio, aux->i);
 
    return inicio;
}
