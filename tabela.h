#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL } Tipo;

// Estrutura do nó da tabela de símbolos (lista encadeada)
typedef struct Simbolo {
    char nome[50];
    char temp[10]; //codigo intermediario
    Tipo tipo;
    struct Simbolo *proximo;
} Simbolo;

// Funções de gerenciamento da tabela e variáveis temporárias
char* novo_temp(Tipo tipo); // gerar um novo nome de variavel temporaria
Simbolo* inserir(char *nome, Tipo tipo); //add uma nova variavel na tabela quando declarada
Simbolo* buscar(char *nome); // vê se a variavel ja foi declarada

// Nova função auxiliar para conversão de tipos
char* gerar_cast(char* temp_origem, Tipo tipo_destino);

// Buffers para armazenar o código intermediário gerado
extern char declaracoes[5000];
extern char instrucoes[5000];


#endif