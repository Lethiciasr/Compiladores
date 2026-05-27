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
#include "tabela.h"

extern int yylex();
void yyerror(const char *s) { printf("Erro: %s\n", s); }

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

#line 94 "sin.tab.c"

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
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_NUM_INT = 5,                    /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 6,                  /* NUM_FLOAT  */
  YYSYMBOL_CHAR_LIT = 7,                   /* CHAR_LIT  */
  YYSYMBOL_BOOL_LIT = 8,                   /* BOOL_LIT  */
  YYSYMBOL_STRING_LIT = 9,                 /* STRING_LIT  */
  YYSYMBOL_TOKEN_INT = 10,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 11,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_CHAR = 12,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_BOOL = 13,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 14,              /* TOKEN_STRING  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_TOKEN_PRINT = 17,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_READ = 18,                /* TOKEN_READ  */
  YYSYMBOL_TOKEN_IF = 19,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 20,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 21,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 22,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_SWITCH = 23,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 24,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 25,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_BREAK = 26,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 27,            /* TOKEN_CONTINUE  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_CAST = 40,                      /* CAST  */
  YYSYMBOL_UMINUS = 41,                    /* UMINUS  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ':'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_programa = 49,                  /* programa  */
  YYSYMBOL_comandos = 50,                  /* comandos  */
  YYSYMBOL_bloco = 51,                     /* bloco  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_comandos_bloco = 53,            /* comandos_bloco  */
  YYSYMBOL_if_cond = 54,                   /* if_cond  */
  YYSYMBOL_incremento_for = 55,            /* incremento_for  */
  YYSYMBOL_casos_lista = 56,               /* casos_lista  */
  YYSYMBOL_caso = 57,                      /* caso  */
  YYSYMBOL_58_2 = 58,                      /* @2  */
  YYSYMBOL_default_caso = 59,              /* default_caso  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_comando = 61,                   /* comando  */
  YYSYMBOL_62_4 = 62,                      /* @4  */
  YYSYMBOL_63_5 = 63,                      /* @5  */
  YYSYMBOL_64_6 = 64,                      /* @6  */
  YYSYMBOL_65_7 = 65,                      /* @7  */
  YYSYMBOL_66_8 = 66,                      /* @8  */
  YYSYMBOL_67_9 = 67,                      /* @9  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_declaracao = 69,                /* declaracao  */
  YYSYMBOL_atribuicao = 70,                /* atribuicao  */
  YYSYMBOL_expressao = 71                  /* expressao  */
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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   376

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      44,    45,    38,     2,     2,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    47,
      35,     2,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    56,    56,    58,    58,    64,    65,    69,
      86,    98,    99,   100,   103,   103,   136,   136,   143,   144,
     145,   146,   147,   164,   192,   198,   198,   223,   232,   223,
     256,   256,   278,   287,   278,   322,   322,   339,   349,   360,
     365,   370,   375,   380,   387,   423,   430,   437,   444,   451,
     458,   473,   500,   527,   554,   583,   598,   613,   628,   643,
     658,   675,   689,   703,   718,   730,   742,   745
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_FOR", "ID",
  "NUM_INT", "NUM_FLOAT", "CHAR_LIT", "BOOL_LIT", "STRING_LIT",
  "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_CHAR", "TOKEN_BOOL", "TOKEN_STRING",
  "ASSIGN", "PLUS", "TOKEN_PRINT", "TOKEN_READ", "TOKEN_IF", "TOKEN_ELSE",
  "TOKEN_WHILE", "TOKEN_DO", "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_DEFAULT",
  "TOKEN_BREAK", "TOKEN_CONTINUE", "AND", "OR", "EQ", "NE", "LE", "GE",
  "NOT", "'<'", "'>'", "'-'", "'*'", "'/'", "CAST", "UMINUS", "'{'", "'}'",
  "'('", "')'", "':'", "';'", "$accept", "programa", "comandos", "bloco",
  "$@1", "comandos_bloco", "if_cond", "incremento_for", "casos_lista",
  "caso", "@2", "default_caso", "$@3", "comando", "@4", "@5", "@6", "@7",
  "@8", "@9", "$@10", "declaracao", "atribuicao", "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,   -38,    -8,   -79,   -79,   -79,   -79,   -79,     4,     5,
       6,     9,    11,   -28,   -27,   -26,   -79,   -79,   -25,   -24,
     -22,   128,   128,   -79,   117,    20,   -79,   -79,    73,    73,
     -20,   -16,   147,    17,   128,   -79,   -79,   -79,   -79,   -79,
     128,    18,   128,   -11,    73,   128,   -79,   -79,   -79,   -79,
     -79,    73,    -9,    19,   219,   -79,    14,   -79,   -79,   -79,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   -79,    -8,    16,    10,   237,    21,   255,   128,
      46,   273,    -6,    73,   128,   128,   -79,   -79,   -37,   337,
     327,   102,   102,   102,   102,   102,   102,   -37,   -79,   -79,
     -79,    23,    24,   -79,   291,    28,   -79,   -79,   -79,   -79,
     -79,    73,   128,   -79,   -79,   -79,   128,    26,   -79,   171,
      73,   309,   -21,   -79,   -79,    41,   128,    27,    50,   -21,
     -79,    85,   -79,   195,   -79,   -79,   -79,    82,    53,   -79,
      73,   128,    73,    73,   -79,    10,   -79,    75,    56,   -79
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,    50,    45,    46,    47,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    30,     0,     0,
       0,     0,     0,     5,     0,     0,     2,    21,     0,     4,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,    37,    38,    50,    63,
      67,     8,     0,     0,     0,     1,    24,     3,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    66,    25,    51,    61,
      62,    55,    56,    60,    59,    58,    57,    52,    53,    54,
      32,     0,     0,     9,     0,     0,    35,     6,     7,    64,
      65,     0,     0,    22,    23,    28,     0,     0,    26,     0,
       0,     0,    13,    33,    29,     0,     0,     0,     0,    13,
      12,     0,    31,     0,    16,    36,    11,     0,     0,    14,
       8,     0,     0,     0,    17,    10,    34,     0,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,    76,   -79,   -79,   -78,   -79,   -79,   -17,   -79,
     -79,   -79,   -79,     0,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,    71,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    51,    82,    28,   138,   128,   129,
     143,   130,   140,    83,   111,    43,   120,    44,   112,   131,
     117,    30,    31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,    70,    71,   126,   127,   108,    33,    34,    35,    36,
      37,    49,    50,    38,    54,    39,    40,    41,    42,    45,
      55,    73,    77,    46,    75,    47,    60,    58,    56,    29,
      76,    59,    78,    79,    87,    81,    84,   107,    61,    62,
      63,    64,    65,    66,    80,    67,    68,    69,    70,    71,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   144,   100,    85,   147,   102,   105,   122,   104,
     113,   114,   116,   134,   109,   110,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   132,   137,
      13,    14,    15,   135,    16,    17,    18,   141,   142,    19,
      20,   148,   119,   149,    74,    57,   121,    21,     0,     0,
      22,   118,   136,     0,     0,    23,   133,    24,    60,     0,
     124,    48,     3,     4,     5,     6,     7,    52,    53,     0,
       0,   145,    48,     3,     4,     5,     6,     7,     0,    69,
      70,    71,   146,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,    22,     0,     0,     0,     0,     0,
       0,    24,    21,    60,     0,    22,     0,     0,     0,     0,
       0,     0,    24,     0,     0,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    60,     0,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,    61,
      62,    63,    64,    65,    66,     0,    67,    68,    69,    70,
      71,    60,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    60,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    60,    67,    68,    69,    70,    71,     0,
       0,     0,     0,     0,    86,    61,    62,    63,    64,    65,
      66,    60,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,   101,    61,    62,    63,    64,    65,    66,    60,
      67,    68,    69,    70,    71,     0,     0,     0,     0,     0,
     103,    61,    62,    63,    64,    65,    66,    60,    67,    68,
      69,    70,    71,     0,     0,     0,     0,     0,   106,    61,
      62,    63,    64,    65,    66,    60,    67,    68,    69,    70,
      71,     0,     0,     0,     0,     0,   115,    61,    62,    63,
      64,    65,    66,    60,    67,    68,    69,    70,    71,     0,
       0,     0,     0,    60,   125,    61,     0,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
       0,    38,    39,    24,    25,    83,    44,    15,     4,     4,
       4,    21,    22,     4,    24,     4,    44,    44,    44,    44,
       0,     4,     4,    47,    34,    47,    16,    47,    28,    29,
      40,    47,    42,    44,    20,    45,    45,    43,    28,    29,
      30,    31,    32,    33,    44,    35,    36,    37,    38,    39,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   140,    47,    45,   143,    45,    21,    42,    79,
      47,    47,    44,    46,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    47,     4,
      17,    18,    19,    43,    21,    22,    23,    15,    45,    26,
      27,    26,   112,    47,    33,    29,   116,    34,    -1,    -1,
      37,   111,   129,    -1,    -1,    42,   126,    44,    16,    -1,
     120,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,   141,     4,     5,     6,     7,     8,     9,    -1,    37,
      38,    39,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    34,    16,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    16,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    16,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    16,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    28,    29,    30,    31,    32,
      33,    16,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    28,    29,    30,    31,    32,    33,    16,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    28,    29,    30,    31,    32,    33,    16,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    28,
      29,    30,    31,    32,    33,    16,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    28,    29,    30,
      31,    32,    33,    16,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    16,    45,    28,    -1,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    17,    18,    19,    21,    22,    23,    26,
      27,    34,    37,    42,    44,    49,    50,    51,    54,    61,
      69,    70,    71,    44,    15,     4,     4,     4,     4,     4,
      44,    44,    44,    63,    65,    44,    47,    47,     4,    71,
      71,    52,    10,    11,    71,     0,    61,    50,    47,    47,
      16,    28,    29,    30,    31,    32,    33,    35,    36,    37,
      38,    39,    47,     4,    70,    71,    71,     4,    71,    44,
      61,    71,    53,    61,    45,    45,    45,    20,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      47,    45,    45,    45,    71,    21,    45,    43,    53,    71,
      71,    62,    66,    47,    47,    45,    44,    68,    61,    71,
      64,    71,    42,    47,    61,    45,    24,    25,    56,    57,
      59,    67,    47,    71,    46,    43,    56,     4,    55,    46,
      60,    15,    45,    58,    53,    71,    61,    53,    26,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    52,    51,    53,    53,    54,
      55,    56,    56,    56,    58,    57,    60,    59,    61,    61,
      61,    61,    61,    61,    61,    62,    61,    63,    64,    61,
      65,    61,    66,    67,    61,    68,    61,    61,    61,    69,
      69,    69,    69,    69,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     4,     2,     0,     4,
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
#line 58 "sin.y"
            { escopo_atual++; }
