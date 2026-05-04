#ifndef YY_YY_SIN_TAB_H_INCLUDED
# define YY_YY_SIN_TAB_H_INCLUDED

/* debug   */
#ifndef YYDEBUG
# define YYDEBUG 0 /* caso ativado, vai ajudar a identificar e corrigir erros da gramatica */
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* token   */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype /* fundamental para o scanner, vai identificar os tokens, quando o analisador lexico identificar uma palavra do codigo,
   vai retornar um dos valores para o parser saber qual foi lido */
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    NUM_INT = 259,                 /* NUM_INT  */
    NUM_FLOAT = 260,               /* NUM_FLOAT  */
    CHAR_LIT = 261,                /* CHAR_LIT  */
    BOOL_LIT = 262,                /* BOOL_LIT  */
    TOKEN_INT = 263,               /* TOKEN_INT  */
    TOKEN_FLOAT = 264,             /* TOKEN_FLOAT  */
    TOKEN_CHAR = 265,              /* TOKEN_CHAR  */
    TOKEN_BOOL = 266,              /* TOKEN_BOOL  */
    ASSIGN = 267,                  /* ASSIGN  */
    PLUS = 268,                    /* PLUS  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    EQ = 271,                      /* EQ  */
    NE = 272,                      /* NE  */
    LE = 273,                      /* LE  */
    GE = 274,                      /* GE  */
    NOT = 275,                     /* NOT  */
    CAST = 276,                    /* CAST  */
    UMINUS = 277                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* valor que o token carrega */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "sin.y"

    char* valor_str;
    struct {
        char* temp;
        int tipo_val;
    } info; 

#line 94 "sin.tab.h"

};
typedef union YYSTYPE YYSTYPE; /* */
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SIN_TAB_H_INCLUDED  */
