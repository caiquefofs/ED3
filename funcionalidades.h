#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

typedef struct{
    char status;
    int quantidadePessoas;
    char lixo[64];
}Cab;

typedef struct{
    char removido;
    int idPessoa;
    char nomePessoa [40];
    int idadePessoa;
    char twitterPessoa [15];

}Dados;

typedef struct {
    Dados registro;
    NoDados *prox;
}NoDados;

typedef struct{
    char status;
    char lixo [7];
}indiceCab;

typedef struct{
    int idPessoa;
    int RRN;
}indiceDados;

typedef struct {
    indiceDados registro;
    NoIndex *prox;
}NoIndex;


void funcionalidade1();

void funcionalidade2();

void funcionalidade3();

void funcionalidade4();

void funcionalidade5();

#endif
