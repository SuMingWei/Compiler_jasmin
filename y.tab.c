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
#line 2 "compiler_hw3.y"

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    
    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    
    void yyerror (char const *s)
    {
        HAS_ERROR = true;
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    struct data {
        int index;
        char *name;
        char *type;
        int address;
        int lineno;
        char *elementType;
    };

    struct data symbol_table[100][100];
    int tail[100] = {0};
    int cur_addr = 0;
    int cur_scope = 0;

    int label = 0;
    char * cur_id = "";
    int assignFlag = 1;
    char * assign_id = "";
    int labelIF[100][100];
    int elseNum[100] = {0};
    int labelFOR[100];
    int labelFORend[100];
    int labelWHILE[100];
    int labelWHILEend[100];

    static void create_symbol();
    static void insert_symbol(char *, char *, char *);
    static char *lookup_symbol(char *);
    static void dump_symbol();
    static void update_symbol(char *);
    static char *getType(char *);
    static int check_id(char *);


#line 134 "y.tab.c"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    AND = 258,
    OR = 259,
    QUO = 260,
    REM = 261,
    INC = 262,
    DEC = 263,
    EQL = 264,
    NEQ = 265,
    LSS = 266,
    LEQ = 267,
    GTR = 268,
    GEQ = 269,
    ASSIGN = 270,
    ADD_ASSIGN = 271,
    SUB_ASSIGN = 272,
    MUL_ASSIGN = 273,
    QUO_ASSIGN = 274,
    REM_ASSIGN = 275,
    TRUE = 276,
    FALSE = 277,
    INT = 278,
    FLOAT = 279,
    BOOL = 280,
    STRING = 281,
    PRINT = 282,
    IF = 283,
    ELSE = 284,
    FOR = 285,
    WHILE = 286,
    SEMICOLON = 287,
    INT_LIT = 288,
    FLOAT_LIT = 289,
    STRING_LIT = 290,
    IDENT = 291
  };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define QUO 260
#define REM 261
#define INC 262
#define DEC 263
#define EQL 264
#define NEQ 265
#define LSS 266
#define LEQ 267
#define GTR 268
#define GEQ 269
#define ASSIGN 270
#define ADD_ASSIGN 271
#define SUB_ASSIGN 272
#define MUL_ASSIGN 273
#define QUO_ASSIGN 274
#define REM_ASSIGN 275
#define TRUE 276
#define FALSE 277
#define INT 278
#define FLOAT 279
#define BOOL 280
#define STRING 281
#define PRINT 282
#define IF 283
#define ELSE 284
#define FOR 285
#define WHILE 286
#define SEMICOLON 287
#define INT_LIT 288
#define FLOAT_LIT 289
#define STRING_LIT 290
#define IDENT 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 71 "compiler_hw3.y"

    int i_val;
    float f_val;
    char *s_val;
    char *id;
    char *type;
    char *operator;

