#ifndef LISTAPONTOS_H_
#define LISTAPONTOS_H_

#include "lista.h"

/*define listaPonto como pointer void*/
typedef void *listaPonto;

/*cria um elemento do tipo ponto e retorna um ponteiro para ele*/
listaPonto criaPonto(double x, double y);

/*retorna um double X a partir do No*/
double getXPonto(Node no);

/*retorna um double Y a partir do No*/
double getYPonto(Node no);

/*recebe pontos de 2 elementos e retorna  a distancia entre eles*/
double distanciaPontos(double x1, double y1, double x2, double y2);

/*calcula a orientacao polar entre  tres pontos e retorna se 'e colinear,
anti-horario ou horario*/
int orientacaoPolar(Node a, Node b, Node c);

/*compara tres pontos e sua orientacao e retorna seu resultado*/
int comparaPontos(Node a, Node b, Node c);

#endif