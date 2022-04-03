#include<stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void iniciar_lista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

void inserirPrimeiroValor(Lista *lista, int valor) {
    No *novoNo = malloc(sizeof(No));

    if (!novoNo) {
        printf("Erro ao criar novo nó\n");
        return;
    }

    novoNo->valor = valor;
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
    lista->fim = novoNo;
    lista->fim->proximo = lista->inicio;
    lista->tamanho++;
}

void inserir(Lista *lista, int valor) {
    No *novoNo = malloc(sizeof(No));

    if (!novoNo) {
        printf("Erro ao criar novo nó\n");
    } else {
        novoNo->valor = valor;
        if (lista->tamanho == 0) {
            inserirPrimeiroValor(lista, valor);
        } else {
            if(lista->inicio == NULL){
                lista->inicio = novoNo;
                lista->fim = novoNo;
                lista->fim->proximo = lista->inicio;
            }else{
                lista->fim->proximo = novoNo;
                lista->fim = novoNo;
                novoNo->proximo = lista->inicio;
            }
            lista->tamanho ++;
        }
    }
}

No *buscar(Lista *lista, int valor) {
    No *aux = lista->inicio;

    if (aux) {
        do {
            if (aux->valor == valor) {
                return aux;
            }
            aux = aux->proximo;
        } while (aux != lista->inicio);
    }
    return NULL;
}

void exibir(Lista lista) {
    No *no = lista.inicio;
    printf("=========================");
    printf("\nTamanho: %d \n", lista.tamanho);
    printf("Lista: ");
    if (no) {
        do {
            printf("%d ", no->valor);
            no = no->proximo;
        } while (no != lista.inicio);
        printf("\nInicio: %d\n",no->valor);
        printf("Fim: %d\n",lista.fim->valor);
    }
    printf("=========================");

    printf("\n\n");
}

int main() {
    int opcao, valor;
    No *retornado;
    Lista lista;

    iniciar_lista(&lista);

    do {
        printf("\n\t1 - inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir(&lista, valor);
                break;
            case 2:
                exibir(lista);
                break;
            case 3:
                printf("Digite o valor que deseja buscar: ");
                scanf("%d", &valor);
                retornado = buscar(&lista, valor);
                if (retornado)
                    printf("No encontrado: %d\n", retornado->valor);
                else
                    printf("No nao encontrado! %d\n");
                break;
            default:
                if (opcao != 0)
                    printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}
