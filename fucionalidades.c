#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funcionalidades.h"



void funcionalidade1(){
    FILE *fe = NULL , *fp = NULL, *fip = NULL;
    int numPessoas = 0;
    char aEntrada[30], aPessoa[30], aIndxPessoa[30];
    char aux;
    Cab regCab;
    Dados regDados;
    indiceCab regICab;
    indiceDados *regID = NULL, *regIDAux;
    NoIndex *indiceDat = NULL, *indiceDatAux;

    indiceDat = (NoIndex *) malloc (sizeof(NoIndex));
    if(indiceDat == NULL){
        printf("Erro de alocacao.");
        return;
    }

    /*
    regID = (indiceDados *) malloc (sizeof(indiceDados));
    if(regID == NULL){
        printf("Erro de alocacao.");
        return;
    }*/

    //regID->idPessoa = -1;
    //regID->RRN = -1;

    //indiceDat->registro = regID;
    //indiceDat->prox = NULL;

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

    regICab.status = '0';
    for(int i=0; i<8; i++){
        regICab.lixo[i]='$';
    }
   
    regCab.status = '0';
    regCab.quantidadePessoas = 0;
    for(int i=0; i<59; i++){
        regCab.lixo[i]='$';
    }
    
    fwrite(&regICab.status, sizeof(char), 1, fip);
    fwrite(regICab.lixo, sizeof(char), 8, fip);

    fwrite(&regCab.status, sizeof(char), 1, fp);
    fwrite(&regCab.quantidadePessoas, sizeof(int), 1, fp);
    fwrite(regCab.lixo, sizeof(char), 59, fp);

    while (1){
        if((fscanf(fe, "%d",&regDados.idPessoa))==EOF){
            break;
        }

        for(int i=0; i<40; i++){
            regDados.nomePessoa[i]='$';
        }
        for(int i=0; i<15; i++){
            regDados.twitterPessoa[i]='$';
        }

        fread(&aux, sizeof(char), 1, fe);
        fscanf(fe, "%[^,]", &regDados.nomePessoa);
        fscanf(fe, "%d",&regDados.idadePessoa);
        fread(&aux, sizeof(char), 1, fe);
        fscanf(fe, "%[^,]", &regDados.twitterPessoa);
        fread(&aux, sizeof(char), 1, fe);
        regDados.removido = '1';

        fwrite(&regDados.removido, sizeof(char), 1, fp);
        fwrite(&regDados.idPessoa, sizeof(int), 1, fp);
        fwrite(&regDados.nomePessoa, sizeof(char), 40, fp);
        fwrite(&regDados.idadePessoa, sizeof(int), 1, fp);
        fwrite(&regDados.twitterPessoa, sizeof(char), 15, fp);

        regID = (indiceDados *) malloc (sizeof(indiceDados));

        if(regID == NULL){
            printf("Erro de alocacao.");
            return;
        }

        

        regID->idPessoa = regDados.idPessoa;
        regID->RRN = numPessoas;


        numPessoas++;


    
    };
    
    
    
    
    


	
}

void funcionalidade2(){

}

void funcionalidade3(){

}

void funcionalidade4(){

}

void funcionalidade5(){

}
