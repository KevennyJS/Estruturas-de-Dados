#include "funcoes.h"

int main(){
    NO *lista, *copia, *busca;
    lista = criarLista();
    int num;

    while(1==1){
        printf("\n\t************ Lista **************\n\t");
        mostrarLista(lista);

        printf("\n\t************ MENU **************\n");
        printf("\t  [0] - SAIR\n");
        printf("\t  [1] - Inserir no Inicio\n");
        printf("\t  [2] - Inserir no Fim\n");
        printf("\t  [3] - Inserir Ordenado\n");
        printf("\t  [4] - Exibir\n");
        printf("\t  [5] - Quantidade de Elemento\n");
        printf("\t  [6] - Remover Elemento\n");
        printf("\t  [7] - Liberar Memoria \n");
        printf("\t*********************************\n");
        int op_menu;
        printf("\tEscolha uma opcao: ");
        scanf("%d", &op_menu);

        switch (op_menu){
            case 0:
                exit(1);
            case 1:
                printf("Número a inserir: ");
                scanf("%d",&num);
                lista = inserirInicio(lista, num);
                break;
            case 2:
                printf("Número a inserir: ");
                scanf("%d", &num);
                lista = inserirFinal(lista, num);
                break;
            case 3:
                printf("Número a inserir: ");
                scanf("%d", &num);
                lista = inserirOrdenado(lista, num);
                break;
            case 4:
                mostrarLista(lista);
                break;
            case 5:
                printf("Número de Elementos: %d", qtdElementos(lista));
                break;
            case 6:
                printf("Número a remover: ");
                scanf("%d", &num);
                lista = removerElemento(lista,num);
                break;
            case 7:
                apagar(lista);
                lista = criarLista();
                break;
            default:
                printf(" -- Opção Invalida --\n");
                break;
        }
    }

    return 0;
}