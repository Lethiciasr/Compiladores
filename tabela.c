#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Simbolo *tabela_global = NULL;

Simbolo* inserir(char *nome, Tipo tipo) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    
    // Gera um nome de temporário (ex: T1) para a variável e guarda nela
    char *nome_t = novo_temp();
    strcpy(novo->temp, nome_t); 
    free(nome_t); // Opcional, dependendo da sua gestão de memória

    novo->tipo = tipo;
    novo->proximo = tabela_global;
    tabela_global = novo;
    return novo;
}

Simbolo* buscar(char *nome) {
    Simbolo *aux = tabela_global;
    while(aux != NULL) {
        if(strcmp(aux->nome, nome) == 0) return aux;
        aux = aux->proximo;
    }
    return NULL;
}

int t_cont = 1;

char* novo_temp() {
    char *t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont++);
    return t;
} 