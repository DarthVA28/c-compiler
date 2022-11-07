/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "c.y"

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "ASTNode.hpp"

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

ASTNode* AST = NULL;


#line 90 "c.tab.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_C_TAB_HPP_INCLUDED
# define YY_YY_C_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "c.y"

	#include <iostream>
	#include "ASTNode.hpp"
	#include <string>
	using namespace std;

#line 140 "c.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING_LITERAL = 258,
    IDENTIFIER = 259,
    ELLIPSIS = 260,
    I_CONSTANT = 261,
    F_CONSTANT = 262,
    FUNC_NAME = 263,
    SIZEOF = 264,
    PTR_OP = 265,
    INC_OP = 266,
    DEC_OP = 267,
    LEFT_OP = 268,
    RIGHT_OP = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    AND_OP = 274,
    OR_OP = 275,
    MUL_ASSIGN = 276,
    DIV_ASSIGN = 277,
    MOD_ASSIGN = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    LEFT_ASSIGN = 281,
    RIGHT_ASSIGN = 282,
    AND_ASSIGN = 283,
    XOR_ASSIGN = 284,
    OR_ASSIGN = 285,
    TYPEDEF_NAME = 286,
    ENUMERATION_CONSTANT = 287,
    TYPEDEF = 288,
    EXTERN = 289,
    STATIC = 290,
    AUTO = 291,
    REGISTER = 292,
    INLINE = 293,
    CONST = 294,
    RESTRICT = 295,
    VOLATILE = 296,
    BOOL = 297,
    CHAR = 298,
    SHORT = 299,
    INT = 300,
    LONG = 301,
    SIGNED = 302,
    UNSIGNED = 303,
    FLOAT = 304,
    DOUBLE = 305,
    VOID = 306,
    COMPLEX = 307,
    IMAGINARY = 308,
    STRUCT = 309,
    UNION = 310,
    ENUM = 311,
    CASE = 312,
    DEFAULT = 313,
    IF = 314,
    ELSE = 315,
    SWITCH = 316,
    WHILE = 317,
    DO = 318,
    FOR = 319,
    GOTO = 320,
    CONTINUE = 321,
    BREAK = 322,
    RETURN = 323,
    ALIGNAS = 324,
    ALIGNOF = 325,
    ATOMIC = 326,
    GENERIC = 327,
    NORETURN = 328,
    STATIC_ASSERT = 329,
    THREAD_LOCAL = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "c.y"

	ASTNode* node;
	ASTNodeList* nodelist;
	int ival;
	float fval;
	char* sval;
	// vector<ASTNode*> nodelist;

#line 236 "c.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_HPP_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  278
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  483

#define YYUNDEFTOK  2
#define YYMAXUTOK   330


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,     2,     2,     2,    94,    78,     2,
      76,    77,    79,    80,    87,    81,    92,    93,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    84,
      95,    88,    96,    99,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    85,     2,    86,    97,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,    98,    90,    82,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    89,    90,    91,    92,    93,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   116,   117,   118,   126,   130,   135,
     136,   137,   138,   139,   140,   144,   151,   152,   156,   157,
     161,   162,   166,   167,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   185,   186,   193,   197,   208,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     226,   232,   235,   239,   240,   244,   245,   249,   250,   254,
     255,   259,   260,   267,   268,   269,   273,   274,   282,   283,
     287,   288,   292,   293,   294,   295,   296,   297,   301,   302,
     310,   311,   312,   316,   320,   323,   327,   331,   332,   333,
     339,   340,   344,   345,   346,   347,   348,   354,   355,   361,
     362,   368,   369,   370,   371,   372,   373,   378,   379,   383,
     384,   385,   386,   387,   388,   389,   393,   394,   398,   399,
     400,   401,   405,   406,   407,   411,   412,   413,   417,   418,
     419,   420,   421,   425,   426,   427,   431,   432,   436,   437,
     441,   442,   446,   447,   451,   452,   456,   457,   461,   462,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   480,   481,   485,   489,   490,   491,   492,   493,   494,
     498,   499,   500,   504,   505,   509,   513,   514,   518,   519,
     524,   525,   529,   530,   531,   535,   536,   537,   538,   542,
     543,   547,   548,   549,   553,   554,   555,   556,   557,   561,
     562,   566,   567,   571,   575,   576,   577,   578,   582,   583,
     587,   588,   592,   593,   594,   595,   599,   600,   605,   606,
     610,   611,   615,   616,   617,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   646,   652,   653,   657,
     658,   659,   660,   664,   668,   669,   673,   674,   678
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING_LITERAL", "IDENTIFIER",
  "ELLIPSIS", "I_CONSTANT", "F_CONSTANT", "FUNC_NAME", "SIZEOF", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME", "ENUMERATION_CONSTANT",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE", "CONST",
  "RESTRICT", "VOLATILE", "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED",
  "UNSIGNED", "FLOAT", "DOUBLE", "VOID", "COMPLEX", "IMAGINARY", "STRUCT",
  "UNION", "ENUM", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('",
  "')'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "';'", "'['", "']'",
  "','", "'='", "'{'", "'}'", "':'", "'.'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "$accept", "start_state", "primary_expression",
  "type_specifier", "constant", "enumeration_constant", "unary_operator",
  "string", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", "declaration_specifiers",
  "declaration", "declarator", "direct_declarator", "init_declarator_list",
  "init_declarator", "parameter_type_list", "parameter_list",
  "parameter_declaration", "compound_statement", "block_item_list",
  "block_item", "statement", "expression_statement", "labeled_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "storage_class_specifier",
  "struct_or_union_specifier", "struct_or_union", "generic_selection",
  "generic_assoc_list", "generic_association", "struct_declaration_list",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "atomic_type_specifier",
  "type_qualifier", "function_specifier", "alignment_specifier", "pointer",
  "type_qualifier_list", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    40,    41,    38,    42,
      43,    45,   126,    33,    59,    91,    93,    44,    61,   123,
     125,    58,    46,    47,    37,    60,    62,    94,   124,    63
};
# endif

