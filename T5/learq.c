#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaRegioes.h"
#include "listaPostos.h"
#include "criaSvg.h"
#include "opqry.h"
#include "opqry2.h"
#include "listaPontos.h"
#include "envoltoria.h"
#include "listaCidadesQT.h"
#include "listToQuad.h"
#include "hashtable.h"
#include "listaEstabelecimentos.h"
#include "listaPessoas.h"
#include "listaEndereco.h"

void openGeo(listaCidade listacidade, QuadTree qt, char *nomeGeo, char *saidaSvg){
    char comando[4];
    char cfillQ[20];
    char cstrkQ[20];
    char cstrkH[20];
    char cfillH[20];
    char cstrkR[20];
    char cfillR[20];
    char cstrkS[20];
    char cfillS[20];
    char corb[20];
    char corp[20];
    char text[50];
    char id[20];
    char cep[20];
    int id_forma;
    int i = 1000;
    int nq = 1000;
    int nh = 1000;
    int ns = 1000;
    int nr = 1000;
    int cont_i = 0;
    int cont_nq = 0;
    int cont_nh = 0;
    int cont_ns = 0;
    int cont_nr = 0;
    double r;
    double x;
    double y;
    double w;
    double h;
    double d;
    char sw[8];
    char cw[8];
    char rw[8];
    int totalP = 0;
    int totalR = 0;

        strcpy(sw, "1.0px");
        strcpy(cw, "1.0px");
        strcpy(rw, "1.0px");
        
    tipo elemento;

    FILE *arq;

    arq = fopen(nomeGeo, "r");

        if(arq == NULL){
            printf("Erro ao abrir o arquivo Geo!!");
            system("pause");
            exit(1);
        }

            while(fscanf(arq, "%s", comando) != EOF){
                if(strcmp(comando, "nx") == 0){
                    fscanf(arq, "%d %d %d %d %d\n", &i, &nq, &nh, &ns, &nr);
                }

                else if((strcmp(comando, "c") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %s %s", &id_forma, &r, &x, &y, corb, corp);
                    elemento = criaCirculo(id_forma, r, x, y, corb, corp, cw);
                    insertElemento(getListaFormas(listacidade), elemento);
                    cont_i += 1;
                }

                else if((strcmp(comando, "r") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %lf %s %s", &id_forma, &w, &h, &x, &y, corb, corp); 
                    elemento = criaRetangulo(id_forma, w, h, x, y, 0, 0, corb, corp, rw);
                    insertElemento(getListaFormas(listacidade), elemento);
                    cont_i += 1;
                }

                else if(strcmp(comando, "t") == 0){
                    fscanf(arq, "%d %lf %lf %s %s %s", &id_forma, &x, &y, corb, corp, text); 
                    elemento = criaTexto(id_forma, x, y, corb, corp, text);
                    insertElemento(getListaFormas(listacidade), elemento);
                }

                else if((strcmp(comando, "q") == 0) && cont_nq < nq){
                    fscanf(arq, "%s %lf %lf %lf %lf", cep, &x, &y ,&w ,&h);
                    elemento = criaQuadra(cep, x, y, w, h, cstrkQ, cfillQ, sw);
                    insertElemento(getListaQuadras(listacidade), elemento);
                    cont_nq += 1;
                }

                else if((strcmp(comando, "h") == 0) && cont_nh < nh){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaHidrante(id, x, y, cfillH, cstrkH, sw);
                    insertElemento(getListaObjetos(listacidade), elemento);
                    cont_nh += 1;
                }

                else if((strcmp(comando, "s") == 0) && cont_ns < ns){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaSemaforo(id, x, y, cfillS, cstrkS, sw);
                    insertElemento(getListaObjetos(listacidade), elemento);
                    cont_ns += 1;
                }

                else if((strcmp(comando, "rb") == 0) && cont_nr < nr){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaRadio(id, x, y, cfillR, cstrkR, sw);
                    insertElemento(getListaObjetos(listacidade), elemento);
                    cont_nr += 1;
                }

                else if((strcmp(comando, "ps") == 0)){
                    fscanf(arq, "%lf %lf", &x, &y);
                    totalP = totalP + 1;
                    elemento = criaPosto(totalP, x, y);
                    insertElemento(getListaPostos(listacidade), elemento); 
                }

                else if((strcmp(comando, "d") == 0)){
                    fscanf(arq, "%lf, %lf, %lf, %lf, %lf", &x, &y, &w, &h, &d);
                    totalR = totalR + 1;
                    elemento = criaRegiao(totalR, x, y, w, h, d);
                    insertElemento(getListaRegioes(listacidade), elemento);
                }

                else if(strcmp(comando, "ch") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillH, cstrkH);
                }

                else if(strcmp(comando, "cr") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillR, cstrkR);
                }

                else if(strcmp(comando, "cs") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillS, cstrkS);
                }

                else if(strcmp(comando, "cq") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillQ, cstrkQ);
                }

                else if(strcmp(comando, "sw") == 0){
                    fscanf(arq, "%s %s", cw, rw);
                }
            }

    svgen(listacidade, saidaSvg);

    transformaListaFormas(getListaFormas(listacidade), getQuadtreeFormas(qt));
    transformaListaQuadras(getListaQuadras(listacidade), getQuadtreeQuadras(qt));
    transformaListaRegioes(getListaRegioes(listacidade), getQuadtreeRegioes(qt));
    transformaListaObjetos(getListaObjetos(listacidade), getQuadtreeObjetos(qt));
    transformaListaPostos(getListaPostos(listacidade), getQuadtreePostos(qt));
    transformaListaCovid(getListaCasosCovid(listacidade), getQuadtreeCasosCovid(qt));
    fclose(arq);

}

