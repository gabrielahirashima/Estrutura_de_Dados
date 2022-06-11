#ifndef QUADTREE_H_
#define QUADTREE_H_

#include "lista.h"
#include "listaCidades.h"

/*define QuadTree como um ponteiro void*/
typedef void *QuadTree;

/*define QuadTreeNo como um ponteiro void*/
typedef void *QuadTreeNo;

/*define QuadTreeElemento como um ponteiro void*/
typedef void *QuadTreeElemento;

/*cria uma quadtree e define uma key para ela, retornando seu pointer*/
QuadTree criaQuadTree(char *key);

/*cria o no para quadtree e retorna seu ponteiro*/
QuadTreeNo criaNoQT();

/*insere um elemento na quadtree verificando as direcoes NE, NO, SE, SO*/
QuadTree insereElementoQT(QuadTree qt, QuadTreeElemento elemento, double px, double py);

/*remove um no da quadtree com base nas coordenadas do elemento passado como parametro*/
void removeNoQuadTree(QuadTree qt, QuadTreeNo no);

/*libera um no da quadtree*/
void liberaNoQuadTree(QuadTreeNo no);

/*libera a quadtree por completo*/
void liberaQuadTree(QuadTree qt);

/*recebe as coordenadas do elemento a ser avaliado e do elemento anterior
a este e avalia o possivel quadrante, o retornando*/
char *getQuadrante(double pAtualX, double pAtualY, double pRaizX, double pRaizY);

/*compara dois pontos e verifica se eles sao iguais*/
int comparaPonto(double pAtualX, double pAtualY, double pRaizX, double pRaizY);

/*recebe um node e o quadrante do filho, e retorna o node filho*/
QuadTreeNo getFilho(QuadTreeNo no, char* quadrante);

/*seta um filho para o node pai a partir das informacoes passadas como
parametro*/
void setFilho(QuadTreeNo pai, QuadTreeNo filho, char *quadrante);

/*percorre a arvore e retorna o elemento buscado*/
QuadTreeNo getNoQt(QuadTreeNo raiz, double x, double y);

/*retorna o ponto x do no passado como parametro*/
double getXQuadTree(QuadTreeNo no);

/*retorna o ponto y do no passado como parametro*/
double getYQuadTree(QuadTreeNo no);

/*retorna o elemento da quadtree a partir do no passado como 
parametro*/
QuadTreeElemento getQuadTreeElemento(QuadTreeNo no);

/*retorna a a raiz da quadtree a partir da lsita passada como parametro*/
QuadTreeNo getRaizQuadTree(QuadTreeNo no);

#endif
