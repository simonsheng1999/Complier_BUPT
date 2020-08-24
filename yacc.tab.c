/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

/*本yacc的生成文件是yacc.tab.c和yacc.tab.h
yacc文件由3段组成，用2个%%行把这3段隔开。
第1段是声明段，包括：
1-C代码部分：include头文件、函数、类型等声明，这些声明会原样拷到生成的.c文件中。
2-记号声明，如%token
3-类型声明，如%type
第2段是规则段，是yacc文件的主体，包括每个产生式是如何匹配的，以及匹配后要执行的C代码动作。
第3段是C函数定义段，如yyerror()的定义，这些C代码会原样拷到生成的.c文件中。该段内容可以为空*/

//第1段：声明段
#include "compile.h"	//lex和yacc要共用的头文件，里面包含了一些头文件，重定义了YYSTYPE
ATRNode p;

ATRNode root_node;

int layer=0;

#line 85 "yacc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc.tab.h".  */
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
    NOT = 283,
    OF = 284,
    OR = 285,
    PROCEDURE = 286,
    PROGRAM = 287,
    REAL = 288,
    RECORD = 289,
    REPEAT = 290,
    THEN = 291,
    TO = 292,
    TYPE = 293,
    UNTIL = 294,
    VAR = 295,
    WHILE = 296,
    SUBBOUNDARY = 297,
    ASSIGNOP = 298,
    LE = 299,
    GE = 300,
    EQ = 301,
    NE = 302,
    notEQUAL = 303,
    EQUAL = 304,
    IDENTIFIER = 305,
    READ = 306,
    WRITE = 307,
    REALNUMBER = 308,
    EQUL = 309,
    LT = 310,
    GT = 311,
    COMMA = 312,
    COLON = 313,
    SEMICOLON = 314,
    DOT = 315,
    DOTDOT = 316,
    LPAREN = 317,
    RPAREN = 318,
    LBRAC = 319,
    RBRAC = 320,
    PLUS = 321,
    MINUS = 322,
    SLASH = 323,
    STAR = 324
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

/* Copy the second part of user declarations.  */