void openQry(listaCidade listacidade, char *entradaQry, char *saidaQry){
  FILE *entrada, *saidaTxt;

    char comando[12];
    char teste[20];
    char id[20];
    char cStrk[20];
    char cFill[20];
    double r;
    double x;
    double y;
    double w;
    double h;
    int j;
    int k;
    char face;
    int num;
    int n_casos;
    int n_postos;

    char *saidaSvgQry = malloc(strlen(saidaQry)+5);
    char *saidaTxtQry = malloc(strlen(saidaQry)+5);

    sprintf(saidaTxtQry, "%s.txt", saidaQry);
    sprintf(saidaSvgQry, "%s.svg", saidaQry);

    entrada = fopen(entradaQry, "r");
    saidaTxt = fopen(saidaTxtQry, "w+");

    if(entrada == NULL){
            printf("Erro ao abrir o arquivo entradaQry!!");
            system("pause");
            exit(1);
        }

    if(saidaTxt == NULL){
            printf("Erro ao abrir o arquivo saidaTxtQry!!");
            system("pause");
            exit(1);
    }

        while(fscanf(entrada, "%s", comando)!=EOF){

            if(strcmp(comando, "dq") == 0){
                fscanf(entrada, "%s", teste);
                    if(strcmp(teste, "#") == 0){
                        fscanf(entrada, "%s %lf", id, &r);
                        delQuadras(listacidade, saidaTxt, 1, id, r);
                    }
                    else{
                        strcpy(id, teste);
                        fscanf(entrada, "%lf", &r);
                        delQuadras(listacidade, saidaTxt, 0, id, r);
                    }
            }
            else if(strcmp(comando, "del") == 0){
                fscanf(entrada, "%s", id);
                delUrb(listacidade, saidaTxt, id);
            }

            else if(strcmp(comando, "cbq") == 0){
                fscanf(entrada, "%lf %lf %lf %s", &x, &y, &r, cStrk);
                colorBorder(listacidade, saidaTxt, x, y, r, cStrk);
            }

            else if(strcmp(comando, "crd?") == 0){
                fscanf(entrada, "%s", id);
                coord(listacidade, saidaTxt, id);
            }

            else if(strcmp(comando, "car") == 0){
                fscanf(entrada, "%lf %lf %lf %lf", &x, &y, &w, &h); 
                rectArea(listacidade, saidaTxt, x, y, w, h);
            }

            else if(strcmp(comando, "o?") == 0){
                fscanf(entrada, "%d %d", &j, &k);
                sobreposicao(j, k, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "i?") == 0){
                fscanf(entrada, "%d %lf %lf", &j, &x, &y);
                pontoInterno(j, x, y, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "pnt") == 0){
                fscanf(entrada, "%d %s %s", &j, cStrk, cFill);
                pnt(j, cStrk, cFill, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "pnt*") == 0){
                fscanf(entrada, "%d %d %s %s", &j, &k, cStrk, cFill);
                if  (j < k){
                    for(int i = j; i < k; i++){
                        pnt(i, cStrk, cFill, listacidade, saidaTxt);
                    }
                }
                else{
                    for(int i = k; i < j; i++){
                        pnt(i, cStrk, cFill, listacidade, saidaTxt);
                    }
                }
            }

            else if(strcmp(comando, "delf") == 0){
                fscanf(entrada, "%d", &j);
                delf(j, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "delf*") == 0){
                fscanf(entrada, "%d %d", &j, &k);
                if  (j < k){
                    for(int i = j; i < k; i++){
                      delf(i, listacidade, saidaTxt);
                    }
                }
                else{
                    for(int i = k; i < j; i++){
                      delf(i, listacidade, saidaTxt);
                    }
                }
            }

            else if(strcmp(comando, "cv") == 0){
                fscanf(entrada, "%d %s %c %d", &n_casos, id, &face, &num);
                casosCovid(listacidade, n_casos, id, face, num, saidaTxt);
            }

            else if(strcmp(comando, "soc") == 0){
                fscanf(entrada, "%d %s %c %d", &n_postos, id, &face, &num);
                socorro(listacidade, n_postos, id, face, num, saidaTxt);
            }

            else if(strcmp(comando, "ci") == 0){
                fscanf(entrada, "%lf %lf %lf", &x, &y, &r);
            }
            else if(strcmp(comando, "m?") == 0){

            }
            else if(strcmp(comando, "dm?") == 0){

            }
            else if(strcmp(comando, "de?") == 0){

            }
            else if(strcmp(comando, "mud") == 0){

            }
            else if(strcmp(comando, "dmprbt") == 0){

            }
            else if(strcmp(comando, "eplg?") == 0){

            }
            else if(strcmp(comando, "catac") == 0){

            }
        }
        
    fclose(saidaTxt);
    fclose(entrada);
    svgen(listacidade, saidaSvgQry);
    free(saidaSvgQry);
    free(saidaTxtQry);
}

