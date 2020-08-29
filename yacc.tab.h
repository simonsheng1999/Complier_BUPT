/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    LETTER = 259,
    SQUOTATION = 260,
    ELSE = 261,
    CHARACTER_STRING = 262,
    DQUOTATION = 263,
    ARRAY = 264,
    DIGSEQ = 265,
    MULTIP = 266,
    DIVIDE = 267,
    AND = 268,
    ARRAR = 269,
    PBEGIN = 270,
    BOOLEAN = 271,
    CASE = 272,
    CHAR = 273,
    CONST = 274,
    DIV = 275,
    DO = 276,
    DOWNTO = 277,
    END = 278,
    FOR = 279,
    FUNCTION = 280,
    IF = 281,
    MOD = 282,
    STRING = 283,
    NOT = 284,
    OF = 285,
    OR = 286,
    PROCEDURE = 287,
    PROGRAM = 288,
    REAL = 289,
    RECORD = 290,
    REPEAT = 291,
    THEN = 292,
    TO = 293,
    TYPE = 294,
    UNTIL = 295,
    VAR = 296,
    WHILE = 297,
    SUBBOUNDARY = 298,
    ASSIGNOP = 299,
    LE = 300,
    GE = 301,
    EQ = 302,
    NE = 303,
    notEQUAL = 304,
    EQUAL = 305,
    IDENTIFIER = 306,
    READ = 307,
    WRITE = 308,
    REALNUMBER = 309,
    EQUL = 310,
    LT = 311,
    GT = 312,
    COMMA = 313,
    COLON = 314,
    SEMICOLON = 315,
    DOT = 316,
    DOTDOT = 317,
    LPAREN = 318,
    RPAREN = 319,
    LBRAC = 320,
    RBRAC = 321,
    PLUS = 322,
    MINUS = 323,
    SLASH = 324,
    STAR = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