#define YYPACT_NINF (-371)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2055,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,    18,   -42,   -37,  -371,   -24,
    -371,    81,  2100,  2055,  -371,  -371,    90,  -371,  2100,  -371,
      25,  -371,  -371,  2100,  2100,  2100,  -371,    -6,    42,  1357,
    1277,  1507,  -371,  -371,  -371,  -371,    92,   141,  -371,  1841,
      91,   155,  -371,    29,  -371,    -4,  2137,  -371,  -371,  -371,
      42,  -371,    21,   156,  -371,  -371,  -371,  -371,  -371,  -371,
    1548,  1589,  1589,  -371,    40,    53,  1357,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  1277,  -371,  1507,  -371,    47,  -371,
    -371,    68,   -65,   220,    48,   251,    57,    45,    50,   131,
      12,  -371,    93,  -371,   -41,  1277,   100,   107,   130,   138,
    -371,  -371,  -371,   141,   819,   628,  1900,    90,  -371,  -371,
    1642,   925,  -371,    92,    91,  2137,  1731,  -371,    46,  -371,
     162,  1507,    16,  -371,  1357,  -371,  1357,  -371,  -371,  1277,
    1507,   395,  -371,  -371,    51,   163,  -371,  -371,   206,  -371,
    -371,  1452,  1507,   244,  1507,  1507,  1507,  1507,  1507,  1507,
    1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,
    1507,  1507,  1507,  -371,  1957,   942,   145,  -371,   146,  -371,
    -371,  -371,   262,  -371,  -371,  -371,   541,  -371,  -371,   198,
    1507,   213,   221,   229,   232,   804,   234,   308,   230,   231,
    1273,  -371,  -371,  -371,  -371,   716,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,   166,  -371,  -371,   225,  -371,  -371,    73,
     240,   233,  -371,    77,  1411,   237,  -371,   238,  1023,  -371,
    1783,  -371,  -371,  -371,  1507,   243,   170,  -371,    23,  -371,
    -371,  -371,  -371,   248,   259,   260,   252,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  1507,  -371,
    1507,   841,  -371,  -371,    86,  -371,   207,  -371,  -371,  -371,
    -371,    68,    68,   -65,   -65,   220,   220,   220,   220,    48,
      48,   251,    57,    45,    50,   131,   -22,  -371,   261,   263,
    1411,   255,  -371,   256,  1040,   146,  2010,  1121,   267,  1507,
     341,  -371,   172,   819,   153,  -371,   804,   257,   804,  1507,
    1507,  1507,   285,  1219,   268,  -371,  -371,  -371,   177,  -371,
    -371,  -371,   266,    75,  -371,  -371,  1694,  -371,   349,   269,
    1411,  -371,  -371,  1507,   273,  -371,   274,  -371,  -371,  1507,
    -371,    36,  -371,   265,   265,  -371,  2173,  -371,  -371,   541,
    -371,  -371,  1507,  -371,  1507,  -371,  -371,   275,  1411,  -371,
    -371,  1507,  -371,   277,  -371,   287,  1411,   280,  -371,   281,
    1138,   284,   283,  -371,   424,  -371,  -371,  -371,  -371,  -371,
     804,  -371,    88,   121,   122,   294,  1303,  1303,  -371,  -371,
     286,  -371,  -371,  -371,  -371,  -371,   288,   289,  -371,  -371,
    -371,  -371,   282,   124,  -371,   291,   176,  -371,  -371,  -371,
     292,   293,  -371,  -371,   297,  1411,  -371,  -371,  1507,  -371,
     299,  -371,  -371,  -371,  -371,   819,  -371,   804,   804,   804,
    1507,  1466,  1493,  -371,  -371,  -371,  1507,  -371,  2173,  1507,
     514,  -371,  -371,  -371,  -371,   300,   301,  -371,  -371,   311,
    -371,  -371,   126,   804,   129,   804,   137,  -371,  -371,  -371,
    -371,  -371,  -371,   804,   296,  -371,   804,  -371,   804,  -371,
    -371,  -371,  -371
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    23,   184,   185,   186,   188,   189,   228,   224,   225,
     226,    17,     9,    10,    11,    12,    15,    16,    13,    14,
       8,    18,    19,   193,   194,     0,     0,   227,   229,     0,
     187,     0,    47,     2,    36,    38,     0,    39,    45,    21,
       0,    22,    20,    49,    51,    53,    56,   218,     0,     0,
       0,     0,     1,    46,    37,    59,     0,   235,    54,    76,
      58,     0,    73,     0,    44,   192,     0,    48,    50,    52,
       0,    28,   222,     0,   219,    26,     3,    24,    25,    35,
       0,     0,     0,    27,     0,     0,     0,    29,    30,    31,
      32,    33,    34,   117,   206,     4,     0,     5,   129,   136,
     138,   142,   145,   148,   153,   156,   158,   160,   162,   164,
     166,   183,     0,     7,   241,   208,     0,     0,     0,     0,
     227,   236,   234,   233,     0,     0,     0,     0,    42,    41,
       0,     0,    55,     0,    57,     0,     0,   200,     0,   204,
       0,     0,     0,   214,     0,   133,     0,   130,   131,     0,
       0,   136,   168,   181,     0,     0,   205,   132,     0,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   231,     0,     0,   243,   240,   244,   207,
     230,   223,     0,    60,   237,   232,     0,   268,    75,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    86,    90,    93,     0,    88,    91,    94,    92,
      95,    96,    97,     0,    43,    40,    76,   238,    71,    84,
       0,    78,    79,     0,     0,    30,    61,     0,     0,    74,
       0,   190,   201,   202,     0,   213,     0,   209,     0,   216,
     221,   215,   220,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   170,     0,     6,
       0,     0,   122,   119,     0,   127,     0,   121,   139,   140,
     141,   143,   144,   146,   147,   151,   152,   149,   150,   154,
     155,   157,   159,   161,   163,   165,     0,   262,     0,     0,
       0,    30,   246,     0,     0,   242,     0,     0,     0,     0,
       0,   270,     0,     0,     0,   274,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   115,     0,    87,
      89,    99,    81,   243,    83,    70,     0,    72,     0,     0,
       0,    62,    69,     0,    30,    68,     0,   191,   211,     0,
     203,     0,   217,   134,     0,   135,     0,   169,   182,     0,
     137,   120,     0,   118,     0,   263,   245,     0,     0,   247,
     253,     0,   252,     0,   264,     0,     0,    30,   254,     0,
       0,     0,     0,   277,     0,   266,   269,   273,   275,   100,
       0,   102,     0,     0,     0,     0,     0,     0,   112,   116,
       0,    82,    77,    80,   239,    64,     0,     0,    65,    67,
     212,   210,     0,     0,   196,     0,     0,   128,   167,   249,
       0,     0,   251,   265,     0,     0,   255,   261,     0,   260,
       0,   278,   276,   267,   272,     0,   101,     0,     0,     0,
       0,     0,     0,    85,    63,    66,     0,   195,     0,     0,
       0,   125,   248,   250,   257,     0,     0,   258,   271,   104,
     105,   106,     0,     0,     0,     0,     0,   199,   197,   198,
     126,   256,   259,     0,     0,   110,     0,   108,     0,   103,
     107,   111,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -371,  -371,  -371,   -45,  -371,  -371,  -371,  -371,  -371,   355,
    -371,  -371,    10,   -23,   -30,   326,  -371,   258,  -173,  -371,
      56,     8,  -371,   179,    14,  -192,  -371,  -371,  -371,  -371,
    -371,  -371,   106,   -93,   128,   133,    55,   123,   218,   219,
     217,   227,   224,  -371,   -21,    22,  -371,   -84,     0,  -371,
    -371,  -371,  -371,  -371,   -48,   276,  -123,   -47,  -371,    58,
    -371,   331,  -130,  -371,   -49,  -371,  -371,   -39,   -75,  -371,
     -25,  -153,  -177,  -117,    49,  -370,  -371,    96,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    93,    32,    95,    72,    96,    97,    33,    34,
      35,   126,   127,    37,   226,    60,    61,    62,   230,   231,
     232,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      98,   274,   151,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   152,   153,   268,   223,   112,    38,
      39,    40,   113,   413,   414,   136,   137,   114,   246,   247,
      41,    73,    74,    42,    43,    44,    45,    63,   123,   233,
     415,   187,   188,   311,   312,   313,   314,   315,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     115,   115,   154,   157,    94,    94,    59,   198,   121,   305,
      36,   298,   252,   242,   435,   167,   168,   115,   122,   138,
      71,    94,    47,   139,   116,   117,   119,    71,   111,    65,
     111,   299,   181,    55,    49,   184,   128,   115,    57,    50,
      55,    94,    53,    36,   185,   115,    71,   156,    64,    94,
      55,   118,    51,    67,    68,    69,   238,   158,   159,   160,
     154,   155,   154,   171,   172,   270,   115,   129,   189,   364,
      94,   278,   279,   280,   194,   186,   334,   332,   276,   401,
     435,    52,   121,    70,   195,   135,   115,   115,   138,   138,
      94,    94,   139,   139,    55,   115,    55,   115,   296,    94,
     115,    94,   213,   224,    94,    56,   251,    48,   245,   141,
     304,   182,    56,   352,    66,    57,   149,   242,   252,   253,
     111,   254,    56,   161,   255,    57,   328,   244,   269,   150,
     243,   397,   162,   375,   225,   177,   121,   244,   270,   163,
     229,   250,   178,   173,   174,   186,   197,   164,   179,   184,
     180,   184,    57,   237,   337,    99,   305,    99,   185,   340,
     185,   165,   166,   361,   338,   437,    56,   130,    56,    57,
     183,    57,   256,   362,    58,   270,   131,   190,   360,   111,
       8,     9,    10,   275,   191,   121,   145,   147,   148,   194,
     333,   115,   213,   138,   229,    94,   386,   139,   438,   439,
     317,   447,    99,   474,   441,   442,   476,   303,   270,   270,
     272,   448,   120,   270,   478,   193,   270,   192,   197,   322,
      57,   184,   306,   111,   270,   368,   285,   286,   287,   288,
     185,   307,   380,   169,   170,   392,   393,   394,   309,   132,
     271,   387,   133,   142,   348,   310,   143,    99,   277,   248,
     331,   121,   249,   270,   350,   194,   339,   351,   121,   384,
     346,   399,   385,   450,   270,   308,   451,   434,   175,   176,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   111,   316,
     357,   194,   358,   363,   270,   281,   282,   319,   289,   290,
     396,   425,   283,   284,   318,   320,    99,   115,   321,   382,
     323,    94,   324,   124,   325,   326,   229,   335,   458,   194,
     336,   245,   367,   341,   342,   353,   373,   121,   111,   379,
     389,   194,   391,   434,   349,   197,   354,   355,   365,   356,
     366,   369,   370,   418,   381,   383,   229,   395,   390,   410,
      99,   400,   398,   404,   359,   405,   462,   464,   466,   408,
     409,   419,   406,   422,   423,   407,   426,   427,   431,   432,
     440,   473,   443,   446,   444,   445,   194,    99,   452,   453,
     480,   197,   449,   454,   417,   457,   471,   472,    54,   134,
     420,   239,   403,   421,   330,   291,   293,   292,   424,   115,
     468,   140,   430,    94,   436,   295,   197,   294,   416,   411,
     388,   240,     0,     0,     0,    99,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,    75,    76,     0,
      77,    78,    79,    80,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,     0,     0,
     456,   459,   460,   461,     0,    99,    83,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   467,     0,
      99,   469,   197,     0,     0,     0,     0,   475,     0,   477,
       0,     0,     0,   267,     0,     0,     0,   479,     0,     0,
     481,     0,   482,     0,    84,     0,    85,     0,     0,     0,
      86,     0,    87,    88,    89,    90,    91,    92,     0,   309,
       0,     0,     0,   196,   433,     0,   310,    75,    76,     0,
      77,    78,    79,    80,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    83,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,    85,     0,     0,     0,
      86,     0,    87,    88,    89,    90,    91,    92,     0,   309,
       0,     0,     0,   196,   470,     0,   310,     0,     0,     0,
       0,    84,     0,    85,     0,     0,     0,    86,     0,    87,
      88,    89,    90,    91,    92,     0,   309,     0,     0,     0,
     196,    75,   199,   310,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
      83,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   200,   201,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,    26,    84,    27,
      85,    28,    29,    30,    86,     0,    87,    88,    89,    90,
      91,    92,   211,     0,     0,     0,     0,   125,   212,    75,
     199,     0,    77,    78,    79,    80,     0,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,    83,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   200,   201,   202,     0,   203,   204,   205,
     206,   207,   208,   209,   210,    26,    84,    27,    85,    28,
      29,    30,    86,     0,    87,    88,    89,    90,    91,    92,
     211,     0,     0,     0,     0,   125,   329,    75,   199,     0,
      77,    78,    79,    80,     0,    81,    82,     0,     0,     0,
       0,     0,    75,    76,     0,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,    78,    79,
      80,    83,    81,    82,     0,     0,     0,     0,     0,     0,
       0,   200,   201,   202,     0,   203,   204,   205,   206,   207,
     208,   209,   210,    83,    84,     0,    85,     0,     0,     0,
      86,     0,    87,    88,    89,    90,    91,    92,   211,    84,
       0,    85,     0,   125,     0,    86,     0,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     0,     0,   196,     0,
       0,    84,     0,    85,     0,     0,     0,    86,     0,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    75,    76,
     359,    77,    78,    79,    80,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,    77,    78,
      79,    80,     0,    81,    82,     0,     0,    83,     0,     0,
     234,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,   300,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,   120,    85,     0,     0,
       0,    86,     0,    87,   235,    89,    90,    91,    92,     0,
       0,   236,    84,   120,    85,     0,     0,     0,    86,     0,
      87,   301,    89,    90,    91,    92,    75,    76,   302,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     0,    77,    78,    79,    80,
       0,    81,    82,     0,     0,    83,     0,     0,   343,     0,
       0,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,   371,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,   120,    85,     0,     0,     0,    86,
       0,    87,   344,    89,    90,    91,    92,     0,     0,   345,
      84,   120,    85,     0,     0,     0,    86,     0,    87,    88,
      89,    90,    91,    92,    75,    76,   372,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,    77,    78,    79,    80,     0,    81,
      82,     0,     0,    83,     0,     0,   376,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,   428,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,   120,    85,     0,     0,     0,    86,     0,    87,
     377,    89,    90,    91,    92,     0,     0,   378,    84,   120,
      85,     0,     0,     0,    86,     0,    87,    88,    89,    90,
      91,    92,    75,    76,   429,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    83,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    75,    76,     0,    77,
      78,    79,    80,     0,    81,    82,     0,     0,    26,    84,
      27,    85,    28,    29,    30,    86,     0,    87,    88,    89,
      90,    91,    92,   211,     0,    83,    75,    76,     1,    77,
      78,    79,    80,     0,    81,    82,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    83,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    85,     0,     0,    27,    86,
       0,    87,    88,    89,    90,    91,    92,   327,     0,     0,
      75,    76,     0,    77,    78,    79,    80,     0,    81,    82,
       0,     0,     0,    84,     0,    85,     0,     0,     0,    86,
       0,    87,    88,    89,    90,    91,    92,   211,     1,    83,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    75,    76,     0,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,    84,    27,    85,
       0,     0,     0,    86,     0,    87,    88,    89,    90,    91,
      92,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       8,     9,    10,     0,     0,    75,    76,     0,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,    75,
      76,     0,    77,    78,    79,    80,     0,    81,    82,     0,
       0,    84,   120,    85,    83,     0,     0,    86,     0,    87,
      88,    89,    90,    91,    92,     0,    75,    76,    83,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
      75,    76,     0,    77,    78,    79,    80,     0,    81,    82,
       0,     0,    84,     0,    85,    83,     0,     0,    86,   273,
      87,    88,    89,    90,    91,    92,    84,     0,    85,    83,
       0,     0,    86,   463,    87,    88,    89,    90,    91,    92,
       0,    75,    76,     0,    77,    78,    79,    80,     0,    81,
      82,     0,     0,    84,     0,    85,     0,     0,     0,    86,
     465,    87,    88,    89,    90,    91,    92,    84,     0,    85,
      83,     0,     0,    86,     0,    87,    88,    89,    90,    91,
      92,     0,    75,    76,     0,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
      85,    83,     0,     0,   144,     0,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,     0,     0,   146,     0,    87,    88,    89,
      90,    91,    92,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   402,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,   228,
       0,     0,     0,     0,     0,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    26,     0,    27,     0,    28,     0,    30,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,   241,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   347,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   125,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,     0,    30,   184,   297,     0,    57,     0,     0,     0,
       0,     1,   185,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,     0,    30,     1,   374,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,    29,
      30,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    26,
       0,    27,     0,    28,     0,    30,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,    27,     0,
       0,    29,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,   412,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      49,    50,    86,    96,    49,    50,    36,   124,    57,   186,
       0,   184,   142,   136,   384,    80,    81,    66,    57,    66,
       4,    66,     4,    66,    49,    50,    56,     4,    49,     4,
      51,   184,    20,     4,    76,    76,    59,    86,    79,    76,
       4,    86,    32,    33,    85,    94,     4,    94,    38,    94,
       4,    51,    76,    43,    44,    45,   131,    10,    11,    12,
     144,    86,   146,    15,    16,    87,   115,    59,   115,    91,
     115,   164,   165,   166,   123,   114,   229,     4,   162,     4,
     450,     0,   131,    89,   123,    89,   135,   136,   135,   136,
     135,   136,   135,   136,     4,   144,     4,   146,   182,   144,
     149,   146,   125,   126,   149,    76,    90,    89,   138,    88,
     185,    99,    76,    90,    89,    79,    76,   240,   248,   144,
     141,   146,    76,    76,   149,    79,   210,    91,    77,    76,
      84,   323,    85,   306,   126,    78,   185,    91,    87,    92,
     130,   141,    97,    95,    96,   184,   124,    79,    98,    76,
      19,    76,    79,   131,    77,    49,   333,    51,    85,   234,
      85,    93,    94,    77,    87,    77,    76,    76,    76,    79,
      77,    79,   150,    87,    84,    87,    85,    77,   271,   200,
      39,    40,    41,   161,    77,   234,    80,    81,    82,   238,
     229,   240,   215,   240,   184,   240,   313,   240,    77,    77,
     200,    77,    96,    77,   396,   397,    77,   185,    87,    87,
       4,    87,    71,    87,    77,    77,    87,    87,   196,   205,
      79,    76,    76,   244,    87,   300,   171,   172,   173,   174,
      85,    85,   307,    13,    14,   319,   320,   321,    85,    84,
      77,    88,    87,    87,   244,    92,    90,   141,     4,    87,
      84,   300,    90,    87,    84,   304,   234,    87,   307,    87,
     238,    84,    90,    87,    87,     3,    90,   384,    17,    18,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   309,    91,
     268,   340,   270,    86,    87,   167,   168,    76,   175,   176,
     323,   376,   169,   170,    91,    76,   200,   356,    76,   309,
      76,   356,     4,    88,    84,    84,   306,    77,   435,   368,
      87,   351,   300,    86,    86,    77,   304,   376,   349,   307,
     316,   380,   318,   450,    91,   313,    77,    77,    77,    87,
      77,    86,    86,   364,    77,     4,   336,    62,    91,   349,
     244,    85,    84,     4,    89,    86,   440,   441,   442,    86,
      86,    86,   340,    86,    77,   343,    86,    86,    84,    86,
      76,    60,    86,    91,    86,    86,   425,   271,    86,    86,
      84,   359,    91,    86,   362,    86,    86,    86,    33,    63,
     368,   133,   336,   371,   215,   177,   179,   178,   376,   448,
     448,    70,   380,   448,   390,   181,   384,   180,   359,   351,
     314,   135,    -1,    -1,    -1,   309,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,     3,     4,    -1,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,
     428,   437,   438,   439,    -1,   349,    32,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,    -1,
     364,   449,   450,    -1,    -1,    -1,    -1,   463,    -1,   465,
      -1,    -1,    -1,    88,    -1,    -1,    -1,   473,    -1,    -1,
     476,    -1,   478,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    -1,    89,    90,    -1,    92,     3,     4,    -1,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    32,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    85,    -1,    -1,    -1,
      89,     3,     4,    92,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    89,    90,     3,
       4,    -1,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    89,    90,     3,     4,    -1,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    32,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    32,    70,    -1,    72,    -1,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    70,
      -1,    72,    -1,    89,    -1,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,     3,     4,
      89,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    32,    -1,    -1,
      35,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,
      -1,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      78,    79,    80,    81,    82,    83,     3,     4,    86,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    32,    -1,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,    79,
      80,    81,    82,    83,     3,     4,    86,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    78,    79,    80,    81,
      82,    83,     3,     4,    86,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     3,     4,    -1,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    -1,    32,     3,     4,    31,     6,
       7,     8,     9,    -1,    11,    12,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    71,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     3,     4,    -1,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    -1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    70,    71,    72,    32,    -1,    -1,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,     3,     4,    32,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    70,    -1,    72,    32,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    70,    -1,    72,    32,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,     3,     4,    -1,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    70,    -1,    72,
      32,    -1,    -1,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,     3,     4,    -1,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    32,    -1,    -1,    76,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    -1,    78,    79,    80,
      81,    82,    83,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    69,    -1,    71,    -1,    73,    -1,    75,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    90,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    89,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    77,    -1,    79,    -1,    -1,    -1,
      -1,    31,    85,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    31,    77,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,
      75,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    69,
      -1,    71,    -1,    73,    -1,    75,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    71,    -1,
      -1,    74,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    69,    71,    73,    74,
      75,   101,   103,   108,   109,   110,   112,   113,   149,   150,
     151,   160,   163,   164,   165,   166,   178,     4,    89,    76,
      76,    76,     0,   112,   109,     4,    76,    79,    84,   114,
     115,   116,   117,   167,   112,     4,    89,   112,   112,   112,
      89,     4,   105,   161,   162,     3,     4,     6,     7,     8,
       9,    11,    12,    32,    70,    72,    76,    78,    79,    80,
      81,    82,    83,   102,   103,   104,   106,   107,   130,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   148,   152,   157,   164,   170,   170,   148,   114,
      71,   164,   167,   168,    88,    89,   111,   112,   113,   121,
      76,    85,    84,    87,   115,    89,   155,   156,   157,   178,
     161,    88,    87,    90,    76,   132,    76,   132,   132,    76,
      76,   132,   144,   145,   147,   170,   157,   133,    10,    11,
      12,    76,    85,    92,    79,    93,    94,    80,    81,    13,
      14,    15,    16,    95,    96,    17,    18,    78,    97,    98,
      19,    20,    99,    77,    76,    85,   167,   171,   172,   157,
      77,    77,    87,    77,   164,   167,    89,   145,   173,     4,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    84,    90,   113,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   147,   113,   121,   114,     4,    77,   112,
     118,   119,   120,   169,    35,    79,    86,   145,   168,   117,
     155,    90,   156,    84,    91,   114,   158,   159,    87,    90,
     148,    90,   162,   170,   170,   170,   145,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    88,   146,    77,
      87,    77,     4,    77,   131,   145,   147,     4,   133,   133,
     133,   134,   134,   135,   135,   136,   136,   136,   136,   137,
     137,   138,   139,   140,   141,   142,   147,    77,   118,   171,
      35,    79,    86,   145,   168,   172,    76,    85,     3,    85,
      92,   173,   174,   175,   176,   177,    91,   148,    91,    76,
      76,    76,   124,    76,     4,    84,    84,    84,   147,    90,
     123,    84,     4,   167,   171,    77,    87,    77,    87,   145,
     168,    86,    86,    35,    79,    86,   145,    90,   148,    91,
      84,    87,    90,    77,    77,    77,    87,   145,   145,    89,
     133,    77,    87,    86,    91,    77,    77,   145,   168,    86,
      86,    35,    86,   145,    77,   118,    35,    79,    86,   145,
     168,    77,   148,     4,    87,    90,   173,    88,   177,   124,
      91,   124,   147,   147,   147,    62,   113,   125,    84,    84,
      85,     4,     5,   120,     4,    86,   145,   145,    86,    86,
     148,   159,    58,   153,   154,   170,   174,   145,   144,    86,
     145,   145,    86,    77,   145,   168,    86,    86,    35,    86,
     145,    84,    86,    90,   173,   175,   124,    77,    77,    77,
      76,   125,   125,    86,    86,    86,    91,    77,    87,    91,
      87,    90,    86,    86,    86,   145,   145,    86,   173,   124,
     124,   124,   147,    77,   147,    77,   147,   145,   154,   145,
      90,    86,    86,    60,    77,   124,    77,   124,    77,   124,
      84,   124,   124
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   102,   102,   102,   102,   102,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   104,   105,   106,
     106,   106,   106,   106,   106,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   126,   126,   127,   127,   127,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   132,   132,   132,   132,   132,   133,   133,   134,   134,
     134,   134,   135,   135,   135,   136,   136,   136,   137,   137,
     137,   137,   137,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   147,   147,   148,   149,   149,   149,   149,   149,   149,
     150,   150,   150,   151,   151,   152,   153,   153,   154,   154,
     155,   155,   156,   156,   156,   157,   157,   157,   157,   158,
     158,   159,   159,   159,   160,   160,   160,   160,   160,   161,
     161,   162,   162,   163,   164,   164,   164,   164,   165,   165,
     166,   166,   167,   167,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   173,   173,   173,   174,
     174,   174,   174,   175,   176,   176,   177,   177,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       4,     3,     1,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     3,     1,     2,     1,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       4,     3,     4,     1,     3,     3,     1,     3,     1,     1,
       3,     2,     3,     2,     1,     4,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     3,     7,     5,     5,     5,     7,     6,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     6,     7,     1,     3,     1,
       2,     2,     2,     2,     4,     4,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     6,     1,     3,     3,     3,
       1,     2,     2,     3,     1,     2,     1,     2,     1,     1,
       3,     2,     3,     1,     4,     5,     5,     6,     2,     1,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     2,     2,     1,     1,     2,     1,     3,
       2,     1,     2,     1,     1,     3,     2,     3,     5,     4,
       5,     4,     3,     3,     3,     4,     6,     5,     5,     6,
       4,     4,     2,     3,     3,     4,     3,     4,     1,     2,
       1,     4,     3,     2,     1,     2,     3,     2,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 81 "c.y"
                           {ASTNode* root = new ASTNode(ASTNode::TRANSLATION_UNIT, "START"); (yyval.node) = root; 
	for(int i = 0; i < (yyvsp[0].nodelist)->getLength(); i++) {
			(yyval.node)->addChild((yyvsp[0].nodelist)->get(i));
		}
	AST = (yyval.node);}
