/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sin.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabela.h"

int houve_erro = 0;
extern int yylex();
void yyerror(const char *s) {printf("Erro: %s\n", s);
houve_erro = 1;
}

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

int escopo_atual = 0;

#line 98 "sin.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sin.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_FOR = 3,                  /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_MAIN = 4,                 /* TOKEN_MAIN  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_NUM_INT = 6,                    /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 7,                  /* NUM_FLOAT  */
  YYSYMBOL_CHAR_LIT = 8,                   /* CHAR_LIT  */
  YYSYMBOL_BOOL_LIT = 9,                   /* BOOL_LIT  */
  YYSYMBOL_STRING_LIT = 10,                /* STRING_LIT  */
  YYSYMBOL_TOKEN_INT = 11,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 12,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_CHAR = 13,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_BOOL = 14,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 15,              /* TOKEN_STRING  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 17,                      /* PLUS  */
  YYSYMBOL_TOKEN_PRINT = 18,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_READ = 19,                /* TOKEN_READ  */
  YYSYMBOL_TOKEN_IF = 20,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 21,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 22,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 23,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_SWITCH = 24,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 25,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 26,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_BREAK = 27,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 28,            /* TOKEN_CONTINUE  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_LE = 33,                        /* LE  */
  YYSYMBOL_GE = 34,                        /* GE  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_CAST = 41,                      /* CAST  */
  YYSYMBOL_UMINUS = 42,                    /* UMINUS  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_programa = 50,                  /* programa  */
  YYSYMBOL_declaracoes_globais = 51,       /* declaracoes_globais  */
  YYSYMBOL_bloco = 52,                     /* bloco  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_comandos_bloco = 54,            /* comandos_bloco  */
  YYSYMBOL_if_cond = 55,                   /* if_cond  */
  YYSYMBOL_incremento_for = 56,            /* incremento_for  */
  YYSYMBOL_casos_lista = 57,               /* casos_lista  */
  YYSYMBOL_caso = 58,                      /* caso  */
  YYSYMBOL_59_2 = 59,                      /* @2  */
  YYSYMBOL_default_caso = 60,              /* default_caso  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_comando = 62,                   /* comando  */
  YYSYMBOL_63_4 = 63,                      /* @4  */
  YYSYMBOL_64_5 = 64,                      /* @5  */
  YYSYMBOL_65_6 = 65,                      /* @6  */
  YYSYMBOL_66_7 = 66,                      /* @7  */
  YYSYMBOL_67_8 = 67,                      /* @8  */
  YYSYMBOL_68_9 = 68,                      /* @9  */
  YYSYMBOL_69_10 = 69,                     /* $@10  */
  YYSYMBOL_declaracao = 70,                /* declaracao  */
  YYSYMBOL_atribuicao = 71,                /* atribuicao  */
  YYSYMBOL_expressao = 72                  /* expressao  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    39,     2,     2,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    45,
      36,     2,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    65,    66,    69,    69,    75,    76,    80,
      97,   109,   110,   111,   114,   114,   147,   147,   154,   155,
     156,   157,   158,   175,   203,   209,   209,   234,   243,   234,
     267,   267,   289,   298,   289,   333,   333,   350,   360,   371,
     376,   381,   386,   391,   398,   434,   441,   448,   455,   462,
     469,   484,   511,   538,   565,   594,   609,   624,   639,   654,
     669,   686,   700,   714,   729,   741,   753,   756
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_FOR",
  "TOKEN_MAIN", "ID", "NUM_INT", "NUM_FLOAT", "CHAR_LIT", "BOOL_LIT",
  "STRING_LIT", "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_CHAR", "TOKEN_BOOL",
  "TOKEN_STRING", "ASSIGN", "PLUS", "TOKEN_PRINT", "TOKEN_READ",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_DO", "TOKEN_SWITCH",
  "TOKEN_CASE", "TOKEN_DEFAULT", "TOKEN_BREAK", "TOKEN_CONTINUE", "AND",
  "OR", "EQ", "NE", "LE", "GE", "NOT", "'<'", "'>'", "'-'", "'*'", "'/'",
  "CAST", "UMINUS", "'('", "')'", "';'", "'{'", "'}'", "':'", "$accept",
  "programa", "declaracoes_globais", "bloco", "$@1", "comandos_bloco",
  "if_cond", "incremento_for", "casos_lista", "caso", "@2", "default_caso",
  "$@3", "comando", "@4", "@5", "@6", "@7", "@8", "@9", "$@10",
  "declaracao", "atribuicao", "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,     5,     8,    10,    11,    25,    55,    52,    18,   -42,
     -42,   -42,   -42,   -42,   -42,    21,    47,    22,   -42,    19,
     -42,   -42,   107,    26,    54,   -42,   -42,   -42,   -42,   -42,
      28,    29,    31,   -42,   -42,    32,    23,    33,    38,    38,
      14,   -42,    30,   107,   107,    37,    39,   150,    80,    38,
      38,    81,    38,    44,   107,    38,   -42,   -42,   -42,   -42,
     -42,    46,    48,   186,   -42,    67,   -42,   -42,   -42,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,   -42,    54,    49,   294,   204,    53,   222,    38,    69,
     240,    38,    38,   -42,   -42,   -35,   322,   312,   -11,   -11,
     -11,   -11,   -11,   -11,   -35,   -42,   -42,   -42,    50,    56,
     -42,   258,    57,   -42,   -42,   -42,   107,    38,   -42,   -42,
     -42,    38,    59,   -42,   168,   107,   276,   -17,   -42,   -42,
      58,    38,    61,    76,   -17,   -42,    91,   -42,   126,   -42,
     -42,   -42,    82,    62,   -42,   107,    38,   107,   107,   -42,
     294,   -42,    72,    79,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     1,     0,     4,     0,     3,     0,
       5,     2,     8,     0,    50,    45,    46,    47,    48,    49,
       0,     0,     0,    27,    30,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    50,    63,
      67,     0,     0,     0,     6,    24,     7,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    25,    51,    61,    62,    55,    56,
      60,    59,    58,    57,    52,    53,    54,    32,     0,     0,
       9,     0,     0,    35,    64,    65,     0,     0,    22,    23,
      28,     0,     0,    26,     0,     0,     0,    13,    33,    29,
       0,     0,     0,     0,    13,    12,     0,    31,     0,    16,
      36,    11,     0,     0,    14,     8,     0,     0,     0,    17,
      10,    34,     0,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,    86,   109,   -42,   -41,   -42,   -42,    -2,   -42,
     -42,   -42,   -42,   -36,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,    51,    85,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    41,    22,    42,    43,   143,   133,   134,
     148,   135,   145,    44,   116,    53,   125,    54,   117,   136,
     122,    45,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    60,    63,    66,    79,    80,    69,    65,   131,   132,
       9,    84,    85,    10,    87,    11,    12,    90,    89,    58,
      25,    26,    27,    28,    29,    61,    62,    78,    79,    80,
      13,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    58,    25,    26,    27,    28,    29,    38,
     111,     8,    39,   114,   115,    14,    15,    40,     1,     2,
       3,     4,     5,    16,    17,    20,    19,     8,    56,    48,
      49,    50,    51,    38,    52,    55,    39,    64,    57,   124,
     123,    40,    67,   126,    68,    82,    86,    88,    94,   129,
      91,   112,    92,   138,   107,   118,   142,   109,   146,   153,
     121,   119,    18,   137,   149,   127,   147,   152,   150,   139,
      23,   151,    24,    25,    26,    27,    28,    29,     1,     2,
       3,     4,     5,   140,   154,    30,    31,    32,    21,    33,
      34,    35,   141,    83,    36,    37,     0,     0,     0,     0,
       0,     0,    38,    69,     0,    39,     0,     0,     0,     0,
      40,     0,     0,    20,     0,    70,    71,    72,    73,    74,
      75,     0,    76,    77,    78,    79,    80,    69,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    69,    76,    77,    78,    79,
      80,     0,     0,     0,     0,    81,     0,    70,    71,    72,
      73,    74,    75,    69,    76,    77,    78,    79,    80,     0,
       0,     0,     0,   128,     0,    70,    71,    72,    73,    74,
      75,    69,    76,    77,    78,    79,    80,     0,     0,     0,
      93,     0,     0,    70,    71,    72,    73,    74,    75,    69,
      76,    77,    78,    79,    80,     0,     0,     0,   108,     0,
       0,    70,    71,    72,    73,    74,    75,    69,    76,    77,
      78,    79,    80,     0,     0,     0,   110,     0,     0,    70,
      71,    72,    73,    74,    75,    69,    76,    77,    78,    79,
      80,     0,     0,     0,   113,     0,     0,    70,    71,    72,
      73,    74,    75,    69,    76,    77,    78,    79,    80,     0,
       0,     0,   120,     0,     0,    70,    71,    72,    73,    74,
      75,    69,    76,    77,    78,    79,    80,     0,     0,     0,
     130,     0,     0,    70,    71,    72,    73,    74,    75,    69,
      76,    77,    78,    79,    80,     0,     0,     0,     0,    69,
       0,    70,     0,    72,    73,    74,    75,     0,    76,    77,
      78,    79,    80,    72,    73,    74,    75,     0,    76,    77,
      78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      38,    39,    40,    44,    39,    40,    17,    43,    25,    26,
       5,    49,    50,     5,    52,     5,     5,    55,    54,     5,
       6,     7,     8,     9,    10,    11,    12,    38,    39,    40,
       5,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     5,     6,     7,     8,     9,    10,    35,
      88,     0,    38,    91,    92,     0,     4,    43,    11,    12,
      13,    14,    15,    45,    43,    46,    44,    16,    45,    43,
      16,    43,    43,    35,    43,    43,    38,    47,    45,   117,
     116,    43,    45,   121,    45,     5,     5,    43,    21,   125,
      44,    22,    44,   131,    45,    45,     5,    44,    16,    27,
      43,    45,    16,    45,   145,    46,    44,   148,   146,    48,
       3,   147,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    47,    45,    18,    19,    20,    19,    22,
      23,    24,   134,    48,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    17,    -1,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    17,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    -1,    29,    30,    31,
      32,    33,    34,    17,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    -1,    29,    30,    31,    32,    33,
      34,    17,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      44,    -1,    -1,    29,    30,    31,    32,    33,    34,    17,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    -1,
      -1,    29,    30,    31,    32,    33,    34,    17,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    -1,    -1,    29,
      30,    31,    32,    33,    34,    17,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    -1,    -1,    29,    30,    31,
      32,    33,    34,    17,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    -1,    -1,    29,    30,    31,    32,    33,
      34,    17,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      44,    -1,    -1,    29,    30,    31,    32,    33,    34,    17,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    17,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    50,    51,    70,     5,
       5,     5,     5,     5,     0,     4,    45,    43,    51,    44,
      46,    52,    53,     3,     5,     6,     7,     8,     9,    10,
      18,    19,    20,    22,    23,    24,    27,    28,    35,    38,
      43,    52,    54,    55,    62,    70,    71,    72,    43,    16,
      43,    43,    43,    64,    66,    43,    45,    45,     5,    72,
      72,    11,    12,    72,    47,    62,    54,    45,    45,    17,
      29,    30,    31,    32,    33,    34,    36,    37,    38,    39,
      40,    45,     5,    71,    72,    72,     5,    72,    43,    62,
      72,    44,    44,    44,    21,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    45,    44,    44,
      44,    72,    22,    44,    72,    72,    63,    67,    45,    45,
      44,    43,    69,    62,    72,    65,    72,    46,    45,    62,
      44,    25,    26,    57,    58,    60,    68,    45,    72,    48,
      47,    57,     5,    56,    48,    61,    16,    44,    59,    54,
      72,    62,    54,    27,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    53,    52,    54,    54,    55,
      56,    57,    57,    57,    59,    58,    61,    60,    62,    62,
      62,    62,    62,    62,    62,    63,    62,    64,    65,    62,
      66,    62,    67,    68,    62,    69,    62,    62,    62,    70,
      70,    70,    70,    70,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     0,     4,     2,     0,     4,
       3,     2,     1,     0,     0,     7,     0,     4,     2,     2,
       2,     1,     5,     5,     2,     0,     5,     0,     0,     7,
       0,     8,     0,     0,    11,     0,     8,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     4,     4,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* $@1: %empty  */
