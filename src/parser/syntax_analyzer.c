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

#line 103 "/home/test/IR/src/parser/syntax_analyzer.c"

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

#include "syntax_analyzer.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ERROR = 3,                      /* ERROR  */
  YYSYMBOL_ADD = 4,                        /* ADD  */
  YYSYMBOL_SUB = 5,                        /* SUB  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_ADASS = 9,                      /* ADASS  */
  YYSYMBOL_SUASS = 10,                     /* SUASS  */
  YYSYMBOL_MUASS = 11,                     /* MUASS  */
  YYSYMBOL_DIASS = 12,                     /* DIASS  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LET = 14,                       /* LET  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_GET = 16,                       /* GET  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NEQ = 18,                       /* NEQ  */
  YYSYMBOL_LPARENTHESIS = 19,              /* LPARENTHESIS  */
  YYSYMBOL_RPARENTHESIS = 20,              /* RPARENTHESIS  */
  YYSYMBOL_LBRACKET = 21,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 22,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 24,                    /* RBRACE  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 27,                 /* SEMICOLON  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_INT = 31,                       /* INT  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_VOID = 33,                      /* VOID  */
  YYSYMBOL_CONST = 34,                     /* CONST  */
  YYSYMBOL_MAIN = 35,                      /* MAIN  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_BREAK = 39,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 40,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_FOR = 42,                       /* FOR  */
  YYSYMBOL_IDENT = 43,                     /* IDENT  */
  YYSYMBOL_INTCONST = 44,                  /* INTCONST  */
  YYSYMBOL_FLOATCONST = 45,                /* FLOATCONST  */
  YYSYMBOL_LOWER_THAN_ASIGN = 46,          /* LOWER_THAN_ASIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 47,           /* LOWER_THAN_ELSE  */
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
       0,   107,   107,   108,   112,   113,   114,   115,   118,   122,
     123,   127,   128,   129,   133,   134,   135,   136,   140,   143,
     144,   148,   152,   153,   157,   158,   159,   162,   163,   167,
     171,   174,   175,   179,   180,   184,   185,   186,   189,   190,
     194,   195,   196,   197,   200,   201,   205,   206,   207,   211,
     212,   215,   216,   220,   223,   224,   228,   229,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   247,
     250,   251,   254,   255,   258,   259,   263,   265,   273,   277,
     278,   279,   280,   284,   288,   292,   296,   297,   298,   302,
     303,   307,   308,   309,   310,   311,   315,   316,   320,   321,
     325,   326,   327,   328,   332,   333,   334,   338,   339,   340,
     341,   342,   346,   347,   348,   352,   353,   357,   358,   362,
     366
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
  "\"end of file\"", "error", "\"invalid token\"", "ERROR", "ADD", "SUB",
  "MUL", "DIV", "MOD", "ADASS", "SUASS", "MUASS", "DIASS", "LT", "LET",
  "GT", "GET", "EQ", "NEQ", "LPARENTHESIS", "RPARENTHESIS", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "ASSIGN", "COMMA", "SEMICOLON", "NOT",
  "AND", "OR", "INT", "FLOAT", "VOID", "CONST", "MAIN", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "RETURN", "FOR", "IDENT", "INTCONST",
  "FLOATCONST", "LOWER_THAN_ASIGN", "LOWER_THAN_ELSE", "$accept",
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
     203,    18,  -140,   -11,   -19,    75,   203,  -140,    41,  -140,
    -140,  -140,  -140,  -140,  -140,    82,    88,  -140,    70,  -140,
    -140,  -140,  -140,    97,    96,  -140,    25,    -5,  -140,   109,
    -140,    34,    23,    94,  -140,   135,   157,   115,  -140,   117,
      17,  -140,    64,    70,  -140,   173,    51,   185,    19,  -140,
    -140,  -140,  -140,   135,  -140,  -140,   167,   175,   -19,    55,
    -140,  -140,  -140,   176,   185,   185,   185,   185,   172,  -140,
    -140,   187,  -140,  -140,  -140,  -140,  -140,    14,   165,  -140,
    -140,     6,  -140,  -140,   165,   140,  -140,   197,  -140,  -140,
    -140,    12,  -140,  -140,  -140,  -140,  -140,  -140,   177,  -140,
      76,   219,  -140,   185,   185,   185,   185,   185,  -140,  -140,
      15,  -140,   199,   227,   228,   221,   223,    87,   232,   209,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,   229,   183,
    -140,  -140,  -140,    44,  -140,  -140,  -140,    53,   185,  -140,
    -140,  -140,    14,    14,  -140,    19,   235,   185,   185,  -140,
    -140,  -140,   230,   185,   236,  -140,   185,   185,   185,   185,
     185,   219,  -140,    55,  -140,   185,   238,  -140,   108,   241,
     165,   201,   189,   233,   234,   243,  -140,   231,  -140,   212,
     239,   240,   242,   244,   245,  -140,  -140,  -140,   246,    67,
     182,   185,   185,   185,   185,   185,   185,   185,   185,   182,
     185,   247,    68,  -140,  -140,  -140,  -140,  -140,   248,   249,
     165,   165,   165,   165,   201,   201,   189,   233,  -140,   250,
    -140,   251,   182,   185,  -140,   256,  -140,   182,  -140
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
     252,   -87,  -140,   237,  -140,  -140,   254,   -73,  -140,   264,
    -140,   -25,   224,   149,   196,  -140,  -140,   -65,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   -48,  -139,   -66,  -140,  -140,
      62,  -140,  -140,   105,   -45,    43,    84,    85,  -140,  -140,
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
     108,    66,    16,    83,    67,    91,   131,    57,    66,   144,
      67,   145,    81,    58,    47,    35,    78,    67,    48,    68,
      69,    70,   136,    15,    45,    68,    69,    70,    36,    64,
      65,   220,    68,    69,    70,    17,     2,    38,   162,   152,
     163,    63,   167,   164,    66,    19,   185,    58,    91,   165,
      64,    65,   120,    67,    23,    47,   119,   208,   221,    59,
     166,    64,    65,    58,    58,    66,   135,    83,    68,    69,
      70,    26,   170,   170,    67,   178,    66,    27,   180,   181,
     182,   183,   184,    28,   151,    67,    31,   186,    78,    68,
      69,    70,    33,    34,   129,   209,    96,    97,   188,    99,
      68,    69,    70,   129,   218,    43,    44,    49,    51,    17,
       2,    38,    54,   189,    64,    65,   210,   211,   212,   213,
     170,   170,   170,   170,   202,   170,   129,   224,    51,    66,
      56,   129,   228,    51,   111,   139,   140,   141,    67,   106,
     107,    17,     2,   112,     4,   226,   113,    53,   114,   115,
     116,   117,   118,    68,    69,    70,    64,    65,    87,    64,
      65,   100,   156,   157,   158,   159,    51,   134,    51,    51,
      61,    66,    88,    94,    66,    51,   195,   196,   160,   102,
      67,   142,   143,    67,   191,   192,   193,   194,   113,   130,
     114,   115,   116,   117,   118,    68,    69,    70,    68,    69,
      70,    52,   201,    55,     1,     2,     3,     4,   214,   215,
     138,    62,   146,    17,     2,    38,   147,   148,   149,    86,
     150,   153,   154,    89,   168,   179,   155,   176,   200,    95,
     187,   190,   197,   199,   198,    20,   203,   204,    60,   205,
      22,   206,   207,    54,    61,    88,   227,   223,    94,   161,
      42,   216,    90,   217,    71,     0,   222,    50
};