#line 2144 "c.tab.cpp"
    break;

  case 3:
#line 89 "c.y"
                     {(yyval.node) = new ASTNode(ASTNode::ID, (yyvsp[0].sval));}
#line 2150 "c.tab.cpp"
    break;

  case 4:
#line 90 "c.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2156 "c.tab.cpp"
    break;

  case 5:
#line 91 "c.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2162 "c.tab.cpp"
    break;

  case 6:
#line 92 "c.y"
                             {(yyval.node) = ((yyvsp[-1].nodelist)->get(0));}
#line 2168 "c.tab.cpp"
    break;

  case 8:
#line 97 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "VOID");}
#line 2174 "c.tab.cpp"
    break;

  case 9:
#line 98 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "CHAR");}
#line 2180 "c.tab.cpp"
    break;

  case 10:
#line 99 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "SHORT");}
#line 2186 "c.tab.cpp"
    break;

  case 11:
#line 100 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "INT");}
#line 2192 "c.tab.cpp"
    break;

  case 12:
#line 101 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "LONG");}
#line 2198 "c.tab.cpp"
    break;

  case 13:
#line 102 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "FLOAT");}
#line 2204 "c.tab.cpp"
    break;

  case 14:
#line 103 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "DOUBLE");}
#line 2210 "c.tab.cpp"
    break;

  case 15:
