#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structfig.h"

void Svg(listaStruct *inicio, char *saida){
    FILE *arq; 

    arq = fopen(saida, "w+");

      if(arq == NULL){
            printf("Erro ao abrir o arquivo Svg!!");
            system("pause");
            exit(1);
        }

    fprintf(arq, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");

    while (inicio!=NULL){
        if(inicio->tipo == 'c'){
            fprintf(arq, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\"  fill=\"%s\"/>\n", inicio->forma->circulo.x, inicio->forma->circulo.y, inicio->forma->circulo.r, inicio->forma->circulo.corb, inicio->forma->circulo.corp);
        }
        else if(inicio->tipo == 'r'){
            if(strcmp(inicio->forma->retangulo.corp, "transparent")==0){
            fprintf(arq, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" stroke=\"%s\"  fill=\"%s\" fill-opacity=\"0.1\"/>\n", inicio->forma->retangulo.x, inicio->forma->retangulo.y, inicio->forma->retangulo.w, inicio->forma->retangulo.h, inicio->forma->retangulo.corb, inicio->forma->retangulo.corp); 
            }
            else{
            fprintf(arq, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" stroke=\"%s\"  fill=\"%s\"/>\n", inicio->forma->retangulo.x, inicio->forma->retangulo.y, inicio->forma->retangulo.w, inicio->forma->retangulo.h, inicio->forma->retangulo.corb, inicio->forma->retangulo.corp);
            }
        }
        else if(inicio->tipo == 't'){
            fprintf(arq, "<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" >%s</text>\n", inicio->forma->texto.x, inicio->forma->texto.y, inicio->forma->texto.corp, inicio->forma->texto.corb, inicio->forma->texto.text);
        }
        else if(inicio->tipo == 'l'){
            fprintf(arq, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" fill = \"%s\" />\n",inicio->forma->linha.x, inicio->forma->linha.y, inicio->forma->linha.x2, inicio->forma->linha.y2, inicio->forma->linha.cor, inicio->forma->linha.cor);
        }
        else if(inicio->tipo == 'x'){
            fprintf(arq, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" stroke=\"%s\"  fill=\"%s\" stoke-dasharray=\"5,5\"/>\n", inicio->forma->retangulo.x, inicio->forma->retangulo.y, inicio->forma->retangulo.w, inicio->forma->retangulo.h, inicio->forma->retangulo.corb, inicio->forma->retangulo.corp);
        }
        inicio = inicio->prox;
    }
    fprintf(arq, "</svg>");

    fclose(arq);
}
