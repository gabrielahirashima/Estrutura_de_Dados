#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structfig.h"
#include "listafig.h"
#include "criasvg.h"
#include "opqry.h"


char *retornaNomeDoArquivo(char *caminhoEntrada){
        char *aux=(char*)malloc(sizeof(caminhoEntrada));
        aux = caminhoEntrada;

        caminhoEntrada = strtok(aux,".");

        free(aux);

        return caminhoEntrada;/*separa o que vem antes do .*/
}

char *retornaNomeDoArquivoQry(char *caminhoEntradaQry){
    char *aux=(char*)malloc(sizeof(caminhoEntradaQry));

    strcpy(aux, strrchr(caminhoEntradaQry, '/'));/*separa o que vem depois da / */
    caminhoEntradaQry = strtok(aux, "/");/*separa novamente a / */

    free(aux);

    return caminhoEntradaQry;
}

listaStruct *openGeo(char *nomeGeo){
    FILE *arq;

    char tipo[3], corb[20], corp[20], text[50];
    double x, y, w, h, r;
    int id, nx = 1000, cont = 0;

    printf("nome geo == >%s<", nomeGeo);

    listaStruct *listaGeo = iniciaLista();

    arq = fopen(nomeGeo, "r");

        if(arq == NULL){
            printf("Erro ao abrir o arquivo Geo!!");
            system("pause");
            exit(1);
        }

        while(fscanf(arq, "%s", tipo) != EOF){
            if(strcmp(tipo, "nx") == 0){
                fscanf(arq, "%d\n", &nx);
            }
            else if((strcmp(tipo, "c") == 0) && cont<nx){
                fscanf(arq, "%d %lf %lf %lf %s %s", &id, &r, &x, &y, corb, corp);
                listaGeo = insereElemento(listaGeo, id, 'c');
                insereCirculo(listaGeo, r, x, y, corb, corp);
                cont = cont + 1;
            }
            else if((strcmp(tipo, "r") == 0) && cont<nx){
                fscanf(arq, "%d %lf %lf %lf %lf %s %s", &id, &w, &h, &x, &y, corb, corp);
                listaGeo = insereElemento(listaGeo, id, 'r');
                insereRetangulo(listaGeo, w, h, x, y, corb, corp);
                cont = cont + 1;
            }
            else if((strcmp(tipo, "t") == 0) && cont<nx){
                fscanf(arq, "%d %lf %lf %s %s", &id, &x, &y, corb, corp);
                fgets(text, 50, arq);
                printf("%d %lf %lf %s %s %s", id, x, y, corb, corp, text);
                listaGeo = insereElemento(listaGeo, id, 't');
                insereTexto(listaGeo, x, y, corb, corp, text);
                cont = cont + 1;
            }
        }

        /*imprimeLista(listaGeo);*/

    fclose (arq);

return listaGeo;
}

listaStruct *openQry(listaStruct *inicio, char *entradaQry, char *saida){
    FILE *entrada, *out;
    char tipo[6], corb[20], corp[20];
    char *saidaSvg = malloc(strlen(saida)+5);
    char *saidaTxt = malloc(strlen(saida)+5);
    int j, k;
    double x, y;

        sprintf(saidaTxt, "%s.txt", saida);
        sprintf(saidaSvg, "%s.svg", saida);

        entrada = fopen(entradaQry, "r");
        out = fopen(saidaTxt, "w+");

        printf("\n\ndiretorio qry== >%s<\n\n", entradaQry);

        if(entrada == NULL){
            printf("Erro ao abrir o arquivo Qry de entrada!!");
            system("pause");
            exit(1);
        }

        if(out == NULL){
            printf("Erro ao abrir o arquivo Qry de saida!!");
            system("pause");
            exit(1);
        }

        while(fscanf(entrada, "%s", tipo)!=EOF){
            if(strcmp(tipo, "o?") == 0){
                fscanf(entrada, "%d %d", &j, &k);
                printf("\nverificando = %d %d\n", j, k);
                sobreposicao(j, k, inicio, out);
            }
            else if(strcmp(tipo, "i?") == 0){
                fscanf(entrada, "%d %lf %lf", &j, &x, &y);
                pontoInterno(j, x, y, inicio, out);
            }
            else if(strcmp(tipo, "pnt")==0){
                fscanf(entrada, "%d %s %s", &j, corb, corp);
                pnt(j, corb, corp, inicio, out);
            }
            else if(strcmp(tipo, "pnt*")==0){
                fscanf(entrada, "%d %d %s %s", &j, &k, corb, corp);
                pnt(j, corb, corp, inicio, out);
                pnt(k, corb, corp, inicio, out);
            }
            else if(strcmp(tipo, "delf")==0){
                fscanf(entrada, "%d", &j);
                inicio = delf(j, inicio, out);
            }
            else if(strcmp(tipo, "delf*")==0){
                fscanf(entrada, "%d %d", &j, &k);
                inicio = delf(j, inicio, out);
                inicio = delf(k, inicio, out);
            }
        }

        Svg(inicio, saidaSvg);

        fclose(out);
        fclose(entrada);

        free(saidaSvg);
        free(saidaTxt);

    return inicio;
}