void openEc(char *arquivoEc, hstable hashEc[]){
    FILE *entrada;
    char comando[5];
    char codt[20];
    char descricao[300];
    char cnpj[25];
    char cpf[20];
    char cep[20];
    char face[2];
    double num;
    char nome[300];
    tipo elemento;

    entrada = fopen(arquivoEc, "r");

    if(entrada == NULL){
            printf("Erro ao abrir o arquivo entradaEc!!");
            system("pause");
            exit(1);
    }

    while(fscanf(entrada, "%s", comando) != EOF){
         if(strcmp(comando, "t") == 0){
            fscanf(entrada ,"%s %s", codt, descricao);
            elemento = criaDescricao(descricao, codt);
            insereHashtable(hashEc[0], codt, elemento);
            printf("foi");
         }
         else if(strcmp(comando, "e") == 0){
            fscanf(entrada ,"%s %s %s %s %s %lf %s", cnpj, cpf, codt, cep, face, &num, nome);
            elemento = criaDescricao(descricao, codt);
            insereHashtable(hashEc[1], cnpj, elemento);
         }
    }
    fclose(entrada);
}

void openPm(char *arquivoPm, hstable hashPm){
    FILE *entrada;
    char comando[5];
    char cpf[20];
    char nome[150];
    char sobrenome[150];
    char sexo[2];
    char nasc[15];
    char face[2];
    double num;
    char comp[25];
    char cep[20];

    entrada = fopen(arquivoPm, "r");

    if(entrada == NULL){
        printf("Erro ao abrir o arquivo entradaPm!!");
        system("pause");
        exit(1);
    }

    while(fscanf(entrada, "%s", comando) != EOF){
        if(strcmp(comando, "p") == 0){
             fscanf(entrada ,"%s %s %s %s %s", cpf, nome, sobrenome, sexo, nasc);
        }
        else if(strcmp(comando, "m") == 0){
             fscanf(entrada ,"%s %s %s %lf %s", cpf, cep, face, &num ,comp);
        }
    }
}