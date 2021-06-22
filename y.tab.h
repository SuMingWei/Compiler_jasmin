/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 138 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
