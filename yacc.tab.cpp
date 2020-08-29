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

/* Copy the second part of user declarations.  */

#line 207 "yacc.tab.c" /* yacc.c:358  */

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
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

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
      65,    66,    67,    68,    69,    70
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
     484,   490,   500,   513,   526,   535,   544,   553,   563,   570,
     578,   588,   600,   609,   617,   623,   636,   644,   651,   659,
     669,   677,   687,   693,   705,   713,   723,   729,   735,   744,
     752,   759,   770,   776,   782,   788,   794,   800,   809,   815,
     821,   831,   837,   843,   849,   855
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
  "DIV", "DO", "DOWNTO", "END", "FOR", "FUNCTION", "IF", "MOD", "STRING",
  "NOT", "OF", "OR", "PROCEDURE", "PROGRAM", "REAL", "RECORD", "REPEAT",
  "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE", "SUBBOUNDARY", "ASSIGNOP",
  "LE", "GE", "EQ", "NE", "notEQUAL", "EQUAL", "IDENTIFIER", "READ",
  "WRITE", "REALNUMBER", "EQUL", "LT", "GT", "COMMA", "COLON", "SEMICOLON",
  "DOT", "DOTDOT", "LPAREN", "RPAREN", "LBRAC", "RBRAC", "PLUS", "MINUS",
  "SLASH", "STAR", "$accept", "programstruct", "program_head",
  "program_body", "identifier_list", "const_declarations",
  "const_declaration", "const_value", "num", "var_declarations",
  "var_declaration", "type", "basic_type", "period",
  "subprogram_declarations", "subprogram", "subprogram_head",
  "formal_parameter", "parameter_list", "parameter", "var_parameter",
  "value_parameter", "subprogram_body", "compound_statement",
  "statement_list", "statement", "variable_list", "variable", "id_varpart",
  "procedure_call", "else_part", "expression_list", "expression",
  "simple_expression", "term", "factor", "relop", "addop", "mulop", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

#define YYPACT_NINF -128

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-128)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,   -22,   107,    18,    17,  -128,    90,    60,    63,    55,
      93,  -128,   -33,    91,    82,  -128,    60,  -128,    89,  -128,
       4,    92,    70,    84,    83,  -128,  -128,  -128,  -128,    -5,
      -5,  -128,  -128,    95,    25,    60,    39,    98,    99,    86,
      94,  -128,  -128,  -128,     4,  -128,    87,  -128,  -128,  -128,
    -128,  -128,    78,   100,    -6,    -6,    30,    96,    97,  -128,
     -14,  -128,   109,  -128,   101,   101,  -128,    -8,  -128,   145,
      25,   112,    -6,    12,    -6,    -6,  -128,  -128,   120,    56,
       0,  -128,   137,    -6,    -6,  -128,   110,    -7,  -128,    39,
      -6,    32,   103,  -128,    93,  -128,   104,    52,  -128,    -6,
    -128,    -6,   105,  -128,    39,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,    -6,    -6,  -128,  -128,  -128,  -128,
    -128,    -6,    39,    36,  -128,    64,   102,    67,  -128,   106,
      68,  -128,  -128,    60,    80,   -28,  -128,  -128,  -128,    21,
     148,   155,   158,   141,    38,    69,  -128,   166,    -1,     0,
    -128,  -128,    -6,  -128,  -128,   110,  -128,  -128,  -128,  -128,
      21,    32,  -128,  -128,  -128,  -128,   111,    21,    -6,    -6,
    -128,    39,  -128,  -128,  -128,  -128,  -128,   164,  -128,   154,
     156,  -128,  -128,    39,    39,  -128,  -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     1,     9,     0,     0,     0,
      19,     7,     0,     0,     0,     2,     0,    31,     0,     3,
       0,     8,     0,     0,     0,     6,    15,    16,    17,     0,
       0,    11,    14,     0,     0,    18,    58,     0,     0,     0,
       0,     5,    12,    13,     0,    24,     0,    26,    27,    25,
      21,    22,     0,     0,     0,     0,    64,     0,     0,    50,
       0,    47,     0,    49,    36,    36,    30,     9,    10,     0,
       0,     0,     0,    63,     0,     0,    76,    77,     0,    71,
      72,    75,     0,     0,     0,    61,     0,     0,    45,    58,
       0,     0,     0,    34,    19,    32,     0,     0,    20,     0,
      80,     0,     0,    81,    58,    90,    85,    86,    87,    83,
      84,    82,    88,    89,     0,     0,    94,    95,    93,    92,
      91,     0,    58,     0,    69,     0,    63,     0,    60,     0,
       0,    46,    48,     0,     0,     0,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,    79,    67,    70,    73,
      74,    57,     0,    65,    62,     0,    54,    56,    55,    41,
       0,     0,    35,    33,    43,    29,     0,     0,     0,     0,
      78,    58,    51,    68,    59,    42,    37,     0,    23,     0,
       0,    66,    28,    58,    58,    53,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,     3,   113,  -128,   132,    59,    85,
    -128,   108,  -127,  -128,  -128,  -128,  -128,   116,  -128,    22,
    -128,    49,  -128,   -23,  -128,   -87,  -128,   -36,  -128,  -128,
    -128,    -2,   -48,    71,    72,   -57,  -128,  -128,  -128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,   134,    10,    14,    31,    76,    17,
      23,    50,    51,    97,    24,    39,    40,    92,   135,   136,
     137,   138,    95,    59,    60,    61,   127,    77,    85,    63,
     172,   123,   124,    79,    80,    81,   114,   115,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    41,   131,    27,    27,    27,    78,    82,    26,    88,
      12,     8,   163,   116,    27,   100,     1,   147,   103,    22,
     117,   129,    72,    72,    45,    18,   102,   118,    45,     4,
     105,    19,   161,   175,    46,   151,   162,    47,    52,    48,
     178,    47,   132,    48,    73,    73,    89,    28,    28,    28,
     128,   144,   -44,    62,    36,    49,    74,    74,    28,    49,
     168,    75,    75,    53,   150,    54,   112,   113,    62,   119,
     120,    29,    30,   133,   -63,   101,   169,    84,     6,    32,
       7,    55,   125,    11,   181,   130,    62,   105,    42,    43,
      56,    57,    58,    83,   152,    84,   185,   186,    36,   145,
     153,   106,   107,    32,   173,   108,   109,     5,    37,     8,
     142,    11,   110,   111,    13,    38,    15,   164,   143,   174,
     179,   180,   152,   112,   113,   155,   152,   152,    18,    34,
     154,   156,   158,   170,    16,    62,    18,    70,    18,   160,
      25,    20,    21,    33,    35,    44,    66,    62,    62,    64,
      65,    71,    69,    90,    67,    96,    99,   104,   122,    86,
      87,   126,   139,    36,    91,   165,   141,    84,   166,   146,
     157,   167,   171,   177,   182,   183,    68,   184,    98,   140,
      94,    93,   159,   176,     0,   148,     0,   149
};

