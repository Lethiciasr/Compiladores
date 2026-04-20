#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL } Tipo;

typedef struct Simbolo {
    char nome[50];
    char temp[10]; 
    Tipo tipo;
    struct Simbolo *proximo;
} Simbolo;

Simbolo* inserir(char *nome, Tipo tipo);
Simbolo* buscar(char *nome);
char* novo_temp(); 

#endif