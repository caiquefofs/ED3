#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funcionalidades.h"


void funcionalidade1(){
    FILE *fe = NULL , *fp = NULL, *fip = NULL;
    char aEntrada[30], aPessoa[30], aIndxPessoa[30];
    char aux;

    scanf("%s", aEntrada);
    scanf("%s", aPessoa);
    scanf("%s", aIndxPessoa);

    fe = fopen(aEntrada, "r");
	if(fe == NULL){
		printf("Falha no carregamento do arquivo.");
		return;
	}

    fp = fopen(aPessoa, "wb");
	if(fp == NULL){
		printf("Falha no carregamento do arquivo.");
		return;
	}

    fip = fopen(aIndxPessoa, "wb");
	if(fip == NULL){
		printf("Falha no carregamento do arquivo.");
		return;
	}

    fread(&aux, sizeof(char), 1, fe);
    while (aux != '\n')
    {
        fread(&aux, sizeof(char), 1, fe);
    }



	
}

void funcionalidade2(){

}

void funcionalidade3(){

}

void funcionalidade4(){

}

void funcionalidade5(){

}
