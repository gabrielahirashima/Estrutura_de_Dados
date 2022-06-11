#ifndef STRUCTFIG_H
#define STRUCTFIG_H

typedef struct formaCirculo{
  double r, x, y;  /* raio, pos x, pos y*/
  char corb[20], corp[20]; /* cor da borda e cor de preenchimento*/
}Circulo; 

typedef struct formaRetangulo{
  double w, h, x, y; /*largura do retanfulo, altura do retagulo, pos x, pos y*/
  char corb[20], corp[20]; /*cor da borda e cor de preenchimento*/
}Retangulo; 

typedef struct formaTexto{
  double x, y; /*pos x e pos y*/
  char corb[20], corp[20], text[100]; /*cor da borda e cor de preenchimento*/
}Texto;

typedef struct formaLinha{
  double x, y, x2, y2;  /*ponto x, ponto y, ponto x2, ponto y2*/
  char cor[20];
}Linha;

typedef union forma{
    Circulo circulo;
    Retangulo retangulo;
    Texto texto;
    Linha linha;
}Forma; /*a union seleciona uma das formas para adicionar ao elemento da lista encadeada*/

typedef struct lista{
    int i; /*numero de identificação da figura*/
    char tipo; /*char que identifica o tipo de figura: c, r, t, l*/
    Forma *forma; /*ponteiro que aponta para uma das structs de forma*/
    struct lista *prox; /*ponteiro que aponta para próximo elemento de lista*/
}listaStruct;

#endif