#line 267 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


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
       2,     2,     2,    46,    43,     2,     2,     2,     2,     2,
      41,    42,    47,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   113,   114,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   130,   158,   179,   201,   225,   229,
     232,   232,   272,   275,   285,   298,   298,   304,   317,   318,
     334,   341,   350,   355,   350,   367,   376,   384,   389,   384,
     404,   405,   406,   410,   410,   439,   443,   444,   466,   467,
     489,   490,   528,   529,   560,   561,   606,   607,   627,   628,
     629,   633,   634,   635,   639,   648,   660,   664,   668,   672,
     676,   683,   684,   685,   689,   690,   691,   692,   693,   694,
     698,   699,   703,   704,   705,   709,   710,   711,   712,   713,
     714,   718,   722,   723,   724,   725
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "QUO", "REM", "INC", "DEC",
  "EQL", "NEQ", "LSS", "LEQ", "GTR", "GEQ", "ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "TRUE", "FALSE",
  "INT", "FLOAT", "BOOL", "STRING", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "SEMICOLON", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT", "'['", "']'",
  "'{'", "'}'", "'('", "')'", "'\"'", "'+'", "'-'", "'!'", "'*'",
  "$accept", "Program", "StatementList", "Statement", "DeclarationStmt",
  "ExpressionStmt", "AssignmentStmt", "AssignmentExpr", "$@1",
  "IncDecStmt", "IncDecExpr", "Block", "$@2", "IfStmt", "IFCondition",
  "BlockELSE", "WhileStmt", "$@3", "$@4", "Condition", "ForStmt",
  "ForClause", "$@5", "$@6", "SimpleExpr", "PrintStmt", "$@7",
  "Expression", "Logical_OR_Expr", "Logical_And_Expr", "Comparison_Expr",
  "Addition_Expr", "Multiplication_Expr", "UnaryExpr", "PrimaryExpr",
  "Operand", "IndexExpr", "ConversionExpr", "Literal", "Unary_op",
  "Cmp_op", "Add_op", "Mul_op", "Assign_op", "Type", "TypeName", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    91,    93,   123,
     125,    40,    41,    34,    43,    45,    33,    42
};
# endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      26,   -47,   -47,   -47,   -47,   -47,   -47,   -47,    78,   -27,
     -47,   -47,   -47,   -47,   -47,    -4,   -20,   -47,   -47,   -47,
      16,   -47,    26,   -47,   -47,   -47,    -7,   -47,    -6,   -47,
     -47,     5,   -47,   -47,   -47,    56,    27,    30,    81,   -33,
      -1,   -47,    -3,   -47,   -47,   -47,   -47,    78,    19,   -47,
      17,   -47,   -47,    78,    20,    26,    24,    31,    25,   -47,
     -47,   -47,   -47,    45,   -15,   -47,   -47,   -47,   114,    78,
      78,   -47,   -47,   -47,   -47,   -47,   -47,    78,   -47,   -47,
      78,   -47,   -47,   -47,    78,    78,   -47,    -9,    78,   -47,
      33,   -47,    78,    36,   -47,    78,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,    78,    30,    81,   -33,
      -1,   -47,    40,    78,   -47,    78,    37,    78,     5,    39,
     -47,   -47,   -47,   -47,    50,    47,    51,   -47,    54,   -47,
     -47,   -47,    -5,   -47,    78,     5,    78,   -47,   -47,   -47,
     -47,     1,   -47,    64,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    69,    70,    92,    93,    95,    94,    43,     0,     0,
      32,    66,    67,    62,    25,     0,     0,    71,    72,    73,
       0,     2,     4,     5,     6,     7,     0,     8,     0,     9,
      10,     0,    11,    12,    13,    20,    45,    46,    48,    50,
      52,    54,    56,    58,    59,    60,    61,     0,     0,    91,
       0,    30,    35,     0,     0,     0,     0,     0,     0,     1,
       3,    19,    22,    27,     0,    23,    24,    18,     0,     0,
       0,    74,    75,    76,    77,    78,    79,     0,    80,    81,
       0,    83,    84,    82,     0,     0,    57,     0,     0,    37,
       0,    20,     0,     0,    63,     0,    68,    31,    29,    28,
      85,    86,    87,    88,    89,    90,     0,    47,    49,    51,
      53,    55,     0,     0,    14,     0,     0,     0,     0,     0,
      26,    65,    21,    64,     0,     0,     0,    38,     0,    36,
      33,    16,     0,    44,     0,     0,     0,    15,    40,    42,
      39,    20,    34,     0,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -19,   -47,   -47,   -16,    44,   -32,   -47,   -47,
     -31,   -29,   -47,    46,   -47,   -47,   -47,   -47,   -47,    12,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,    -8,   -47,    48,
      38,    41,    35,   -46,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,    98,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    68,    27,
      28,    29,    55,    30,    31,    64,    32,    54,   135,    51,
      33,    90,   117,   134,   140,    34,    50,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      77,    80,    84,   106,    48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    86,    63,    60,    81,    82,   113,    56,    65,    66,
     136,    78,    79,     8,    53,    58,    59,     1,     2,     3,
       4,     5,     6,   114,    14,    61,    62,   137,   115,    11,
      12,    69,    13,    70,    85,    98,    93,    15,   111,    16,
      17,    18,    19,   -41,    14,    91,    83,     1,     2,     3,
       4,     5,     6,     7,     8,    87,     9,    10,    88,    11,
      12,    92,    13,    65,    66,    14,    94,    15,    96,    16,
      17,    18,    19,    95,    97,   118,   120,   112,   123,   126,
     116,   130,   131,   133,    52,   132,    67,   121,    67,   129,
      71,    72,    73,    74,    75,    76,   144,    89,   122,     1,
       2,   127,   138,   139,   119,   124,   142,   125,   108,   128,
      99,    11,    12,    57,    13,   110,     0,   107,   109,    15,
       0,    16,    17,    18,    19,     0,   141,     0,   143,   100,
     101,   102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
       8,    47,    31,    22,     5,     6,    15,    15,     7,     8,
      15,    44,    45,    28,    41,    35,     0,    21,    22,    23,
      24,    25,    26,    32,    39,    32,    32,    32,    37,    33,
      34,     4,    36,     3,    37,    64,    55,    41,    84,    43,
      44,    45,    46,    42,    39,    53,    47,    21,    22,    23,
      24,    25,    26,    27,    28,    36,    30,    31,    41,    33,
      34,    41,    36,     7,     8,    39,    42,    41,    43,    43,
      44,    45,    46,    42,    29,    42,    40,    85,    38,    42,
      88,    42,    32,    32,    92,    38,    32,    95,    32,   118,
       9,    10,    11,    12,    13,    14,    32,    53,   106,    21,
      22,   117,   134,   134,    92,   113,   135,   115,    70,   117,
      64,    33,    34,    15,    36,    80,    -1,    69,    77,    41,
      -1,    43,    44,    45,    46,    -1,   134,    -1,   136,    15,
      16,    17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      31,    33,    34,    36,    39,    41,    43,    44,    45,    46,
      49,    50,    51,    52,    53,    54,    55,    57,    58,    59,
      61,    62,    64,    68,    73,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    92,    93,
      74,    67,    75,    41,    65,    60,    75,    92,    35,     0,
      50,    32,    32,    59,    63,     7,     8,    32,    56,     4,
       3,     9,    10,    11,    12,    13,    14,    88,    44,    45,
      89,     5,     6,    47,    90,    37,    81,    36,    41,    54,
      69,    75,    41,    50,    42,    42,    43,    29,    59,    61,
      15,    16,    17,    18,    19,    20,    91,    77,    78,    79,
      80,    81,    75,    15,    32,    37,    75,    70,    42,    67,
      40,    75,    75,    38,    75,    75,    42,    53,    75,    59,
      42,    32,    38,    32,    71,    66,    15,    32,    55,    58,
      72,    75,    59,    75,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    54,
      56,    55,    57,    58,    58,    60,    59,    61,    61,    61,
      62,    63,    65,    66,    64,    67,    68,    70,    71,    69,
      72,    72,    72,    74,    73,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    83,    83,    83,    84,    85,    86,    86,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    92,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     5,     8,     2,     2,
       0,     4,     2,     2,     2,     0,     4,     2,     3,     3,
       2,     2,     0,     0,     7,     1,     5,     0,     0,     5,
       1,     1,     1,     0,     6,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     3,     4,     4,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  case 14:
#line 130 "compiler_hw3.y"
                           {
        // id has been declared
        if(check_id((yyvsp[-1].id)) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        (yyvsp[-1].id), check_id((yyvsp[-1].id)));
            yyerror(errorMessage);
        }else{
            if(strcmp((yyvsp[-2].type),"int") == 0){
                codegen("ldc 0\n");
                codegen("istore %d\n",cur_addr);
            }else if(strcmp((yyvsp[-2].type),"float") == 0){
                codegen("ldc 0.0\n");
                codegen("fstore %d\n",cur_addr);
            }else if(strcmp((yyvsp[-2].type),"string") == 0){
                codegen("ldc \"\"\n");
                codegen("astore %d\n",cur_addr);
            }
            // else if(strcmp($1,"bool") == 0){
            //     codegen("ldc \"true\"\n");
            //     codegen("astore %d\n",cur_addr);
            // }

            insert_symbol((yyvsp[-1].id),(yyvsp[-2].type),"-");
        }
        
    }
#line 1580 "y.tab.c"
    break;

  case 15:
#line 158 "compiler_hw3.y"
                                              {
        // id has been declared
        if(check_id((yyvsp[-4].id)) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        (yyvsp[-4].id), check_id((yyvsp[-4].id)));
            yyerror(errorMessage);
        }else{
            char *type;
            if(strcmp((yyvsp[-5].type),"int") == 0){
                type = "int";
            }else if(strcmp((yyvsp[-5].type),"float") == 0){
                type = "float";
            }
            codegen("newarray %s\n", type);
            codegen("astore %d\n",cur_addr);
            
            insert_symbol((yyvsp[-4].id),"array",(yyvsp[-5].type));
        }
    }
#line 1606 "y.tab.c"
    break;

  case 16:
#line 179 "compiler_hw3.y"
                                             {
        // id has been declared
        if(check_id((yyvsp[-3].id)) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        (yyvsp[-3].id), check_id((yyvsp[-3].id)));
            yyerror(errorMessage);
        }else{
            if(strcmp((yyvsp[-4].type),"int") == 0){
                codegen("istore %d\n",cur_addr);
            }else if(strcmp((yyvsp[-4].type),"float") == 0){
                codegen("fstore %d\n",cur_addr);
            }else if(strcmp((yyvsp[-4].type),"string") == 0){
                codegen("astore %d\n",cur_addr);
            }
            // else if(strcmp($1,"bool") == 0){
            //     codegen("astore %d\n",cur_addr);
            // }
            insert_symbol((yyvsp[-3].id),(yyvsp[-4].type),"-");
        }
    }
#line 1633 "y.tab.c"
    break;

  case 17:
#line 201 "compiler_hw3.y"
                                                                {
        // id has been declared
        if(check_id((yyvsp[-6].id)) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        (yyvsp[-6].id), check_id((yyvsp[-6].id)));
            yyerror(errorMessage);
        }else{
            char *type;
            if(strcmp((yyvsp[-7].type),"int") == 0){
                type = "int";
            }else if(strcmp((yyvsp[-7].type),"float") == 0){
                type = "float";
            }
            codegen("newarray %s\n", type);
            codegen("astore %d\n",cur_addr);

            insert_symbol((yyvsp[-6].id),"array",(yyvsp[-7].type));
        }
    }
#line 1659 "y.tab.c"
    break;

  case 20:
#line 232 "compiler_hw3.y"
                 {
        // assign later
        assignFlag = 0;
        assign_id = cur_id;
    }
#line 1669 "y.tab.c"
    break;

  case 21:
