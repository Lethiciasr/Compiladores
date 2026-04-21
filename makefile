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

# Compilador e flags
CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall

# Regra principal (executada ao digitar 'make')
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

# Limpeza de arquivos temporários
clean:
	rm -f $(TARGET) $(LEX_OUT) $(YACC_OUT) $(YACC_HDR)

# Executar com arquivo de teste
run: all
	./$(TARGET) < exemplo.txt