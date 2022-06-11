#ifndef  LISTAFIG_H_
#define  LISTAFIG_H_

listaStruct *iniciaLista();

listaStruct *insereElemento(listaStruct*, int, char);

void insereCirculo(listaStruct*, double, double, double, char*, char*);

void insereRetangulo(listaStruct*, double, double, double, double, char*, char*);

void insereTexto(listaStruct*, double, double, char*, char*, char*);

void insereLinha(listaStruct*, double, double, double, double, char*);

listaStruct *buscaElemento(listaStruct*, int);

void imprimeLista(listaStruct*);

void liberaLista(listaStruct*);

listaStruct *liberaElemento(listaStruct*, int);

#endif
