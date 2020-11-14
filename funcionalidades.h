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

typedef struct{
    char status;
    char lixo [7];
}indiceCab;

typedef struct{
    int idPessoa;
    int RRN;
}indiceDados;

void funcionalidade1();

void funcionalidade2();

void funcionalidade3();

void funcionalidade4();

void funcionalidade5();

#endif
