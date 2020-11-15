#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H


typedef struct Cab{
    char status;
    int quantidadePessoas;
    char lixo[59];
}Cab;

typedef struct Dados{
    char removido;
    int idPessoa;
    char nomePessoa [40];
    int idadePessoa;
    char twitterPessoa [15];

}Dados;

typedef struct NoDados{
    Dados registro;
    NoDados *prox;
}NoDados;

typedef struct indiceCab{
    char status;
    char lixo [7];
}indiceCab;

typedef struct indiceDados{
    int idPessoa;
    int RRN;
}indiceDados;

typedef struct NoIndex{
    indiceDados registro;
    NoIndex *prox;
}NoIndex;


void funcionalidade1();

void funcionalidade2();

void funcionalidade3();

void funcionalidade4();

void funcionalidade5();

#endif