static const yytype_int16 yycheck[] =
{
      36,    24,    89,    10,    10,    10,    54,    55,     4,    23,
       7,    19,   139,    13,    10,    72,    33,   104,    75,    16,
      20,    28,    29,    29,     3,    58,    74,    27,     3,    51,
      31,    64,    60,   160,     9,   122,    64,    16,    35,    18,
     167,    16,    90,    18,    51,    51,    60,    54,    54,    54,
      86,    99,    60,    89,    15,    34,    63,    63,    54,    34,
      22,    68,    68,    24,   121,    26,    67,    68,   104,    69,
      70,    67,    68,    41,    44,    63,    38,    65,    60,    20,
      63,    42,    84,    51,   171,    87,   122,    31,    29,    30,
      51,    52,    53,    63,    58,    65,   183,   184,    15,   101,
      64,    45,    46,    44,   152,    49,    50,     0,    25,    19,
      58,    51,    56,    57,    51,    32,    61,   140,    66,   155,
     168,   169,    58,    67,    68,    58,    58,    58,    58,    59,
      66,    64,    64,    64,    41,   171,    58,    59,    58,    59,
      51,    50,    60,    51,    60,    50,    60,   183,   184,    51,
      51,    51,    65,    44,    60,    10,    44,    37,    21,    63,
      63,    51,    59,    15,    63,    10,    62,    65,    10,    64,
      64,    30,     6,    62,    10,    21,    44,    21,    70,    94,
      67,    65,   133,   161,    -1,   114,    -1,   115
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    72,    73,    51,     0,    60,    63,    19,    74,
      76,    51,    75,    51,    77,    61,    41,    80,    58,    64,
      50,    60,    75,    81,    85,    51,     4,    10,    54,    67,
      68,    78,    79,    51,    59,    60,    15,    25,    32,    86,
      87,    94,    79,    79,    50,     3,     9,    16,    18,    34,
      82,    83,    75,    24,    26,    42,    51,    52,    53,    94,
      95,    96,    98,   100,    51,    51,    60,    60,    78,    65,
      59,    51,    29,    51,    63,    68,    79,    98,   103,   104,
     105,   106,   103,    63,    65,    99,    63,    63,    23,    60,
      44,    63,    88,    88,    76,    93,    10,    84,    82,    44,
     106,    63,   103,   106,    37,    31,    45,    46,    49,    50,
      56,    57,    67,    68,   107,   108,    13,    20,    27,    69,
      70,   109,    21,   102,   103,   102,    51,    97,    98,    28,
     102,    96,   103,    41,    75,    89,    90,    91,    92,    59,
      80,    62,    58,    66,   103,   102,    64,    96,   104,   105,
     106,    96,    58,    64,    66,    58,    64,    64,    64,    92,
      59,    60,    64,    83,    94,    10,    10,    30,    22,    38,
      64,     6,   101,   103,    98,    83,    90,    62,    83,   103,
     103,    96,    10,    21,    21,    96,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    92,    93,    93,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   108,   108,
     108,   109,   109,   109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     5,     2,     4,     3,     1,     3,     0,
       5,     3,     2,     2,     1,     1,     1,     1,     3,     0,
       5,     3,     1,     6,     1,     1,     1,     1,     5,     3,
       3,     0,     3,     5,     3,     3,     0,     3,     1,     1,
       1,     2,     3,     3,     0,     3,     3,     1,     3,     1,
       1,     5,     8,     8,     4,     4,     4,     4,     0,     3,
       1,     2,     3,     0,     1,     4,     2,     0,     3,     1,
       3,     1,     1,     3,     3,     1,     1,     1,     4,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 1434 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1448 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"program_head",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1459 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1472 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1484 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"identifier_list",0);
		p.children.push_back((yyvsp[0]));
		(yyval) = p;
	}