#line 236 "compiler_hw3.y"
                           { 
        // intLit/floatLit cannot be assigned
        if(strcmp((yyvsp[-3].type),"intLit") == 0 || strcmp((yyvsp[-3].type), "floatLit") == 0){
            char errorMessage[100] = "";
            snprintf(errorMessage,sizeof(errorMessage),
                        "cannot assign to %s", getType((yyvsp[0].type)));
            yyerror(errorMessage);
        }
        // mismatched types
        else if(strcmp(getType((yyvsp[-3].type)),getType((yyvsp[0].type))) != 0){
            char errorMessage[100] = "";
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: %s (mismatched types %s and %s)",
                        (yyvsp[-1].operator), getType((yyvsp[-3].type)),getType((yyvsp[0].type)));
            yyerror(errorMessage);
        }else{
            (yyval.type) = (yyvsp[-3].type);
        }

        if(strcmp((yyvsp[-1].operator),"ADD_ASSIGN") == 0){
            codegen("%cadd\n",getType((yyvsp[0].type))[0]);
        }else if(strcmp((yyvsp[-1].operator),"SUB_ASSIGN") == 0){
            codegen("%csub\n",getType((yyvsp[0].type))[0]);
        }else if(strcmp((yyvsp[-1].operator),"MUL_ASSIGN") == 0){
            codegen("%cmul\n",getType((yyvsp[0].type))[0]);
        }else if(strcmp((yyvsp[-1].operator),"QUO_ASSIGN") == 0){
            codegen("%cdiv\n",getType((yyvsp[0].type))[0]);
        }else if(strcmp((yyvsp[-1].operator),"REM_ASSIGN") == 0){
            codegen("%crem\n",getType((yyvsp[0].type))[0]);
        }
        update_symbol(assign_id);
        assignFlag = 1;
    }
#line 1707 "y.tab.c"
    break;

  case 23:
#line 275 "compiler_hw3.y"
                     { 
        if(strcmp(getType((yyvsp[-1].type)),"int") == 0){
            codegen("ldc 1\n");
            codegen("iadd\n");
        }else{
            codegen("ldc 1.0\n");
            codegen("fadd\n");
        }
        update_symbol(cur_id);
    }
#line 1722 "y.tab.c"
    break;

  case 24:
#line 285 "compiler_hw3.y"
                     { 
        if(strcmp(getType((yyvsp[-1].type)),"int") == 0){
            codegen("ldc 1\n");
            codegen("isub\n");
        }else{
            codegen("ldc 1.0\n");
            codegen("fsub\n");
        }
        update_symbol(cur_id);
    }
#line 1737 "y.tab.c"
    break;

  case 25:
#line 298 "compiler_hw3.y"
          { create_symbol(); }
#line 1743 "y.tab.c"
    break;

  case 26:
#line 300 "compiler_hw3.y"
          { dump_symbol(); }
#line 1749 "y.tab.c"
    break;

  case 27:
#line 304 "compiler_hw3.y"
                        {
        INDENT--;
        int index;
        if(elseNum[cur_scope] == 0){
            index = 0;
        }else{
            index = elseNum[cur_scope] - 1;
        }
        while(index >= 0){
            codegen("label%d:\n",labelIF[cur_scope][index--]);
        }
        INDENT++;
    }
#line 1767 "y.tab.c"
    break;

  case 29:
#line 318 "compiler_hw3.y"
                                  {
        INDENT--;
        int index;
        if(elseNum[cur_scope] == 0){
            index = 0;
        }else{
            index = elseNum[cur_scope] - 1;
        }
        while(index >= 0){
            codegen("label%d:\n",labelIF[cur_scope][index--]);
        }
        INDENT++;
    }
#line 1785 "y.tab.c"
    break;

  case 30:
#line 334 "compiler_hw3.y"
                   {
        labelIF[cur_scope][elseNum[cur_scope]] = label; 
        codegen("ifeq label%d\n",label++);
    }
#line 1794 "y.tab.c"
    break;

  case 31:
#line 341 "compiler_hw3.y"
                 {
        codegen("goto label%d\n",label++);
        INDENT--;
        codegen("label%d:\n",labelIF[cur_scope][elseNum[cur_scope]]);
        INDENT++;
        labelIF[cur_scope][elseNum[cur_scope]++] = label-1;
    }
#line 1806 "y.tab.c"
    break;

  case 32:
#line 350 "compiler_hw3.y"
            {
        labelWHILE[cur_scope] = label;
        INDENT--;
        codegen("label%d:\n",label++);    
        INDENT++;
    }
#line 1817 "y.tab.c"
    break;

  case 33:
#line 355 "compiler_hw3.y"
                       {
        labelWHILEend[cur_scope] = label;
        codegen("ifeq label%d\n",label++);
    }
#line 1826 "y.tab.c"
    break;

  case 34:
#line 358 "compiler_hw3.y"
            {
        codegen("goto label%d\n",labelWHILE[cur_scope]);
        INDENT--;
        codegen("label%d:\n",labelWHILEend[cur_scope]);
        INDENT++;
    }
#line 1837 "y.tab.c"
    break;

  case 35:
#line 367 "compiler_hw3.y"
                 {
        // condition must be bool
        if(strcmp(getType((yyvsp[0].type)), "bool") != 0){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, getType((yyvsp[0].type)));
        }
    }
