bruna
bru_na.
Não perturbar
Em voz






Opções

Opções

Opções
Sala de estudo 1





Jogar atividades aqui





Sala de estudo 1
Chat do canal Sala de estudo 1
29 de abril de 2026

bruna — 29/04/2026 22:00quarta-feira, 29 de abril de 2026 22:00
############
atribuicao : ID ASSIGN expressao {
    Simbolo s = buscar($1); // Ponteiro corrigido (do código 2)

    if (!s) {
        // Mensagem de erro informando o nome da variável (do código 2)
        char erro_msg[100];
        sprintf(erro_msg, "Erro: Variável '%s' não declarada.", $1);
        yyerror(erro_msg);
    } else {
        char valor_final = $3.temp; // Ponteiro corrigido (do código 1)
        int sem_erro = 1;

        // Conversão Implícita e Análise Semântica (do código 1)
        if (s->tipo == T_FLOAT && $3.tipo_val == T_INT) {
            valor_final = gerar_cast($3.temp, T_FLOAT); 
        } else if (s->tipo == T_INT && $3.tipo_val == T_FLOAT) {
            valor_final = gerar_cast($3.temp, T_INT);
        } else if (s->tipo != $3.tipo_val) {
            yyerror("Erro Semantico: Atribuicao com tipos incompativeis.");
            sem_erro = 0;
        }

        if (sem_erro) {
            // OBS: Mantive a impressão SEM o comentário "// Atribuicao para..."
            // que existia no código 2, para garantir que a sua saída continue
            // batendo 100% com o que o professor pediu no PDF!
            sprintf(buf, "%s = %s;\n", s->temp, valor_final);
            strcat(instrucoes, buf); 
        }
    }
};
[22:02]quarta-feira, 29 de abril de 2026 22:02
bison -d sin.y

lele — 29/04/2026 22:06quarta-feira, 29 de abril de 2026 22:06
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Expandir (177 linhas)
message.txt
message.txt (9 KB)
9 KB

bruna — 29/04/2026 22:08quarta-feira, 29 de abril de 2026 22:08
#######
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Expandir (249 linhas)
message.txt
message.txt (11 KB)
11 KB
Excluir
[22:09]quarta-feira, 29 de abril de 2026 22:09
oiiii leth
[22:10]quarta-feira, 29 de abril de 2026 22:10
kkkkkkkkkkkk
[22:10]quarta-feira, 29 de abril de 2026 22:10
sim
[22:10]quarta-feira, 29 de abril de 2026 22:10
muda tudo

lele — 29/04/2026 22:11quarta-feira, 29 de abril de 2026 22:11
sin.y: warning: 1 shift/reduce conflict [-Wconflicts-sr]
sin.y: note: rerun with option '-Wcounterexamples' to generate conflict counterexamples
:heart:
Clique para reagir
:arrow_up:
Clique para reagir
:thumbsup:
Clique para reagir
Adicionar reação
Responder
Encaminhar
Mais
[22:18]quarta-feira, 29 de abril de 2026 22:18
Erro: Var nao declarada
Erro: Erro: Vari├ível 'A' n├úo declarada.
Erro: syntax error
Codigo Intermediario:
int T1;
int T2;
int T3;
int T4;

T1 = 2;
T2 = ERRO + T1;
T3 = 3;
T4 = T2 * T3;
:heart:
Clique para reagir
:arrow_up:
Clique para reagir
:thumbsup:
Clique para reagir
Adicionar reação
Responder
Encaminhar
Mais
3 de maio de 2026

guiferrao — 21:16domingo, 3 de maio de 2026 21:16
sin.y
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Expandir (257 linhas)
message.txt
message.txt (12 KB)
12 KB
:heart:
Clique para reagir
:arrow_up:
Clique para reagir
:thumbsup:
Clique para reagir
Adicionar reação
Responder
Encaminhar
Mais
[21:16]domingo, 3 de maio de 2026 21:16
tabela.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Simbolo tabela_global = NULL;
int t_cont = 1; 

char declaracoes[5000] = "";
char instrucoes[5000] = "";

// Cria uma nova variável temporária e registra sua declaração
char novo_temp(Tipo tipo) {
    char t = (char) malloc(10);
    sprintf(t, "T%d", t_cont++);

    char linha[50];
    switch(tipo) {
        case T_INT:   sprintf(linha, "int %s;\n", t); break;
        case T_FLOAT: sprintf(linha, "float %s;\n", t); break;
        case T_CHAR:  sprintf(linha, "char %s;\n", t); break;
        case T_BOOL:  sprintf(linha, "int %s; //mapeamento bool_int\n", t); break;
    }
    strcat(declaracoes, linha); 

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
Simbolo* inserir(char nome, Tipo tipo) {
    Simbolonovo = (Simbolo) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    charnome_t = novo_temp(tipo); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    novo->tipo = tipo;
    novo->proximo = tabela_global;
    tabela_global = novo;
    return novo;
}

// Busca um símbolo na tabela pelo nome
Simbolo* buscar(char nome) {
    Simboloatual = tabela_global;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
        atual = atual->proximo;
    }
    return NULL;
}
:heart:
Clique para reagir
:arrow_up:
Clique para reagir
:thumbsup:
Clique para reagir
Adicionar reação
Responder
Encaminhar
Mais
NOVO
[21:16]domingo, 3 de maio de 2026 21:16
tabela.h

