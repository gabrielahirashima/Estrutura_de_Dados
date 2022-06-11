#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structfig.h"
#include "listafig.h"
#include "criasvg.h"
#include "opqry.h"
#include "learq.h"

int main(int argc, char *argv[]){
    
    listaStruct *inicio;
    char *caminhoGeo = NULL, *caminhoQry = NULL, *caminhoEntrada = NULL, *caminhoSaida = NULL;
    char *nomeGeo = NULL, *nomeQry = NULL, *nomeArquivo = NULL, *nomeArquivoQry = NULL;
    char *saida = NULL, *saidaQry = NULL;
    int i;

    for(i=1; i<argc; i++){
        if(strcmp(argv[i], "-e") == 0){
            i++;
            if(argv[i] == NULL){
                perror("Sem parametros validos em -e");
                exit (1);
            }
            caminhoEntrada = (char*)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(caminhoEntrada, argv[i]);
        }
        else if(strcmp(argv[i], "-f") == 0){
            i++;
            if(argv[i] == NULL){
                perror("Sem parametros validos em -f");
                exit(1);
            }
            
            caminhoGeo = (char*)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(caminhoGeo, argv[i]);
            
        }
        else if(strcmp(argv[i], "-q") == 0){
            i++;
            if(argv[i] == NULL){
                perror("Sem parametros validos em -q");
                exit(1);
            }
            caminhoQry = (char*)malloc((strlen(argv[i])+1)*sizeof(char)*2);
            strcpy(caminhoQry, argv[i]);
        }
        else if(strcmp(argv[i], "-o") == 0){
            i++;
            if(argv[i] == NULL){
                perror("Sem parametros validos em -o");
                exit(1);
            }
            caminhoSaida = (char*)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(caminhoSaida, argv[i]);
        }
    }

    printf("\n%s %s %s %s\n", caminhoEntrada, caminhoGeo, caminhoQry, caminhoSaida);
    nomeArquivo = (char*) malloc( (sizeof(retornaNomeDoArquivo(caminhoGeo)) + 1) * sizeof(char) * 2);

    if(caminhoEntrada != NULL){//se for passado um argumento de entrada em -e(diretórios)
        nomeGeo = (char*)malloc((sizeof(caminhoEntrada)+sizeof(caminhoGeo)+2)*sizeof(char) * 2);
        sprintf(nomeGeo, "%s/%s", caminhoEntrada, caminhoGeo);
            if(caminhoQry != NULL){
                nomeQry = (char*)malloc((sizeof(caminhoEntrada)+sizeof(caminhoQry)+2)*sizeof(char));
                sprintf(nomeQry, "%s/%s", caminhoEntrada, caminhoQry);
            }
            // printf("nome geo antessss == >%s<\n\n", nomeGeo);
    }
    else{//nenhum argumento passado para argumento -e
        nomeGeo = (char*)malloc((strlen(caminhoGeo)+1)*sizeof(char) * 2);
        strcpy(nomeGeo, caminhoGeo);
            if(caminhoQry != NULL){
                nomeQry = (char*)malloc((strlen(caminhoQry)+1)*sizeof(char) * 2);
                strcpy(nomeQry, caminhoQry);
            }
    }

    strcpy(nomeArquivo, strtok(caminhoGeo,"."));

    saida = (char*) malloc( (strlen(nomeArquivo) + strlen(caminhoSaida) + 6) * sizeof(char) * 2);

    inicio = openGeo(nomeGeo);
    Svg(inicio, saida);

    if(caminhoQry != NULL){
        nomeArquivoQry = (char*) malloc(sizeof(retornaNomeDoArquivoQry(caminhoQry))*sizeof(char) * 2);
        strcpy(nomeArquivo, retornaNomeDoArquivoQry(caminhoQry));
        saidaQry = (char*) malloc((strlen(nomeArquivo)+strlen(caminhoSaida)+strlen(nomeArquivoQry)+3)*sizeof(char) * 2);
        sprintf(saidaQry, "%s/%s-%s", caminhoSaida, nomeArquivo, nomeArquivoQry);
        inicio = openQry(inicio, nomeQry, saidaQry);
        free(nomeQry);
        free(saidaQry);
        free(caminhoQry);
        free(nomeArquivoQry);
    }

    free(saida);
    free(nomeArquivo);
    free(nomeGeo);
    free(caminhoSaida);
    free(caminhoGeo);
    free(caminhoEntrada);

    liberaLista(inicio);

    return 0;

}
