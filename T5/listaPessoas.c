#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaPessoas.h"

typedef struct pessoa{
char cpf[25];
char nome[35];
char sobrenome[35];
char sexo;
char nasc[15];
}Pessoa;


listaPessoa criaPessoa(char *cpf, char *nome, char *sobrenome, char sexo, char* nasc){
    Pessoa *p =(Pessoa*)malloc(sizeof(Pessoa));
    strcpy(p->cpf, cpf);
    strcpy(p->nome, nome);
    strcpy(p->sobrenome, sobrenome);
    p->sexo = sexo;
    strcpy(p->nasc, nasc);
    return p;
}

char *getCpfPessoa(listaPessoa lista){
    Pessoa *p = (Pessoa*)lista;
    return p->cpf;
}

char *getNomePessoa(listaPessoa lista){
    Pessoa *p = (Pessoa*)lista;
    return p->nome;
}

char *getSobrenomePessoa(listaPessoa lista){
    Pessoa *p = (Pessoa*)lista;
    return p->sobrenome;
}

char getSexoPessoa(listaPessoa lista){
    Pessoa *p = (Pessoa*)lista;
    return p->sexo;
}

char *getNascPessoa(listaPessoa lista){
    Pessoa *p = (Pessoa*)lista;
    return p->nasc;
}

void setCpfPessoa(listaPessoa lista, char *cpf){
    Pessoa *p = (Pessoa*)lista;
    strcpy(p->cpf, cpf);
}

void setNomePessoa(listaPessoa lista, char *nome){
    Pessoa *p = (Pessoa*)lista;
    strcpy(p->nome, nome);
}

void setSobrenomePessoa(listaPessoa lista, char *sobrenome){
    Pessoa *p = (Pessoa*)lista;
    strcpy(p->sobrenome, sobrenome);
}

void setSexoPessoa(listaPessoa lista, char sexo){
    Pessoa *p = (Pessoa*)lista;
    p->sexo = sexo;
}

void setNascPessoa(listaPessoa lista, char *nasc){
    Pessoa *p = (Pessoa*)lista;
    strcpy(p->nasc, nasc);
}