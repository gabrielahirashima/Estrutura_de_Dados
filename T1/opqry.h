#ifndef  OPQRY_H_
#define  OPQRY_H_

float max(float, float);

float min(float, float);

void sobrepoeCirculoRetangulo(listaStruct *, FILE *, Circulo, Retangulo);

void sobrepoeCirculoCirculo(listaStruct *, FILE *, Circulo, Circulo);

void sobrepoeRetanguloRetangulo(listaStruct *, FILE *, Retangulo, Retangulo);

void sobreposicao(int, int, listaStruct *, FILE *);

void pontoInterno(int, double, double, listaStruct *, FILE *);

void pnt(int, char[], char[], listaStruct *, FILE *);

listaStruct *delf(int, listaStruct *, FILE *);


#endif
