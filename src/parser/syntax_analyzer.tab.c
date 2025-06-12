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
#line 2 "syntax_analyzer.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "../../include/common/syntax_tree.h"
#include "syntax_analyzer.h"

// external functions from lex
extern int yylex();
extern int yyparse();
extern int yyrestart(FILE *input_file);
extern FILE * yyin;

// external variables from lexical_analyzer module
extern char line_buffer[1024];
extern int lines;
extern char * yytext;
extern int pos_end;
extern int pos_start;

// Global syntax tree
syntax_tree *gt;

// Error reporting
void yyerror(const char *s);

// Helper functions written for you with love
syntax_tree_node *node(const char *node_name, int children_num, ...);

#line 103 "syntax_analyzer.tab.c"

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

#include "syntax_analyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LOWER_THAN_ELSE = 3,            /* LOWER_THAN_ELSE  */
  YYSYMBOL_ERROR = 4,                      /* ERROR  */
  YYSYMBOL_ADD = 5,                        /* ADD  */
  YYSYMBOL_SUB = 6,                        /* SUB  */
  YYSYMBOL_MUL = 7,                        /* MUL  */
  YYSYMBOL_DIV = 8,                        /* DIV  */
  YYSYMBOL_MOD = 9,                        /* MOD  */
  YYSYMBOL_ADASS = 10,                     /* ADASS  */
  YYSYMBOL_SUASS = 11,                     /* SUASS  */
  YYSYMBOL_MUASS = 12,                     /* MUASS  */
  YYSYMBOL_DIASS = 13,                     /* DIASS  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LET = 15,                       /* LET  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_GET = 17,                       /* GET  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NEQ = 19,                       /* NEQ  */
  YYSYMBOL_LPARENTHESIS = 20,              /* LPARENTHESIS  */
  YYSYMBOL_RPARENTHESIS = 21,              /* RPARENTHESIS  */
  YYSYMBOL_LBRACKET = 22,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 23,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 28,                 /* SEMICOLON  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_FLOAT = 33,                     /* FLOAT  */
  YYSYMBOL_VOID = 34,                      /* VOID  */
  YYSYMBOL_CONST = 35,                     /* CONST  */
  YYSYMBOL_MAIN = 36,                      /* MAIN  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_BREAK = 40,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 41,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 42,                    /* RETURN  */
  YYSYMBOL_FOR = 43,                       /* FOR  */
  YYSYMBOL_IDENT = 44,                     /* IDENT  */
  YYSYMBOL_INTCONST = 45,                  /* INTCONST  */
  YYSYMBOL_FLOATCONST = 46,                /* FLOATCONST  */
  YYSYMBOL_LOWER_THAN_ASIGN = 47,          /* LOWER_THAN_ASIGN  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Program = 49,                   /* Program  */
  YYSYMBOL_CompMod = 50,                   /* CompMod  */
  YYSYMBOL_MainMod = 51,                   /* MainMod  */
  YYSYMBOL_BType = 52,                     /* BType  */
  YYSYMBOL_Decl = 53,                      /* Decl  */
  YYSYMBOL_FuncDecl = 54,                  /* FuncDecl  */
  YYSYMBOL_ConstDecl = 55,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 56,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 57,                  /* ConstDef  */
  YYSYMBOL_ConstList = 58,                 /* ConstList  */
  YYSYMBOL_ConstInit = 59,                 /* ConstInit  */
  YYSYMBOL_ConstInitList = 60,             /* ConstInitList  */
  YYSYMBOL_ConstExp = 61,                  /* ConstExp  */
  YYSYMBOL_VarDecl = 62,                   /* VarDecl  */
  YYSYMBOL_VarDeclList = 63,               /* VarDeclList  */
  YYSYMBOL_VarDef = 64,                    /* VarDef  */
  YYSYMBOL_InitVal = 65,                   /* InitVal  */
  YYSYMBOL_InitValList = 66,               /* InitValList  */
  YYSYMBOL_FuncDef = 67,                   /* FuncDef  */
  YYSYMBOL_MainDef = 68,                   /* MainDef  */
  YYSYMBOL_FuncParams = 69,                /* FuncParams  */
  YYSYMBOL_FuncParam = 70,                 /* FuncParam  */
  YYSYMBOL_ExpList = 71,                   /* ExpList  */
  YYSYMBOL_Body = 72,                      /* Body  */
  YYSYMBOL_BodyList = 73,                  /* BodyList  */
  YYSYMBOL_BodyItem = 74,                  /* BodyItem  */
  YYSYMBOL_stmt = 75,                      /* stmt  */
  YYSYMBOL_Forstmt = 76,                   /* Forstmt  */
  YYSYMBOL_ForInit = 77,                   /* ForInit  */
  YYSYMBOL_ForCond = 78,                   /* ForCond  */
  YYSYMBOL_ForIncr = 79,                   /* ForIncr  */
  YYSYMBOL_IFItem = 80,                    /* IFItem  */
  YYSYMBOL_WhileItem = 81,                 /* WhileItem  */
  YYSYMBOL_jump_stmt = 82,                 /* jump_stmt  */
  YYSYMBOL_Expr = 83,                      /* Expr  */
  YYSYMBOL_Cond = 84,                      /* Cond  */
  YYSYMBOL_LVal = 85,                      /* LVal  */
  YYSYMBOL_Primary_Expr = 86,              /* Primary_Expr  */
  YYSYMBOL_Number = 87,                    /* Number  */
  YYSYMBOL_Unary_Expr = 88,                /* Unary_Expr  */
  YYSYMBOL_Func_Expr = 89,                 /* Func_Expr  */
  YYSYMBOL_FuncRParams = 90,               /* FuncRParams  */
  YYSYMBOL_MDM_Expr = 91,                  /* MDM_Expr  */
  YYSYMBOL_Add_Expr = 92,                  /* Add_Expr  */
  YYSYMBOL_Rel_Expr = 93,                  /* Rel_Expr  */
  YYSYMBOL_Eq_Expr = 94,                   /* Eq_Expr  */
  YYSYMBOL_And_expr = 95,                  /* And_expr  */
  YYSYMBOL_OR_Expr = 96,                   /* OR_Expr  */
  YYSYMBOL_Integer = 97,                   /* Integer  */
  YYSYMBOL_Floatnum = 98                   /* Floatnum  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   111,   115,   116,   117,   118,   121,   125,
     126,   130,   131,   132,   136,   137,   138,   139,   143,   146,
     147,   151,   155,   156,   160,   161,   162,   165,   166,   170,
     174,   177,   178,   182,   183,   187,   188,   189,   192,   193,
     197,   198,   199,   200,   203,   204,   208,   209,   210,   214,
     215,   218,   219,   223,   226,   227,   231,   232,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   250,
     253,   254,   257,   258,   261,   262,   266,   268,   276,   280,
     281,   282,   283,   287,   291,   295,   299,   300,   301,   305,
     306,   310,   311,   312,   313,   314,   318,   319,   323,   324,
     328,   329,   330,   331,   335,   336,   337,   341,   342,   343,
     344,   345,   349,   350,   351,   355,   356,   360,   361,   365,
     369
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
  "\"end of file\"", "error", "\"invalid token\"", "LOWER_THAN_ELSE",
  "ERROR", "ADD", "SUB", "MUL", "DIV", "MOD", "ADASS", "SUASS", "MUASS",
  "DIASS", "LT", "LET", "GT", "GET", "EQ", "NEQ", "LPARENTHESIS",
  "RPARENTHESIS", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "ASSIGN",
  "COMMA", "SEMICOLON", "NOT", "AND", "OR", "INT", "FLOAT", "VOID",
  "CONST", "MAIN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN",
  "FOR", "IDENT", "INTCONST", "FLOATCONST", "LOWER_THAN_ASIGN", "$accept",
  "Program", "CompMod", "MainMod", "BType", "Decl", "FuncDecl",
  "ConstDecl", "ConstDefList", "ConstDef", "ConstList", "ConstInit",
  "ConstInitList", "ConstExp", "VarDecl", "VarDeclList", "VarDef",
  "InitVal", "InitValList", "FuncDef", "MainDef", "FuncParams",
  "FuncParam", "ExpList", "Body", "BodyList", "BodyItem", "stmt",
  "Forstmt", "ForInit", "ForCond", "ForIncr", "IFItem", "WhileItem",
  "jump_stmt", "Expr", "Cond", "LVal", "Primary_Expr", "Number",
  "Unary_Expr", "Func_Expr", "FuncRParams", "MDM_Expr", "Add_Expr",
  "Rel_Expr", "Eq_Expr", "And_expr", "OR_Expr", "Integer", "Floatnum", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     202,    -4,  -140,     9,   -20,    84,   202,  -140,    31,  -140,
    -140,  -140,  -140,  -140,  -140,    81,    87,  -140,    69,  -140,
    -140,  -140,  -140,    96,    95,  -140,    24,    -6,  -140,   108,
    -140,    33,    22,    93,  -140,   134,   156,    61,  -140,   144,
      16,  -140,   116,    69,  -140,   172,    50,   184,    18,  -140,
    -140,  -140,  -140,   134,  -140,  -140,   138,   174,   -20,    54,
    -140,  -140,  -140,   175,   184,   184,   184,   184,   171,  -140,
    -140,   186,  -140,  -140,  -140,  -140,  -140,    13,   164,  -140,
    -140,     5,  -140,  -140,   164,   139,  -140,   215,  -140,  -140,
    -140,    11,  -140,  -140,  -140,  -140,  -140,  -140,   176,  -140,
      75,   197,  -140,   184,   184,   184,   184,   184,  -140,  -140,
      14,  -140,   198,   226,   227,   220,   222,    86,   231,   208,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,   228,   182,
    -140,  -140,  -140,    43,  -140,  -140,  -140,    52,   184,  -140,
    -140,  -140,    13,    13,  -140,    18,   234,   184,   184,  -140,
    -140,  -140,   229,   184,   235,  -140,   184,   184,   184,   184,
     184,   197,  -140,    54,  -140,   184,   237,  -140,   107,   240,
     164,   200,   188,   232,   233,   242,  -140,   230,  -140,   211,
     238,   239,   241,   243,   244,  -140,  -140,  -140,   245,    66,
     181,   184,   184,   184,   184,   184,   184,   184,   184,   181,
     184,   246,    67,  -140,  -140,  -140,  -140,  -140,   247,   248,
     164,   164,   164,   164,   200,   200,   188,   232,  -140,   249,
    -140,   250,   181,   184,  -140,   255,  -140,   181,  -140
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     0,     0,     0,     3,     0,     6,
      13,    11,    12,     7,     8,     0,     0,     9,     0,     1,
       2,     4,     5,    22,     0,    31,     0,     0,    22,     0,
      19,     0,    33,     0,    30,     0,     0,     0,    48,     0,
       0,    46,     0,     0,    18,     0,     0,     0,     0,    22,
      32,    54,    44,     0,    16,    41,    49,     0,     0,     0,
      20,    17,    40,     0,     0,     0,     0,     0,    51,   119,
     120,     0,    87,    91,    88,   100,    92,   104,    29,    89,
      90,     0,    34,    35,    83,     0,    45,     0,    15,    43,
      47,     0,    21,    24,    14,    42,    93,    94,     0,    95,
       0,    85,    23,     0,     0,     0,     0,     0,    37,    38,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    64,    55,    57,    68,    65,    66,    67,     0,    87,
      51,    26,    27,     0,    86,    97,    98,     0,     0,   101,
     102,   103,   105,   106,    36,     0,     0,     0,     0,    81,
      82,    80,     0,    71,    22,    63,     0,     0,     0,     0,
       0,    50,    25,     0,    96,     0,     0,    39,     0,     0,
     107,   112,   115,   117,    84,     0,    79,     0,    70,     0,
       0,     0,     0,     0,     0,    28,    99,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,    59,    60,    61,    62,    58,     0,    76,
     108,   109,   110,   111,   113,   114,   116,   118,    78,     0,
      72,     0,     0,    75,    77,     0,    74,     0,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,   259,     1,    -3,  -140,  -140,  -140,   225,
     251,   -87,  -140,   223,  -140,  -140,   252,   -73,  -140,   274,
    -140,   -25,   224,   151,   196,  -140,  -140,   -65,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   -48,  -139,   -66,  -140,  -140,
      62,  -140,  -140,   105,   -45,    44,    90,    85,  -140,  -140,
    -140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    39,     9,    10,    11,    29,    30,
      32,    92,   133,    93,    12,    24,    25,    82,   110,    13,
      14,    40,    41,   101,   121,    85,   122,   123,   124,   177,
     219,   225,   125,   126,   127,   128,   169,    72,    73,    74,
      75,    76,   137,    77,    84,   171,   172,   173,   174,    79,
      80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,     8,    78,    21,   132,    18,    46,     8,   109,   175,
      64,    65,    17,     2,    78,    37,    64,    65,    98,   129,
     103,   104,   105,    64,    65,    66,    17,     2,    38,    81,
     108,    66,    15,    83,    67,    91,   131,    57,    66,   144,
      67,   145,    81,    58,    47,    35,    78,    67,    48,    68,
      69,    70,   136,    16,    45,    68,    69,    70,    36,    64,
      65,   220,    68,    69,    70,    17,     2,    38,   162,   152,
     163,    63,   167,   164,    66,    23,   185,    58,    91,   165,
      64,    65,   120,    67,    19,    51,   119,   208,   221,    54,
     166,    64,    65,    58,    58,    66,   135,    83,    68,    69,
      70,    26,   170,   170,    67,   178,    66,    27,   180,   181,
     182,   183,   184,    28,   151,    67,    31,   186,    78,    68,
      69,    70,    33,    34,   129,   209,    96,    97,   188,    99,
      68,    69,    70,   129,   218,    43,    44,    49,    47,    17,
       2,    38,    59,   189,    64,    65,   210,   211,   212,   213,
     170,   170,   170,   170,   202,   170,   129,   224,    51,    66,
      87,   129,   228,    51,   111,   139,   140,   141,    67,   106,
     107,    17,     2,   112,     4,   226,   113,    53,   114,   115,
     116,   117,   118,    68,    69,    70,    64,    65,    56,    64,
      65,   100,   156,   157,   158,   159,    51,   134,    51,    51,
      61,    66,    88,    94,    66,    51,   195,   196,   160,   102,
      67,   142,   143,    67,   191,   192,   193,   194,   113,   138,
     114,   115,   116,   117,   118,    68,    69,    70,    68,    69,
      70,    52,   201,    55,     1,     2,     3,     4,   130,   214,
     215,    62,   146,    17,     2,    38,   147,   148,   149,    86,
     150,   153,   154,    89,   168,   179,   155,   176,   200,    95,
     187,   190,   197,   199,   198,    20,   203,   204,    60,   205,
      71,   206,   207,    54,    61,    88,   227,   223,    94,    42,
      22,   161,    90,   217,     0,    50,   222,   216
};

static const yytype_int16 yycheck[] =
{
      48,     0,    47,     6,    91,     4,    31,     6,    81,   148,
       5,     6,    32,    33,    59,    21,     5,     6,    66,    85,
       7,     8,     9,     5,     6,    20,    32,    33,    34,    24,
      25,    20,    36,    81,    29,    24,    25,    21,    20,    25,
      29,    27,    24,    27,    22,    21,    91,    29,    26,    44,
      45,    46,   100,    44,    21,    44,    45,    46,    34,     5,
       6,   200,    44,    45,    46,    32,    33,    34,    25,   117,
      27,    21,   145,    21,    20,    44,   163,    27,    24,    27,
       5,     6,    85,    29,     0,    24,    85,    21,    21,    28,
     138,     5,     6,    27,    27,    20,    21,   145,    44,    45,
      46,    20,   147,   148,    29,   153,    20,    20,   156,   157,
     158,   159,   160,    44,    28,    29,    20,   165,   163,    44,
      45,    46,    27,    28,   190,   190,    64,    65,    21,    67,
      44,    45,    46,   199,   199,    27,    28,    44,    22,    32,
      33,    34,    26,   168,     5,     6,   191,   192,   193,   194,
     195,   196,   197,   198,   179,   200,   222,   222,    24,    20,
      22,   227,   227,    24,    25,   103,   104,   105,    29,     5,
       6,    32,    33,    34,    35,   223,    37,    21,    39,    40,
      41,    42,    43,    44,    45,    46,     5,     6,    44,     5,
       6,    20,    10,    11,    12,    13,    24,    21,    24,    24,
      28,    20,    28,    28,    20,    24,    18,    19,    26,    23,
      29,   106,   107,    29,    14,    15,    16,    17,    37,    22,
      39,    40,    41,    42,    43,    44,    45,    46,    44,    45,
      46,    35,    21,    37,    32,    33,    34,    35,    23,   195,
     196,    45,    44,    32,    33,    34,    20,    20,    28,    53,
      28,    20,    44,    57,    20,    20,    28,    28,    28,    63,
      23,    21,    30,    21,    31,     6,    28,    28,    43,    28,
      47,    28,    28,    28,    28,    28,    21,    28,    28,    28,
       6,   130,    58,   198,    -1,    33,    38,   197
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    33,    34,    35,    49,    50,    51,    52,    53,
      54,    55,    62,    67,    68,    36,    44,    32,    52,     0,
      51,    53,    67,    44,    63,    64,    20,    20,    44,    56,
      57,    20,    58,    27,    28,    21,    34,    21,    34,    52,
      69,    70,    58,    27,    28,    21,    69,    22,    26,    44,
      64,    24,    72,    21,    28,    72,    44,    21,    27,    26,
      57,    28,    72,    21,     5,     6,    20,    29,    44,    45,
      46,    61,    85,    86,    87,    88,    89,    91,    92,    97,
      98,    24,    65,    83,    92,    73,    72,    22,    28,    72,
      70,    24,    59,    61,    28,    72,    88,    88,    83,    88,
      20,    71,    23,     7,     8,     9,     5,     6,    25,    65,
      66,    25,    34,    37,    39,    40,    41,    42,    43,    52,
      53,    72,    74,    75,    76,    80,    81,    82,    83,    85,
      23,    25,    59,    60,    21,    21,    83,    90,    22,    88,
      88,    88,    91,    91,    25,    27,    44,    20,    20,    28,
      28,    28,    83,    20,    44,    28,    10,    11,    12,    13,
      26,    71,    25,    27,    21,    27,    83,    65,    20,    84,
      92,    93,    94,    95,    96,    84,    28,    77,    83,    20,
      83,    83,    83,    83,    83,    59,    83,    23,    21,    69,
      21,    14,    15,    16,    17,    18,    19,    30,    31,    21,
      28,    21,    69,    28,    28,    28,    28,    28,    21,    75,
      92,    92,    92,    92,    93,    93,    94,    95,    75,    78,
      84,    21,    38,    28,    75,    79,    83,    21,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    51,    52,
      52,    53,    53,    53,    54,    54,    54,    54,    55,    56,
      56,    57,    58,    58,    59,    59,    59,    60,    60,    61,
      62,    63,    63,    64,    64,    65,    65,    65,    66,    66,
      67,    67,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    72,    73,    73,    74,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    82,
      82,    82,    82,    83,    84,    85,    86,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    93,    93,    93,
      93,    93,    94,    94,    94,    95,    95,    96,    96,    97,
      98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     6,     5,     5,     4,     1,
       3,     4,     0,     4,     1,     3,     2,     1,     3,     1,
       3,     1,     3,     2,     4,     1,     3,     2,     1,     3,
       5,     5,     6,     6,     5,     6,     1,     3,     1,     2,
       5,     0,     4,     3,     0,     2,     1,     1,     4,     4,
       4,     4,     4,     2,     1,     1,     1,     1,     1,     9,
       1,     0,     1,     0,     1,     0,     5,     7,     5,     3,
       2,     2,     2,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     4,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       1
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
  case 2: /* Program: CompMod MainMod  */