#line 1289 "sin.tab.c"
    break;

  case 6: /* bloco: '{' $@1 comandos_bloco '}'  */
#line 58 "sin.y"
                                                   {
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
        }
#line 1298 "sin.tab.c"
    break;

  case 9: /* if_cond: TOKEN_IF '(' expressao ')'  */
#line 69 "sin.y"
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
#line 1317 "sin.tab.c"
    break;

  case 10: /* incremento_for: ID ASSIGN expressao  */
#line 86 "sin.y"
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
#line 1332 "sin.tab.c"
    break;

  case 14: /* @2: %empty  */
#line 103 "sin.y"
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
#line 1357 "sin.tab.c"
    break;

  case 15: /* caso: TOKEN_CASE expressao ':' @2 comandos_bloco TOKEN_BREAK ';'  */
#line 122 "sin.y"
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
#line 1374 "sin.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 136 "sin.y"
                                 {
        strcat(c_body, "default:\n");
    }
#line 1382 "sin.tab.c"
    break;

  case 17: /* default_caso: TOKEN_DEFAULT ':' $@3 comandos_bloco  */
#line 138 "sin.y"
                     {
        // O default não precisa de break nem de desvios no 3AC, ele só termina.
    }
#line 1390 "sin.tab.c"
    break;

  case 22: /* comando: TOKEN_PRINT '(' expressao ')' ';'  */