#line 1848 "y.tab.c"
    break;

  case 36:
#line 376 "compiler_hw3.y"
                                  {
        codegen("goto label%d\n",label-2);
        INDENT--;
        codegen("label%d:\n",labelFORend[cur_scope]);
        INDENT++;
    }
#line 1859 "y.tab.c"
    break;

  case 37:
#line 384 "compiler_hw3.y"
                     {
        labelFOR[cur_scope] = label;
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
    }
#line 1870 "y.tab.c"
    break;

  case 38:
#line 389 "compiler_hw3.y"
                     {
        labelFORend[cur_scope] = label;
        codegen("ifeq label%d\n",label++);
        codegen("goto label%d\n",label+1);
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
    }
#line 1883 "y.tab.c"
    break;

  case 39:
#line 396 "compiler_hw3.y"
                 {
        codegen("goto label%d\n",labelFOR[cur_scope]);
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
    }
#line 1894 "y.tab.c"
    break;

  case 43:
#line 410 "compiler_hw3.y"
            {
        assignFlag = 0;    
    }
#line 1902 "y.tab.c"
    break;

  case 44:
#line 412 "compiler_hw3.y"
                                  {
        if(strcmp(getType((yyvsp[-2].type)),"bool") == 0){
            codegen("ifne label%d\n",label);
            codegen("ldc \"false\"\n");
            codegen("goto label%d\n",label+1);
            INDENT--;
            codegen("label%d:\n",label++);
            INDENT++;
            codegen("ldc \"true\"\n");
            INDENT--;
            codegen("label%d:\n",label++);
            INDENT++;
        }
        codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        codegen("swap\n");
        if(strcmp(getType((yyvsp[-2].type)),"int") == 0){
            codegen("invokevirtual java/io/PrintStream/print(I)V\n");
        }else if(strcmp(getType((yyvsp[-2].type)),"float") == 0){
            codegen("invokevirtual java/io/PrintStream/print(F)V\n");
        }else{
            codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
        assignFlag = 1;
    }
#line 1931 "y.tab.c"
    break;

  case 45:
#line 439 "compiler_hw3.y"
                      { (yyval.type) = (yyvsp[0].type); }
#line 1937 "y.tab.c"
    break;

  case 46:
#line 443 "compiler_hw3.y"
                       { (yyval.type) = (yyvsp[0].type); }
#line 1943 "y.tab.c"
    break;

  case 47:
#line 444 "compiler_hw3.y"
                                          { 
        if(strcmp(getType((yyvsp[-2].type)),"bool") == 0 && strcmp(getType((yyvsp[0].type)),"bool") == 0){
            (yyval.type) = "boolLit";
        }
        // operator OR not defined
        else{
            char errorMessage[100] = "";
            char *errorType;
            if(strcmp(getType((yyvsp[-2].type)),"bool") == 1){
                errorType = getType((yyvsp[-2].type));
            }else{
                errorType = getType((yyvsp[0].type));
            }
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: (operator OR not defined on %s)",errorType);
            yyerror(errorMessage);
        }
        codegen("ior\n");
    }
#line 1967 "y.tab.c"
    break;

  case 48:
#line 466 "compiler_hw3.y"
                      { (yyval.type) = (yyvsp[0].type); }
#line 1973 "y.tab.c"
    break;

  case 49:
#line 467 "compiler_hw3.y"
                                           { 
        if(strcmp(getType((yyvsp[-2].type)),"bool") == 0 && strcmp(getType((yyvsp[0].type)),"bool") == 0){
            (yyval.type) = "boolLit";
        }
        // operator AND not defined
        else{
            char errorMessage[100] = "";
            char *errorType;
            if(strcmp(getType((yyvsp[-2].type)),"bool") != 0){
                errorType = getType((yyvsp[-2].type));
            }else{
                errorType = getType((yyvsp[0].type));
            }
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: (operator AND not defined on %s)",errorType);
            yyerror(errorMessage);
        }
        codegen("iand\n"); 
    }
#line 1997 "y.tab.c"
    break;

  case 50:
#line 489 "compiler_hw3.y"
                    { (yyval.type) = (yyvsp[0].type); }
#line 2003 "y.tab.c"
    break;

  case 51:
#line 490 "compiler_hw3.y"
                                           { 
        (yyval.type) = "boolLit";

        if(strcmp(getType((yyvsp[0].type)),"int") == 0){
            codegen("isub\n");
        }else{
            codegen("fcmpl\n");
        }

        if(strcmp((yyvsp[-1].operator),"EQL") == 0){
            codegen("ifeq label%d\n",label);
        }else if(strcmp((yyvsp[-1].operator),"NEQ") == 0){
            codegen("ifne label%d\n",label);
        }else if(strcmp((yyvsp[-1].operator),"LSS") == 0){
            codegen("iflt label%d\n",label);
        }else if(strcmp((yyvsp[-1].operator),"LEQ") == 0){
            codegen("ifle label%d\n",label);
        }else if(strcmp((yyvsp[-1].operator),"EQL") == 0){
            codegen("ifeq label%d\n",label);
        }else if(strcmp((yyvsp[-1].operator),"GTR") == 0){
            codegen("ifgt label%d\n",label);
        }else if(strcmp((yyvsp[-1].operator),"GEQ") == 0){
            codegen("ifge label%d\n",label);
        }

        codegen("iconst_0\n");
        codegen("goto label%d\n",label+1);
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
        codegen("iconst_1\n");
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
    }
#line 2043 "y.tab.c"
    break;

  case 52:
#line 528 "compiler_hw3.y"
                          { (yyval.type) = (yyvsp[0].type); }
#line 2049 "y.tab.c"
    break;

  case 53:
#line 529 "compiler_hw3.y"
                                               { 
        if(strcmp(getType((yyvsp[-2].type)),getType((yyvsp[0].type))) == 0){
            (yyval.type) = (yyvsp[-2].type);
        }
        // mismatched types
        else{
            char errorMessage[100] = "";
            char *errorOp = (yyvsp[-1].operator);
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: %s (mismatched types %s and %s)",
                        errorOp, getType((yyvsp[-2].type)),getType((yyvsp[0].type)));
            yyerror(errorMessage);
        } 

        if(strcmp((yyvsp[-1].operator),"ADD") == 0){
            if(strcmp(getType((yyvsp[0].type)),"int") == 0){
                codegen("iadd\n");
            }else{
                codegen("fadd\n");
            }
        }else if(strcmp((yyvsp[-1].operator),"SUB") == 0){
            if(strcmp(getType((yyvsp[0].type)),"int") == 0){
                codegen("isub\n");
            }else{
                codegen("fsub\n");
            }
        }
    }