#line 104 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "SIGNED");}
#line 2216 "c.tab.cpp"
    break;

  case 16:
#line 105 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "UNSIGNED");}
#line 2222 "c.tab.cpp"
    break;

  case 17:
#line 106 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "BOOL");}
#line 2228 "c.tab.cpp"
    break;

  case 18:
#line 107 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::TYPE, "COMPLEX");}
#line 2234 "c.tab.cpp"
    break;

  case 24:
#line 116 "c.y"
                                {(yyval.node) = new ASTNode(ASTNode::ICONST, (yyvsp[0].ival));}
#line 2240 "c.tab.cpp"
    break;

  case 25:
#line 117 "c.y"
                                {(yyval.node) = new ASTNode(ASTNode::FCONST, (yyvsp[0].fval));}
#line 2246 "c.tab.cpp"
    break;

  case 26:
#line 118 "c.y"
                                {
	std::string s = (yyvsp[0].sval);
	std::size_t pos = s.find("\\n");
    if (pos != std::string::npos) {
		s.replace(pos, 2, "\n");
	}
    
	(yyval.node) = new ASTNode(ASTNode::SCONST, s);}
#line 2259 "c.tab.cpp"
    break;

  case 28:
#line 130 "c.y"
                     {(yyval.node) = new ASTNode(ASTNode::TYPE, (yyvsp[0].sval));}
