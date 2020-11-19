#include <stdio.h>
#include <string.h> 
#include "funcionalidades.h"
#include "fornecido.h"

int main(){
    FILE * entrada;
    FILE * pessoa;
    FILE * index;

    int funcionalidade;
    
    scanf("%d", &funcionalidade);

    switch (funcionalidade)
    {
    case 1:
        funcionalidade1();
        break;
    case 2:
        funcionalidade2();
        break;
    case 3:
        funcionalidade3();
        break;
    case 4:
        funcionalidade4();
        break;
    case 5:
        funcionalidade5();
        break;

    default:
        printf("Opcao invalida!");
        break;
    }

    return 0;

}