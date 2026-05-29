#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL, T_STRING } Tipo;

typedef struct Simbolo {
    char nome[50];
    char temp[10];
    Tipo tipo;
    int nivel;             // Adicionado para controle de escopo
    struct Simbolo *proximo; // Mantém a lista encadeada
} Simbolo;

// Protótipos de Funções
char* novo_temp(Tipo tipo);
char* novo_label();

// Gestão de Tabela e Escopo
Simbolo* inserir(char *nome, Tipo tipo);
Simbolo* buscar(char *nome);
void entrar_escopo();
void sair_escopo();
char* gerar_cast(char* temp_origem, Tipo tipo_destino);

// Variáveis Globais (definidas no tabela.c)
extern char instrucoes[5000];
extern char c_decl[5000];
extern char c_body[5000];

#endif