#line 69 "sin.y"
            { escopo_atual++; }
#line 1296 "sin.tab.c"
    break;

  case 6: /* bloco: '{' $@1 comandos_bloco '}'  */
#line 69 "sin.y"
                                                   {
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
        }
#line 1305 "sin.tab.c"
    break;

  case 9: /* if_cond: TOKEN_IF '(' expressao ')'  */
#line 80 "sin.y"
                                     {
    if ((yyvsp[-1].info).tipo_val != T_BOOL) {
        yyerror("Erro Semantico: A condicao do 'if' deve ser booleana.");
    }
    char* l_false = novo_label();
    
    sprintf(buf, "ifFalse %s goto %s;\n", (yyvsp[-1].info).temp, l_false);
    strcat(instrucoes, buf);
    
    sprintf(buf, "if (%s) {\n", (yyvsp[-1].info).c_expr);
    strcat(c_body, buf);
    
    (yyval.valor_str) = l_false; /* Passa o label pra frente */
}
#line 1324 "sin.tab.c"
    break;

  case 10: /* incremento_for: ID ASSIGN expressao  */
#line 97 "sin.y"
                                     {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
    } else {
        // Guarda o código em vez de imprimir direto nos buffers principais
        sprintf(inc_3ac, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        sprintf(inc_c, "%s = %s;\n", s->nome, (yyvsp[0].info).c_expr);
    }
}
#line 1339 "sin.tab.c"
    break;

  case 14: /* @2: %empty  */
