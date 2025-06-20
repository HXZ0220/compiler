%option noyywrap
%{
/*****************声明和选项设置  begin*****************/
#include <stdio.h>
#include <stdlib.h>

#include "syntax_tree.h"
#include "syntax_analyzer.h"
#define MAX_LINE_LENGTH 1024

int lines=1;
int pos_start;
int pos_end;
int currentline=1;
int linelenth=0;
char line_buffer[MAX_LINE_LENGTH]="";


void pass_node(char *text){
     yylval.node = new_syntax_tree_node(text);
}

/*****************声明和选项设置  end*****************/
void lexical_error(const char *msg) {
    fprintf(stderr, "Lexical Error at line %d, column %d: %s ('%s'). Current line content: '%s'\n",
            lines, pos_start, msg, yytext, line_buffer);
    exit(1);
}

void update_token_info() {
    pos_start = pos_end;
    pos_end += yyleng;
    if (linelenth + yyleng >= MAX_LINE_LENGTH-1) {
        fprintf(stderr, "Error: Line %d exceeds maximum length of %d characters. Content: '%s'\n",
                lines, MAX_LINE_LENGTH - 1, line_buffer); 
        exit(1); 
    }
    
    for (int j = 0; j < yyleng; j++) { 
        line_buffer[linelenth + j] = yytext[j]; 
    }
    linelenth += yyleng;
    line_buffer[linelenth] = '\0';

    if(lines!=currentline){
        pos_end=0;
        currentline+=1;
        linelenth=0;
        line_buffer[0] = '\0';
    }
}

%}


%%
 /* to do for students */
 /* two cases for you, pass_node will send flex's token to bison */
\/\*([^*]|\*+[^/])*\*+\/ {
    char *p = yytext;
    while (*p) {
        if (*p == '\n') {
            lines++;
        } 
        update_token_info();
        p++;
    }
}

\/\/.* {
    if (yytext[yyleng - 1] == '\n') {
        lines++;
        update_token_info();
    } 
}

[ \t]     {update_token_info();}  
\n   {lines += 1;update_token_info();}


"int"       { update_token_info(); pass_node(yytext); return INT;}
"float"     { update_token_info(); pass_node(yytext); return FLOAT;}
"void"      { update_token_info(); pass_node(yytext); return VOID;}
"const"     { update_token_info(); pass_node(yytext); return CONST;}
"main"      { update_token_info(); pass_node(yytext); return MAIN;}
"if"        { update_token_info(); pass_node(yytext); return IF;}
"else"      { update_token_info(); pass_node(yytext); return ELSE;}
"while"     { update_token_info(); pass_node(yytext); return WHILE;}
"break"     { update_token_info(); pass_node(yytext); return BREAK;}
"continue"  { update_token_info(); pass_node(yytext); return CONTINUE;}
"return"    { update_token_info(); pass_node(yytext); return RETURN;}
"for"       { update_token_info(); pass_node(yytext); return FOR;}


"+=" { update_token_info(); pass_node(yytext); return ADASS;}
"-=" { update_token_info(); pass_node(yytext); return SUASS;}
"*=" { update_token_info(); pass_node(yytext); return MUASS;}
"/=" { update_token_info(); pass_node(yytext); return DIASS;}
"<=" { update_token_info(); pass_node(yytext); return LET;}
">=" { update_token_info(); pass_node(yytext); return GET;}
"==" { update_token_info(); pass_node(yytext); return EQ;}
"!=" { update_token_info(); pass_node(yytext); return NEQ;}
"&&" { update_token_info(); pass_node(yytext); return AND;}
"||" { update_token_info(); pass_node(yytext); return OR;}

"+" { update_token_info(); pass_node(yytext); return ADD;}
"-" { update_token_info(); pass_node(yytext); return SUB;}
"*" { update_token_info(); pass_node(yytext); return MUL;}
"/" { update_token_info(); pass_node(yytext); return DIV;}
"%" { update_token_info(); pass_node(yytext); return MOD;}
"<" { update_token_info(); pass_node(yytext); return LT;}
">" { update_token_info(); pass_node(yytext); return GT;}
"(" { update_token_info(); pass_node(yytext); return LPARENTHESIS;}
")" { update_token_info(); pass_node(yytext); return RPARENTHESIS;}
"[" { update_token_info(); pass_node(yytext); return LBRACKET;}
"]" { update_token_info(); pass_node(yytext); return RBRACKET;}
"{" { update_token_info(); pass_node(yytext); return LBRACE;}
"}" { update_token_info(); pass_node(yytext); return RBRACE;}
"=" { update_token_info(); pass_node(yytext); return ASSIGN;}
"," { update_token_info(); pass_node(yytext); return COMMA;}
";" { update_token_info(); pass_node(yytext); return SEMICOLON;}
"!" { update_token_info(); pass_node(yytext); return NOT;}


[1-9][0-9]* { update_token_info(); pass_node(yytext); return INTCONST;}
0[0-7]* { update_token_info(); pass_node(yytext); return INTCONST;} 
0[xX][0-9a-fA-F]+ { update_token_info(); pass_node(yytext); return INTCONST;} 

[0-9]+[eE][-+]?[0-9]+             { update_token_info(); pass_node(yytext); return FLOATCONST;}
[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?  { update_token_info(); pass_node(yytext); return FLOATCONST;} 
[0-9]+\.[0-9]*([eE][-+]?[0-9]+)?  { update_token_info(); pass_node(yytext); return FLOATCONST;} 
0[xX][0-9a-fA-F]+[pP][-+]?[0-9]+  { update_token_info(); pass_node(yytext); return FLOATCONST;} 
0[xX][0-9a-fA-F]*\.[0-9a-fA-F]+([pP][-+]?[0-9]+)? { update_token_info(); pass_node(yytext); return FLOATCONST;} 

[a-zA-Z_][a-zA-Z_0-9]* { update_token_info(); pass_node(yytext); return IDENT;}

. {
    pos_start = pos_end; 
    pos_end += yyleng;   
    update_token_info(); 
    lexical_error("Unrecognized character");
}


%%