#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaEstabelecimentos.h"
#include "listaQuadras.h"

typedef struct estabelecimento{
    char cnpj[25];
    char cpf[25];
    char codt[15];
    char cep[25];
    char face;
    int num;
    char nome[35];
}Estabelecimento;

typedef struct descricaoestabelecimento{
    char descricao[300];
    char codt[15];
}descricaoEstabelecimento;

listaEstabelecimento criaEstabelecimento(char *cnpj, char *cpf, char *codt, char *cep, char face, int num, char *nome){
    Estabelecimento *e = (Estabelecimento*)malloc(sizeof(Estabelecimento));
    strcpy(e->cnpj, cnpj);
    strcpy(e->cpf, cpf);
    strcpy(e->codt, codt);
    strcpy(e->cep, cep);
    e->face = face;
    e->num = num;
    strcpy(e->nome, nome);
    return e;
}

listaDescricaoEstabelecimento criaDescricao(char* descricao, char* codt){ 
    descricaoEstabelecimento *d = (descricaoEstabelecimento*)malloc(sizeof(descricaoEstabelecimento));
    strcpy(d->descricao, descricao);
    strcpy(d->codt, codt);
    return d;
}

char *getCnpjEstabelecimento(listaEstabelecimento lista){
    Estabelecimento *e = (Estabelecimento*)lista;
    return e->cnpj;
}

char *getCpfEstabelecimento(listaEstabelecimento lista){
    Estabelecimento *e = (Estabelecimento*)lista;
    return e->cpf;
}

char *getCodtEstabelecimento(listaEstabelecimento lista){
    Estabelecimento *e = (Estabelecimento*)lista;
    return e->codt;
}

char *getCepEstabelecimento(listaEstabelecimento lista){
    Estabelecimento *e = (Estabelecimento*)lista;
    return e->cep;
}

char getFaceEstabelecimento(listaEstabelecimento lista){
    Estabelecimento *e = (Estabelecimento*)lista;
    return e->face;
}

int getNumEstabelecimento(listaEstabelecimento lista){
    Estabelecimento *e = (Estabelecimento*)lista;
    return e->num;
}

char *getNomeEstabelecimento(listaEstabelecimento lista){
    Estabelecimento *e = (Estabelecimento*)lista;
    return e->nome;
}

void setCnpjEstabelecimento(listaEstabelecimento lista, char *cnpj){
    Estabelecimento *e = (Estabelecimento*)lista;
    strcpy(e->cnpj, cnpj);
}

void setCpfEstabelecimento(listaEstabelecimento lista, char *cpf){
    Estabelecimento *e = (Estabelecimento*)lista;
    strcpy(e->cpf, cpf);
}

void setCodtEstabelecimento(listaEstabelecimento lista, char *codt){
    Estabelecimento *e = (Estabelecimento*)lista;
    strcpy(e->codt, codt);
}

void setCepEstabelecimento(listaEstabelecimento lista, char *cep){
    Estabelecimento *e = (Estabelecimento*)lista;
    strcpy(e->cep, cep);
}

void setFaceEstabelecimento(listaEstabelecimento lista, char face){
    Estabelecimento *e = (Estabelecimento*)lista;
    e->face = face;
}

void setNumEstabelecimento(listaEstabelecimento lista, char num){
    Estabelecimento *e = (Estabelecimento*)lista;
    e->num = num;
}

void setNomeEstabelecimento(listaEstabelecimento lista, char *nome){
    Estabelecimento *e = (Estabelecimento*)lista;
    strcpy(e->nome, nome);
}