#line 2265 "c.tab.cpp"
    break;

  case 29:
#line 135 "c.y"
              {(yyval.node) = new ASTNode(ASTNode::UNOP, "&");}
#line 2271 "c.tab.cpp"
    break;

  case 30:
#line 136 "c.y"
              {(yyval.node) = new ASTNode(ASTNode::UNOP, "*");}
#line 2277 "c.tab.cpp"
    break;

  case 31:
#line 137 "c.y"
              {(yyval.node) = new ASTNode(ASTNode::UNOP, "+");}
#line 2283 "c.tab.cpp"
    break;

  case 32:
#line 138 "c.y"
              {(yyval.node) = new ASTNode(ASTNode::UNOP, "-");}
#line 2289 "c.tab.cpp"
    break;

  case 33:
#line 139 "c.y"
              {(yyval.node) = new ASTNode(ASTNode::UNOP, "~");}
#line 2295 "c.tab.cpp"
    break;

  case 34:
#line 140 "c.y"
              {(yyval.node) = new ASTNode(ASTNode::UNOP, "!");}
#line 2301 "c.tab.cpp"
    break;

  case 36:
#line 151 "c.y"
                               {(yyval.nodelist) = new ASTNodeList((yyvsp[0].node));}
#line 2307 "c.tab.cpp"
    break;

  case 37:
#line 152 "c.y"
                                                {(yyvsp[-1].nodelist)->add((yyvsp[0].node)); (yyval.nodelist) = (yyvsp[-1].nodelist);}
#line 2313 "c.tab.cpp"
    break;

  case 38:
#line 156 "c.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2319 "c.tab.cpp"
    break;

  case 39:
#line 157 "c.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2325 "c.tab.cpp"
    break;

  case 40:
#line 161 "c.y"
                                                                                {(yyval.node) = new ASTNode(ASTNode::FUNC, "FUNCTION"); (yyval.node)->addChild((yyvsp[-3].node)); (yyval.node)->addChild((yyvsp[-2].node)); (yyval.node)->addChild((yyvsp[-1].node)); (yyval.node)->addChild((yyvsp[0].node));}
#line 2331 "c.tab.cpp"
    break;

  case 41:
#line 162 "c.y"
                                                               {(yyval.node) = new ASTNode(ASTNode::FUNC, "FUNCTION"); (yyval.node)->addChild((yyvsp[-2].node)); (yyval.node)->addChild((yyvsp[-1].node)); (yyval.node)->addChild((yyvsp[0].node)); }
#line 2337 "c.tab.cpp"
    break;

  case 47:
#line 174 "c.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2343 "c.tab.cpp"
    break;

  case 49:
#line 176 "c.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2349 "c.tab.cpp"
    break;

  case 55:
#line 186 "c.y"
                                                          {
		(yyval.node) = new ASTNode(ASTNode::VARDEC, "DECL");
		(yyval.node)->addChild((yyvsp[-2].node));
		for(int i = 0; i < (yyvsp[-1].nodelist)->getLength(); i++) {
			(yyval.node)->addChild((yyvsp[-1].nodelist)->get(i));
		}
	}
#line 2361 "c.tab.cpp"
    break;

  case 57:
#line 197 "c.y"
                                    {int np = (yyvsp[-1].ival);
	ASTNode* tmp = new ASTNode(ASTNode::POINTER, "POINTER");
	(yyval.node) = tmp;
	ASTNode* tmp1;
	for(int i = 0; i < np-1; i++) {
		tmp1 = new ASTNode(ASTNode::POINTER, "POINTER");
		tmp->addChild(tmp1);
		tmp = tmp1;
	}
	tmp -> addChild((yyvsp[0].node));
	}
#line 2377 "c.tab.cpp"
    break;

  case 58:
#line 208 "c.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2383 "c.tab.cpp"
    break;

  case 59:
#line 212 "c.y"
                     {(yyval.node) = new ASTNode(ASTNode::ID, (yyvsp[0].sval));}
#line 2389 "c.tab.cpp"
    break;

  case 61:
#line 214 "c.y"
                                    {(yyval.node) = new ASTNode(ASTNode::ARRAY, "ARRAY"); (yyval.node)->addChild((yyvsp[-2].node)); }
#line 2395 "c.tab.cpp"
    break;

  case 69:
#line 223 "c.y"
        {(yyval.node) = new ASTNode(ASTNode::ARRAY, "ARRAY"); (yyval.node)->addChild((yyvsp[-3].node)); (yyval.node)->addChild((yyvsp[-1].node));
	}
#line 2402 "c.tab.cpp"
    break;

  case 70:
#line 226 "c.y"
                                                        {(yyval.node) = new ASTNode(ASTNode::FUNCDEF, "FUNCDEF"); 
	(yyval.node)->addChild((yyvsp[-3].node)); 
	for(int i = 0; i < (yyvsp[-1].nodelist)->getLength(); i++) {
			(yyval.node)->addChild((yyvsp[-1].nodelist)->get(i));
		}
	}
#line 2413 "c.tab.cpp"
    break;

  case 71:
#line 232 "c.y"
                                    {(yyval.node) = new ASTNode(ASTNode::FUNCDEF, "FUNCDEF"); 
	(yyval.node)->addChild((yyvsp[-2].node)); 
	}
#line 2421 "c.tab.cpp"
    break;

  case 73:
#line 239 "c.y"
                          {(yyval.nodelist) = new ASTNodeList((yyvsp[0].node));}
#line 2427 "c.tab.cpp"
    break;

  case 74:
#line 240 "c.y"
                                                   {(yyvsp[-2].nodelist)->add((yyvsp[0].node)); (yyval.nodelist) = (yyvsp[-2].nodelist);}
#line 2433 "c.tab.cpp"
    break;

  case 75:
#line 244 "c.y"
                                     {ASTNode* tmp = new ASTNode(ASTNode::ASSIGNEXP, "="); (yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "ASSIGN", (yyvsp[-2].node), tmp, (yyvsp[0].node));}
#line 2439 "c.tab.cpp"
    break;

  case 76:
#line 245 "c.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2445 "c.tab.cpp"
    break;

  case 77:
#line 249 "c.y"
                                      {(yyval.nodelist) = (yyvsp[-2].nodelist); ASTNode* moreparam = new ASTNode(ASTNode::ID, (yyvsp[0].sval)); (yyval.nodelist)->add(moreparam);}
#line 2451 "c.tab.cpp"
    break;

  case 78:
#line 250 "c.y"
                         {(yyval.nodelist) = (yyvsp[0].nodelist);}
#line 2457 "c.tab.cpp"
    break;

  case 79:
#line 254 "c.y"
                                {(yyval.nodelist) = new ASTNodeList((yyvsp[0].node));}
#line 2463 "c.tab.cpp"
    break;

  case 80:
#line 255 "c.y"
                                                   {(yyvsp[-2].nodelist)->add((yyvsp[0].node)); (yyval.nodelist) = (yyvsp[-2].nodelist);}
#line 2469 "c.tab.cpp"
    break;

  case 81:
#line 259 "c.y"
                                            {(yyval.node) = new ASTNode(ASTNode::PARAMETER, "PARAM"); (yyval.node)->addChild((yyvsp[-1].node)); ASTNode* id = new ASTNode(ASTNode::ID, (yyvsp[0].sval)); (yyval.node)->addChild(id);}
#line 2475 "c.tab.cpp"
    break;

  case 82:
#line 260 "c.y"
                                                    {(yyval.node) = new ASTNode(ASTNode::PARAMETER, "PARAM"); 
	int ptrs = (yyvsp[-1].ival);
	for(int i =0; i<ptrs; i++){
		(yyvsp[-2].node)->repr = (yyvsp[-2].node)->repr + "*";
	}
	(yyval.node)->addChild((yyvsp[-2].node)); 
	ASTNode* id = new ASTNode(ASTNode::ID, (yyvsp[0].sval)); (yyval.node)->addChild(id);}
#line 2487 "c.tab.cpp"
    break;

  case 85:
#line 269 "c.y"
                                                    {(yyval.node) = new ASTNode(ASTNode::PARAMETER, "PARAM"); (yyval.node)->addChild((yyvsp[-3].node)); ASTNode* id = new ASTNode(ASTNode::ID, (yyvsp[-2].sval)); ASTNode* arr = new ASTNode(ASTNode::ARRAY, "ARRAY"); arr->addChild(id); (yyval.node)->addChild(arr);}
#line 2493 "c.tab.cpp"
    break;

  case 86:
#line 273 "c.y"
                  {(yyval.node) = new ASTNode(ASTNode::BLOCK, "STBLOCK"); }