#line 206 "yacc.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    50,    60,    71,    84,    92,   102,   111,
     118,   128,   140,   148,   155,   161,   176,   183,   193,   202,
     209,   219,   231,   237,   252,   258,   264,   270,   280,   290,
     302,   311,   318,   330,   340,   352,   361,   368,   376,   386,
     392,   402,   413,   425,   434,   441,   452,   460,   470,   478,
     484,   490,   500,   513,   522,   531,   541,   548,   556,   566,
     578,   587,   595,   601,   614,   622,   629,   637,   647,   655,
     665,   671,   683,   691,   701,   707,   713,   722,   730,   737,
     748,   754,   760,   766,   772,   778,   787,   793,   799,   809,
     815,   821,   827,   833
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "LETTER", "SQUOTATION",
  "ELSE", "CHARACTER_STRING", "DQUOTATION", "ARRAY", "DIGSEQ", "MULTIP",
  "DIVIDE", "AND", "ARRAR", "PBEGIN", "BOOLEAN", "CASE", "CHAR", "CONST",
  "DIV", "DO", "DOWNTO", "END", "FOR", "FUNCTION", "IF", "MOD", "NOT",
  "OF", "OR", "PROCEDURE", "PROGRAM", "REAL", "RECORD", "REPEAT", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "SUBBOUNDARY", "ASSIGNOP", "LE",
  "GE", "EQ", "NE", "notEQUAL", "EQUAL", "IDENTIFIER", "READ", "WRITE",
  "REALNUMBER", "EQUL", "LT", "GT", "COMMA", "COLON", "SEMICOLON", "DOT",
  "DOTDOT", "LPAREN", "RPAREN", "LBRAC", "RBRAC", "PLUS", "MINUS", "SLASH",
  "STAR", "$accept", "programstruct", "program_head", "program_body",
  "identifier_list", "const_declarations", "const_declaration",
  "const_value", "num", "var_declarations", "var_declaration", "type",
  "basic_type", "period", "subprogram_declarations", "subprogram",
  "subprogram_head", "formal_parameter", "parameter_list", "parameter",
  "var_parameter", "value_parameter", "subprogram_body",
  "compound_statement", "statement_list", "statement", "variable_list",
  "variable", "id_varpart", "procedure_call", "else_part",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "relop", "addop", "mulop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   -32,    40,   -25,    -8,  -124,    41,    51,    54,    64,
      72,  -124,    30,    73,    67,  -124,    51,  -124,    80,  -124,
       3,    81,    34,    74,     1,  -124,  -124,  -124,  -124,    -2,
      -2,  -124,  -124,    85,    11,    51,    56,    86,    87,    76,
      79,  -124,  -124,  -124,     3,  -124,    75,  -124,  -124,  -124,
    -124,  -124,    63,    90,    -5,    -5,    38,    82,    83,  -124,
       2,  -124,    98,  -124,    84,    84,  -124,    -7,  -124,   132,
      11,   104,    -5,   -31,    -5,    -5,  -124,  -124,   112,    29,
      -3,  -124,   128,    -5,    -5,  -124,   100,    -5,  -124,    56,
      -5,    -4,    93,  -124,    72,  -124,    91,     7,  -124,    -5,
    -124,    -5,    92,  -124,    56,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,    -5,    -5,  -124,  -124,  -124,  -124,
    -124,    -5,    56,    48,  -124,    33,    89,    52,  -124,    60,
    -124,  -124,    51,    71,     4,  -124,  -124,  -124,    25,   139,
     146,   147,   129,   122,    62,  -124,   154,     9,    -3,  -124,
    -124,    -5,  -124,  -124,   100,  -124,  -124,  -124,    25,    -4,
    -124,  -124,  -124,  -124,   101,    25,    -5,  -124,    56,  -124,
    -124,  -124,  -124,  -124,   151,  -124,   142,  -124,  -124,    56,
    -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     1,     9,     0,     0,     0,
      19,     7,     0,     0,     0,     2,     0,    31,     0,     3,
       0,     8,     0,     0,     0,     6,    15,    16,    17,     0,
       0,    11,    14,     0,     0,    18,    56,     0,     0,     0,
       0,     5,    12,    13,     0,    24,     0,    26,    27,    25,
      21,    22,     0,     0,     0,     0,    62,     0,     0,    50,
       0,    47,     0,    49,    36,    36,    30,     9,    10,     0,
       0,     0,     0,    61,     0,     0,    74,    75,     0,    69,
      70,    73,     0,     0,     0,    59,     0,     0,    45,    56,
       0,     0,     0,    34,    19,    32,     0,     0,    20,     0,
      78,     0,     0,    79,    56,    88,    83,    84,    85,    81,
      82,    80,    86,    87,     0,     0,    92,    93,    91,    90,
      89,     0,    56,     0,    67,     0,    61,     0,    58,     0,
      46,    48,     0,     0,     0,    38,    39,    40,     0,     0,
       0,     0,     0,     0,     0,    77,    65,    68,    71,    72,
      55,     0,    63,    60,     0,    53,    54,    41,     0,     0,
      35,    33,    43,    29,     0,     0,     0,    76,    56,    51,
      66,    57,    42,    37,     0,    23,     0,    64,    28,    56,
      52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -124,  -124,  -124,  -124,    14,    97,  -124,   121,    59,    77,
    -124,    96,  -123,  -124,  -124,  -124,  -124,   102,  -124,    10,
    -124,    36,  -124,   -23,  -124,   -85,  -124,   -36,  -124,  -124,
    -124,    26,   -52,    58,    55,   -66,  -124,  -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,   133,    10,    14,    31,    76,    17,
      23,    50,    51,    97,    24,    39,    40,    92,   134,   135,
     136,   137,    95,    59,    60,    61,   127,    77,    85,    63,
     169,   123,   124,    79,    80,    81,   114,   115,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    41,    78,    82,   130,    27,   100,    26,    27,   103,
     116,     1,     8,    27,    45,   161,    36,   117,     4,   146,
      46,    12,   102,    72,   118,    88,    37,    47,    45,    48,
      22,   101,    38,    84,     6,   172,   132,   150,   131,   105,
       5,    47,   175,    48,    49,    73,    11,   143,    28,    52,
     128,    28,   -44,    62,     7,   149,    28,    74,    49,   105,
       8,    89,    75,   159,   141,   119,   120,   160,    62,    29,
      30,    36,   142,   106,   107,   112,   113,   108,   109,    32,
      53,   -61,    54,   177,   110,   111,    62,    18,    42,    43,
     151,    18,    34,    19,   180,   112,   113,    55,   153,   170,
      83,    11,    84,    32,    13,   151,    56,    57,    58,   154,
     125,   152,    16,   129,   176,   155,   162,   151,   171,   151,
      18,    70,    20,   156,    15,   167,    21,   144,    18,   158,
      25,    33,    62,    35,    44,    66,    64,    65,    67,    69,
      71,    90,    96,    62,    86,    87,    91,    99,   104,   122,
     126,   138,   140,    84,    36,   145,   163,   164,   165,   166,
     168,   178,   174,   179,    94,    68,    98,    93,   157,   173,
     148,   139,   147
};

