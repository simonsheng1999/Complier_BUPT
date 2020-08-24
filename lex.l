%{

#include "compile.h"		//lex和yacc要共用的头文件，里面包含了一些头文件，重定义了YYSTYPE
#include "yacc.tab.h"	    //用yacc编译yacc.y后生成的C头文件，内含%token、YYSTYPE、yylval等定义(都是C宏)，供lex.yy.c和yacc.tab.c使用


// 外部变量声明，yytext和yyin分别为字符指针和文件指针
// 这两个变量在lex提供的库中被定义，因此我们如果想要使用，必须添加extern声明

int line = 1;

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

%%

\n                           {line++;}

{A}{N}{D}                    {yylval = newNode(AND, yytext, line); 
                              return(AND);
                              }
{A}{R}{R}{A}{Y}              {yylval = newNode(ARRAY, yytext, line); 
                              return(ARRAY);
                              }
{C}{O}{N}{S}{T}              {yylval = newNode(CONST, yytext, line); 
                              return(CONST);
                              }
{D}{I}{V}                    {yylval = newNode(DIV, yytext, line); 
                              return(DIV);
                              }
{D}{O}                       {yylval = newNode(DO, yytext, line); 
                              return(DO);
                              }
{E}{L}{S}{E}                 {yylval = newNode(ELSE, yytext, line); 
                              return(ELSE);
                              }
{E}{N}{D}                    {yylval = newNode(END, yytext, line); 
                              return(END);
                              }
{F}{O}{R}                    {yylval = newNode(FOR, yytext, line); 
                              return(FOR);
                              }
{F}{U}{N}{C}{T}{I}{O}{N}     {yylval = newNode(FUNCTION, yytext, line); 
                              return(FUNCTION);
                              }
{I}{F}                       {yylval = newNode(IF, yytext, line); 
                              return(IF);
                              }
{M}{O}{D}                    {yylval = newNode(MOD, yytext, line); 
                              return(MOD);
                              }
{N}{O}{T}                    {yylval = newNode(NOT, yytext, line); 
                              return(NOT);
                              }
{O}{F}                       {yylval = newNode(OF, yytext, line); 
                              return(OF);
                              } 
{O}{R}                       {yylval = newNode(OR, yytext, line); 
                              return(OR);
                              }
{B}{E}{G}{I}{N}              {yylval = newNode(PBEGIN, yytext, line); 
                              return(PBEGIN);
                              }
{P}{R}{O}{C}{E}{D}{U}{R}{E}  {yylval = newNode(PROCEDURE, yytext, line); 
                              return(PROCEDURE);
                              }
{P}{R}{O}{G}{R}{A}{M}        {yylval = newNode(PROGRAM, yytext, line); 
                              return(PROGRAM);
                              }
{T}{H}{E}{N}                 {yylval = newNode(THEN, yytext, line); 
                              return(THEN);
                              }
{T}{O}                       {yylval = newNode(TO, yytext, line); 
                              return(TO);
                              }
{V}{A}{R}                    {yylval = newNode(VAR, yytext, line); 
                              return(VAR);
                              }
{W}{H}{I}{L}{E}              {yylval = newNode(WHILE, yytext, line); 
                              return(WHILE);
                              }
{R}{E}{A}{D}                 {yylval = newNode(READ, yytext, line); 
                              return(READ);
                              }
{W}{R}{I}{T}{E}              {yylval = newNode(WRITE, yytext, line); 
                              return(WRITE);
                              }
{I}{N}{T}{E}{G}{E}{R}        {yylval = newNode(INTEGER, yytext, line); 
                              return(INTEGER);
                              }
{R}{E}{A}{L}                 {yylval = newNode(REAL, yytext, line); 
                              return(REAL);
                              }
{C}{H}{A}{R}                 {yylval = newNode(CHAR, yytext, line); 
                              return(CHAR);
                              }
{B}{O}{O}{L}{E}{A}{N}         {yylval = newNode(BOOLEAN, yytext, line); 
                              return(BOOLEAN);
                              }
"\'[a-zA-Z]\'"                {yylval = newNode(LETTER, yytext, line); 
                              return(LETTER);
                              }
[a-zA-Z]([a-zA-Z0-9])*       {yylval = newNode(IDENTIFIER, yytext, line); 
                              return(IDENTIFIER);
                              }
":="                         {yylval = newNode(ASSIGNOP, yytext, line); 
                              return(ASSIGNOP);
                              }
":"                          {yylval = newNode(COLON, yytext, line); 
                              return(COLON);
                              }
","                          {yylval = newNode(COMMA, yytext, line); 
                              return(COMMA);
                              }
[0-9]+                       {yylval = newNode(DIGSEQ, yytext, line); 
                              return(DIGSEQ);
                              }
"."                          {yylval = newNode(DOT, yytext, line); 
                              return(DOT);
                              }
".."                         {yylval = newNode(DOTDOT, yytext, line); 
                              return(DOTDOT);
                              }
"="                          {yylval = newNode(EQUAL, yytext, line); 
                              return(EQUAL);
                              }
"<>"                         {yylval = newNode(notEQUAL, yytext, line); 
                              return(notEQUAL);
                              }
">="                         {yylval = newNode(GE, yytext, line); 
                              return(GE);
                              }
">"                          {yylval = newNode(GT, yytext, line); 
                              return(GT);
                              }
"["                          {yylval = newNode(LBRAC, yytext, line); 
                              return(LBRAC);
                              }
"<="                         {yylval = newNode(LE, yytext, line); 
                              return(LE);
                              }
"("                          {yylval = newNode(LPAREN, yytext, line); 
                              return(LPAREN);
                              }
"<"                          {yylval = newNode(LT, yytext, line); 
                              return(LT);
                              }
"-"                          {yylval = newNode(MINUS, yytext, line); 
                              return(MINUS);
                              }
"+"                          {yylval = newNode(PLUS, yytext, line); 
                              return(PLUS);
                              }
"]"                          {yylval = newNode(RBRAC, yytext, line); 
                              return(RBRAC);
                              }
[0-9]+"."[0-9]+              {yylval = newNode(REALNUMBER, yytext, line); 
                              return(REALNUMBER);
                              }
")"                          {yylval = newNode(RPAREN, yytext, line); 
                              return(RPAREN);
                              }
";"                          {yylval = newNode(SEMICOLON, yytext, line); 
                              return(SEMICOLON);
                              }
"/"                          {yylval = newNode(SLASH, yytext, line); 
                              return(SLASH);
                              }
"*"                          {yylval = newNode(STAR, yytext, line); 
                              return(STAR);
                              }
[" "\t\f]    ;
\r           ;


.    {yyerror("Error:invalid input.\n");}

%%


int yywrap(void)
{
	puts("-----the file is end");
	return 1;								//返回1表示读取全部结束。如果要接着读其它文件，可以这里fopen该文件，文件指针赋给yyin，并返回0
}

