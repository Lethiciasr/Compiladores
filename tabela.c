#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

// Variáveis de controle
Simbolo *tabela_global = NULL; // Início da nossa lista (escopo mais recente)
int t_cont = 1; 
int l_cont = 1; 
int nivel_atual = 0;

// Strings para geração de código
char instrucoes[5000] = "";
char c_decl[5000] = "";
char c_body[5000] = "";

char* novo_temp(Tipo tipo) {
    char *t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont++);
    
    char linha[50];
    switch(tipo) {
        case T_INT:    sprintf(linha, "int %s;\n", t); break;
        case T_FLOAT:  sprintf(linha, "float %s;\n", t); break;
        case T_CHAR:   sprintf(linha, "char %s;\n", t); break;
        case T_BOOL:   sprintf(linha, "int %s;\n", t); break;
        case T_STRING: sprintf(linha, "char* %s;\n", t); break;
    }
    strcat(c_decl, linha); 
    return t;
}

char* novo_label() {
    char *l = (char*) malloc(10);
    sprintf(l, "L%d", l_cont++);
    return l;
}

char* gerar_cast(char* temp_origem, Tipo tipo_destino) {
    char* t_destino = novo_temp(tipo_destino);
    char buf[100];
    const char* label_tipo = (tipo_destino == T_FLOAT) ? "float" : "int";
    sprintf(buf, "%s = (%s) %s;\n", t_destino, label_tipo, temp_origem);
    strcat(instrucoes, buf);
    return t_destino;
}

Simbolo* inserir(char *nome, Tipo tipo) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    
    // Gerar temp e guardar
    char *nome_t = novo_temp(tipo); 
    strcpy(novo->temp, nome_t);
    free(nome_t);
    
    novo->tipo = tipo;
    novo->nivel = nivel_atual; // Registra o escopo atual
    
    // Insere no início da lista (sombreamento automático)
    novo->proximo = tabela_global;
    tabela_global = novo;
    
    return novo;
}

Simbolo* buscar(char* nome) {
    Simbolo *atual = tabela_global;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual; // Encontra a variável mais próxima no escopo
        }
        atual = atual->proximo;
    }
    return NULL;
}

void entrar_escopo() {
    nivel_atual++;
}

void sair_escopo() {
    // Remove todos os símbolos que pertencem ao nível que está fechando
    while (tabela_global != NULL && tabela_global->nivel == nivel_atual) {
        Simbolo *temp = tabela_global;
        tabela_global = tabela_global->proximo;
        free(temp);
    }
    nivel_atual--;
}