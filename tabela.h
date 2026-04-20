#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL } Tipo;

typedef struct Simbolo {
    char nome[50];
    char temp[10];
    Tipo tipo;
    struct Simbolo *proximo;
} Simbolo;

char* novo_temp(Tipo tipo); 
Simbolo* inserir(char *nome, Tipo tipo);
Simbolo* buscar(char *nome);

extern char declaracoes[5000];
extern char instrucoes[5000];

#endif