static const yytype_uint8 yycheck[] =
{
      36,    24,    54,    55,    89,    10,    72,     4,    10,    75,
      13,    32,    19,    10,     3,   138,    15,    20,    50,   104,
       9,     7,    74,    28,    27,    23,    25,    16,     3,    18,
      16,    62,    31,    64,    59,   158,    40,   122,    90,    30,
       0,    16,   165,    18,    33,    50,    50,    99,    53,    35,
      86,    53,    59,    89,    62,   121,    53,    62,    33,    30,
      19,    59,    67,    59,    57,    68,    69,    63,   104,    66,
      67,    15,    65,    44,    45,    66,    67,    48,    49,    20,
      24,    43,    26,   168,    55,    56,   122,    57,    29,    30,
      57,    57,    58,    63,   179,    66,    67,    41,    65,   151,
      62,    50,    64,    44,    50,    57,    50,    51,    52,    57,
      84,    63,    40,    87,   166,    63,   139,    57,   154,    57,
      57,    58,    49,    63,    60,    63,    59,   101,    57,    58,
      50,    50,   168,    59,    49,    59,    50,    50,    59,    64,
      50,    43,    10,   179,    62,    62,    62,    43,    36,    21,
      50,    58,    61,    64,    15,    63,    10,    10,    29,    37,
       6,    10,    61,    21,    67,    44,    70,    65,   132,   159,
     115,    94,   114
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    71,    72,    50,     0,    59,    62,    19,    73,
      75,    50,    74,    50,    76,    60,    40,    79,    57,    63,
      49,    59,    74,    80,    84,    50,     4,    10,    53,    66,
      67,    77,    78,    50,    58,    59,    15,    25,    31,    85,
      86,    93,    78,    78,    49,     3,     9,    16,    18,    33,
      81,    82,    74,    24,    26,    41,    50,    51,    52,    93,
      94,    95,    97,    99,    50,    50,    59,    59,    77,    64,
      58,    50,    28,    50,    62,    67,    78,    97,   102,   103,
     104,   105,   102,    62,    64,    98,    62,    62,    23,    59,
      43,    62,    87,    87,    75,    92,    10,    83,    81,    43,
     105,    62,   102,   105,    36,    30,    44,    45,    48,    49,
      55,    56,    66,    67,   106,   107,    13,    20,    27,    68,
      69,   108,    21,   101,   102,   101,    50,    96,    97,   101,
      95,   102,    40,    74,    88,    89,    90,    91,    58,    79,
      61,    57,    65,   102,   101,    63,    95,   103,   104,   105,
      95,    57,    63,    65,    57,    63,    63,    91,    58,    59,
      63,    82,    93,    10,    10,    29,    37,    63,     6,   100,
     102,    97,    82,    89,    61,    82,   102,    95,    10,    21,
      95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    91,    92,    92,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     106,   106,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     5,     2,     4,     3,     1,     3,     0,
       5,     3,     2,     2,     1,     1,     1,     1,     3,     0,
       5,     3,     1,     6,     1,     1,     1,     1,     5,     3,
       3,     0,     3,     5,     3,     3,     0,     3,     1,     1,
       1,     2,     3,     3,     0,     3,     3,     1,     3,     1,
       1,     5,     8,     4,     4,     4,     0,     3,     1,     2,
       3,     0,     1,     4,     2,     0,     3,     1,     3,     1,
       1,     3,     3,     1,     1,     1,     4,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 37 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"Program",0);
		p.children.push_back((yyvsp[-3]));
		p.children.push_back((yyvsp[-2]));
		p.children.push_back((yyvsp[-1]));
		p.children.push_back((yyvsp[0]));
		root_node=p;
		(yyval)=p;
	}
