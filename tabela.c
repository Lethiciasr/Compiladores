#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Simbolo *tabela_global = NULL;
int t_cont = 1; 

int l_cont = 1;

char* novo_label() {
    char *l = (char*) malloc(10);
    sprintf(l, "L%d", l_cont++);
    return l;
}

char declaracoes[5000] = "";
char instrucoes[5000] = "";
// Novo buffer global (junto com declaracoes e instrucoes)
char c_code_decl[5000] = "";   // declarações C (int x; float y; …)
char c_code_body[5000] = "";   // corpo C (atribuições, operações…)


// Insere um novo símbolo na tabela (lista encadeada)
char* novo_temp(Tipo tipo) {
    char *t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont++);
    
    char linha[50];
    switch(tipo) {
        case T_INT:   sprintf(linha, "int %s;\n", t); break;
        case T_FLOAT: sprintf(linha, "float %s;\n", t); break;
        case T_CHAR:  sprintf(linha, "char %s;\n", t); break;
        case T_BOOL:  sprintf(linha, "int %s; //mapeamento bool_int\n", t); break;
        case T_STRING: sprintf(linha, "char* %s;\n", t); break;
    }
    strcat(declaracoes, linha); 
    strcat(c_code_decl, linha);   // replica declaração no buffer C
    return t;
}

// Gera a instrução de cast e retorna o novo temporário
char* gerar_cast(char* temp_origem, Tipo tipo_destino) {
    char* t_destino = novo_temp(tipo_destino);
    char buf[100];
    const char* label_tipo = (tipo_destino == T_FLOAT) ? "float" : "int";

    sprintf(buf, "%s = (%s) %s;\n", t_destino, label_tipo, temp_origem);
    strcat(instrucoes, buf);
    return t_destino;
}
// Insere um novo símbolo na tabela (lista encadeada)
Simbolo* inserir(char *nome, Tipo tipo, int nivel) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    char *nome_t = novo_temp(tipo); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    novo->tipo = tipo;
    novo->nivel = nivel;
    novo->proximo = tabela_global;
    tabela_global = novo;
    return novo;
}
// Busca um símbolo na tabela pelo nome
Simbolo* buscar(char *nome) {
    Simbolo *atual = tabela_global;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void remover_simbolos_do_nivel(int nivel) {
    while (tabela_global != NULL && tabela_global->nivel == nivel) {
        Simbolo *remover = tabela_global;
        tabela_global = tabela_global->proximo;
        free(remover); // Libera a memória da variável local
    }
}