#line 110 "syntax_analyzer.y"
                          {(yyval.node) = node("program", 2, (yyvsp[-1].node), (yyvsp[0].node)); gt->root = (yyval.node);}
#line 1361 "syntax_analyzer.tab.c"
    break;

  case 3: /* Program: MainMod  */
#line 111 "syntax_analyzer.y"
          {(yyval.node) = node("program", 1, (yyvsp[0].node)); gt->root = (yyval.node);}
#line 1367 "syntax_analyzer.tab.c"
    break;

  case 4: /* CompMod: CompMod Decl  */
#line 115 "syntax_analyzer.y"
               {(yyval.node) = node("CompMod", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1373 "syntax_analyzer.tab.c"
    break;

  case 5: /* CompMod: CompMod FuncDef  */
#line 116 "syntax_analyzer.y"
                   {(yyval.node) = node("CompMod", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1379 "syntax_analyzer.tab.c"
    break;

  case 6: /* CompMod: Decl  */
#line 117 "syntax_analyzer.y"
       {(yyval.node) = node("CompMod", 1, (yyvsp[0].node));}
#line 1385 "syntax_analyzer.tab.c"
    break;

  case 7: /* CompMod: FuncDef  */
#line 118 "syntax_analyzer.y"
          {(yyval.node) = node("CompMod", 1, (yyvsp[0].node));}
#line 1391 "syntax_analyzer.tab.c"
    break;

  case 8: /* MainMod: MainDef  */
#line 121 "syntax_analyzer.y"
          {(yyval.node) = node("MainMod", 1, (yyvsp[0].node));}
#line 1397 "syntax_analyzer.tab.c"
    break;

  case 9: /* BType: INT  */
#line 125 "syntax_analyzer.y"
      {(yyval.node) = node("BType", 1, (yyvsp[0].node));}
#line 1403 "syntax_analyzer.tab.c"
    break;

  case 10: /* BType: FLOAT  */
#line 126 "syntax_analyzer.y"
        {(yyval.node) = node("BType", 1, (yyvsp[0].node));}
#line 1409 "syntax_analyzer.tab.c"
    break;

  case 11: /* Decl: ConstDecl  */
#line 130 "syntax_analyzer.y"
            {(yyval.node) = node("Decl", 1, (yyvsp[0].node));}
#line 1415 "syntax_analyzer.tab.c"
    break;

  case 12: /* Decl: VarDecl  */
#line 131 "syntax_analyzer.y"
            {(yyval.node) = node("Decl", 1, (yyvsp[0].node));}
#line 1421 "syntax_analyzer.tab.c"
    break;

  case 13: /* Decl: FuncDecl  */
#line 132 "syntax_analyzer.y"
            {(yyval.node) = node("Decl", 1, (yyvsp[0].node));}
#line 1427 "syntax_analyzer.tab.c"
    break;

  case 14: /* FuncDecl: BType IDENT LPARENTHESIS FuncParams RPARENTHESIS SEMICOLON  */
#line 136 "syntax_analyzer.y"
                                                             {(yyval.node) = node("FuncDecl", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1433 "syntax_analyzer.tab.c"
    break;

  case 15: /* FuncDecl: VOID IDENT LPARENTHESIS FuncParams RPARENTHESIS SEMICOLON  */
#line 137 "syntax_analyzer.y"
                                                            {(yyval.node) = node("FuncDecl", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1439 "syntax_analyzer.tab.c"
    break;

  case 16: /* FuncDecl: VOID IDENT LPARENTHESIS RPARENTHESIS SEMICOLON  */
#line 138 "syntax_analyzer.y"
                                                 {(yyval.node) = node("FuncDecl", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1445 "syntax_analyzer.tab.c"
    break;

  case 17: /* FuncDecl: BType IDENT LPARENTHESIS RPARENTHESIS SEMICOLON  */
#line 139 "syntax_analyzer.y"
                                                  {(yyval.node) = node("FuncDecl", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1451 "syntax_analyzer.tab.c"
    break;

  case 18: /* ConstDecl: CONST BType ConstDefList SEMICOLON  */
#line 143 "syntax_analyzer.y"
                                     {(yyval.node) = node("ConstDecl", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1457 "syntax_analyzer.tab.c"
    break;

  case 19: /* ConstDefList: ConstDef  */
#line 146 "syntax_analyzer.y"
           {(yyval.node) = node("ConstDefList", 1, (yyvsp[0].node));}
#line 1463 "syntax_analyzer.tab.c"
    break;

  case 20: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 147 "syntax_analyzer.y"
                              {(yyval.node) = node("ConstDefList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1469 "syntax_analyzer.tab.c"
    break;

  case 21: /* ConstDef: IDENT ConstList ASSIGN ConstInit  */
#line 151 "syntax_analyzer.y"
                                   {(yyval.node) = node("ConstDef", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1475 "syntax_analyzer.tab.c"
    break;

  case 22: /* ConstList: %empty  */
#line 155 "syntax_analyzer.y"
   {(yyval.node) = node("ConstList", 0);}
#line 1481 "syntax_analyzer.tab.c"
    break;

  case 23: /* ConstList: ConstList LBRACKET ConstExp RBRACKET  */
#line 156 "syntax_analyzer.y"
                                       {(yyval.node) = node("ConstList", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1487 "syntax_analyzer.tab.c"
    break;

  case 24: /* ConstInit: ConstExp  */
#line 160 "syntax_analyzer.y"
            {(yyval.node) = node("ConstInit", 1, (yyvsp[0].node));}
#line 1493 "syntax_analyzer.tab.c"
    break;

  case 25: /* ConstInit: LBRACE ConstInitList RBRACE  */
#line 161 "syntax_analyzer.y"
                              {(yyval.node) = node("ConstInit", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1499 "syntax_analyzer.tab.c"
    break;

  case 26: /* ConstInit: LBRACE RBRACE  */
#line 162 "syntax_analyzer.y"
                {(yyval.node) = node("ConstInit", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1505 "syntax_analyzer.tab.c"
    break;

  case 27: /* ConstInitList: ConstInit  */
#line 165 "syntax_analyzer.y"
            {(yyval.node) = node("ConstInitList", 1, (yyvsp[0].node));}
#line 1511 "syntax_analyzer.tab.c"
    break;

  case 28: /* ConstInitList: ConstInitList COMMA ConstInit  */
#line 166 "syntax_analyzer.y"
                                {(yyval.node) = node("ConstInitList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1517 "syntax_analyzer.tab.c"
    break;

  case 29: /* ConstExp: Add_Expr  */
#line 170 "syntax_analyzer.y"
           {(yyval.node) = node("ConstExp", 1, (yyvsp[0].node));}
#line 1523 "syntax_analyzer.tab.c"
    break;

  case 30: /* VarDecl: BType VarDeclList SEMICOLON  */
#line 174 "syntax_analyzer.y"
                              {(yyval.node) = node("VarDecl", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1529 "syntax_analyzer.tab.c"
    break;

  case 31: /* VarDeclList: VarDef  */
#line 177 "syntax_analyzer.y"
          { (yyval.node) = node("VarDefList", 1, (yyvsp[0].node)); }
#line 1535 "syntax_analyzer.tab.c"
    break;

  case 32: /* VarDeclList: VarDeclList COMMA VarDef  */
#line 178 "syntax_analyzer.y"
                           {(yyval.node) = node("VarDeclList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1541 "syntax_analyzer.tab.c"
    break;

  case 33: /* VarDef: IDENT ConstList  */
#line 182 "syntax_analyzer.y"
                  {(yyval.node) = node("VarDef", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1547 "syntax_analyzer.tab.c"
    break;

  case 34: /* VarDef: IDENT ConstList ASSIGN InitVal  */
#line 183 "syntax_analyzer.y"
                                 {(yyval.node) = node("VarDef", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1553 "syntax_analyzer.tab.c"
    break;

  case 35: /* InitVal: Expr  */
#line 187 "syntax_analyzer.y"
       {(yyval.node) = node("InitVal", 1, (yyvsp[0].node));}
#line 1559 "syntax_analyzer.tab.c"
    break;

  case 36: /* InitVal: LBRACE InitValList RBRACE  */
#line 188 "syntax_analyzer.y"
                            {(yyval.node) = node("InitVal", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1565 "syntax_analyzer.tab.c"
    break;

  case 37: /* InitVal: LBRACE RBRACE  */
#line 189 "syntax_analyzer.y"
                {(yyval.node) = node("InitVal", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1571 "syntax_analyzer.tab.c"
    break;

  case 38: /* InitValList: InitVal  */
#line 192 "syntax_analyzer.y"
          {(yyval.node) = node("InitValList", 1, (yyvsp[0].node));}
#line 1577 "syntax_analyzer.tab.c"
    break;

  case 39: /* InitValList: InitValList COMMA InitVal  */
#line 193 "syntax_analyzer.y"
                            {(yyval.node) = node("InitValList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1583 "syntax_analyzer.tab.c"
    break;

  case 40: /* FuncDef: BType IDENT LPARENTHESIS RPARENTHESIS Body  */
#line 197 "syntax_analyzer.y"
                                             {(yyval.node) = node("FuncDef", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1589 "syntax_analyzer.tab.c"
    break;

  case 41: /* FuncDef: VOID IDENT LPARENTHESIS RPARENTHESIS Body  */
#line 198 "syntax_analyzer.y"
                                            {(yyval.node) = node("FuncDef", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1595 "syntax_analyzer.tab.c"
    break;

  case 42: /* FuncDef: BType IDENT LPARENTHESIS FuncParams RPARENTHESIS Body  */
#line 199 "syntax_analyzer.y"
                                                        {(yyval.node) = node("FuncDef", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1601 "syntax_analyzer.tab.c"
    break;

  case 43: /* FuncDef: VOID IDENT LPARENTHESIS FuncParams RPARENTHESIS Body  */
#line 200 "syntax_analyzer.y"
                                                       {(yyval.node) = node("FuncDef", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1607 "syntax_analyzer.tab.c"
    break;

  case 44: /* MainDef: INT MAIN LPARENTHESIS RPARENTHESIS Body  */
#line 203 "syntax_analyzer.y"
                                          {(yyval.node) = node("MainDef", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1613 "syntax_analyzer.tab.c"
    break;

  case 45: /* MainDef: INT MAIN LPARENTHESIS VOID RPARENTHESIS Body  */
#line 204 "syntax_analyzer.y"
                                               {(yyval.node) = node("MainDef", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1619 "syntax_analyzer.tab.c"
    break;

  case 46: /* FuncParams: FuncParam  */
#line 208 "syntax_analyzer.y"
            {(yyval.node) = node("FuncParams", 1, (yyvsp[0].node));}
#line 1625 "syntax_analyzer.tab.c"
    break;

  case 47: /* FuncParams: FuncParams COMMA FuncParam  */
#line 209 "syntax_analyzer.y"
                             {(yyval.node) = node("FuncParams", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1631 "syntax_analyzer.tab.c"
    break;

  case 48: /* FuncParams: VOID  */
#line 210 "syntax_analyzer.y"
       {(yyval.node) = node("FuncParams", 1, (yyvsp[0].node));}
#line 1637 "syntax_analyzer.tab.c"
    break;

  case 49: /* FuncParam: BType IDENT  */
#line 214 "syntax_analyzer.y"
              {(yyval.node) = node("FuncParam", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1643 "syntax_analyzer.tab.c"
    break;

  case 50: /* FuncParam: BType IDENT LBRACKET RBRACKET ExpList  */
#line 215 "syntax_analyzer.y"
                                        {(yyval.node) = node("FuncParam", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1649 "syntax_analyzer.tab.c"
    break;

  case 51: /* ExpList: %empty  */
#line 218 "syntax_analyzer.y"
  {(yyval.node) = node("ExpList", 0);}
#line 1655 "syntax_analyzer.tab.c"
    break;

  case 52: /* ExpList: ExpList LBRACKET Expr RBRACKET  */
#line 219 "syntax_analyzer.y"
                                 {(yyval.node) = node("ExpList", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1661 "syntax_analyzer.tab.c"
    break;

  case 53: /* Body: LBRACE BodyList RBRACE  */
#line 223 "syntax_analyzer.y"
                         {(yyval.node) = node("Body", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1667 "syntax_analyzer.tab.c"
    break;

  case 54: /* BodyList: %empty  */
#line 226 "syntax_analyzer.y"
  {(yyval.node) = node("BodyList", 0);}
#line 1673 "syntax_analyzer.tab.c"
    break;

  case 55: /* BodyList: BodyList BodyItem  */
#line 227 "syntax_analyzer.y"
                    {(yyval.node) = node("BodyList", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1679 "syntax_analyzer.tab.c"
    break;

  case 56: /* BodyItem: Decl  */
#line 231 "syntax_analyzer.y"
       {(yyval.node) = node("BodyItem", 1, (yyvsp[0].node));}
#line 1685 "syntax_analyzer.tab.c"
    break;

  case 57: /* BodyItem: stmt  */
#line 232 "syntax_analyzer.y"
       {(yyval.node) = node("BodyItem", 1, (yyvsp[0].node));}
#line 1691 "syntax_analyzer.tab.c"
    break;

  case 58: /* stmt: LVal ASSIGN Expr SEMICOLON  */
#line 236 "syntax_analyzer.y"
                             {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1697 "syntax_analyzer.tab.c"
    break;

  case 59: /* stmt: LVal ADASS Expr SEMICOLON  */
#line 237 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1703 "syntax_analyzer.tab.c"
    break;

  case 60: /* stmt: LVal SUASS Expr SEMICOLON  */
#line 238 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1709 "syntax_analyzer.tab.c"
    break;

  case 61: /* stmt: LVal MUASS Expr SEMICOLON  */
#line 239 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1715 "syntax_analyzer.tab.c"
    break;

  case 62: /* stmt: LVal DIASS Expr SEMICOLON  */
#line 240 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1721 "syntax_analyzer.tab.c"
    break;

  case 63: /* stmt: Expr SEMICOLON  */
#line 241 "syntax_analyzer.y"
                 {(yyval.node) = node("stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1727 "syntax_analyzer.tab.c"
    break;

  case 64: /* stmt: Body  */
#line 242 "syntax_analyzer.y"
       {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1733 "syntax_analyzer.tab.c"
    break;

  case 65: /* stmt: IFItem  */
#line 243 "syntax_analyzer.y"
         {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1739 "syntax_analyzer.tab.c"
    break;

  case 66: /* stmt: WhileItem  */
#line 244 "syntax_analyzer.y"
            {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1745 "syntax_analyzer.tab.c"
    break;

  case 67: /* stmt: jump_stmt  */
#line 245 "syntax_analyzer.y"
            {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1751 "syntax_analyzer.tab.c"
    break;

  case 68: /* stmt: Forstmt  */
#line 246 "syntax_analyzer.y"
          {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1757 "syntax_analyzer.tab.c"
    break;

  case 69: /* Forstmt: FOR LPARENTHESIS ForInit SEMICOLON ForCond SEMICOLON ForIncr RPARENTHESIS stmt  */
#line 250 "syntax_analyzer.y"
                                                                                 { (yyval.node) = node("Forstmt", 5, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1763 "syntax_analyzer.tab.c"
    break;

  case 70: /* ForInit: Expr  */
#line 253 "syntax_analyzer.y"
       { (yyval.node) = node("ForInit", 1, (yyvsp[0].node)); }
#line 1769 "syntax_analyzer.tab.c"
    break;

  case 71: /* ForInit: %empty  */
#line 254 "syntax_analyzer.y"
  { (yyval.node) = node("ForInit", 0); }
#line 1775 "syntax_analyzer.tab.c"
    break;

  case 72: /* ForCond: Cond  */
#line 257 "syntax_analyzer.y"
       { (yyval.node) = node("ForCond", 1, (yyvsp[0].node)); }
#line 1781 "syntax_analyzer.tab.c"
    break;

  case 73: /* ForCond: %empty  */
#line 258 "syntax_analyzer.y"
  { (yyval.node) = node("ForCond", 0); }
#line 1787 "syntax_analyzer.tab.c"
    break;

  case 74: /* ForIncr: Expr  */
#line 261 "syntax_analyzer.y"
       { (yyval.node) = node("ForIncr", 1, (yyvsp[0].node)); }
#line 1793 "syntax_analyzer.tab.c"
    break;

  case 75: /* ForIncr: %empty  */
#line 262 "syntax_analyzer.y"
  { (yyval.node) = node("ForIncr", 0); }
#line 1799 "syntax_analyzer.tab.c"
    break;

  case 76: /* IFItem: IF LPARENTHESIS Cond RPARENTHESIS stmt  */
#line 267 "syntax_analyzer.y"
      { (yyval.node) = node("IFItem", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1805 "syntax_analyzer.tab.c"
    break;

  case 77: /* IFItem: IF LPARENTHESIS Cond RPARENTHESIS stmt ELSE stmt  */
#line 269 "syntax_analyzer.y"
      { (yyval.node) = node("IFItem", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1811 "syntax_analyzer.tab.c"
    break;

  case 78: /* WhileItem: WHILE LPARENTHESIS Cond RPARENTHESIS stmt  */
#line 276 "syntax_analyzer.y"
                                            {(yyval.node) = node("WhileItem", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1817 "syntax_analyzer.tab.c"
    break;

  case 79: /* jump_stmt: RETURN Expr SEMICOLON  */
#line 280 "syntax_analyzer.y"
                        { (yyval.node) = node("jump_stmt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1823 "syntax_analyzer.tab.c"
    break;

  case 80: /* jump_stmt: RETURN SEMICOLON  */
#line 281 "syntax_analyzer.y"
                   { (yyval.node) = node("jump_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1829 "syntax_analyzer.tab.c"
    break;

  case 81: /* jump_stmt: BREAK SEMICOLON  */
#line 282 "syntax_analyzer.y"
                  { (yyval.node) = node("jump_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1835 "syntax_analyzer.tab.c"
    break;

  case 82: /* jump_stmt: CONTINUE SEMICOLON  */
#line 283 "syntax_analyzer.y"
                     { (yyval.node) = node("jump_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1841 "syntax_analyzer.tab.c"
    break;

  case 83: /* Expr: Add_Expr  */
#line 287 "syntax_analyzer.y"
           {(yyval.node) = node("Expr", 1, (yyvsp[0].node));}
#line 1847 "syntax_analyzer.tab.c"
    break;

  case 84: /* Cond: OR_Expr  */
#line 291 "syntax_analyzer.y"
          {(yyval.node) = node("Cond", 1, (yyvsp[0].node));}
#line 1853 "syntax_analyzer.tab.c"
    break;

  case 85: /* LVal: IDENT ExpList  */
#line 295 "syntax_analyzer.y"
                {(yyval.node) = node("LVal", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1859 "syntax_analyzer.tab.c"
    break;

  case 86: /* Primary_Expr: LPARENTHESIS Expr RPARENTHESIS  */
#line 299 "syntax_analyzer.y"
                                 {(yyval.node) = node("Primary_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1865 "syntax_analyzer.tab.c"
    break;

  case 87: /* Primary_Expr: LVal  */
#line 300 "syntax_analyzer.y"
       {(yyval.node) = node("Primary_Expr", 1, (yyvsp[0].node));}
#line 1871 "syntax_analyzer.tab.c"
    break;

  case 88: /* Primary_Expr: Number  */
#line 301 "syntax_analyzer.y"
         {(yyval.node) = node("Primary_Expr", 1, (yyvsp[0].node));}
#line 1877 "syntax_analyzer.tab.c"
    break;

  case 89: /* Number: Integer  */
#line 305 "syntax_analyzer.y"
          {(yyval.node) = node("Number", 1, (yyvsp[0].node));}
#line 1883 "syntax_analyzer.tab.c"
    break;

  case 90: /* Number: Floatnum  */
#line 306 "syntax_analyzer.y"
           {(yyval.node) = node("Number", 1, (yyvsp[0].node));}
#line 1889 "syntax_analyzer.tab.c"
    break;

  case 91: /* Unary_Expr: Primary_Expr  */
#line 310 "syntax_analyzer.y"
               {(yyval.node) = node("Unary_Expr", 1, (yyvsp[0].node));}
#line 1895 "syntax_analyzer.tab.c"
    break;

  case 92: /* Unary_Expr: Func_Expr  */
#line 311 "syntax_analyzer.y"
                {(yyval.node) = node("Unary_Expr", 1, (yyvsp[0].node));}
#line 1901 "syntax_analyzer.tab.c"
    break;

  case 93: /* Unary_Expr: ADD Unary_Expr  */
#line 312 "syntax_analyzer.y"
                 {(yyval.node) = node("Unary_Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1907 "syntax_analyzer.tab.c"
    break;

  case 94: /* Unary_Expr: SUB Unary_Expr  */
#line 313 "syntax_analyzer.y"
                 {(yyval.node) = node("Unary_Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1913 "syntax_analyzer.tab.c"
    break;

  case 95: /* Unary_Expr: NOT Unary_Expr  */
#line 314 "syntax_analyzer.y"
                 {(yyval.node) = node("Unary_Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1919 "syntax_analyzer.tab.c"
    break;

  case 96: /* Func_Expr: IDENT LPARENTHESIS FuncRParams RPARENTHESIS  */
#line 318 "syntax_analyzer.y"
                                              {(yyval.node) = node("Func_Expr", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1925 "syntax_analyzer.tab.c"
    break;

  case 97: /* Func_Expr: IDENT LPARENTHESIS RPARENTHESIS  */
#line 319 "syntax_analyzer.y"
                                  {(yyval.node) = node("Func_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1931 "syntax_analyzer.tab.c"
    break;

  case 98: /* FuncRParams: Expr  */
#line 323 "syntax_analyzer.y"
       {(yyval.node) = node("FuncRParams", 1, (yyvsp[0].node));}
#line 1937 "syntax_analyzer.tab.c"
    break;

  case 99: /* FuncRParams: FuncRParams COMMA Expr  */
#line 324 "syntax_analyzer.y"
                         {(yyval.node) = node("FuncRParams", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1943 "syntax_analyzer.tab.c"
    break;

  case 100: /* MDM_Expr: Unary_Expr  */
#line 328 "syntax_analyzer.y"
             {(yyval.node) = node("MDM_Expr", 1, (yyvsp[0].node));}
#line 1949 "syntax_analyzer.tab.c"
    break;

  case 101: /* MDM_Expr: MDM_Expr MUL Unary_Expr  */
#line 329 "syntax_analyzer.y"
                          {(yyval.node) = node("MDM_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1955 "syntax_analyzer.tab.c"
    break;

  case 102: /* MDM_Expr: MDM_Expr DIV Unary_Expr  */
#line 330 "syntax_analyzer.y"
                          {(yyval.node) = node("MDM_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1961 "syntax_analyzer.tab.c"
    break;

  case 103: /* MDM_Expr: MDM_Expr MOD Unary_Expr  */
#line 331 "syntax_analyzer.y"
                          {(yyval.node) = node("MDM_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1967 "syntax_analyzer.tab.c"
    break;

  case 104: /* Add_Expr: MDM_Expr  */
#line 335 "syntax_analyzer.y"
           {(yyval.node) = node("Add_Expr", 1, (yyvsp[0].node));}
#line 1973 "syntax_analyzer.tab.c"
    break;

  case 105: /* Add_Expr: Add_Expr ADD MDM_Expr  */
#line 336 "syntax_analyzer.y"
                        {(yyval.node) = node("Add_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1979 "syntax_analyzer.tab.c"
    break;

  case 106: /* Add_Expr: Add_Expr SUB MDM_Expr  */
#line 337 "syntax_analyzer.y"
                        {(yyval.node) = node("Add_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1985 "syntax_analyzer.tab.c"
    break;

  case 107: /* Rel_Expr: Add_Expr  */
#line 341 "syntax_analyzer.y"
           {(yyval.node) = node("Rel_Expr", 1, (yyvsp[0].node));}
#line 1991 "syntax_analyzer.tab.c"
    break;

  case 108: /* Rel_Expr: Rel_Expr LT Add_Expr  */
#line 342 "syntax_analyzer.y"
                       {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1997 "syntax_analyzer.tab.c"
    break;

  case 109: /* Rel_Expr: Rel_Expr LET Add_Expr  */
#line 343 "syntax_analyzer.y"
                        {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2003 "syntax_analyzer.tab.c"
    break;

  case 110: /* Rel_Expr: Rel_Expr GT Add_Expr  */
#line 344 "syntax_analyzer.y"
                       {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2009 "syntax_analyzer.tab.c"
    break;

  case 111: /* Rel_Expr: Rel_Expr GET Add_Expr  */
#line 345 "syntax_analyzer.y"
                        {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2015 "syntax_analyzer.tab.c"
    break;

  case 112: /* Eq_Expr: Rel_Expr  */
#line 349 "syntax_analyzer.y"
           {(yyval.node) = node("Eq_Expr", 1, (yyvsp[0].node));}
#line 2021 "syntax_analyzer.tab.c"
    break;

  case 113: /* Eq_Expr: Eq_Expr EQ Rel_Expr  */
#line 350 "syntax_analyzer.y"
                      {(yyval.node) = node("Eq_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2027 "syntax_analyzer.tab.c"
    break;

  case 114: /* Eq_Expr: Eq_Expr NEQ Rel_Expr  */
#line 351 "syntax_analyzer.y"
                       {(yyval.node) = node("Eq_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2033 "syntax_analyzer.tab.c"
    break;

  case 115: /* And_expr: Eq_Expr  */
#line 355 "syntax_analyzer.y"
          {(yyval.node) = node("And_expr", 1, (yyvsp[0].node));}
#line 2039 "syntax_analyzer.tab.c"
    break;

  case 116: /* And_expr: And_expr AND Eq_Expr  */
#line 356 "syntax_analyzer.y"
                       {(yyval.node) = node("And_expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2045 "syntax_analyzer.tab.c"
    break;

  case 117: /* OR_Expr: And_expr  */
#line 360 "syntax_analyzer.y"
           {(yyval.node) = node("OR_Expr", 1, (yyvsp[0].node));}
#line 2051 "syntax_analyzer.tab.c"
    break;

  case 118: /* OR_Expr: OR_Expr OR And_expr  */
#line 361 "syntax_analyzer.y"
                      {(yyval.node) = node("OR_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2057 "syntax_analyzer.tab.c"
    break;

  case 119: /* Integer: INTCONST  */
#line 365 "syntax_analyzer.y"
           {(yyval.node) = node("Integer", 1, (yyvsp[0].node));}
#line 2063 "syntax_analyzer.tab.c"
    break;

  case 120: /* Floatnum: FLOATCONST  */
#line 369 "syntax_analyzer.y"
             {(yyval.node) = node("Floatnum", 1, (yyvsp[0].node));}
#line 2069 "syntax_analyzer.tab.c"
    break;


#line 2073 "syntax_analyzer.tab.c"

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

#line 371 "syntax_analyzer.y"


/// The error reporting function.
void yyerror(const char * s)
{   
    // TO sTUDENTs: This is just an example.
    // You can customize it as you like.
    int errorline=lines;
    int start=pos_start;
    int end=pos_end;

    fprintf(stderr, "%d:%d: error:%s\n", lines, pos_start, s);
    fprintf(stderr,"%d  |%s\n", lines, line_buffer);
    fprintf(stderr,"   |");
    for(int i=0;i<start;i++){
        fprintf(stderr," ");
    }
    for(int i=0;i<end-start;i++){
        fprintf(stderr,"^");
    }
    fprintf(stderr,"\n");

}

/// Parse input from file `input_path`, and prints the parsing results
/// to stdout.  If input_path is NULL, read from stdin.
///
/// This function initializes esential states before running yyparse().
syntax_tree *parse(const char *input_path)
{
    if (input_path != NULL) {
        if (!(yyin = fopen(input_path, "r"))) {
            fprintf(stderr, "[ERR] Open input file %s failed.\n", input_path);
            exit(1);
        }
    } else {
        yyin = stdin;
    }
    lines = pos_start = pos_end = 1;
    gt = new_syntax_tree();
    yyrestart(yyin);
    yyparse();
    return gt;
}

/// A helper function to quickly construct a tree node.
///
/// e.g. $$ = node("program", 1, $1);
syntax_tree_node *node(const char *name, int children_num, ...)
{
    syntax_tree_node *p = new_syntax_tree_node(name);
    syntax_tree_node *child;
    if (children_num == 0) {
        child = new_syntax_tree_node("epsilon");
        syntax_tree_add_child(p, child);
    } else {
        va_list ap;
        va_start(ap, children_num);
        for (int i = 0; i < children_num; ++i) {
            child = va_arg(ap, syntax_tree_node *);
            syntax_tree_add_child(p, child);
        }
        va_end(ap);
    }
    return p;
}