#line 2499 "c.tab.cpp"
    break;

  case 87:
#line 274 "c.y"
                                   {(yyval.node) = new ASTNode(ASTNode::BLOCK, "STBLOCK");
		for(int i = 0; i < (yyvsp[-1].nodelist)->getLength(); i++) {
			(yyval.node)->addChild((yyvsp[-1].nodelist)->get(i));
		}
	}
#line 2509 "c.tab.cpp"
    break;

  case 88:
#line 282 "c.y"
                     {(yyval.nodelist) = new ASTNodeList((yyvsp[0].node));}
#line 2515 "c.tab.cpp"
    break;

  case 89:
#line 283 "c.y"
                                     {(yyvsp[-1].nodelist)->add((yyvsp[0].node)); (yyval.nodelist) = (yyvsp[-1].nodelist);}
#line 2521 "c.tab.cpp"
    break;

  case 90:
#line 287 "c.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2527 "c.tab.cpp"
    break;

  case 91:
#line 288 "c.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2533 "c.tab.cpp"
    break;

  case 92:
#line 292 "c.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2539 "c.tab.cpp"
    break;

  case 93:
#line 293 "c.y"
                             {(yyval.node) = (yyvsp[0].node);}
#line 2545 "c.tab.cpp"
    break;

  case 94:
#line 294 "c.y"
                               {(yyval.node) = (yyvsp[0].node);}
#line 2551 "c.tab.cpp"
    break;

  case 95:
#line 295 "c.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2557 "c.tab.cpp"
    break;

  case 96:
#line 296 "c.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2563 "c.tab.cpp"
    break;

  case 97:
#line 297 "c.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2569 "c.tab.cpp"
    break;

  case 99:
#line 302 "c.y"
                         {(yyval.node) = new ASTNode(ASTNode::EXPRESSION, "EXPBLOCK");
		for(int i = 0; i < (yyvsp[-1].nodelist)->getLength(); i++) {
			(yyval.node)->addChild((yyvsp[-1].nodelist)->get(i));
		}
	}
#line 2579 "c.tab.cpp"
    break;

  case 100:
#line 310 "c.y"
                                   {(yyval.node) = new ASTNode(ASTNode::LABEL, (yyvsp[-2].sval)); (yyval.node)->addChild((yyvsp[0].node));}
#line 2585 "c.tab.cpp"
    break;

  case 103:
#line 316 "c.y"
                                                         {(yyval.node) = new ASTNode(ASTNode::ITE, "ITE"); 
		(yyval.node)->addChild((yyvsp[-4].nodelist)->get(0));
		(yyval.node)->addChild((yyvsp[-2].node)); (yyval.node)->addChild((yyvsp[0].node));
	}
#line 2594 "c.tab.cpp"
    break;

  case 104:
#line 320 "c.y"
                                          {(yyval.node) = new ASTNode(ASTNode::ITE, "ITE"); 
		(yyval.node)->addChild((yyvsp[-2].nodelist)->get(0)); (yyval.node)->addChild((yyvsp[0].node));
	}
#line 2602 "c.tab.cpp"
    break;

  case 106:
#line 327 "c.y"
                                             { (yyval.node) = new ASTNode(ASTNode::WHILE, "WHILE");
		(yyval.node)->addChild((yyvsp[-2].nodelist)->get(0));
		(yyval.node)->addChild((yyvsp[0].node)); 
	}
#line 2611 "c.tab.cpp"
    break;

  case 109:
#line 333 "c.y"
                                                                                     { (yyval.node) = new ASTNode(ASTNode::FOR, "FOR");
		(yyval.node)->addChild((yyvsp[-4].node));
		(yyval.node)->addChild((yyvsp[-3].node)); 
		(yyval.node)->addChild((yyvsp[-2].nodelist)->get(0));
		(yyval.node)->addChild((yyvsp[0].node)); 
	}
#line 2622 "c.tab.cpp"
    break;

  case 112:
#line 344 "c.y"
                              {(yyval.node) = new ASTNode(ASTNode::GOTO, "GOTO"); ASTNode* temp = new ASTNode(ASTNode::ID, (yyvsp[-1].sval)); (yyval.node)->addChild(temp);}
#line 2628 "c.tab.cpp"
    break;

  case 115:
#line 347 "c.y"
                     {}
#line 2634 "c.tab.cpp"
    break;

  case 116:
#line 348 "c.y"
                                {(yyval.node) = new ASTNode(ASTNode::RETURN, "RETURN"); (yyval.node)-> addChild((yyvsp[-1].nodelist)->get(0));}
#line 2640 "c.tab.cpp"
    break;

  case 117:
#line 354 "c.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2646 "c.tab.cpp"
    break;

  case 118:
#line 355 "c.y"
                                                {(yyval.node) = new ASTNode(ASTNode::ARRELEM, (yyvsp[-3].node)->repr);  
	ASTNode* tmp = new ASTNode(ASTNode::EXPRESSION, "INDEX");
	for(int i = 0; i < (yyvsp[-1].nodelist)->getLength(); i++) {
		tmp->addChild((yyvsp[-1].nodelist)->get(i));
	}
	(yyval.node)->addChild(tmp);}
#line 2657 "c.tab.cpp"
    break;

  case 120:
#line 362 "c.y"
                                                              {(yyval.node) = new ASTNode(ASTNode::FUNCALL, "FUNCALL");
		(yyval.node)->addChild((yyvsp[-3].node));
		for(int i = 0; i < (yyvsp[-1].nodelist)->getLength(); i++) {
			(yyval.node)->addChild((yyvsp[-1].nodelist)->get(i));
		}
	}
#line 2668 "c.tab.cpp"
    break;

  case 123:
#line 370 "c.y"
                                    {(yyval.node) = new ASTNode(ASTNode::UNEXP, "POSTINCR", (yyvsp[-1].node));}
#line 2674 "c.tab.cpp"
    break;

  case 124:
#line 371 "c.y"
                                    {(yyval.node) = new ASTNode(ASTNode::UNEXP, "POSTDECR", (yyvsp[-1].node));}
#line 2680 "c.tab.cpp"
    break;

  case 127:
#line 378 "c.y"
                                {(yyval.nodelist) = new ASTNodeList((yyvsp[0].node));}
#line 2686 "c.tab.cpp"
    break;

  case 128:
#line 379 "c.y"
                                                             {(yyvsp[-2].nodelist)->add((yyvsp[0].node)); (yyval.nodelist) = (yyvsp[-2].nodelist);}
#line 2692 "c.tab.cpp"
    break;

  case 129:
#line 383 "c.y"
                             {(yyval.node) = (yyvsp[0].node);}
#line 2698 "c.tab.cpp"
    break;

  case 130:
#line 384 "c.y"
                                  {(yyval.node) = new ASTNode(ASTNode::UNEXP, "++", (yyvsp[0].node));}
#line 2704 "c.tab.cpp"
    break;

  case 131:
#line 385 "c.y"
                                  {(yyval.node) = new ASTNode(ASTNode::UNEXP, "--", (yyvsp[0].node));}
#line 2710 "c.tab.cpp"
    break;

  case 136:
#line 393 "c.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2716 "c.tab.cpp"
    break;

  case 138:
#line 398 "c.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 2722 "c.tab.cpp"
    break;

  case 139:
#line 399 "c.y"
                                                        {(yyval.node) = new ASTNode(ASTNode::BINEXP, "TIMES", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2728 "c.tab.cpp"
    break;

  case 140:
#line 400 "c.y"
                                                        {(yyval.node) = new ASTNode(ASTNode::BINEXP, "DIV", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2734 "c.tab.cpp"
    break;

  case 141:
#line 401 "c.y"
                                                        {(yyval.node) = new ASTNode(ASTNode::BINEXP, "MOD", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2740 "c.tab.cpp"
    break;

  case 142:
#line 405 "c.y"
                                    {(yyval.node) = (yyvsp[0].node);}
#line 2746 "c.tab.cpp"
    break;

  case 143:
#line 406 "c.y"
                                                            {(yyval.node) = new ASTNode(ASTNode::BINEXP, "PLUS", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2752 "c.tab.cpp"
    break;

  case 144:
#line 407 "c.y"
                                                            {(yyval.node) = new ASTNode(ASTNode::BINEXP, "MINUS", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2758 "c.tab.cpp"
    break;

  case 145:
#line 411 "c.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2764 "c.tab.cpp"
    break;

  case 146:
#line 412 "c.y"
                                                       {(yyval.node) = new ASTNode(ASTNode::BINEXP, "<<", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2770 "c.tab.cpp"
    break;

  case 147:
#line 413 "c.y"
                                                        {(yyval.node) = new ASTNode(ASTNode::BINEXP, ">>", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2776 "c.tab.cpp"
    break;

  case 148:
#line 417 "c.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2782 "c.tab.cpp"
    break;

  case 149:
#line 418 "c.y"
                                                     {(yyval.node) = new ASTNode(ASTNode::BINEXP, "LT", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2788 "c.tab.cpp"
    break;

  case 150:
#line 419 "c.y"
                                                     {(yyval.node) = new ASTNode(ASTNode::BINEXP, "GT", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2794 "c.tab.cpp"
    break;

  case 151:
#line 420 "c.y"
                                                       {(yyval.node) = new ASTNode(ASTNode::BINEXP, "LE", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2800 "c.tab.cpp"
    break;

  case 152:
#line 421 "c.y"
                                                       {(yyval.node) = new ASTNode(ASTNode::BINEXP, "GE", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2806 "c.tab.cpp"
    break;

  case 153:
#line 425 "c.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 2812 "c.tab.cpp"
    break;

  case 154:
#line 426 "c.y"
                                                          {(yyval.node) = new ASTNode(ASTNode::BINEXP, "EQ", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2818 "c.tab.cpp"
    break;

  case 155:
#line 427 "c.y"
                                                          {(yyval.node) = new ASTNode(ASTNode::BINEXP, "NEQ", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2824 "c.tab.cpp"
    break;

  case 156:
#line 431 "c.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2830 "c.tab.cpp"
    break;

  case 157:
#line 432 "c.y"
                                                 {(yyval.node) = new ASTNode(ASTNode::BINEXP, "&", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2836 "c.tab.cpp"
    break;

  case 158:
#line 436 "c.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2842 "c.tab.cpp"
    break;

  case 159:
#line 437 "c.y"
                                                     {(yyval.node) = new ASTNode(ASTNode::BINEXP, "XOR", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2848 "c.tab.cpp"
    break;

  case 160:
#line 441 "c.y"
                                  {(yyval.node) = (yyvsp[0].node);}
#line 2854 "c.tab.cpp"
    break;

  case 161:
#line 442 "c.y"
                                                              {(yyval.node) = new ASTNode(ASTNode::BINEXP, "IOR", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2860 "c.tab.cpp"
    break;

  case 162:
#line 446 "c.y"
                                  {(yyval.node) = (yyvsp[0].node);}
#line 2866 "c.tab.cpp"
    break;

  case 163:
#line 447 "c.y"
                                                                {(yyval.node) = new ASTNode(ASTNode::BINEXP, "AND", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2872 "c.tab.cpp"
    break;

  case 164:
#line 451 "c.y"
                                 {(yyval.node) = (yyvsp[0].node);}
#line 2878 "c.tab.cpp"
    break;

  case 165:
#line 452 "c.y"
                                                             {(yyval.node) = new ASTNode(ASTNode::BINEXP, "OR", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2884 "c.tab.cpp"
    break;

  case 166:
#line 456 "c.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 2890 "c.tab.cpp"
    break;

  case 168:
#line 461 "c.y"
                                 {(yyval.node) = (yyvsp[0].node);}
#line 2896 "c.tab.cpp"
    break;

  case 169:
#line 462 "c.y"
                                                                     {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "ASSIGN", (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 2902 "c.tab.cpp"
    break;

  case 170:
#line 466 "c.y"
                                {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "=");}
#line 2908 "c.tab.cpp"
    break;

  case 171:
#line 467 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "*=");}
#line 2914 "c.tab.cpp"
    break;

  case 172:
#line 468 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "/=");}
#line 2920 "c.tab.cpp"
    break;

  case 173:
#line 469 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "%=");}
#line 2926 "c.tab.cpp"
    break;

  case 174:
#line 470 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "+=");}
#line 2932 "c.tab.cpp"
    break;

  case 175:
#line 471 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "-=");}
#line 2938 "c.tab.cpp"
    break;

  case 178:
#line 474 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "&=");}
#line 2944 "c.tab.cpp"
    break;

  case 179:
#line 475 "c.y"
                        {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "^=");}
#line 2950 "c.tab.cpp"
    break;

  case 180:
#line 476 "c.y"
                                {(yyval.node) = new ASTNode(ASTNode::ASSIGNEXP, "|=");}
#line 2956 "c.tab.cpp"
    break;

  case 181:
#line 480 "c.y"
                                 {(yyval.nodelist) = new ASTNodeList((yyvsp[0].node));}
#line 2962 "c.tab.cpp"
    break;

  case 182:
#line 481 "c.y"
                                               {(yyvsp[-2].nodelist)->add((yyvsp[0].node)); (yyval.nodelist) = (yyvsp[-2].nodelist);}
#line 2968 "c.tab.cpp"
    break;

  case 234:
#line 594 "c.y"
                      {(yyval.ival) = (yyvsp[0].ival) + 1;}
#line 2974 "c.tab.cpp"
    break;

  case 235:
#line 595 "c.y"
              {(yyval.ival) = 1;}
#line 2980 "c.tab.cpp"
    break;

  case 266:
#line 646 "c.y"
                                   {	
		(yyval.node) = new ASTNode(ASTNode::LIST, "LIST");	
		for(int i = 0; i < (yyvsp[-1].nodelist)->getLength(); i++) {
			(yyval.node)->addChild((yyvsp[-1].nodelist)->get(i));
		}
		}
#line 2991 "c.tab.cpp"
    break;

  case 268:
#line 653 "c.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 2997 "c.tab.cpp"
    break;

  case 270:
#line 658 "c.y"
                      {(yyval.nodelist) = new ASTNodeList((yyvsp[0].node));}
#line 3003 "c.tab.cpp"
    break;

  case 272:
#line 660 "c.y"
                                           {(yyvsp[-2].nodelist)->add((yyvsp[0].node)); (yyval.nodelist) = (yyvsp[-2].nodelist);}
#line 3009 "c.tab.cpp"
    break;


#line 3013 "c.tab.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 681 "c.y"

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}

void replace_first(std::string& s, std::string const& toReplace, std::string const& replaceWith) {
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos) return;
    s.replace(pos, toReplace.length(), replaceWith);
}
