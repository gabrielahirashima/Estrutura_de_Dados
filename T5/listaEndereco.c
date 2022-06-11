#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaendereco.h"
#include "listaQuadras.h"

typedef struct endereco{
    char cpf[25];
    char cep[25];
    char complemento[25];
    char face;
    int num;
    double x;
    double y;
}Endereco;

listaEndereco criaEndereco(char *cpf, char *complemento, char face, int num, listaQuadra quadra){
    Endereco *e =(Endereco*)malloc(sizeof(Endereco));
    float x = getXQuadra(quadra);
    float y = getYQuadra(quadra);
    float w = getWQuadra(quadra);
    float h = getHQuadra(quadra);
    strcpy(e->cpf, cpf);
    strcpy(e->cep, getCepQuadra(quadra));     
    strcpy(e->complemento, complemento);
    e->face = face;
    e->num = num;

    return e;
}