#line 2082 "y.tab.c"
    break;

  case 54:
#line 560 "compiler_hw3.y"
                { (yyval.type) = (yyvsp[0].type); }
#line 2088 "y.tab.c"
    break;

  case 55:
#line 561 "compiler_hw3.y"
                                           { 
        char *errorOp = (yyvsp[-1].operator);
        if(strcmp(errorOp,"REM") == 0){
            // operator REM not defined on float
            if(strcmp(getType((yyvsp[-2].type)),"float") == 0 || strcmp(getType((yyvsp[0].type)),"float") == 0){
                char errorMessage[100] = "";
                snprintf(errorMessage,sizeof(errorMessage),
                            "invalid operation: (operator REM not defined on float)");
                yyerror(errorMessage);
            }else{
                (yyval.type) = (yyvsp[-2].type);
            }
        }else{
            if(strcmp(getType((yyvsp[-2].type)),getType((yyvsp[0].type))) == 0){
                (yyval.type) = (yyvsp[-2].type);
            }
            // mismatched types
            else{
                char errorMessage[100] = "";
                snprintf(errorMessage,sizeof(errorMessage),
                            "invalid operation: %s (mismatched types %s and %s)",
                            errorOp, getType((yyvsp[-2].type)),getType((yyvsp[0].type)));
                yyerror(errorMessage);
            } 
        }
        
        if(strcmp((yyvsp[-1].operator),"MUL") == 0){
            if(strcmp(getType((yyvsp[0].type)),"int") == 0){
                codegen("imul\n");
            }else{
                codegen("fmul\n");
            }
        }else if(strcmp((yyvsp[-1].operator),"QUO") == 0){
            if(strcmp(getType((yyvsp[0].type)),"int") == 0){
                codegen("idiv\n");
            }else{
                codegen("fdiv\n");
            }
        }else{
            codegen("irem\n");
        }
    }
#line 2135 "y.tab.c"
    break;

  case 56:
#line 606 "compiler_hw3.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2141 "y.tab.c"
    break;

  case 57:
#line 607 "compiler_hw3.y"
                         { 
        (yyval.type) = (yyvsp[0].type);
        
        if(strcmp((yyvsp[-1].operator),"POS") == 0){
            codegen(" \n");
        }else if(strcmp((yyvsp[-1].operator),"NEG") == 0){
            if(strcmp(getType((yyvsp[0].type)),"int") == 0){
                codegen("ineg\n");
            }else{
                codegen("fneg\n");
            }
        }else if(strcmp((yyvsp[-1].operator),"NOT") == 0){
            codegen("iconst_1\n");
            codegen("ixor\n");
        }
        
    }
#line 2163 "y.tab.c"
    break;

  case 58:
#line 627 "compiler_hw3.y"
                      { (yyval.type) = (yyvsp[0].type); }
#line 2169 "y.tab.c"
    break;

  case 59:
#line 628 "compiler_hw3.y"
                      { (yyval.type) = (yyvsp[0].type); }
#line 2175 "y.tab.c"
    break;

  case 61:
#line 633 "compiler_hw3.y"
                         { (yyval.type) = (yyvsp[0].type); }
#line 2181 "y.tab.c"
    break;

  case 62:
#line 634 "compiler_hw3.y"
                         { (yyval.type) = lookup_symbol((yyvsp[0].id)); }
#line 2187 "y.tab.c"
    break;

  case 63:
