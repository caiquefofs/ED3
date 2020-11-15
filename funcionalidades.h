#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

typedef struct Cab Cab;
typedef struct Dados Dados;
typedef struct NoDados NoDados;
typedef struct indiceCab indiceCab;
typedef struct indiceDados indiceDados;
typedef struct NoIndex NoIndex;

struct Cab{
    char status;
    int quantidadePessoas;
    char lixo[59];
};

struct Dados{
    char removido;
    int idPessoa;
    char nomePessoa [40];
    int idadePessoa;
    char twitterPessoa [15];

};

struct NoDados{
    Dados registro;
    NoDados *prox;
};

struct indiceCab{
    char status;
    char lixo [7];
};

struct indiceDados{
    int idPessoa;
    int RRN;
};

struct NoIndex{
    indiceDados *registro;
    NoIndex *prox;
};


void funcionalidade1();

void funcionalidade2();

void funcionalidade3();

void funcionalidade4();

void funcionalidade5();

#endif