#line 1430 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"program_head",0);
		p.children.push_back((yyvsp[-4]));
		p.children.push_back((yyvsp[-3]));
		p.children.push_back((yyvsp[-2]));
		p.children.push_back((yyvsp[-1]));
		p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1444 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"program_head",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1455 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"program_body",0);
		p.children.push_back((yyvsp[-3]));
		p.children.push_back((yyvsp[-2]));
		p.children.push_back((yyvsp[-1]));
		p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1468 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"identifier_list",0);
		p.children.push_back((yyvsp[-2]));
		p.children.push_back((yyvsp[-1]));
		p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1480 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"identifier_list",0);
		p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1490 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"const_declarations",0);
		p.children.push_back((yyvsp[-2]));
		p.children.push_back((yyvsp[-1]));
		p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1502 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"const_declarations",0);
	}
#line 1510 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"const_declaration",0);
		p.children.push_back((yyvsp[-4]));
		p.children.push_back((yyvsp[-3]));
		p.children.push_back((yyvsp[-2]));
		p.children.push_back((yyvsp[-1]));
		p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1524 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"const_declaration",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1536 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"const_value",0);                        
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;

	}
#line 1548 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"const_value",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1559 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 156 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"const_value",0);       			
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1569 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 162 "yacc.y" /* yacc.c:1646  */
    {
		ATRNode node_1 = newNode(SQUOTATION, (yyvsp[0]).attr.substr(0,1), (yyvsp[0]).line);
		ATRNode node_2 = newNode(SQUOTATION, (yyvsp[0]).attr.substr(1,1), (yyvsp[0]).line);
		ATRNode node_3 = newNode(SQUOTATION, (yyvsp[0]).attr.substr(2,1), (yyvsp[0]).line);
        p=newNode(-1,"const_value",0);       			
        p.children.push_back(node_1);
		p.children.push_back(node_2);
		p.children.push_back(node_3);
        (yyval) = p;
	}
#line 1584 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"num",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;

	}
#line 1595 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"num",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1605 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 194 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"var_declarations",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1617 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 202 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"var_declarations",0);
	}
#line 1625 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 210 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"var_declaration",0);
        p.children.push_back((yyvsp[-4]));
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1639 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 220 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"var_declaration",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1651 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1661 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 238 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"type",0);
        p.children.push_back((yyvsp[-5]));
		p.children.push_back((yyvsp[-4]));
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2])); 
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1676 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 253 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1686 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 259 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1696 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 265 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1706 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 271 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1716 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 281 "yacc.y" /* yacc.c:1646  */
    {                     
        p=newNode(-1,"period",0);
        p.children.push_back((yyvsp[-4]));
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1730 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 291 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"period",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1742 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 303 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"subprogram_declarations",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1754 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 311 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"subprogram_declarations",0);
	}
