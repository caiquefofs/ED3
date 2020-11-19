#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funcionalidades.h"
#include "fornecido.h"



void funcionalidade1(){
    FILE *fe = NULL , *fp = NULL, *fip = NULL, *nulo=NULL;
    int numPessoas = 0;
    char aEntrada[30], aPessoa[30], aIndxPessoa[30];
    char aux;
    Cab regCab;
    Dados regDados;
    indiceCab regICab;
    indiceDados *regID = NULL, *regIDAux;
    NoIndex *indiceDatHead = NULL, *indiceDat = NULL, *percorreIndiceDat = NULL, *indiceDatAux;

    indiceDatHead = (NoIndex *) malloc (sizeof(NoIndex));
    if(indiceDatHead == NULL){
        printf("Erro de alocacao.");
        return;
    }

    indiceDatHead->registro = NULL;
    indiceDatHead->prox = NULL; 

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
    fwrite(regICab.lixo, sizeof(char), 7, fip);

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
        fscanf(fe, "%[^,]", regDados.nomePessoa);
        fread(&aux, sizeof(char), 1, fe);
        fscanf(fe, "%d",&regDados.idadePessoa);
        fread(&aux, sizeof(char), 1, fe);
        fscanf(fe, "%[^\n]", regDados.twitterPessoa);
        fread(&aux, sizeof(char), 1, fe);
        regDados.removido = '1';

        fwrite(&regDados.removido, sizeof(char), 1, fp);
        fwrite(&regDados.idPessoa, sizeof(int), 1, fp);
        fwrite(&regDados.nomePessoa, sizeof(char), 40, fp);
        fwrite(&regDados.idadePessoa, sizeof(int), 1, fp);
        fwrite(&regDados.twitterPessoa, sizeof(char), 15, fp);

        regID = (indiceDados *) malloc (sizeof(indiceDados));                    //Aloca a estrutura do registrador do Indice de Dados

        if(regID == NULL){
            printf("Erro de alocacao.");
            return;
        }

        regID->idPessoa = regDados.idPessoa;
        regID->RRN = numPessoas;

        indiceDat = (NoIndex *) malloc (sizeof(NoIndex));
        if(indiceDat == NULL){
            printf("Erro de alocacao.");
            return;
        }

        indiceDat->prox = NULL;
        indiceDat->registro = regID;

        if(indiceDatHead->registro == NULL){
            indiceDatHead->registro = regID;
        }else
        {

            percorreIndiceDat = indiceDatHead;
            while (percorreIndiceDat->prox != NULL)
            {
                if(percorreIndiceDat->prox->registro->idPessoa < indiceDat->registro->idPessoa){
                    percorreIndiceDat = percorreIndiceDat->prox;
                }else{ 
                    break;
                }    
            }
            if (percorreIndiceDat->prox==NULL)
            {
                if(percorreIndiceDat->registro->idPessoa<indiceDat->registro->idPessoa){
                    percorreIndiceDat->prox=indiceDat;
                }else
                {
                    indiceDatAux = percorreIndiceDat->prox;
                    percorreIndiceDat->prox = indiceDat;
                    indiceDat->prox = indiceDatAux; 
                }
                
                
            }else{
                indiceDatAux = percorreIndiceDat->prox;
                percorreIndiceDat->prox = indiceDat;
                indiceDat->prox = indiceDatAux; 
            }               
        }
        
        numPessoas++;
    }

    percorreIndiceDat = indiceDatHead;
        
    while(percorreIndiceDat!=NULL){
        fwrite(&percorreIndiceDat->registro->idPessoa, sizeof(int), 1, fip);
        fwrite(&percorreIndiceDat->registro->RRN, sizeof(int), 1, fip);
        percorreIndiceDat = percorreIndiceDat->prox;
    }

    regCab.status = '1';
    regICab.status = '1';

    fseek(fp, 0, SEEK_SET);
    fseek(fip, 0, SEEK_SET);
    fwrite(&regCab.status, sizeof(char), 1, fp);
    fwrite(&numPessoas, sizeof(int), 1, fp);
    fwrite(&regICab.status, sizeof(char), 1, fip);

    fclose(fe);
    fclose(fp);
    fclose(fip);

    binarioNaTela1(aPessoa, aIndxPessoa);
	
}

void funcionalidade2(){

}

void funcionalidade3(){

}

void funcionalidade4(){

}

void funcionalidade5(){

}