#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL } Tipo;

// Estrutura do nó da tabela de símbolos (lista encadeada)
typedef struct Simbolo {
    char nome[50];
    char temp[10];
    Tipo tipo;
    struct Simbolo proximo;
} Simbolo;

// Funções de gerenciamento da tabela e variáveis temporárias
char novo_temp(Tipo tipo); 
Simbolo* inserir(char nome, Tipo tipo);
Simbolo buscar(char nome);
char gerar_cast(char* temp_origem, Tipo tipo_destino);

// Buffers para armazenar o código intermediário gerado
extern char declaracoes[5000]; 
extern char instrucoes[5000]; 


#endif
:heart:
Clique para reagir
:arrow_up:
Clique para reagir
:thumbsup:
Clique para reagir
Adicionar reação
Responder
Encaminhar
Mais

Conversar em Sala de estudo 1
﻿
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

extern int yylex();
void yyerror(const char *s) { printf("Erro: %s\n", s); }

char buf[200];
%}

// Define os tipos de dados que os tokens e as regras da gramática podem armazenar.
%union {
    char* valor_str;
    struct {
        char* temp;
        int tipo_val;
    } info; 
}

// Definição dos tokens e da precedência/associatividade dos operadores.
%token <valor_str> ID NUM_INT NUM_FLOAT CHAR_LIT BOOL_LIT
%token TOKEN_INT TOKEN_FLOAT TOKEN_CHAR TOKEN_BOOL ASSIGN PLUS
%token AND OR EQ NE LE GE NOT

%left OR
%left AND
%left EQ NE '<' '>' LE GE
%left PLUS '-'
%left '*' '/'
%right NOT
%right CAST
%right UMINUS

// Associa a regra 'expressao' ao tipo 'info' definido no %union.
%type <info> expressao

// Início das regras gramaticais e ações semânticas do analisador sintático.
%%

// Estrutura base do programa contendo múltiplos comandos.
programa : comandos ;

comandos : comando comandos | ;

comando : declaracao ';' 
        | atribuicao ';' 
        | expressao ';' ;

// Regras para declaração de variáveis e inserção na tabela de símbolos.
declaracao : TOKEN_INT ID    { inserir($2, T_INT); }
           | TOKEN_FLOAT ID  { inserir($2, T_FLOAT); }
           | TOKEN_CHAR ID   { inserir($2, T_CHAR); }
           | TOKEN_BOOL ID   { inserir($2, T_BOOL); };

// Regras de atribuição com validação semântica de tipos e geração de coerção implícita.
atribuicao : ID ASSIGN expressao {
    Simbolo *s = buscar($1); 
    if (!s) {
        char erro_msg[100];
        sprintf(erro_msg, "Erro: Variável '%s' não declarada.", $1);
        yyerror(erro_msg);
    } else {
        char* valor_final = $3.temp;
        int sem_erro = 1;
        
        // Conversão Implícita na Atribuição (Coerção)
        if (s->tipo == T_FLOAT && $3.tipo_val == T_INT) {
            valor_final = gerar_cast($3.temp, T_FLOAT); 
        } else if (s->tipo == T_INT && $3.tipo_val == T_FLOAT) {
            valor_final = gerar_cast($3.temp, T_INT);
        } else if (s->tipo != $3.tipo_val) {
            yyerror("Erro Semantico: Atribuicao com tipos incompativeis.");
            sem_erro = 0;
        }
        
        if (sem_erro) {
            sprintf(buf, "%s = %s;\n", s->temp, valor_final);
            strcat(instrucoes, buf); 
        }
    }
};

