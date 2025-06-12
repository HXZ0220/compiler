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

#ifndef YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
# define YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
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
    LOWER_THAN_ELSE = 258,         /* LOWER_THAN_ELSE  */
    ERROR = 259,                   /* ERROR  */
    ADD = 260,                     /* ADD  */
    SUB = 261,                     /* SUB  */
    MUL = 262,                     /* MUL  */
    DIV = 263,                     /* DIV  */
    MOD = 264,                     /* MOD  */
    ADASS = 265,                   /* ADASS  */
    SUASS = 266,                   /* SUASS  */
    MUASS = 267,                   /* MUASS  */
    DIASS = 268,                   /* DIASS  */
    LT = 269,                      /* LT  */
    LET = 270,                     /* LET  */
    GT = 271,                      /* GT  */
    GET = 272,                     /* GET  */
    EQ = 273,                      /* EQ  */
    NEQ = 274,                     /* NEQ  */
    LPARENTHESIS = 275,            /* LPARENTHESIS  */
    RPARENTHESIS = 276,            /* RPARENTHESIS  */
    LBRACKET = 277,                /* LBRACKET  */
    RBRACKET = 278,                /* RBRACKET  */
    LBRACE = 279,                  /* LBRACE  */
    RBRACE = 280,                  /* RBRACE  */
    ASSIGN = 281,                  /* ASSIGN  */
    COMMA = 282,                   /* COMMA  */
    SEMICOLON = 283,               /* SEMICOLON  */
    NOT = 284,                     /* NOT  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    INT = 287,                     /* INT  */
    FLOAT = 288,                   /* FLOAT  */
    VOID = 289,                    /* VOID  */
    CONST = 290,                   /* CONST  */
    MAIN = 291,                    /* MAIN  */
    IF = 292,                      /* IF  */
    ELSE = 293,                    /* ELSE  */
    WHILE = 294,                   /* WHILE  */
    BREAK = 295,                   /* BREAK  */
    CONTINUE = 296,                /* CONTINUE  */
    RETURN = 297,                  /* RETURN  */
    FOR = 298,                     /* FOR  */
    IDENT = 299,                   /* IDENT  */
    INTCONST = 300,                /* INTCONST  */
    FLOATCONST = 301,              /* FLOATCONST  */
    LOWER_THAN_ASIGN = 302         /* LOWER_THAN_ASIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "syntax_analyzer.y"

    struct _syntax_tree_node* node;

#line 115 "syntax_analyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED  */