#line 114 "sin.y"
                                {
        // 1. Gera rótulo pro próximo case (se este falhar)
        char* l_proximo = novo_label();
        
        // 2. Compara a expressão do Switch com a expressão do Case
        char* t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t_cmp, switch_exp, (yyvsp[-1].info).temp);
        strcat(instrucoes, buf);
        
        // 3. Se falso, pula pro próximo case
        sprintf(buf, "ifFalse %s goto %s;\n", t_cmp, l_proximo);
        strcat(instrucoes, buf);
        
        // 4. Código C
        sprintf(buf, "case %s:\n", (yyvsp[-1].info).c_expr);
        strcat(c_body, buf);
        
        (yyval.valor_str) = l_proximo; // Salva o l_proximo em $4
        
    }
#line 1364 "sin.tab.c"
    break;

  case 15: /* caso: TOKEN_CASE expressao ':' @2 comandos_bloco TOKEN_BREAK ';'  */
#line 133 "sin.y"
                                     {
        // 5. Fim do case: pula pro fim do switch (break do 3AC)
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);
        
        // 6. Imprime o rótulo do próximo case (recupera de $4)
        sprintf(buf, "%s:\n", (yyvsp[-3].valor_str));
        strcat(instrucoes, buf);
        
        // 7. Break do C
        strcat(c_body, "break;\n");
    }