#line 147 "sin.y"
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
#line 1411 "sin.tab.c"
    break;

  case 23: /* comando: TOKEN_READ '(' ID ')' ';'  */
#line 164 "sin.y"
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
#line 1444 "sin.tab.c"
    break;

  case 24: /* comando: if_cond comando  */
#line 192 "sin.y"
                          {
            // IF SIMPLES (Sem else)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); // Puxa o rótulo do if_cond
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1455 "sin.tab.c"
    break;

  case 25: /* @4: %empty  */
#line 198 "sin.y"
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
#line 1479 "sin.tab.c"
    break;

  case 26: /* comando: if_cond comando TOKEN_ELSE @4 comando  */
#line 216 "sin.y"
                  {
            // FIM DO ELSE
            // Imprime o label de fim (que veio do bloco anterior)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1491 "sin.tab.c"
    break;

  case 27: /* @5: %empty  */
#line 223 "sin.y"
                      {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; 
            
            // --- LINHA NOVA 1: Salva o início na pilha ---
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        }
#line 1506 "sin.tab.c"
    break;

  case 28: /* @6: %empty  */
#line 232 "sin.y"
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
#line 1526 "sin.tab.c"
    break;

  case 29: /* comando: TOKEN_WHILE @5 '(' expressao ')' @6 comando  */
#line 246 "sin.y"
                  {
            // --- LINHA NOVA 4: Desce a pilha pois o laço acabou ---
            topo_laco--; 
            
            sprintf(buf, "goto %s;\n", (yyvsp[-5].valor_str)); 
            strcat(instrucoes, buf);
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1541 "sin.tab.c"
    break;

  case 30: /* @7: %empty  */
#line 256 "sin.y"
                   {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio;
            strcat(c_body, "do {\n");
        }
#line 1553 "sin.tab.c"
    break;

  case 31: /* comando: TOKEN_DO @7 comando TOKEN_WHILE '(' expressao ')' ';'  */
#line 262 "sin.y"
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
#line 1574 "sin.tab.c"
    break;

  case 32: /* @8: %empty  */
#line 278 "sin.y"
                                       {
            // 1. A inicialização já foi impressa pela 'atribuicao'.
            
            // 2. Marca o rótulo de INÍCIO
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; // Salva na posição $5
            
        }
#line 1589 "sin.tab.c"
    break;

  case 33: /* @9: %empty  */
#line 287 "sin.y"
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
#line 1609 "sin.tab.c"
    break;

  case 34: /* comando: TOKEN_FOR '(' atribuicao ';' @8 expressao ';' @9 incremento_for ')' comando  */
#line 301 "sin.y"
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
#line 1635 "sin.tab.c"
    break;

  case 35: /* $@10: %empty  */
#line 322 "sin.y"
                                         {
            // 1. Salva a variável avaliada e gera o rótulo de saída
            strcpy(switch_exp, (yyvsp[-1].info).temp);
            strcpy(switch_fim, novo_label());
            
            // 2. Código C
            sprintf(buf, "switch (%s) {\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
            
        }
#line 1650 "sin.tab.c"
    break;

  case 36: /* comando: TOKEN_SWITCH '(' expressao ')' $@10 '{' casos_lista '}'  */
#line 331 "sin.y"
                              {
            // 3. Fim do Switch: imprime o rótulo de saída
            sprintf(buf, "%s:\n", switch_fim);
            strcat(instrucoes, buf);
            
            strcat(c_body, "}\n");
        }
#line 1662 "sin.tab.c"
    break;

  case 37: /* comando: TOKEN_BREAK ';'  */
#line 339 "sin.y"
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
#line 1677 "sin.tab.c"
    break;

  case 38: /* comando: TOKEN_CONTINUE ';'  */
#line 349 "sin.y"
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
#line 1692 "sin.tab.c"
    break;

  case 39: /* declaracao: TOKEN_INT ID  */
#line 360 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1702 "sin.tab.c"
    break;

  case 40: /* declaracao: TOKEN_FLOAT ID  */
#line 365 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1712 "sin.tab.c"
    break;

  case 41: /* declaracao: TOKEN_CHAR ID  */
#line 370 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1722 "sin.tab.c"
    break;

  case 42: /* declaracao: TOKEN_BOOL ID  */
#line 375 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_BOOL, escopo_atual);
                sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1732 "sin.tab.c"
    break;

  case 43: /* declaracao: TOKEN_STRING ID  */
#line 380 "sin.y"
                              {
                inserir((yyvsp[0].valor_str), T_STRING, escopo_atual);
                sprintf(buf, "char* %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1742 "sin.tab.c"
    break;

  case 44: /* atribuicao: ID ASSIGN expressao  */
#line 387 "sin.y"
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
#line 1782 "sin.tab.c"
    break;

  case 45: /* expressao: NUM_INT  */
#line 423 "sin.y"
                    {
                (yyval.info).tipo_val = T_INT;
                (yyval.info).temp   = novo_temp(T_INT);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1794 "sin.tab.c"
    break;

  case 46: /* expressao: NUM_FLOAT  */
#line 430 "sin.y"
                      {
                (yyval.info).tipo_val = T_FLOAT;
                (yyval.info).temp   = novo_temp(T_FLOAT);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1806 "sin.tab.c"
    break;

  case 47: /* expressao: CHAR_LIT  */
#line 437 "sin.y"
                     {
                (yyval.info).tipo_val = T_CHAR;
                (yyval.info).temp   = novo_temp(T_CHAR);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1818 "sin.tab.c"
    break;

  case 48: /* expressao: BOOL_LIT  */
#line 444 "sin.y"
                     {
                (yyval.info).tipo_val = T_BOOL;
                (yyval.info).temp   = novo_temp(T_BOOL);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1830 "sin.tab.c"
    break;

  case 49: /* expressao: STRING_LIT  */
#line 451 "sin.y"
                         {
                (yyval.info).tipo_val = T_STRING;
                (yyval.info).temp   = novo_temp(T_STRING);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1842 "sin.tab.c"
    break;

  case 50: /* expressao: ID  */
#line 458 "sin.y"
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
#line 1860 "sin.tab.c"
    break;

  case 51: /* expressao: expressao PLUS expressao  */
#line 473 "sin.y"
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
#line 1892 "sin.tab.c"
    break;

  case 52: /* expressao: expressao '-' expressao  */
#line 500 "sin.y"
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
#line 1924 "sin.tab.c"
    break;

  case 53: /* expressao: expressao '*' expressao  */
#line 527 "sin.y"
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
#line 1956 "sin.tab.c"
    break;

  case 54: /* expressao: expressao '/' expressao  */
#line 554 "sin.y"
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
#line 1988 "sin.tab.c"
    break;

  case 55: /* expressao: expressao EQ expressao  */
#line 583 "sin.y"
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
#line 2008 "sin.tab.c"
    break;

  case 56: /* expressao: expressao NE expressao  */
#line 598 "sin.y"
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
#line 2028 "sin.tab.c"
    break;

  case 57: /* expressao: expressao '>' expressao  */
#line 613 "sin.y"
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
#line 2048 "sin.tab.c"
    break;

  case 58: /* expressao: expressao '<' expressao  */
#line 628 "sin.y"
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
#line 2068 "sin.tab.c"
    break;

  case 59: /* expressao: expressao GE expressao  */
#line 643 "sin.y"
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
#line 2088 "sin.tab.c"
    break;

  case 60: /* expressao: expressao LE expressao  */
#line 658 "sin.y"
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
#line 2108 "sin.tab.c"
    break;

  case 61: /* expressao: expressao AND expressao  */
#line 675 "sin.y"
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
#line 2127 "sin.tab.c"
    break;

  case 62: /* expressao: expressao OR expressao  */
#line 689 "sin.y"
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
#line 2146 "sin.tab.c"
    break;

  case 63: /* expressao: NOT expressao  */
#line 703 "sin.y"
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
#line 2165 "sin.tab.c"
    break;

  case 64: /* expressao: '(' TOKEN_INT ')' expressao  */
#line 718 "sin.y"
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
#line 2182 "sin.tab.c"
    break;

  case 65: /* expressao: '(' TOKEN_FLOAT ')' expressao  */
#line 730 "sin.y"
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
#line 2199 "sin.tab.c"
    break;

  case 66: /* expressao: '(' expressao ')'  */
#line 742 "sin.y"
                              {
                (yyval.info) = (yyvsp[-1].info);
            }
#line 2207 "sin.tab.c"
    break;

  case 67: /* expressao: '-' expressao  */
#line 745 "sin.y"
                                       {
                (yyval.info).tipo_val = (yyvsp[0].info).tipo_val;
                (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                sprintf(buf, "%s = -%s;\n", (yyval.info).temp, (yyvsp[0].info).temp);
                strcat(instrucoes, buf);
                char *ce = (char*) malloc(strlen((yyvsp[0].info).c_expr) + 4);
                sprintf(ce, "(-%s)", (yyvsp[0].info).c_expr);
                (yyval.info).c_expr = ce;
            }
#line 2221 "sin.tab.c"
    break;


#line 2225 "sin.tab.c"

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

#line 756 "sin.y"


int main() {
    yyparse();

    /* Codigo Intermediario */
    printf("=== Codigo Intermediario ===\n");
    printf("%s\n%s\n", declaracoes, instrucoes);

    /* Codigo C */
    printf("=== Codigo C ===\n");
    printf("#include <stdio.h>\n\nint main() {\n");

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