// Resolução de literais básicos e busca de variáveis para expressões.
expressao : NUM_INT { 
                $$.tipo_val = T_INT; 
                $$.temp = novo_temp(T_INT); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf); 
            }
          | NUM_FLOAT { 
                $$.tipo_val = T_FLOAT; 
                $$.temp = novo_temp(T_FLOAT); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf); 
            }
          | CHAR_LIT { 
                $$.tipo_val = T_CHAR; 
                $$.temp = novo_temp(T_CHAR); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf);
            }
          | BOOL_LIT { 
                $$.tipo_val = T_BOOL; 
                $$.temp = novo_temp(T_BOOL); 
                sprintf(buf, "%s = %s;\n", $$.temp, $1); 
                strcat(instrucoes, buf);
            }
          | ID { 
                Simbolo *s = buscar($1); 
                if(s) { 
                    $$.tipo_val = s->tipo; 
                    $$.temp = s->temp; 
                } else { 
                    yyerror("Var nao declarada");
                    $$.temp = "ERRO"; 
                    $$.tipo_val = T_INT;
                } 
            }
          
          // Operações aritméticas com validação e coerção automática de tipos.
          | expressao PLUS expressao { 
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) || ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de soma com tipos invalidos.");
                } else {
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                        else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val); 
                    sprintf(buf, "%s = %s + %s;\n", $$.temp, $1.temp, $3.temp); 
                    strcat(instrucoes, buf);
                }
            }
          | expressao '-' expressao { 
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) || ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de subtracao com tipos invalidos.");
                } else {
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                        else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val); 
                    sprintf(buf, "%s = %s - %s;\n", $$.temp, $1.temp, $3.temp); 
                    strcat(instrucoes, buf); 
                }
            }
          | expressao '*' expressao { 
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) || ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de multiplicacao com tipos invalidos.");
                } else {
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                        else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val); 
                    sprintf(buf, "%s = %s * %s;\n", $$.temp, $1.temp, $3.temp); 
                    strcat(instrucoes, buf); 
                }
            }
          | expressao '/' expressao { 
                if (($1.tipo_val != T_INT && $1.tipo_val != T_FLOAT) || ($3.tipo_val != T_INT && $3.tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de divisao com tipos invalidos.");
                } else {
                    if ($1.tipo_val != $3.tipo_val) {
                        if ($1.tipo_val == T_INT) { $1.temp = gerar_cast($1.temp, T_FLOAT); $1.tipo_val = T_FLOAT; }
                        else { $3.temp = gerar_cast($3.temp, T_FLOAT); $3.tipo_val = T_FLOAT; }
                    }
                    $$.tipo_val = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    $$.temp = novo_temp($$.tipo_val); 
                    sprintf(buf, "%s = %s / %s;\n", $$.temp, $1.temp, $3.temp); 
                    strcat(instrucoes, buf); 
                }
            }

          // Operações relacionais (geram resultados booleanos).
          | expressao EQ expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s == %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao NE expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s != %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao '>' expressao { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s > %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao '<' expressao { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s < %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao GE expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s >= %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }
          | expressao LE expressao  { $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); sprintf(buf, "%s = %s <= %s;\n", $$.temp, $1.temp, $3.temp); strcat(instrucoes, buf); }

          // Operações lógicas com validação estrita de operandos booleanos.
          | expressao AND expressao { 
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador AND requer operandos booleanos.");
                } else {
                    $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); 
                    sprintf(buf, "%s = %s && %s;\n", $$.temp, $1.temp, $3.temp); 
                    strcat(instrucoes, buf); 
                }
            }
          | expressao OR expressao  { 
                if ($1.tipo_val != T_BOOL || $3.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador OR requer operandos booleanos.");
                } else {
                    $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); 
                    sprintf(buf, "%s = %s || %s;\n", $$.temp, $1.temp, $3.temp); 
                    strcat(instrucoes, buf); 
                }
            }
          | NOT expressao           { 
                if ($2.tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador NOT requer operando booleano.");
                } else {
                    $$.tipo_val = T_BOOL; $$.temp = novo_temp(T_BOOL); 
                    sprintf(buf, "%s = !%s;\n", $$.temp, $2.temp); 
                    strcat(instrucoes, buf); 
                }
            }
          
          // Regras para conversão explícita de tipos (Casts) e agrupamento.
          | '(' TOKEN_INT ')' expressao %prec CAST { 
                char* temp_copia = novo_temp($4.tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, $4.temp);
                strcat(instrucoes, buf);

                $$.tipo_val = T_INT;   
                $$.temp = novo_temp(T_INT);
                sprintf(buf, "%s = (int) %s;\n", $$.temp, temp_copia);
                strcat(instrucoes, buf);
            }
          | '(' TOKEN_FLOAT ')' expressao %prec CAST { 
                char* temp_copia = novo_temp($4.tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, $4.temp);
                strcat(instrucoes, buf);

                $$.tipo_val = T_FLOAT; 
                $$.temp = novo_temp(T_FLOAT);
                sprintf(buf, "%s = (float) %s;\n", $$.temp, temp_copia);
                strcat(instrucoes, buf);
            }
          | '(' expressao ')' { $$ = $2; }
          
          // Operador unário de negação (ex: -x).
          | '-' expressao %prec UMINUS { 
                $$.tipo_val = $2.tipo_val; 
                $$.temp = novo_temp($$.tipo_val); 
                sprintf(buf, "%s = -%s;\n", $$.temp, $2.temp); 
                strcat(instrucoes, buf); 
            }
          ;

%%

// Função principal que inicia o parser e exibe o código intermediário gerado.
int main() {
    yyparse();
    printf("Codigo Intermediario:\n");
    printf("%s\n%s", declaracoes, instrucoes);   
    return 0;
}
