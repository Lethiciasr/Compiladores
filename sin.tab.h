/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SIN_TAB_H_INCLUDED
# define YY_YY_SIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_FOR = 258,               /* TOKEN_FOR  */
    TOKEN_MAIN = 259,              /* TOKEN_MAIN  */
    ID = 260,                      /* ID  */
    NUM_INT = 261,                 /* NUM_INT  */
    NUM_FLOAT = 262,               /* NUM_FLOAT  */
    CHAR_LIT = 263,                /* CHAR_LIT  */
    BOOL_LIT = 264,                /* BOOL_LIT  */
    STRING_LIT = 265,              /* STRING_LIT  */
    TOKEN_INT = 266,               /* TOKEN_INT  */
    TOKEN_FLOAT = 267,             /* TOKEN_FLOAT  */
    TOKEN_CHAR = 268,              /* TOKEN_CHAR  */
    TOKEN_BOOL = 269,              /* TOKEN_BOOL  */
    TOKEN_STRING = 270,            /* TOKEN_STRING  */
    ASSIGN = 271,                  /* ASSIGN  */
    PLUS = 272,                    /* PLUS  */
    TOKEN_PRINT = 273,             /* TOKEN_PRINT  */
    TOKEN_READ = 274,              /* TOKEN_READ  */
    TOKEN_IF = 275,                /* TOKEN_IF  */
    TOKEN_ELSE = 276,              /* TOKEN_ELSE  */
    TOKEN_WHILE = 277,             /* TOKEN_WHILE  */
    TOKEN_DO = 278,                /* TOKEN_DO  */
    TOKEN_SWITCH = 279,            /* TOKEN_SWITCH  */
    TOKEN_CASE = 280,              /* TOKEN_CASE  */
    TOKEN_DEFAULT = 281,           /* TOKEN_DEFAULT  */
    TOKEN_BREAK = 282,             /* TOKEN_BREAK  */
    TOKEN_CONTINUE = 283,          /* TOKEN_CONTINUE  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    EQ = 286,                      /* EQ  */
    NE = 287,                      /* NE  */
    LE = 288,                      /* LE  */
    GE = 289,                      /* GE  */
    NOT = 290,                     /* NOT  */
    CAST = 291,                    /* CAST  */
    UMINUS = 292                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "sin.y"

    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        int tipo_val;
    } info;

#line 110 "sin.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SIN_TAB_H_INCLUDED  */