#line 1762 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 319 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"subprogram",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1774 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 331 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"subprogram_head",0);
        p.children.push_back((yyvsp[-4]));
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1788 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 341 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"subprogram_head",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1800 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 353 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"formal_parameter",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1812 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 361 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"formal_parameter",0);
	}
#line 1820 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 369 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"parameter_list",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1832 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 377 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"parameter_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1842 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 387 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"parameter",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1852 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 393 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"parameter",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1862 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 403 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"var_parameter",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1873 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 414 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"value_parameter",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
		p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1885 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 426 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"subprogram_body",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1897 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 434 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"subprogram_body",0);
	}
#line 1905 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 442 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"compound_statement",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1917 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 453 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement_list",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1929 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 461 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1939 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 471 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1951 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 479 "yacc.y" /* yacc.c:1646  */
    {	
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1961 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 485 "yacc.y" /* yacc.c:1646  */
    {	
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1971 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 491 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-4]));
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1985 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 501 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-7]));
        p.children.push_back((yyvsp[-6]));
        p.children.push_back((yyvsp[-5]));
        p.children.push_back((yyvsp[-4]));
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2002 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 514 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2015 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 523 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2028 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 532 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2041 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 541 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"statement",0);
	}
#line 2049 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 549 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"variable_list",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2061 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 557 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"variable_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2071 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 567 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"variable",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2082 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 579 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"id_varpart",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2094 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 587 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"id_varpart",0);
		(yyval) = p;
	}
#line 2103 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 596 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"procedure_call",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2113 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 602 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"procedure_call",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2126 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 615 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"else_part",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2137 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 622 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"else_part",0);
	}
#line 2145 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 630 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression_list",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2157 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 638 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2167 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 648 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2179 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 656 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2189 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 666 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"simple_expression",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2199 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 672 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"simple_expression",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2211 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 684 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"term",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2223 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 692 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"term",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2233 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 702 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2243 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 708 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2253 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 714 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2266 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 723 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2278 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 731 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2289 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 738 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2300 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 749 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2310 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 755 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2320 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 761 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2330 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 767 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2340 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 773 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2350 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 779 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2360 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 788 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"addop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2370 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 794 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"addop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2380 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 800 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"addop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2390 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 810 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2400 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 816 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2410 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 822 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2420 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 828 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2430 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 834 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2440 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2444 "yacc.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 840 "yacc.y" /* yacc.c:1906  */


void yyerror(const char *s)			//当yacc遇到语法错误时，会回调yyerror函数，并且把错误信息放在参数s中
{
	cerr<<s<<endl;					//直接输出错误信息
}

void postorder_traversal(const ATRNode& Node)
{
    for(int i=0; i<layer; i++)
    {
        cout << "\t";
    }
    
    if(Node.children.empty() and Node.id != -1)
    {
        cout << "[" << Node.id << " | " << Node.attr << " | " << Node.line << "]" << endl;
    }
    else{
        cout << Node.attr << endl;
        layer++;
        for(auto & i : Node.children)
        {
            postorder_traversal(i);
        }
        layer--;
    }
}

ATRNode newNode(int id, string attr, int line=0)
{
	cout << id << "\t" << attr << endl;
    ATRNode temp(id, attr, line);
    return temp;
}

int syntax_process()							//程序主函数，这个函数也可以放到其它.c, .cpp文件里
{
	const char* sFile="file.txt";	//打开要读取的文本文件
	FILE* fp=fopen(sFile, "r");
	if(fp==NULL)
	{
		printf("cannot open %s\n", sFile);
		return -1;
	}
	extern FILE* yyin;				//yyin和yyout都是FILE*类型
	yyin=fp;						//yacc会从yyin读取输入，yyin默认是标准输入，这里改为磁盘文件。yacc默认向yyout输出，可修改yyout改变输出目的

	printf("-----PBEGIN parsing %s\n", sFile);
	yyparse();						//使yacc开始读取输入和解析，它会调用lex的yylex()读取记号
	puts("-----end parsing");
	fclose(fp);
	postorder_traversal(root_node);
	cout << endl;
	return 0;
}