#line 1494 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1506 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"const_declarations",0);
	}
#line 1514 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1528 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1540 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"const_value",0);                        
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;

	}
#line 1552 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"const_value",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1563 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 156 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"const_value",0);       			
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1573 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1588 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"num",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;

	}
#line 1599 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"num",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1609 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1621 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 202 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"var_declarations",0);
	}
#line 1629 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1643 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1655 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1665 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1680 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 253 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1690 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 259 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1700 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 265 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1710 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 271 "yacc.y" /* yacc.c:1646  */
    {
        p=newNode(-1,"basic_type",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1720 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1734 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1746 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1758 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 311 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"subprogram_declarations",0);
	}
#line 1766 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1778 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1792 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1804 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1816 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 361 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"formal_parameter",0);
	}
#line 1824 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1836 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 377 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"parameter_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1846 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 387 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"parameter",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1856 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 393 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"parameter",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1866 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 403 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"var_parameter",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1877 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1889 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1901 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 434 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"subprogram_body",0);
	}
#line 1909 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1921 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1933 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 461 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1943 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1955 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 479 "yacc.y" /* yacc.c:1646  */
    {	
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1965 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 485 "yacc.y" /* yacc.c:1646  */
    {	
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 1975 "yacc.tab.c" /* yacc.c:1646  */
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
#line 1989 "yacc.tab.c" /* yacc.c:1646  */
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
#line 2006 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 514 "yacc.y" /* yacc.c:1646  */
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
#line 2023 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 527 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2036 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 536 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2049 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 545 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2062 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 554 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"statement",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2075 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 563 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"statement",0);
	}
#line 2083 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 571 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"variable_list",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2095 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 579 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"variable_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2105 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 589 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"variable",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2116 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 601 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"id_varpart",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2128 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 609 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"id_varpart",0);
		(yyval) = p;
	}
#line 2137 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 618 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"procedure_call",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2147 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 624 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"procedure_call",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2160 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 637 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"else_part",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2171 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 644 "yacc.y" /* yacc.c:1646  */
    {
		(yyval) = newNode(-1,"else_part",0);
	}
#line 2179 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 652 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression_list",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2191 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 660 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression_list",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2201 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 670 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2213 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 678 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"expression",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2223 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 688 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"simple_expression",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2233 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 694 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"simple_expression",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2245 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 706 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"term",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2257 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 714 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"term",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2267 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 724 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2277 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 730 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2287 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 736 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-3]));
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2300 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 745 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-2]));
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2312 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 753 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2323 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 760 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"factor",0);
        p.children.push_back((yyvsp[-1]));
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2334 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 771 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2344 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 777 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2354 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 783 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2364 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 789 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2374 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 795 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2384 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 801 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"relop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2394 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 810 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"addop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2404 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 816 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"addop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2414 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 822 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"addop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2424 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 832 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2434 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 838 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2444 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 844 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2454 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 850 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2464 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 856 "yacc.y" /* yacc.c:1646  */
    {
		p=newNode(-1,"mulop",0);
        p.children.push_back((yyvsp[0]));
        (yyval) = p;
	}
#line 2474 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2478 "yacc.tab.c" /* yacc.c:1646  */
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
#line 862 "yacc.y" /* yacc.c:1906  */


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
    ATRNode temp(id, std::move(attr), line);
    return temp;
}

int syntax_process(const char* file_path)							//程序主函数，这个函数也可以放到其它.c, .cpp文件里
{
	const char* sFile = file_path;	//打开要读取的文本文件
	FILE* fp=fopen(sFile, "r");
	if(fp==nullptr)
	{
		printf("cannot open %s\n", sFile);
		return -1;
	}
	extern FILE* yyin;				//yyin和yyout都是FILE*类型
	yyin=fp;						//yacc会从yyin读取输入，yyin默认是标准输入，这里改为磁盘文件。yacc默认向yyout输出，可修改yyout改变输出目的
	printf("-----begin parsing %s\n", sFile);
	yyparse();						//使yacc开始读取输入和解析，它会调用lex的yylex()读取记号
	puts("-----end parsing");
	fclose(fp);
	postorder_traversal(root_node);
	cout << endl;
	return 0;
}


