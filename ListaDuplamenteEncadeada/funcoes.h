#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;

NO *criarLista();

NO *inserirInicio(NO *lista, int v);

NO *inserirFinal(NO *lista, int v);

NO *inserirOrdenado(NO *lista, int v);

void mostrarLista(NO *lista);

int qtdElementos(NO *lista);

NO* removerElemento(NO *lista, int valor);

void apagar(NO *lista);