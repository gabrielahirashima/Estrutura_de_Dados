#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "learq.h"
#include "criaSvg.h"
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaCidadesQT.h"
#include "hashtable.h"

char *retornaString(char *string){
     char *aux = strrchr(string,'/');
          if(aux == NULL){
             return strtok(string,".");
            }
	return strtok(&aux[1],".");
}

void tratamentoString(char *diretorio, char *arquivoGeo, char *arquivoQry, char *pastaSaida, char *arquivoEc, char *arquivoPm){
    char *nomeArquivoGeo = NULL; /*nome do arquivo geo pós tratamento*/
    char *nomeArquivoQry = NULL; /*nome do arquivo qry pós tratamento*/
    char *caminhoGeo = NULL; /*caminho final do arquivo geo*/
    char *caminhoQry = NULL; /*caminho final do arquivo Qry*/
    char *saidaSvg = NULL; /*caminho de saída para o arquivo Svg*/
    char *saidaQry = NULL; /*caminho de saída para o arquivo Qry*/
    char *caminhoEc = NULL;
    char *caminhoPm = NULL;

    listaCidade Cidade = iniciaListaCidade();
    listaCidadeQT CidadeQt = iniciaListaQTCidade();
    
            nomeArquivoGeo = (char*)malloc( ( ( strlen(arquivoGeo) )+1 )*sizeof(char) );
            strcpy(nomeArquivoGeo, arquivoGeo);
            nomeArquivoGeo = strtok(nomeArquivoGeo, "."); /*vai retornar somente o nome anterior ao .geo*/ 
            /*printf("\n\nnome geo formatado: %s", nomeArquivoGeo);*/

            if (diretorio != NULL){/*Se foi passado um argumento de diretório*/
                caminhoGeo = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoGeo) )+8 )* sizeof(char) );
                sprintf(caminhoGeo, "%s/%s", diretorio, arquivoGeo);
                /*printf("\n\ncaminho geo com argumento de diretorio: %s", caminhoGeo);*/
                   if(arquivoQry !=  NULL){/*se foi passado um arquivo de qry*/
                        caminhoQry = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoQry) )+ 8 )* sizeof(char) );
                        sprintf(caminhoQry, "%s/%s", diretorio, arquivoQry);
                        /*printf("\n\ncaminho Qry com argumento de diretorio: %s", caminhoQry);*/
                    }
                    if(arquivoEc != NULL){
                        caminhoEc = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoEc) )+8 )* sizeof(char) );
                        sprintf(caminhoEc, "%s/%s", diretorio, arquivoEc);
                    }
                    if(arquivoPm != NULL){
                        caminhoPm = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoPm) )+8 )* sizeof(char) );
                        sprintf(caminhoPm, "%s/%s", diretorio, arquivoPm);
                    }
            }
            else{/*Não foram passados argumentos para o diretório*/
               caminhoGeo =  (char*)malloc( ( (strlen(arquivoGeo) )+8 )* sizeof(char) );
                strcpy(caminhoGeo, arquivoGeo);
                /*printf("\n\ncaminho Geo sem argumento de diretorio: %s", caminhoGeo);*/
                    if(arquivoQry != NULL){/*se foi passado um arquivo de qry*/
                        caminhoQry = (char*)malloc( ( (strlen(arquivoQry) )+8 )* sizeof(char) );
                        strcpy(caminhoQry, arquivoQry);
                       /* printf("\n\ncaminho Qry sem argumento de diretorio: %s", caminhoQry);*/
                    }
                    if(arquivoEc != NULL){
                        caminhoEc = (char*)malloc( ( ( strlen(arquivoEc) )+8 )* sizeof(char) );
                        strcpy(caminhoEc, arquivoEc);
                    }
                    if(arquivoPm != NULL){
                        caminhoPm = (char*)malloc( ( ( strlen(arquivoPm) )+8 )* sizeof(char) );
                        strcpy(caminhoEc, arquivoPm);
                    }
            }

            if(arquivoEc != NULL){
                hstable hashtableEstabelecimentos[1];
                hashtableEstabelecimentos[0] = iniciaHashtable();
                hashtableEstabelecimentos[1] = iniciaHashtable();
                openEc(arquivoEc, hashtableEstabelecimentos[1]);
            }
            if(arquivoPm != NULL){
                hstable hashtablePessoas[1];
                hashtablePessoas[0] = iniciaHashtable();
                hashtablePessoas[1] = iniciaHashtable();
                openPm(arquivoPm, hashtablePessoas[1]);
            }
            

                saidaSvg =  (char*)malloc( ( (strlen(pastaSaida)+strlen(nomeArquivoGeo) )+8 )* sizeof(char) );
                sprintf(saidaSvg, "%s/%s.svg", pastaSaida, nomeArquivoGeo);
                /*printf("\n\nsaida Svg: %s", saidaSvg);*/
                /*printf("\n\nsaida caminhoEc: %s", caminhoEc);
                printf("\n\nsaida caminhoPm: %s", caminhoPm);*/

                openGeo(Cidade, CidadeQt, caminhoGeo, saidaSvg);

                liberaLista(getListaFormas(Cidade));
                liberaLista(getListaObjetos(Cidade));
                liberaLista(getListaQuadras(Cidade));
                liberaLista(getListaPostos(Cidade));
                liberaLista(getListaRegioes(Cidade));
                liberaLista(getListaCasosCovid(Cidade));
                free(Cidade);

            if (arquivoQry != NULL){
                    nomeArquivoQry = (char*)malloc( ( ( strlen(arquivoQry) )+8 )*sizeof(char) );

                    nomeArquivoQry = strcpy(nomeArquivoQry, retornaString(arquivoQry));
         
                    //printf("\n\nnome Qry formatado: %s", nomeArquivoQry);

                    saidaQry =  (char*)malloc( ( (strlen(pastaSaida)+strlen(nomeArquivoGeo)+strlen(nomeArquivoQry) )+16 )* sizeof(char) );
                    sprintf(saidaQry, "%s/%s-%s", pastaSaida, nomeArquivoGeo, nomeArquivoQry);
                    /*printf("\n\nsaida Qry: %s", saidaQry);*/
                    //openQry(Cidade, caminhoQry, saidaQry);
                free(saidaQry);
                free(nomeArquivoQry);
            }

    /*liberaQuadTree(getQuadtreeFormas(CidadeQt));
    liberaQuadTree(getQuadtreeObjetos(CidadeQt));
    liberaQuadTree(getQuadtreeQuadras(CidadeQt));
    liberaQuadTree(getQuadtreePostos(CidadeQt));
    liberaQuadTree(getQuadtreeRegioes(CidadeQt));
    liberaQuadTree(getQuadtreeCasosCovid(CidadeQt));
    free(CidadeQt);*/
    
    free(caminhoEc);
    free(caminhoPm);
    free(saidaSvg);
    free(caminhoQry);
    free(caminhoGeo);
    free(nomeArquivoGeo);

}