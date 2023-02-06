#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"BBT_ABP.c"

int main (){
    NO *raiz;
    int opcao;
    char letra;
    inicializar(&raiz);

    do{
        printf("Selecione uma das opcoes abaixo:  \n");
        printf("1 - Inserir um novo elemento na ABP \n");
        printf("2 - Remover um elemento da ABP \n");
        printf("3 - Exibir os elementos em pre-ordem \n");
        printf("4 - Exibir a quantidade de elementos \n");
        printf("5 - Sair \n");

        printf("--> ");

        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            fflush(stdin);
                printf("Digite uma letra: \n");
                scanf("%c", &letra);
                enserir(&raiz,letra);
            break;
        case 2:
                printf("Digite a letra a ser removida\n");
                fflush(stdin);
                scanf("%c", &letra);
                raiz=remover(raiz,letra);
            break;
        case 3:
                printf("Impressao: \n");
                exibir_preordem(raiz);
                printf("\n");
            break;
        case 4:
            printf("Quantidade de elementos: %d\n", quantidade_elem(raiz));
            break;
        default:
             printf("Saindo do programa");
            break;
        }

    }while(opcao!=5);

return 0;

}
