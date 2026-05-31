# Nome do executável final
TARGET = compilador.exe

# Arquivos fonte
LEX_FILE = lexica.l
YACC_FILE = sin.y
TABLE_FILE = tabela.c

# Arquivos gerados
LEX_OUT = lex.yy.c
YACC_OUT = sin.tab.c
YACC_HDR = sin.tab.h

# Arquivos do compilador C que o seu compilador gera
SAIDA_C = saida.c
PROG_EXE = programa.exe

# Compilador e flags
CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall

# Regra principal
all: $(TARGET)

# Linkagem final
$(TARGET): $(LEX_OUT) $(YACC_OUT) $(TABLE_FILE)
	$(CC) $(CFLAGS) $^ -o $@

# Geração do código C a partir do Bison
$(YACC_OUT) $(YACC_HDR): $(YACC_FILE)
	$(YACC) -d $(YACC_FILE)

# Geração do código C a partir do Flex
$(LEX_OUT): $(LEX_FILE) $(YACC_HDR)
	$(LEX) $(LEX_FILE)

# Limpeza de todos os arquivos gerados (incluindo os da execução)
clean:
	rm -f $(TARGET) $(LEX_OUT) $(YACC_OUT) $(YACC_HDR) $(SAIDA_C) $(PROG_EXE)

# Executar com arquivo de teste (já limpa os arquivos anteriores antes de rodar)
run: all
	./$(TARGET) < exemplo.txt