#line 635 "compiler_hw3.y"
                         { (yyval.type) = (yyvsp[-1].type); }
#line 2193 "y.tab.c"
    break;

  case 64:
#line 639 "compiler_hw3.y"
                                     { 
        (yyval.type) = (yyvsp[-3].type); 
        if(!assignFlag){
            codegen("%caload\n",(yyvsp[-3].type)[0]);
        }
    }
#line 2204 "y.tab.c"
    break;

  case 65:
#line 648 "compiler_hw3.y"
                              {
        (yyval.type) = (yyvsp[-2].type);

        if(strcmp(getType((yyvsp[0].type)),"int") == 0){
            codegen("i2f\n");
        }else{
            codegen("f2i\n");
        }
    }
#line 2218 "y.tab.c"
    break;

  case 66:
#line 660 "compiler_hw3.y"
              {
        (yyval.type) = "intLit";
        codegen("ldc %d\n", (yyvsp[0].i_val));
    }
#line 2227 "y.tab.c"
    break;

  case 67:
#line 664 "compiler_hw3.y"
                {
        (yyval.type) = "floatLit";
        codegen("ldc %.6f\n", (yyvsp[0].f_val));
    }
#line 2236 "y.tab.c"
    break;

  case 68:
#line 668 "compiler_hw3.y"
                         {
        (yyval.type) = "stringLit";
        codegen("ldc \"%s\"\n", (yyvsp[-1].s_val));
    }
#line 2245 "y.tab.c"
    break;

  case 69:
#line 672 "compiler_hw3.y"
           {
        (yyval.type) = "boolLit";
        codegen("iconst_1\n");
    }
#line 2254 "y.tab.c"
    break;

  case 70:
#line 676 "compiler_hw3.y"
            {
        (yyval.type) = "boolLit";
        codegen("iconst_0\n");
    }
#line 2263 "y.tab.c"
    break;

  case 71:
#line 683 "compiler_hw3.y"
          { (yyval.operator) = "POS"; }
#line 2269 "y.tab.c"
    break;

  case 72:
#line 684 "compiler_hw3.y"
          { (yyval.operator) = "NEG"; }
#line 2275 "y.tab.c"
    break;

  case 73:
#line 685 "compiler_hw3.y"
          { (yyval.operator) = "NOT"; }
#line 2281 "y.tab.c"
    break;

  case 74:
#line 689 "compiler_hw3.y"
          { (yyval.operator) = "EQL"; }
#line 2287 "y.tab.c"
    break;

  case 75:
#line 690 "compiler_hw3.y"
          { (yyval.operator) = "NEQ"; }
#line 2293 "y.tab.c"
    break;

  case 76:
#line 691 "compiler_hw3.y"
          { (yyval.operator) = "LSS"; }
#line 2299 "y.tab.c"
    break;

  case 77:
#line 692 "compiler_hw3.y"
          { (yyval.operator) = "LEQ"; }
#line 2305 "y.tab.c"
    break;

  case 78:
#line 693 "compiler_hw3.y"
          { (yyval.operator) = "GTR"; }
#line 2311 "y.tab.c"
    break;

  case 79:
#line 694 "compiler_hw3.y"
          { (yyval.operator) = "GEQ"; }
#line 2317 "y.tab.c"
    break;

  case 80:
#line 698 "compiler_hw3.y"
          { (yyval.operator) = "ADD"; }
#line 2323 "y.tab.c"
    break;

  case 81:
#line 699 "compiler_hw3.y"
          { (yyval.operator) = "SUB"; }
#line 2329 "y.tab.c"
    break;

  case 82:
#line 703 "compiler_hw3.y"
          { (yyval.operator) = "MUL"; }
#line 2335 "y.tab.c"
    break;

  case 83:
#line 704 "compiler_hw3.y"
          { (yyval.operator) = "QUO"; }
#line 2341 "y.tab.c"
    break;

  case 84:
#line 705 "compiler_hw3.y"
          { (yyval.operator) = "REM"; }
#line 2347 "y.tab.c"
    break;

  case 85:
#line 709 "compiler_hw3.y"
             { (yyval.operator) = "ASSIGN"; }
#line 2353 "y.tab.c"
    break;

  case 86:
#line 710 "compiler_hw3.y"
                 { (yyval.operator) = "ADD_ASSIGN"; }
#line 2359 "y.tab.c"
    break;

  case 87:
#line 711 "compiler_hw3.y"
                 { (yyval.operator) = "SUB_ASSIGN"; }
#line 2365 "y.tab.c"
    break;

  case 88:
#line 712 "compiler_hw3.y"
                 { (yyval.operator) = "MUL_ASSIGN"; }
#line 2371 "y.tab.c"
    break;

  case 89:
#line 713 "compiler_hw3.y"
                 { (yyval.operator) = "QUO_ASSIGN"; }
#line 2377 "y.tab.c"
    break;

  case 90:
#line 714 "compiler_hw3.y"
                 { (yyval.operator) = "REM_ASSIGN"; }
#line 2383 "y.tab.c"
    break;

  case 91:
#line 718 "compiler_hw3.y"
               { (yyval.type) = (yyvsp[0].type); }
#line 2389 "y.tab.c"
    break;

  case 92:
#line 722 "compiler_hw3.y"
          { (yyval.type) = "int"; }
#line 2395 "y.tab.c"
    break;

  case 93:
#line 723 "compiler_hw3.y"
            { (yyval.type) = "float"; }
#line 2401 "y.tab.c"
    break;

  case 94:
#line 724 "compiler_hw3.y"
             { (yyval.type) = "string"; }
#line 2407 "y.tab.c"
    break;

  case 95:
#line 725 "compiler_hw3.y"
           { (yyval.type) = "bool"; }
#line 2413 "y.tab.c"
    break;


#line 2417 "y.tab.c"

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
#line 728 "compiler_hw3.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
    return 0;
}

static void create_symbol(){
    cur_scope++;
}

static void insert_symbol(char *id, char *type, char *elementType){
    int cur_index = tail[cur_scope];
    symbol_table[cur_scope][cur_index].index = cur_index;
    symbol_table[cur_scope][cur_index].name = id;
    symbol_table[cur_scope][cur_index].type = type;
    symbol_table[cur_scope][cur_index].address = cur_addr;
    symbol_table[cur_scope][cur_index].lineno = yylineno;
    symbol_table[cur_scope][cur_index].elementType = elementType;

    cur_addr++;
    tail[cur_scope]++;
    printf("> Insert {%s} into symbol table (scope level: %d)\n",id,cur_scope);
}

static char *lookup_symbol(char *id){
    bool find_flag = false;
    int match_scope,match_index;
    for(int i=cur_scope;i>=0;i--){
        for(int j=0;j<tail[i];j++){
            if(strcmp(symbol_table[i][j].name , id) == 0){

                if(strcmp(symbol_table[i][j].type, "int") == 0){
                    codegen("iload %d\n", symbol_table[i][j].address);
                }else if(strcmp(symbol_table[i][j].type, "float") == 0){
                    codegen("fload %d\n", symbol_table[i][j].address);
                }else if(strcmp(symbol_table[i][j].type, "string") == 0){
                    codegen("aload %d\n", symbol_table[i][j].address);
                }else if(strcmp(symbol_table[i][j].type, "array") == 0){
                    codegen("aload %d\n", symbol_table[i][j].address);
                }

                find_flag = true;
                match_scope = i;
                match_index = j;
                break;
            }
        }
        if(find_flag){
            break;
        }
    }
    // set cur id for update 
    cur_id = id;
    if(find_flag){
        char *find_type = symbol_table[match_scope][match_index].type; 
        if(strcmp(find_type,"array") == 0){
            return symbol_table[match_scope][match_index].elementType;
        }else{
            return find_type;
        }
    }else{
        // undefined
        char errorMessage[100] = "";        
        snprintf(errorMessage,sizeof(errorMessage),
                    "undefined: %s", id);
        yyerror(errorMessage);
        return "int"; // set undifined type to int
    }
    
}

static void update_symbol(char * id){
    bool find_flag = false;
    for(int i=cur_scope;i>=0;i--){
        for(int j=0;j<tail[i];j++){
            if(strcmp(symbol_table[i][j].name , id) == 0){

                if(strcmp(symbol_table[i][j].type, "int") == 0){
                    codegen("istore %d\n", symbol_table[i][j].address);
                }else if(strcmp(symbol_table[i][j].type, "float") == 0){
                    codegen("fstore %d\n", symbol_table[i][j].address);
                }else if(strcmp(symbol_table[i][j].type, "string") == 0){
                    codegen("astore %d\n", symbol_table[i][j].address);
                }else if(strcmp(symbol_table[i][j].type, "array") == 0){
                    codegen("%castore\n", symbol_table[i][j].elementType[0]);
                }

                find_flag = true;
                break;
            }
        }
        if(find_flag){
            break;
        }
    }
}


static void dump_symbol(){
    printf("> Dump symbol table (scope level: %d)\n",cur_scope);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
            "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i=0;i<tail[cur_scope];i++){
        printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            symbol_table[cur_scope][i].index,
            symbol_table[cur_scope][i].name,
            symbol_table[cur_scope][i].type,
            symbol_table[cur_scope][i].address,
            symbol_table[cur_scope][i].lineno,
            symbol_table[cur_scope][i].elementType);
    }
    // clear table
    tail[cur_scope] = 0;
    cur_scope--;
}

static char *getType(char *input){
    if(strcmp(input,"intLit") == 0){
        return "int";
    }
    if(strcmp(input,"floatLit") == 0){
        return "float";
    }
    if(strcmp(input,"stringLit") == 0){
        return "string";
    }
    if(strcmp(input,"boolLit") == 0){
        return "bool";
    }
    return input;
}

static int check_id(char *id){
    for(int i=0;i<tail[cur_scope];i++){
        if(strcmp(symbol_table[cur_scope][i].name , id) == 0){
            return symbol_table[cur_scope][i].lineno;
        }
    }
    // if not found then return -1
    return -1;
}