#line 1381 "sin.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 147 "sin.y"
                                 {
        strcat(c_body, "default:\n");
    }
#line 1389 "sin.tab.c"
    break;

  case 17: /* default_caso: TOKEN_DEFAULT ':' $@3 comandos_bloco  */
#line 149 "sin.y"
                     {
        // O default não precisa de break nem de desvios no 3AC, ele só termina.
    }
#line 1397 "sin.tab.c"
    break;

  case 22: /* comando: TOKEN_PRINT '(' expressao ')' ';'  */
#line 158 "sin.y"
                                            {
            // 1. Gera o Código Intermediário (3AC)
            sprintf(buf, "print %s;\n", (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);

            // 2. Descobre o formato para o printf do C
            char* formato = "";
            if ((yyvsp[-2].info).tipo_val == T_INT || (yyvsp[-2].info).tipo_val == T_BOOL) formato = "%d";
            else if ((yyvsp[-2].info).tipo_val == T_FLOAT) formato = "%f";
            else if ((yyvsp[-2].info).tipo_val == T_CHAR) formato = "%c";
            else if ((yyvsp[-2].info).tipo_val == T_STRING) formato = "%s";

            // 3. Gera o Código C
            sprintf(buf, "printf(\"%s\\n\", %s);\n", formato, (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
        }
#line 1418 "sin.tab.c"
    break;

  case 23: /* comando: TOKEN_READ '(' ID ')' ';'  */
#line 175 "sin.y"
                                    {
            Simbolo *s = buscar((yyvsp[-2].valor_str));
            if (!s) {
                char erro_msg[100];
                sprintf(erro_msg, "Erro: Variavel '%s' nao declarada para leitura.", (yyvsp[-2].valor_str));
                yyerror(erro_msg);
            } else {
                // 1. Gera o Código Intermediário (3AC)
                sprintf(buf, "read %s;\n", s->nome); 
                strcat(instrucoes, buf);

                // 2. Descobre o formato para o scanf do C
                char* formato = "";
                if (s->tipo == T_INT || s->tipo == T_BOOL) formato = "%d";
                else if (s->tipo == T_FLOAT) formato = "%f";
                else if (s->tipo == T_CHAR) formato = " %c"; 

                // 3. Gera o Código C 
                if (s->tipo == T_STRING) {
                    sprintf(buf, "%s = (char*) malloc(256);\n", s->nome);
                    strcat(c_body, buf);
                    sprintf(buf, "scanf(\"%%s\", %s);\n", s->nome);
                } else {
                    sprintf(buf, "scanf(\"%s\", &%s);\n", formato, s->nome);
                }
                strcat(c_body, buf);
            }
        }
#line 1451 "sin.tab.c"
    break;

  case 24: /* comando: if_cond comando  */
#line 203 "sin.y"
                          {
            // IF SIMPLES (Sem else)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); // Puxa o rótulo do if_cond
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1462 "sin.tab.c"
    break;

  case 25: /* @4: %empty  */
#line 209 "sin.y"
                                     {
            // METADE DO ELSE
            char* l_fim = novo_label();
            
            // 1. O 'true' pula pro fim
            sprintf(buf, "goto %s;\n", l_fim);
            strcat(instrucoes, buf);
            
            // 2. Imprime o label do 'false' (que veio do if_cond)
            sprintf(buf, "%s:\n", (yyvsp[-2].valor_str));
            strcat(instrucoes, buf);
            
            // 3. Código C
            strcat(c_body, "} else {\n");
            
            // Passa o label de fim para o próximo bloco
            (yyval.valor_str) = l_fim; 
            
        }
#line 1486 "sin.tab.c"
    break;

  case 26: /* comando: if_cond comando TOKEN_ELSE @4 comando  */
#line 227 "sin.y"
                  {
            // FIM DO ELSE
            // Imprime o label de fim (que veio do bloco anterior)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1498 "sin.tab.c"
    break;

  case 27: /* @5: %empty  */
#line 234 "sin.y"
                      {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; 
            
            // --- LINHA NOVA 1: Salva o início na pilha ---
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        }
#line 1513 "sin.tab.c"
    break;

  case 28: /* @6: %empty  */
#line 243 "sin.y"
                            {
            if ((yyvsp[-1].info).tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao deve ser booleana.");
            
            char* l_fim = novo_label();
            sprintf(buf, "ifFalse %s goto %s;\n", (yyvsp[-1].info).temp, l_fim);
            strcat(instrucoes, buf);
            sprintf(buf, "while (%s) {\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
            (yyval.valor_str) = l_fim; 
            
            // --- LINHAS NOVAS 2 e 3: Salva o fim e sobe a pilha ---
            strcpy(pilha_fim[topo_laco], l_fim);
            topo_laco++; 
            
        }
#line 1533 "sin.tab.c"
    break;

  case 29: /* comando: TOKEN_WHILE @5 '(' expressao ')' @6 comando  */
#line 257 "sin.y"
                  {
            // --- LINHA NOVA 4: Desce a pilha pois o laço acabou ---
            topo_laco--; 
            
            sprintf(buf, "goto %s;\n", (yyvsp[-5].valor_str)); 
            strcat(instrucoes, buf);
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1548 "sin.tab.c"
    break;

  case 30: /* @7: %empty  */
#line 267 "sin.y"
                   {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio;
            strcat(c_body, "do {\n");
        }
#line 1560 "sin.tab.c"
    break;

  case 31: /* comando: TOKEN_DO @7 comando TOKEN_WHILE '(' expressao ')' ';'  */
#line 273 "sin.y"
                                                    {
            // Agora a expressao é o $6, porque:
            // 1=TOKEN_DO, 2={...}, 3=comando, 4=WHILE, 5='(', 6=expressao
            
            if ((yyvsp[-2].info).tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'do-while' deve ser booleana.");
            }
            
            // Pula para o início se for verdadeiro
            sprintf(buf, "if %s goto %s;\n", (yyvsp[-2].info).temp, (yyvsp[-6].valor_str));
            strcat(instrucoes, buf);
            
            // Código C
            sprintf(buf, "} while (%s);\n", (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
        }
#line 1581 "sin.tab.c"
    break;

  case 32: /* @8: %empty  */
#line 289 "sin.y"
                                       {
            // 1. A inicialização já foi impressa pela 'atribuicao'.
            
            // 2. Marca o rótulo de INÍCIO
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; // Salva na posição $5
            
        }
#line 1596 "sin.tab.c"
    break;

  case 33: /* @9: %empty  */
#line 298 "sin.y"
                        {
            // 3. Verifica a CONDIÇÃO
            if ((yyvsp[-1].info).tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'for' deve ser booleana.");
            }
            char* l_fim = novo_label();
            sprintf(buf, "ifFalse %s goto %s;\n", (yyvsp[-1].info).temp, l_fim);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_fim; // Salva na posição $8
            
            // Converte o FOR num WHILE no código C gerado (mesma semântica!)
            sprintf(buf, "while (%s) {\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
            
        }
#line 1616 "sin.tab.c"
    break;

  case 34: /* comando: TOKEN_FOR '(' atribuicao ';' @8 expressao ';' @9 incremento_for ')' comando  */
#line 312 "sin.y"
                                     {
            // 4. Chegamos no final do laço!
            
            // Imprime o incremento que estava "guardado"
            strcat(instrucoes, inc_3ac);
            
            // Imprime o incremento no C
            sprintf(buf, "%s", inc_c);
            strcat(c_body, buf);
            
            // Pula de volta pro início
            sprintf(buf, "goto %s;\n", (yyvsp[-6].valor_str));
            strcat(instrucoes, buf);
            
            // Marca o rótulo de FIM
            sprintf(buf, "%s:\n", (yyvsp[-3].valor_str));
            strcat(instrucoes, buf);
            
            // Fecha a chave no C
            strcat(c_body, "}\n");
        }
#line 1642 "sin.tab.c"
    break;

  case 35: /* $@10: %empty  */
#line 333 "sin.y"
                                         {
            // 1. Salva a variável avaliada e gera o rótulo de saída
            strcpy(switch_exp, (yyvsp[-1].info).temp);
            strcpy(switch_fim, novo_label());
            
            // 2. Código C
            sprintf(buf, "switch (%s) {\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
            
        }
#line 1657 "sin.tab.c"
    break;

  case 36: /* comando: TOKEN_SWITCH '(' expressao ')' $@10 '{' casos_lista '}'  */
#line 342 "sin.y"
                              {
            // 3. Fim do Switch: imprime o rótulo de saída
            sprintf(buf, "%s:\n", switch_fim);
            strcat(instrucoes, buf);
            
            strcat(c_body, "}\n");
        }
#line 1669 "sin.tab.c"
    break;

  case 37: /* comando: TOKEN_BREAK ';'  */
#line 350 "sin.y"
                          {
            if (topo_laco == 0) {
                yyerror("Erro Semantico: 'break' usado fora de um laco de repeticao.");
            } else {
                // Pula para o rótulo de FIM do laço atual
                sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
                strcat(instrucoes, buf);
                strcat(c_body, "break;\n");
            }
        }
#line 1684 "sin.tab.c"
    break;

  case 38: /* comando: TOKEN_CONTINUE ';'  */
#line 360 "sin.y"
                             {
            if (topo_laco == 0) {
                yyerror("Erro Semantico: 'continue' usado fora de um laco de repeticao.");
            } else {
                // Pula para o rótulo de INÍCIO do laço atual
                sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
                strcat(instrucoes, buf);
                strcat(c_body, "continue;\n");
            }
        }
#line 1699 "sin.tab.c"
    break;

  case 39: /* declaracao: TOKEN_INT ID  */
#line 371 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1709 "sin.tab.c"
    break;

  case 40: /* declaracao: TOKEN_FLOAT ID  */
#line 376 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1719 "sin.tab.c"
    break;

  case 41: /* declaracao: TOKEN_CHAR ID  */
#line 381 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1729 "sin.tab.c"
    break;

  case 42: /* declaracao: TOKEN_BOOL ID  */
#line 386 "sin.y"
                           {
                 inserir((yyvsp[0].valor_str), T_BOOL, escopo_atual);
                 sprintf(buf, "bool %s;\n", (yyvsp[0].valor_str));
                 strcat(c_decl, buf);
             }
#line 1739 "sin.tab.c"
    break;

  case 43: /* declaracao: TOKEN_STRING ID  */
#line 391 "sin.y"
                              {
                inserir((yyvsp[0].valor_str), T_STRING, escopo_atual);
                sprintf(buf, "char* %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1749 "sin.tab.c"
    break;

  case 44: /* atribuicao: ID ASSIGN expressao  */
#line 398 "sin.y"
                                 {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        char erro_msg[100];
        sprintf(erro_msg, "Erro: Variavel '%s' nao declarada.", (yyvsp[-2].valor_str));
        yyerror(erro_msg);
    } else {
        char* valor_final  = (yyvsp[0].info).temp;
        char* c_expr_final = (yyvsp[0].info).c_expr;
        int sem_erro = 1;

        if (s->tipo == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) {
            valor_final = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
            char *tmp = (char*) malloc(strlen(c_expr_final) + 16);
            sprintf(tmp, "(float)(%s)", c_expr_final);
            c_expr_final = tmp;
        } else if (s->tipo == T_INT && (yyvsp[0].info).tipo_val == T_FLOAT) {
            valor_final = gerar_cast((yyvsp[0].info).temp, T_INT);
            char *tmp = (char*) malloc(strlen(c_expr_final) + 16);
            sprintf(tmp, "(int)(%s)", c_expr_final);
            c_expr_final = tmp;
        } else if (s->tipo != (yyvsp[0].info).tipo_val) {
            yyerror("Erro Semantico: Atribuicao com tipos incompativeis.");
            sem_erro = 0;
        }

        if (sem_erro) {
            sprintf(buf, "%s = %s;\n", s->temp, valor_final);
            strcat(instrucoes, buf);

            sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
            strcat(c_body, buf);
        }
    }
}
#line 1789 "sin.tab.c"
    break;

  case 45: /* expressao: NUM_INT  */
#line 434 "sin.y"
                    {
                (yyval.info).tipo_val = T_INT;
                (yyval.info).temp   = novo_temp(T_INT);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1801 "sin.tab.c"
    break;

  case 46: /* expressao: NUM_FLOAT  */
#line 441 "sin.y"
                      {
                (yyval.info).tipo_val = T_FLOAT;
                (yyval.info).temp   = novo_temp(T_FLOAT);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1813 "sin.tab.c"
    break;

  case 47: /* expressao: CHAR_LIT  */
#line 448 "sin.y"
                     {
                (yyval.info).tipo_val = T_CHAR;
                (yyval.info).temp   = novo_temp(T_CHAR);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1825 "sin.tab.c"
    break;

  case 48: /* expressao: BOOL_LIT  */
#line 455 "sin.y"
                     {
                (yyval.info).tipo_val = T_BOOL;
                (yyval.info).temp   = novo_temp(T_BOOL);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1837 "sin.tab.c"
    break;

  case 49: /* expressao: STRING_LIT  */
#line 462 "sin.y"
                         {
                (yyval.info).tipo_val = T_STRING;
                (yyval.info).temp   = novo_temp(T_STRING);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1849 "sin.tab.c"
    break;

  case 50: /* expressao: ID  */
#line 469 "sin.y"
               {
                Simbolo *s = buscar((yyvsp[0].valor_str));
                if (s) {
                    (yyval.info).tipo_val = s->tipo;
                    (yyval.info).temp   = s->temp;
                    (yyval.info).c_expr = strdup(s->nome);
                } else {
                    yyerror("Var nao declarada");
                    (yyval.info).temp   = "ERRO";
                    (yyval.info).c_expr = strdup("ERRO");
                    (yyval.info).tipo_val = T_INT;
                }
            }
#line 1867 "sin.tab.c"
    break;

  case 51: /* expressao: expressao PLUS expressao  */
#line 484 "sin.y"
                                     {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de soma com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    if ((yyvsp[-2].info).tipo_val != (yyvsp[0].info).tipo_val) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT); (yyvsp[-2].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT); (yyvsp[0].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s + %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s + %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
            }
#line 1899 "sin.tab.c"
    break;

  case 52: /* expressao: expressao '-' expressao  */
#line 511 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de subtracao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    if ((yyvsp[-2].info).tipo_val != (yyvsp[0].info).tipo_val) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT); (yyvsp[-2].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT); (yyvsp[0].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s - %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s - %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
            }
#line 1931 "sin.tab.c"
    break;

  case 53: /* expressao: expressao '*' expressao  */
#line 538 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de multiplicacao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    if ((yyvsp[-2].info).tipo_val != (yyvsp[0].info).tipo_val) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT); (yyvsp[-2].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT); (yyvsp[0].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s * %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s * %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
            }
#line 1963 "sin.tab.c"
    break;

  case 54: /* expressao: expressao '/' expressao  */
#line 565 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de divisao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    if ((yyvsp[-2].info).tipo_val != (yyvsp[0].info).tipo_val) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT); (yyvsp[-2].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce1) + 16);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT); (yyvsp[0].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(strlen(ce3) + 16);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s / %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen(ce1) + strlen(ce3) + 8);
                    sprintf(ce, "(%s / %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
            }
#line 1995 "sin.tab.c"
    break;

  case 55: /* expressao: expressao EQ expressao  */
#line 594 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val == T_BOOL && (yyvsp[0].info).tipo_val != T_BOOL) ||
                    ((yyvsp[-2].info).tipo_val != T_BOOL && (yyvsp[0].info).tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '==' entre tipos incompativeis.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s == %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s == %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2015 "sin.tab.c"
    break;

  case 56: /* expressao: expressao NE expressao  */
#line 609 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val == T_BOOL && (yyvsp[0].info).tipo_val != T_BOOL) ||
                    ((yyvsp[-2].info).tipo_val != T_BOOL && (yyvsp[0].info).tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '!=' entre tipos incompativeis.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s != %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s != %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2035 "sin.tab.c"
    break;

  case 57: /* expressao: expressao '>' expressao  */
#line 624 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s > %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s > %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2055 "sin.tab.c"
    break;

  case 58: /* expressao: expressao '<' expressao  */
#line 639 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s < %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s < %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2075 "sin.tab.c"
    break;

  case 59: /* expressao: expressao GE expressao  */
#line 654 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>=' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s >= %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s >= %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2095 "sin.tab.c"
    break;

  case 60: /* expressao: expressao LE expressao  */
#line 669 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<=' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s <= %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s <= %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2115 "sin.tab.c"
    break;

  case 61: /* expressao: expressao AND expressao  */
#line 686 "sin.y"
                                    {
                if ((yyvsp[-2].info).tipo_val != T_BOOL || (yyvsp[0].info).tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador AND requer operandos booleanos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s && %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s && %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2134 "sin.tab.c"
    break;

  case 62: /* expressao: expressao OR expressao  */
#line 700 "sin.y"
                                   {
                if ((yyvsp[-2].info).tipo_val != T_BOOL || (yyvsp[0].info).tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador OR requer operandos booleanos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s || %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 8);
                    sprintf(ce, "(%s || %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2153 "sin.tab.c"
    break;

  case 63: /* expressao: NOT expressao  */
#line 714 "sin.y"
                          {
                if ((yyvsp[0].info).tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador NOT requer operando booleano.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = !%s;\n", (yyval.info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 4);
                    sprintf(ce, "(!%s)", (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 2172 "sin.tab.c"
    break;

  case 64: /* expressao: '(' TOKEN_INT ')' expressao  */
#line 729 "sin.y"
                                                   {
                char* temp_copia = novo_temp((yyvsp[0].info).tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, (yyvsp[0].info).temp);
                strcat(instrucoes, buf);
                (yyval.info).tipo_val = T_INT;
                (yyval.info).temp = novo_temp(T_INT);
                sprintf(buf, "%s = (int) %s;\n", (yyval.info).temp, temp_copia);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 16);
                sprintf(ce, "(int)(%s)", (yyvsp[0].info).c_expr);
                (yyval.info).c_expr = ce;
            }
#line 2189 "sin.tab.c"
    break;

  case 65: /* expressao: '(' TOKEN_FLOAT ')' expressao  */
#line 741 "sin.y"
                                                     {
                char* temp_copia = novo_temp((yyvsp[0].info).tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, (yyvsp[0].info).temp);
                strcat(instrucoes, buf);
                (yyval.info).tipo_val = T_FLOAT;
                (yyval.info).temp = novo_temp(T_FLOAT);
                sprintf(buf, "%s = (float) %s;\n", (yyval.info).temp, temp_copia);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 16);
                sprintf(ce, "(float)(%s)", (yyvsp[0].info).c_expr);
                (yyval.info).c_expr = ce;
            }
#line 2206 "sin.tab.c"
    break;

  case 66: /* expressao: '(' expressao ')'  */
#line 753 "sin.y"
                              {
                (yyval.info) = (yyvsp[-1].info);
            }
#line 2214 "sin.tab.c"
    break;

  case 67: /* expressao: '-' expressao  */
#line 756 "sin.y"
                                       {
                (yyval.info).tipo_val = (yyvsp[0].info).tipo_val;
                (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                sprintf(buf, "%s = -%s;\n", (yyval.info).temp, (yyvsp[0].info).temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 4);
                sprintf(ce, "(-%s)", (yyvsp[0].info).c_expr);
                (yyval.info).c_expr = ce;
            }
#line 2228 "sin.tab.c"
    break;


#line 2232 "sin.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 767 "sin.y"


int main() {
    yyparse();

    if (houve_erro) {
        return 1;
    }

    /* Codigo Intermediario */
    printf("=== Codigo Intermediario ===\n");
    printf("%s\n%s\n", declaracoes, instrucoes);

    /* Codigo C */
    printf("=== Codigo C ===\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdbool.h>\n\n");
    printf("int main() {\n");

    char tmp1[5000], tmp2[5000];

    strcpy(tmp1, c_decl);
    for (char *l = strtok(tmp1, "\n"); l; l = strtok(NULL, "\n"))
        printf("    %s\n", l);

    printf("\n");

    strcpy(tmp2, c_body);
    for (char *l = strtok(tmp2, "\n"); l; l = strtok(NULL, "\n"))
        printf("    %s\n", l);

    printf("    return 0;\n}\n");
    return 0;
}
