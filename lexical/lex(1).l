%{

#include "compile.h"		//lex和yacc要共用的头文件，里面包含了一些头文件，重定义了YYSTYPE
#include "yacc.tab.h"	    //用yacc编译yacc.y后生成的C头文件，内含%token、YYSTYPE、yylval等定义(都是C宏)，供lex.yy.c和yacc.tab.c使用


// 外部变量声明，yytext和yyin分别为字符指针和文件指针
// 这两个变量在lex提供的库中被定义，因此我们如果想要使用，必须添加extern声明

int line = 1;
ATRNode last_word;

%}

%x COMMENT


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
DQ ["]

%%

\n                           {line++;}

{A}{N}{D}                    {yylval = newNode(AND, yytext, line); last_word = yylval; 
                              return(AND);
                              }
{A}{R}{R}{A}{Y}              {yylval = newNode(ARRAY, yytext, line); last_word = yylval; 
                              return(ARRAY);
                              }
{C}{O}{N}{S}{T}              {yylval = newNode(CONST, yytext, line); last_word = yylval; 
                              return(CONST);
                              }
{D}{I}{V}                    {yylval = newNode(DIV, yytext, line); last_word = yylval; 
                              return(DIV);
                              }
{D}{O}                       {yylval = newNode(DO, yytext, line); last_word = yylval; 
                              return(DO);
                              }
{D}{O}{W}{N}{T}{O}            {yylval = newNode(DOWNTO, yytext, line); last_word = yylval; 
                              return(DOWNTO);
                              }
{E}{L}{S}{E}                 {yylval = newNode(ELSE, yytext, line); last_word = yylval; 
                              return(ELSE);
                              }
{E}{N}{D}                    {yylval = newNode(END, yytext, line); last_word = yylval; 
                              return(END);
                              }
{F}{O}{R}                    {yylval = newNode(FOR, yytext, line); last_word = yylval; 
                              return(FOR);
                              }
{F}{U}{N}{C}{T}{I}{O}{N}     {yylval = newNode(FUNCTION, yytext, line); last_word = yylval; 
                              return(FUNCTION);
                              }
{I}{F}                       {yylval = newNode(IF, yytext, line); last_word = yylval; 
                              return(IF);
                              }
{M}{O}{D}                    {yylval = newNode(MOD, yytext, line); last_word = yylval; 
                              return(MOD);
                              }
{N}{O}{T}                    {yylval = newNode(NOT, yytext, line); last_word = yylval; 
                              return(NOT);
                              }
{O}{F}                       {yylval = newNode(OF, yytext, line); last_word = yylval; 
                              return(OF);
                              } 
{O}{R}                       {yylval = newNode(OR, yytext, line); last_word = yylval; 
                              return(OR);
                              }
{B}{E}{G}{I}{N}              {yylval = newNode(PBEGIN, yytext, line); last_word = yylval; 
                              return(PBEGIN);
                              }
{P}{R}{O}{C}{E}{D}{U}{R}{E}  {yylval = newNode(PROCEDURE, yytext, line); last_word = yylval; 
                              return(PROCEDURE);
                              }
{P}{R}{O}{G}{R}{A}{M}        {yylval = newNode(PROGRAM, yytext, line); last_word = yylval; 
                              return(PROGRAM);
                              }
{T}{H}{E}{N}                 {yylval = newNode(THEN, yytext, line); last_word = yylval; 
                              return(THEN);
                              }
{T}{O}                       {yylval = newNode(TO, yytext, line); last_word = yylval; 
                              return(TO);
                              }
{V}{A}{R}                    {yylval = newNode(VAR, yytext, line); last_word = yylval; 
                              return(VAR);
                              }
{W}{H}{I}{L}{E}              {yylval = newNode(WHILE, yytext, line); last_word = yylval; 
                              return(WHILE);
                              }
{R}{E}{A}{D}                 {yylval = newNode(READ, yytext, line); last_word = yylval; 
                              return(READ);
                              }
{W}{R}{I}{T}{E}              {yylval = newNode(WRITE, yytext, line); last_word = yylval; 
                              return(WRITE);
                              }
{I}{N}{T}{E}{G}{E}{R}        {yylval = newNode(INTEGER, yytext, line); last_word = yylval; 
                              return(INTEGER);
                              }
{R}{E}{A}{L}                 {yylval = newNode(REAL, yytext, line); last_word = yylval; 
                              return(REAL);
                              }
{C}{H}{A}{R}                 {yylval = newNode(CHAR, yytext, line); last_word = yylval; 
                              return(CHAR);
                              }
{B}{O}{O}{L}{E}{A}{N}         {yylval = newNode(BOOLEAN, yytext, line); last_word = yylval; 
                              return(BOOLEAN);
                              }
"'"."'"                     {yylval = newNode(LETTER, yytext, line); last_word = yylval; 
                              return(LETTER);
                              }
{DQ}.*{DQ}                    {yylval = newNode(STRING, yytext, line); last_word = yylval; 
                              return(STRING);
                            }
[a-zA-Z]([a-zA-Z0-9])*       {yylval = newNode(IDENTIFIER, yytext, line); last_word = yylval; 
                              return(IDENTIFIER);
                              }
":="                         {yylval = newNode(ASSIGNOP, yytext, line); last_word = yylval; 
                              return(ASSIGNOP);
                              }
":"                          {yylval = newNode(COLON, yytext, line); last_word = yylval; 
                              return(COLON);
                              }
","                          {yylval = newNode(COMMA, yytext, line); last_word = yylval; 
                              return(COMMA);
                              }
[0-9]+                       {yylval = newNode(DIGSEQ, yytext, line); last_word = yylval; 
                              return(DIGSEQ);
                              }
"."                          {yylval = newNode(DOT, yytext, line); last_word = yylval; 
                              return(DOT);
                              }
".."                         {yylval = newNode(DOTDOT, yytext, line); last_word = yylval; 
                              return(DOTDOT);
                              }
"="                          {yylval = newNode(EQUAL, yytext, line); last_word = yylval; 
                              return(EQUAL);
                              }
"<>"                         {yylval = newNode(notEQUAL, yytext, line); last_word = yylval; 
                              return(notEQUAL);
                              }
">="                         {yylval = newNode(GE, yytext, line); last_word = yylval; 
                              return(GE);
                              }
">"                          {yylval = newNode(GT, yytext, line); last_word = yylval; 
                              return(GT);
                              }
"["                          {yylval = newNode(LBRAC, yytext, line); last_word = yylval; 
                              return(LBRAC);
                              }
"<="                         {yylval = newNode(LE, yytext, line); last_word = yylval; 
                              return(LE);
                              }
"("                          {yylval = newNode(LPAREN, yytext, line); last_word = yylval; 
                              return(LPAREN);
                              }
"<"                          {yylval = newNode(LT, yytext, line); last_word = yylval; 
                              return(LT);
                              }
"-"                          {yylval = newNode(MINUS, yytext, line); last_word = yylval; 
                              return(MINUS);
                              }
"+"                          {yylval = newNode(PLUS, yytext, line); last_word = yylval; 
                              return(PLUS);
                              }
"]"                          {yylval = newNode(RBRAC, yytext, line); last_word = yylval; 
                              return(RBRAC);
                              }
[0-9]+"."[0-9]+              {yylval = newNode(REALNUMBER, yytext, line); last_word = yylval; 
                              return(REALNUMBER);
                              }
")"                          {yylval = newNode(RPAREN, yytext, line); last_word = yylval; 
                              return(RPAREN);
                              }
";"                          {yylval = newNode(SEMICOLON, yytext, line); last_word = yylval; 
                              return(SEMICOLON);
                              }
"/"                          {yylval = newNode(SLASH, yytext, line); last_word = yylval; 
                              return(SLASH);
                              }
"*"                          {yylval = newNode(STAR, yytext, line); last_word = yylval; 
                              return(STAR);
                              }
[" "\t\f]    ;
\r           ;

"//"			                    {BEGIN COMMENT;	//用BEGIN宏切换到注释状态，去过滤这段注释，下一次lex将只匹配前面带有<COMMENT>的正则式
				                      }
.                             {
                              string error_desc = "Last detected token: " + last_word.attr;
                              cout << "Lexial error: invalid input at line " << line << endl;
                              cout << error_desc << endl;
                              exit(80);
                              }
<COMMENT>\n		              {line++;
                               BEGIN INITIAL;			//在注释状态下，当遇到换行符时，表明注释结束了，返回初始态
				                      }
<COMMENT>.		              {							
                              }

%%


int yywrap(void)
{
	puts("-----the file is end");
	return 1;								//返回1表示读取全部结束。如果要接着读其它文件，可以这里fopen该文件，文件指针赋给yyin，并返回0
}