static const yytype_int16 yycheck[] =
{
      48,     0,    47,     6,    91,     4,    31,     6,    81,   148,
       4,     5,    31,    32,    59,    20,     4,     5,    66,    85,
       6,     7,     8,     4,     5,    19,    31,    32,    33,    23,
      24,    19,    43,    81,    28,    23,    24,    20,    19,    24,
      28,    26,    23,    26,    21,    20,    91,    28,    25,    43,
      44,    45,   100,    35,    20,    43,    44,    45,    33,     4,
       5,   200,    43,    44,    45,    31,    32,    33,    24,   117,
      26,    20,   145,    20,    19,     0,   163,    26,    23,    26,
       4,     5,    85,    28,    43,    21,    85,    20,    20,    25,
     138,     4,     5,    26,    26,    19,    20,   145,    43,    44,
      45,    19,   147,   148,    28,   153,    19,    19,   156,   157,
     158,   159,   160,    43,    27,    28,    19,   165,   163,    43,
      44,    45,    26,    27,   190,   190,    64,    65,    20,    67,
      43,    44,    45,   199,   199,    26,    27,    43,    23,    31,
      32,    33,    27,   168,     4,     5,   191,   192,   193,   194,
     195,   196,   197,   198,   179,   200,   222,   222,    23,    19,
      43,   227,   227,    23,    24,   103,   104,   105,    28,     4,
       5,    31,    32,    33,    34,   223,    36,    20,    38,    39,
      40,    41,    42,    43,    44,    45,     4,     5,    21,     4,
       5,    19,     9,    10,    11,    12,    23,    20,    23,    23,
      27,    19,    27,    27,    19,    23,    17,    18,    25,    22,
      28,   106,   107,    28,    13,    14,    15,    16,    36,    22,
      38,    39,    40,    41,    42,    43,    44,    45,    43,    44,
      45,    35,    20,    37,    31,    32,    33,    34,   195,   196,
      21,    45,    43,    31,    32,    33,    19,    19,    27,    53,
      27,    19,    43,    57,    19,    19,    27,    27,    27,    63,
      22,    20,    29,    20,    30,     6,    27,    27,    43,    27,
       6,    27,    27,    27,    27,    27,    20,    27,    27,   130,
      28,   197,    58,   198,    47,    -1,    37,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    32,    33,    34,    49,    50,    51,    52,    53,
      54,    55,    62,    67,    68,    35,    43,    31,    52,     0,
      51,    53,    67,    43,    63,    64,    19,    19,    43,    56,
      57,    19,    58,    26,    27,    20,    33,    20,    33,    52,
      69,    70,    58,    26,    27,    20,    69,    21,    25,    43,
      64,    23,    72,    20,    27,    72,    43,    20,    26,    25,
      57,    27,    72,    20,     4,     5,    19,    28,    43,    44,
      45,    61,    85,    86,    87,    88,    89,    91,    92,    97,
      98,    23,    65,    83,    92,    73,    72,    21,    27,    72,
      70,    23,    59,    61,    27,    72,    88,    88,    83,    88,
      19,    71,    22,     6,     7,     8,     4,     5,    24,    65,
      66,    24,    33,    36,    38,    39,    40,    41,    42,    52,
      53,    72,    74,    75,    76,    80,    81,    82,    83,    85,
      22,    24,    59,    60,    20,    20,    83,    90,    21,    88,
      88,    88,    91,    91,    24,    26,    43,    19,    19,    27,
      27,    27,    83,    19,    43,    27,     9,    10,    11,    12,
      25,    71,    24,    26,    20,    26,    83,    65,    19,    84,
      92,    93,    94,    95,    96,    84,    27,    77,    83,    19,
      83,    83,    83,    83,    83,    59,    83,    22,    20,    69,
      20,    13,    14,    15,    16,    17,    18,    29,    30,    20,
      27,    20,    69,    27,    27,    27,    27,    27,    20,    75,
      92,    92,    92,    92,    93,    93,    94,    95,    75,    78,
      84,    20,    37,    27,    75,    79,    83,    20,    75
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
#line 107 "syntax_analyzer.y"
                          {(yyval.node) = node("program", 2, (yyvsp[-1].node), (yyvsp[0].node)); gt->root = (yyval.node);}
#line 1361 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 3: /* Program: MainMod  */
#line 108 "syntax_analyzer.y"
          {(yyval.node) = node("program", 1, (yyvsp[0].node)); gt->root = (yyval.node);}
#line 1367 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 4: /* CompMod: CompMod Decl  */
#line 112 "syntax_analyzer.y"
               {(yyval.node) = node("CompMod", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1373 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 5: /* CompMod: CompMod FuncDef  */
#line 113 "syntax_analyzer.y"
                   {(yyval.node) = node("CompMod", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1379 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 6: /* CompMod: Decl  */
#line 114 "syntax_analyzer.y"
       {(yyval.node) = node("CompMod", 1, (yyvsp[0].node));}
#line 1385 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 7: /* CompMod: FuncDef  */
#line 115 "syntax_analyzer.y"
          {(yyval.node) = node("CompMod", 1, (yyvsp[0].node));}
#line 1391 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 8: /* MainMod: MainDef  */
#line 118 "syntax_analyzer.y"
          {(yyval.node) = node("MainMod", 1, (yyvsp[0].node));}
#line 1397 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 9: /* BType: INT  */
#line 122 "syntax_analyzer.y"
      {(yyval.node) = node("BType", 1, (yyvsp[0].node));}
#line 1403 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 10: /* BType: FLOAT  */
#line 123 "syntax_analyzer.y"
        {(yyval.node) = node("BType", 1, (yyvsp[0].node));}
#line 1409 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 11: /* Decl: ConstDecl  */
#line 127 "syntax_analyzer.y"
            {(yyval.node) = node("Decl", 1, (yyvsp[0].node));}
#line 1415 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 12: /* Decl: VarDecl  */
#line 128 "syntax_analyzer.y"
            {(yyval.node) = node("Decl", 1, (yyvsp[0].node));}
#line 1421 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 13: /* Decl: FuncDecl  */
#line 129 "syntax_analyzer.y"
            {(yyval.node) = node("Decl", 1, (yyvsp[0].node));}
#line 1427 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 14: /* FuncDecl: BType IDENT LPARENTHESIS FuncParams RPARENTHESIS SEMICOLON  */
#line 133 "syntax_analyzer.y"
                                                             {(yyval.node) = node("FuncDecl", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1433 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 15: /* FuncDecl: VOID IDENT LPARENTHESIS FuncParams RPARENTHESIS SEMICOLON  */
#line 134 "syntax_analyzer.y"
                                                            {(yyval.node) = node("FuncDecl", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1439 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 16: /* FuncDecl: VOID IDENT LPARENTHESIS RPARENTHESIS SEMICOLON  */
#line 135 "syntax_analyzer.y"
                                                 {(yyval.node) = node("FuncDecl", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1445 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 17: /* FuncDecl: BType IDENT LPARENTHESIS RPARENTHESIS SEMICOLON  */
#line 136 "syntax_analyzer.y"
                                                  {(yyval.node) = node("FuncDecl", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1451 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 18: /* ConstDecl: CONST BType ConstDefList SEMICOLON  */
#line 140 "syntax_analyzer.y"
                                     {(yyval.node) = node("ConstDecl", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1457 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 19: /* ConstDefList: ConstDef  */
#line 143 "syntax_analyzer.y"
           {(yyval.node) = node("ConstDefList", 1, (yyvsp[0].node));}
#line 1463 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 20: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 144 "syntax_analyzer.y"
                              {(yyval.node) = node("ConstDefList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1469 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 21: /* ConstDef: IDENT ConstList ASSIGN ConstInit  */
#line 148 "syntax_analyzer.y"
                                   {(yyval.node) = node("ConstDef", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1475 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 22: /* ConstList: %empty  */
#line 152 "syntax_analyzer.y"
   {(yyval.node) = node("ConstList", 0);}
#line 1481 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 23: /* ConstList: ConstList LBRACKET ConstExp RBRACKET  */
#line 153 "syntax_analyzer.y"
                                       {(yyval.node) = node("ConstList", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1487 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 24: /* ConstInit: ConstExp  */
#line 157 "syntax_analyzer.y"
            {(yyval.node) = node("ConstInit", 1, (yyvsp[0].node));}
#line 1493 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 25: /* ConstInit: LBRACE ConstInitList RBRACE  */
#line 158 "syntax_analyzer.y"
                              {(yyval.node) = node("ConstInit", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1499 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 26: /* ConstInit: LBRACE RBRACE  */
#line 159 "syntax_analyzer.y"
                {(yyval.node) = node("ConstInit", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1505 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 27: /* ConstInitList: ConstInit  */
#line 162 "syntax_analyzer.y"
            {(yyval.node) = node("ConstInitList", 1, (yyvsp[0].node));}
#line 1511 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 28: /* ConstInitList: ConstInitList COMMA ConstInit  */
#line 163 "syntax_analyzer.y"
                                {(yyval.node) = node("ConstInitList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1517 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 29: /* ConstExp: Add_Expr  */
#line 167 "syntax_analyzer.y"
           {(yyval.node) = node("ConstExp", 1, (yyvsp[0].node));}
#line 1523 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 30: /* VarDecl: BType VarDeclList SEMICOLON  */
#line 171 "syntax_analyzer.y"
                              {(yyval.node) = node("VarDecl", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1529 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 31: /* VarDeclList: VarDef  */
#line 174 "syntax_analyzer.y"
          { (yyval.node) = node("VarDefList", 1, (yyvsp[0].node)); }
#line 1535 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 32: /* VarDeclList: VarDeclList COMMA VarDef  */
#line 175 "syntax_analyzer.y"
                           {(yyval.node) = node("VarDeclList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1541 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 33: /* VarDef: IDENT ConstList  */
#line 179 "syntax_analyzer.y"
                  {(yyval.node) = node("VarDef", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1547 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 34: /* VarDef: IDENT ConstList ASSIGN InitVal  */
#line 180 "syntax_analyzer.y"
                                 {(yyval.node) = node("VarDef", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1553 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 35: /* InitVal: Expr  */
#line 184 "syntax_analyzer.y"
       {(yyval.node) = node("InitVal", 1, (yyvsp[0].node));}
#line 1559 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 36: /* InitVal: LBRACE InitValList RBRACE  */
#line 185 "syntax_analyzer.y"
                            {(yyval.node) = node("InitVal", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1565 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 37: /* InitVal: LBRACE RBRACE  */
#line 186 "syntax_analyzer.y"
                {(yyval.node) = node("InitVal", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1571 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 38: /* InitValList: InitVal  */
#line 189 "syntax_analyzer.y"
          {(yyval.node) = node("InitValList", 1, (yyvsp[0].node));}
#line 1577 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 39: /* InitValList: InitValList COMMA InitVal  */
#line 190 "syntax_analyzer.y"
                            {(yyval.node) = node("InitValList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1583 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 40: /* FuncDef: BType IDENT LPARENTHESIS RPARENTHESIS Body  */
#line 194 "syntax_analyzer.y"
                                             {(yyval.node) = node("FuncDef", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1589 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 41: /* FuncDef: VOID IDENT LPARENTHESIS RPARENTHESIS Body  */
#line 195 "syntax_analyzer.y"
                                            {(yyval.node) = node("FuncDef", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1595 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 42: /* FuncDef: BType IDENT LPARENTHESIS FuncParams RPARENTHESIS Body  */
#line 196 "syntax_analyzer.y"
                                                        {(yyval.node) = node("FuncDef", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1601 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 43: /* FuncDef: VOID IDENT LPARENTHESIS FuncParams RPARENTHESIS Body  */
#line 197 "syntax_analyzer.y"
                                                       {(yyval.node) = node("FuncDef", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1607 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 44: /* MainDef: INT MAIN LPARENTHESIS RPARENTHESIS Body  */
#line 200 "syntax_analyzer.y"
                                          {(yyval.node) = node("MainDef", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1613 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 45: /* MainDef: INT MAIN LPARENTHESIS VOID RPARENTHESIS Body  */
#line 201 "syntax_analyzer.y"
                                               {(yyval.node) = node("MainDef", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1619 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 46: /* FuncParams: FuncParam  */
#line 205 "syntax_analyzer.y"
            {(yyval.node) = node("FuncParams", 1, (yyvsp[0].node));}
#line 1625 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 47: /* FuncParams: FuncParams COMMA FuncParam  */
#line 206 "syntax_analyzer.y"
                             {(yyval.node) = node("FuncParams", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1631 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 48: /* FuncParams: VOID  */
#line 207 "syntax_analyzer.y"
       {(yyval.node) = node("FuncParams", 1, (yyvsp[0].node));}
#line 1637 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 49: /* FuncParam: BType IDENT  */
#line 211 "syntax_analyzer.y"
              {(yyval.node) = node("FuncParam", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1643 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 50: /* FuncParam: BType IDENT LBRACKET RBRACKET ExpList  */
#line 212 "syntax_analyzer.y"
                                        {(yyval.node) = node("FuncParam", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1649 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 51: /* ExpList: %empty  */
#line 215 "syntax_analyzer.y"
  {(yyval.node) = node("ExpList", 0);}
#line 1655 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 52: /* ExpList: ExpList LBRACKET Expr RBRACKET  */
#line 216 "syntax_analyzer.y"
                                 {(yyval.node) = node("ExpList", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1661 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 53: /* Body: LBRACE BodyList RBRACE  */
#line 220 "syntax_analyzer.y"
                         {(yyval.node) = node("Body", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1667 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 54: /* BodyList: %empty  */
#line 223 "syntax_analyzer.y"
  {(yyval.node) = node("BodyList", 0);}
#line 1673 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 55: /* BodyList: BodyList BodyItem  */
#line 224 "syntax_analyzer.y"
                    {(yyval.node) = node("BodyList", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1679 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 56: /* BodyItem: Decl  */
#line 228 "syntax_analyzer.y"
       {(yyval.node) = node("BodyItem", 1, (yyvsp[0].node));}
#line 1685 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 57: /* BodyItem: stmt  */
#line 229 "syntax_analyzer.y"
       {(yyval.node) = node("BodyItem", 1, (yyvsp[0].node));}
#line 1691 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 58: /* stmt: LVal ASSIGN Expr SEMICOLON  */
#line 233 "syntax_analyzer.y"
                             {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1697 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 59: /* stmt: LVal ADASS Expr SEMICOLON  */
#line 234 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1703 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 60: /* stmt: LVal SUASS Expr SEMICOLON  */
#line 235 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1709 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 61: /* stmt: LVal MUASS Expr SEMICOLON  */
#line 236 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1715 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 62: /* stmt: LVal DIASS Expr SEMICOLON  */
#line 237 "syntax_analyzer.y"
                            {(yyval.node) = node("stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1721 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 63: /* stmt: Expr SEMICOLON  */
#line 238 "syntax_analyzer.y"
                 {(yyval.node) = node("stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1727 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 64: /* stmt: Body  */
#line 239 "syntax_analyzer.y"
       {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1733 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 65: /* stmt: IFItem  */
#line 240 "syntax_analyzer.y"
         {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1739 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 66: /* stmt: WhileItem  */
#line 241 "syntax_analyzer.y"
            {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1745 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 67: /* stmt: jump_stmt  */
#line 242 "syntax_analyzer.y"
            {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1751 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 68: /* stmt: Forstmt  */
#line 243 "syntax_analyzer.y"
          {(yyval.node) = node("stmt", 1, (yyvsp[0].node));}
#line 1757 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 69: /* Forstmt: FOR LPARENTHESIS ForInit SEMICOLON ForCond SEMICOLON ForIncr RPARENTHESIS stmt  */
#line 247 "syntax_analyzer.y"
                                                                                 { (yyval.node) = node("Forstmt", 5, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1763 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 70: /* ForInit: Expr  */
#line 250 "syntax_analyzer.y"
       { (yyval.node) = node("ForInit", 1, (yyvsp[0].node)); }
#line 1769 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 71: /* ForInit: %empty  */
#line 251 "syntax_analyzer.y"
  { (yyval.node) = node("ForInit", 0); }
#line 1775 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 72: /* ForCond: Cond  */
#line 254 "syntax_analyzer.y"
       { (yyval.node) = node("ForCond", 1, (yyvsp[0].node)); }
#line 1781 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 73: /* ForCond: %empty  */
#line 255 "syntax_analyzer.y"
  { (yyval.node) = node("ForCond", 0); }
#line 1787 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 74: /* ForIncr: Expr  */
#line 258 "syntax_analyzer.y"
       { (yyval.node) = node("ForIncr", 1, (yyvsp[0].node)); }
#line 1793 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 75: /* ForIncr: %empty  */
#line 259 "syntax_analyzer.y"
  { (yyval.node) = node("ForIncr", 0); }
#line 1799 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 76: /* IFItem: IF LPARENTHESIS Cond RPARENTHESIS stmt  */
#line 264 "syntax_analyzer.y"
      { (yyval.node) = node("IFItem", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1805 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 77: /* IFItem: IF LPARENTHESIS Cond RPARENTHESIS stmt ELSE stmt  */
#line 266 "syntax_analyzer.y"
      { (yyval.node) = node("IFItem", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1811 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 78: /* WhileItem: WHILE LPARENTHESIS Cond RPARENTHESIS stmt  */
#line 273 "syntax_analyzer.y"
                                            {(yyval.node) = node("WhileItem", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1817 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 79: /* jump_stmt: RETURN Expr SEMICOLON  */
#line 277 "syntax_analyzer.y"
                        { (yyval.node) = node("jump_stmt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1823 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 80: /* jump_stmt: RETURN SEMICOLON  */
#line 278 "syntax_analyzer.y"
                   { (yyval.node) = node("jump_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1829 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 81: /* jump_stmt: BREAK SEMICOLON  */
#line 279 "syntax_analyzer.y"
                  { (yyval.node) = node("jump_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1835 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 82: /* jump_stmt: CONTINUE SEMICOLON  */
#line 280 "syntax_analyzer.y"
                     { (yyval.node) = node("jump_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1841 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 83: /* Expr: Add_Expr  */
#line 284 "syntax_analyzer.y"
           {(yyval.node) = node("Expr", 1, (yyvsp[0].node));}
#line 1847 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 84: /* Cond: OR_Expr  */
#line 288 "syntax_analyzer.y"
          {(yyval.node) = node("Cond", 1, (yyvsp[0].node));}
#line 1853 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 85: /* LVal: IDENT ExpList  */
#line 292 "syntax_analyzer.y"
                {(yyval.node) = node("LVal", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1859 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 86: /* Primary_Expr: LPARENTHESIS Expr RPARENTHESIS  */
#line 296 "syntax_analyzer.y"
                                 {(yyval.node) = node("Primary_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1865 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 87: /* Primary_Expr: LVal  */
#line 297 "syntax_analyzer.y"
       {(yyval.node) = node("Primary_Expr", 1, (yyvsp[0].node));}
#line 1871 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 88: /* Primary_Expr: Number  */
#line 298 "syntax_analyzer.y"
         {(yyval.node) = node("Primary_Expr", 1, (yyvsp[0].node));}
#line 1877 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 89: /* Number: Integer  */
#line 302 "syntax_analyzer.y"
          {(yyval.node) = node("Number", 1, (yyvsp[0].node));}
#line 1883 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 90: /* Number: Floatnum  */
#line 303 "syntax_analyzer.y"
           {(yyval.node) = node("Number", 1, (yyvsp[0].node));}
#line 1889 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 91: /* Unary_Expr: Primary_Expr  */
#line 307 "syntax_analyzer.y"
               {(yyval.node) = node("Unary_Expr", 1, (yyvsp[0].node));}
#line 1895 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 92: /* Unary_Expr: Func_Expr  */
#line 308 "syntax_analyzer.y"
                {(yyval.node) = node("Unary_Expr", 1, (yyvsp[0].node));}
#line 1901 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 93: /* Unary_Expr: ADD Unary_Expr  */
#line 309 "syntax_analyzer.y"
                 {(yyval.node) = node("Unary_Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1907 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 94: /* Unary_Expr: SUB Unary_Expr  */
#line 310 "syntax_analyzer.y"
                 {(yyval.node) = node("Unary_Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1913 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 95: /* Unary_Expr: NOT Unary_Expr  */
#line 311 "syntax_analyzer.y"
                 {(yyval.node) = node("Unary_Expr", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1919 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 96: /* Func_Expr: IDENT LPARENTHESIS FuncRParams RPARENTHESIS  */
#line 315 "syntax_analyzer.y"
                                              {(yyval.node) = node("Func_Expr", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1925 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 97: /* Func_Expr: IDENT LPARENTHESIS RPARENTHESIS  */
#line 316 "syntax_analyzer.y"
                                  {(yyval.node) = node("Func_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1931 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 98: /* FuncRParams: Expr  */
#line 320 "syntax_analyzer.y"
       {(yyval.node) = node("FuncRParams", 1, (yyvsp[0].node));}
#line 1937 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 99: /* FuncRParams: FuncRParams COMMA Expr  */
#line 321 "syntax_analyzer.y"
                         {(yyval.node) = node("FuncRParams", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1943 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 100: /* MDM_Expr: Unary_Expr  */
#line 325 "syntax_analyzer.y"
             {(yyval.node) = node("MDM_Expr", 1, (yyvsp[0].node));}
#line 1949 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 101: /* MDM_Expr: MDM_Expr MUL Unary_Expr  */
#line 326 "syntax_analyzer.y"
                          {(yyval.node) = node("MDM_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1955 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 102: /* MDM_Expr: MDM_Expr DIV Unary_Expr  */
#line 327 "syntax_analyzer.y"
                          {(yyval.node) = node("MDM_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1961 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 103: /* MDM_Expr: MDM_Expr MOD Unary_Expr  */
#line 328 "syntax_analyzer.y"
                          {(yyval.node) = node("MDM_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1967 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 104: /* Add_Expr: MDM_Expr  */
#line 332 "syntax_analyzer.y"
           {(yyval.node) = node("Add_Expr", 1, (yyvsp[0].node));}
#line 1973 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 105: /* Add_Expr: Add_Expr ADD MDM_Expr  */
#line 333 "syntax_analyzer.y"
                        {(yyval.node) = node("Add_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1979 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 106: /* Add_Expr: Add_Expr SUB MDM_Expr  */
#line 334 "syntax_analyzer.y"
                        {(yyval.node) = node("Add_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1985 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 107: /* Rel_Expr: Add_Expr  */
#line 338 "syntax_analyzer.y"
           {(yyval.node) = node("Rel_Expr", 1, (yyvsp[0].node));}
#line 1991 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 108: /* Rel_Expr: Rel_Expr LT Add_Expr  */
#line 339 "syntax_analyzer.y"
                       {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1997 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 109: /* Rel_Expr: Rel_Expr LET Add_Expr  */
#line 340 "syntax_analyzer.y"
                        {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2003 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 110: /* Rel_Expr: Rel_Expr GT Add_Expr  */
#line 341 "syntax_analyzer.y"
                       {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2009 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 111: /* Rel_Expr: Rel_Expr GET Add_Expr  */
#line 342 "syntax_analyzer.y"
                        {(yyval.node) = node("Rel_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2015 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 112: /* Eq_Expr: Rel_Expr  */
#line 346 "syntax_analyzer.y"
           {(yyval.node) = node("Eq_Expr", 1, (yyvsp[0].node));}
#line 2021 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 113: /* Eq_Expr: Eq_Expr EQ Rel_Expr  */
#line 347 "syntax_analyzer.y"
                      {(yyval.node) = node("Eq_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2027 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 114: /* Eq_Expr: Eq_Expr NEQ Rel_Expr  */
#line 348 "syntax_analyzer.y"
                       {(yyval.node) = node("Eq_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2033 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 115: /* And_expr: Eq_Expr  */
#line 352 "syntax_analyzer.y"
          {(yyval.node) = node("And_expr", 1, (yyvsp[0].node));}
#line 2039 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 116: /* And_expr: And_expr AND Eq_Expr  */
#line 353 "syntax_analyzer.y"
                       {(yyval.node) = node("And_expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2045 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 117: /* OR_Expr: And_expr  */
#line 357 "syntax_analyzer.y"
           {(yyval.node) = node("OR_Expr", 1, (yyvsp[0].node));}
#line 2051 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 118: /* OR_Expr: OR_Expr OR And_expr  */
#line 358 "syntax_analyzer.y"
                      {(yyval.node) = node("OR_Expr", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2057 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 119: /* Integer: INTCONST  */
#line 362 "syntax_analyzer.y"
           {(yyval.node) = node("Integer", 1, (yyvsp[0].node));}
#line 2063 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;

  case 120: /* Floatnum: FLOATCONST  */
#line 366 "syntax_analyzer.y"
             {(yyval.node) = node("Floatnum", 1, (yyvsp[0].node));}
#line 2069 "/home/test/IR/src/parser/syntax_analyzer.c"
    break;


#line 2073 "/home/test/IR/src/parser/syntax_analyzer.c"

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

#line 368 "syntax_analyzer.y"


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
