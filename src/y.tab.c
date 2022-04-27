/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "s_parser.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include "s_symbol.c"
	int g_addr = 100;
int i=1,lnum1=0,label1[20],ltop1;
int stack[100],index1=0,end[100],arr[10],gl1,gl2,ct,c,b,fl,top=0,label[20],lnum=0,ltop=0;
char st1[100][10];
char i_[2]="0";
char temp[2]="t";
char null[2]=" ";
void yyerror(char *s);
int printline();
void open1()
{
	stack[index1]=i;
	i++;
	index1++;
	return;
}
void close1()
{
	index1--;
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}
void if1()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;	
	
}
void if2()
{
	lnum++;
	printf("goto L%d\n",lnum);
	printf("L%d: \n",label[ltop--]);
	label[++ltop]=lnum;
}
void if3()
{
	printf("L%d:\n",label[ltop--]);
}
void w1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void w2()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
}
void w3()
{
	int y=label[ltop--];
	printf("goto L%d\n",label[ltop--]);
	printf("L%d:\n",y);
}
void dw1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void dw2()
{
 	printf("if %s goto L%d\n",st1[top--],label[ltop--]);
}
void f1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void f2()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
	lnum++;
	printf("goto L%d\n",lnum);
	label[++ltop]=lnum;
	lnum++;
	printf("L%d:\n",lnum);	
	label[++ltop]=lnum;
}
void f3()
{
	printf("goto L%d\n",label[ltop-3]);
	printf("L%d:\n",label[ltop-1]);
}
void f4()
{
	printf("goto L%d\n",label[ltop]);
	printf("L%d:\n",label[ltop-2]);
	ltop-=4;
}
void push(char *a)
{
	strcpy(st1[++top],a);
}
void array1()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s * 4\n",temp,st1[top]);
	strcpy(st1[top],temp);
	i_[0]++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s [ %s ] \n",temp,st1[top-1],st1[top]);
	top--;
	strcpy(st1[top],temp);
	i_[0]++;	
}
void codegen()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s %s %s\n",temp,st1[top-2],st1[top-1],st1[top]);
	top-=2;
	strcpy(st1[top],temp);
	i_[0]++;
}
void codegen_umin()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = -%s\n",temp,st1[top]);
	top--;
	strcpy(st1[top],temp);
	i_[0]++;
}
void codegen_assign()
{
	printf("%s = %s\n",st1[top-2],st1[top]);
	top-=2;
}



#line 230 "y.tab.c"

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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    VOID = 260,                    /* VOID  */
    ID = 261,                      /* ID  */
    NUM = 262,                     /* NUM  */
    REAL = 263,                    /* REAL  */
    LE = 264,                      /* LE  */
    GE = 265,                      /* GE  */
    EQ = 266,                      /* EQ  */
    NEQ = 267,                     /* NEQ  */
    AND = 268,                     /* AND  */
    OR = 269,                      /* OR  */
    WHILE = 270,                   /* WHILE  */
    IF = 271,                      /* IF  */
    RETURN = 272,                  /* RETURN  */
    PREPROC = 273,                 /* PREPROC  */
    STRING = 274,                  /* STRING  */
    PRINT = 275,                   /* PRINT  */
    FUNCTION = 276,                /* FUNCTION  */
    DO = 277,                      /* DO  */
    ARRAY = 278,                   /* ARRAY  */
    ELSE = 279,                    /* ELSE  */
    STRUCT = 280,                  /* STRUCT  */
    STRUCT_VAR = 281,              /* STRUCT_VAR  */
    FOR = 282,                     /* FOR  */
    UMINUS = 283                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define VOID 260
#define ID 261
#define NUM 262
#define REAL 263
#define LE 264
#define GE 265
#define EQ 266
#define NEQ 267
#define AND 268
#define OR 269
#define WHILE 270
#define IF 271
#define RETURN 272
#define PREPROC 273
#define STRING 274
#define PRINT 275
#define FUNCTION 276
#define DO 277
#define ARRAY 278
#define ELSE 279
#define STRUCT 280
#define STRUCT_VAR 281
#define FOR 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 169 "s_parser.y"

		int ival;
		char *str;
	

#line 342 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_NUM = 7,                        /* NUM  */
  YYSYMBOL_REAL = 8,                       /* REAL  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_GE = 10,                        /* GE  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_NEQ = 12,                       /* NEQ  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_PREPROC = 18,                   /* PREPROC  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_PRINT = 20,                     /* PRINT  */
  YYSYMBOL_FUNCTION = 21,                  /* FUNCTION  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_ARRAY = 23,                     /* ARRAY  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_STRUCT_VAR = 26,                /* STRUCT_VAR  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_start = 45,                     /* start  */
  YYSYMBOL_Function = 46,                  /* Function  */
  YYSYMBOL_Type = 47,                      /* Type  */
  YYSYMBOL_CompoundStmt = 48,              /* CompoundStmt  */
  YYSYMBOL_StmtList = 49,                  /* StmtList  */
  YYSYMBOL_stmt = 50,                      /* stmt  */
  YYSYMBOL_dowhile = 51,                   /* dowhile  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_for = 54,                       /* for  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_if = 58,                        /* if  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_else = 61,                      /* else  */
  YYSYMBOL_while = 62,                     /* while  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_assignment = 65,                /* assignment  */
  YYSYMBOL_assignment1 = 66,               /* assignment1  */
  YYSYMBOL_67_10 = 67,                     /* $@10  */
  YYSYMBOL_68_11 = 68,                     /* $@11  */
  YYSYMBOL_69_12 = 69,                     /* $@12  */
  YYSYMBOL_consttype = 70,                 /* consttype  */
  YYSYMBOL_Declaration = 71,               /* Declaration  */
  YYSYMBOL_72_13 = 72,                     /* $@13  */
  YYSYMBOL_73_14 = 73,                     /* $@14  */
  YYSYMBOL_74_15 = 74,                     /* $@15  */
  YYSYMBOL_array = 75,                     /* array  */
  YYSYMBOL_76_16 = 76,                     /* $@16  */
  YYSYMBOL_E = 77,                         /* E  */
  YYSYMBOL_78_17 = 78,                     /* $@17  */
  YYSYMBOL_79_18 = 79,                     /* $@18  */
  YYSYMBOL_80_19 = 80,                     /* $@19  */
  YYSYMBOL_81_20 = 81,                     /* $@20  */
  YYSYMBOL_82_21 = 82,                     /* $@21  */
  YYSYMBOL_83_22 = 83,                     /* $@22  */
  YYSYMBOL_84_23 = 84,                     /* $@23  */
  YYSYMBOL_85_24 = 85,                     /* $@24  */
  YYSYMBOL_86_25 = 86,                     /* $@25  */
  YYSYMBOL_87_26 = 87,                     /* $@26  */
  YYSYMBOL_88_27 = 88,                     /* $@27  */
  YYSYMBOL_89_28 = 89,                     /* $@28  */
  YYSYMBOL_90_29 = 90,                     /* $@29  */
  YYSYMBOL_91_30 = 91,                     /* $@30  */
  YYSYMBOL_92_31 = 92,                     /* $@31  */
  YYSYMBOL_93_32 = 93,                     /* $@32  */
  YYSYMBOL_94_33 = 94,                     /* $@33  */
  YYSYMBOL_95_34 = 95,                     /* $@34  */
  YYSYMBOL_96_35 = 96,                     /* $@35  */
  YYSYMBOL_97_36 = 97,                     /* $@36  */
  YYSYMBOL_T = 98,                         /* T  */
  YYSYMBOL_99_37 = 99,                     /* $@37  */
  YYSYMBOL_100_38 = 100,                   /* $@38  */
  YYSYMBOL_F = 101,                        /* F  */
  YYSYMBOL_102_39 = 102                    /* $@39  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    34,    32,    41,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      28,    30,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   175,   175,   176,   177,   178,   181,   202,   203,   204,
     207,   210,   211,   214,   215,   216,   217,   218,   219,   220,
     226,   227,   228,   229,   232,   232,   232,   235,   235,   235,
     235,   238,   238,   238,   241,   242,   245,   245,   245,   248,
     249,   250,   251,   252,   253,   256,   256,   256,   256,   273,
     277,   278,   282,   285,   286,   289,   289,   289,   289,   320,
     332,   337,   338,   342,   346,   349,   349,   352,   352,   353,
     353,   354,   355,   355,   355,   356,   356,   356,   357,   357,
     357,   358,   358,   358,   359,   359,   359,   360,   360,   360,
     361,   361,   361,   362,   362,   362,   363,   363,   363,   364,
     366,   366,   367,   367,   368,   370,   371,   371,   372,   373
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "VOID",
  "ID", "NUM", "REAL", "LE", "GE", "EQ", "NEQ", "AND", "OR", "WHILE", "IF",
  "RETURN", "PREPROC", "STRING", "PRINT", "FUNCTION", "DO", "ARRAY",
  "ELSE", "STRUCT", "STRUCT_VAR", "FOR", "'<'", "'>'", "'='", "UMINUS",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "','",
  "'['", "']'", "$accept", "start", "Function", "Type", "CompoundStmt",
  "StmtList", "stmt", "dowhile", "$@1", "$@2", "for", "$@3", "$@4", "$@5",
  "if", "$@6", "$@7", "else", "while", "$@8", "$@9", "assignment",
  "assignment1", "$@10", "$@11", "$@12", "consttype", "Declaration",
  "$@13", "$@14", "$@15", "array", "$@16", "E", "$@17", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "T",
  "$@37", "$@38", "F", "$@39", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
      61,   283,    43,    45,    42,    47,    40,    41,   123,   125,
      59,    44,    91,    93
};
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     141,   -80,   -80,   -80,   -80,   -34,   -80,   -80,   141,     7,
      25,   141,    21,    -3,    -9,   141,   161,   161,    28,   -80,
      -2,   -80,   -80,    -8,   -80,   161,   -80,    12,   -80,     4,
     -80,    34,   157,    14,   164,    77,   -80,    46,    23,   -80,
     128,    97,   101,    16,   100,   116,   -80,   -80,    10,   -80,
      23,   -80,   -80,    71,    88,   -80,   131,   134,   -80,   -80,
     119,   164,   164,   135,   164,    23,   136,   167,   169,   166,
     168,   170,   171,   153,   155,   156,    62,    55,   -80,   -80,
     -80,   -80,   -80,   -80,   113,   -80,   -80,   -80,   -80,   -80,
      71,    23,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    62,    62,    62,    62,   114,   -80,
     151,     3,   152,   -80,   154,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   149,    17,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    88,    88,   -80,   -80,   158,
     160,    23,   -80,   159,   172,   101,    23,   -80,   -80,    71,
      71,    71,    71,    71,    71,    71,    71,    71,   162,    23,
      57,   -80,   163,   177,    71,   -80,    69,   -80,   165,   173,
     174,   -80,   101,   -80,    23,    23,   101,   -80,    78,    71,
     -80,   179,   -80,   175,   101,   -80,   176,    23,   -80,   -80,
      71,   180,   101,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    64,     7,     8,     9,    45,    53,    54,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     3,
       0,     1,     2,    55,    59,     0,     4,    51,    49,     0,
      46,     0,     0,     0,     0,     0,    50,     0,     0,    63,
       0,     0,     0,    43,     0,    44,    56,    61,   108,   106,
       0,   109,    99,    47,    71,   104,    55,     0,    12,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    69,
      48,   100,   102,    62,     0,    39,    40,    41,    60,    42,
      57,     0,    73,    76,    79,    82,    85,    88,    91,    94,
      97,   108,   107,   105,     0,     0,     0,     0,    45,    36,
       0,     0,     0,    24,     0,    10,    21,    23,    11,    17,
      18,    14,    16,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    70,   101,   103,     0,
       0,     0,    20,     0,     0,     0,     0,    58,    66,    74,
      77,    80,    83,    86,    89,    92,    95,    98,     0,     0,
       0,    19,     0,     0,    27,    15,     0,    31,     0,     0,
       0,    37,     0,    22,     0,     0,     0,    32,     0,    28,
      38,    35,    25,     0,     0,    33,     0,     0,    34,    26,
      29,     0,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,    56,   -80,   -30,   -79,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,    11,    83,   -80,   -80,   -80,     1,   -29,   -80,   -80,
     -80,   -80,   -80,   -50,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    27,   -80,   -80,   -62,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    59,    84,   118,   119,   145,   186,
     120,   170,   183,   191,   121,   172,   181,   185,   122,   140,
     176,    44,    13,    18,    38,    80,    51,    15,    35,    65,
     124,    52,    66,    53,   104,   105,    67,   126,    68,   127,
      69,   128,    70,   129,    71,   130,    72,   131,    73,   132,
      74,   133,    75,   134,    54,   106,   107,    55,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    14,    40,    41,    31,   117,   -51,    16,    17,    14,
       6,     7,    14,    20,   102,    90,    14,    14,    14,   -72,
     -75,   -78,   -81,   -84,   -87,    21,    14,    23,    33,    48,
       6,     7,    25,    14,    34,    45,    32,    24,   -90,   -93,
     -96,   125,   -45,   142,   137,   138,    60,    37,    61,    78,
      79,    42,   -65,    16,    40,   123,    49,    62,    30,    50,
     148,    85,    45,    45,    19,    45,   163,    22,   101,     6,
       7,    26,    86,    87,    39,    89,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    14,    47,    78,    79,    78,
      79,   160,   103,   177,   167,    49,   164,   180,    50,    28,
      29,    78,    79,    78,    79,   188,   171,    46,    36,   166,
      78,    79,   143,   193,     1,   182,     2,     3,     4,   108,
       6,     7,    81,    82,   178,   179,     6,     7,   109,   110,
     111,   135,   136,   112,    56,   113,    57,   190,     9,    58,
     114,    -5,     1,    63,     2,     3,     4,     5,     6,     7,
     139,    58,   115,   116,   -51,    16,    17,    64,     1,     8,
       2,     3,     4,     5,     6,     7,     9,    27,     6,     7,
      43,     6,     7,    34,    83,    88,    92,    94,    91,    93,
      95,    98,     9,    96,    99,    97,   100,   141,   144,   147,
     146,   162,   169,     0,     0,   158,   159,     0,     0,   161,
     168,     0,   165,   184,     0,   173,     0,     0,     0,   174,
       0,     0,     0,     0,   175,   187,   189,   192
};

static const yytype_int16 yycheck[] =
{
      50,     0,    32,    32,     6,    84,    40,    41,    42,     8,
       7,     8,    11,     6,    76,    65,    15,    16,    17,     9,
      10,    11,    12,    13,    14,     0,    25,     6,    36,     6,
       7,     8,    41,    32,    42,    34,    38,    40,    28,    29,
      30,    91,    30,    40,   106,   107,    30,    43,    32,    32,
      33,    37,    42,    41,    84,    84,    33,    41,    30,    36,
      43,    60,    61,    62,     8,    64,   145,    11,     6,     7,
       8,    15,    61,    62,    40,    64,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    84,    40,    32,    33,    32,
      33,   141,    37,   172,    37,    33,   146,   176,    36,    16,
      17,    32,    33,    32,    33,   184,    37,    30,    25,   159,
      32,    33,   111,   192,     1,    37,     3,     4,     5,     6,
       7,     8,    34,    35,   174,   175,     7,     8,    15,    16,
      17,   104,   105,    20,     6,    22,    39,   187,    25,    38,
      27,     0,     1,    43,     3,     4,     5,     6,     7,     8,
      36,    38,    39,    40,    40,    41,    42,    41,     1,    18,
       3,     4,     5,     6,     7,     8,    25,     6,     7,     8,
       6,     7,     8,    42,    40,    40,     9,    11,    42,    10,
      12,    28,    25,    13,    29,    14,    30,    36,    36,    40,
      36,    19,    15,    -1,    -1,    37,    36,    -1,    -1,    40,
      37,    -1,    40,    24,    -1,    40,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    40,    40,    40,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    18,    25,
      45,    46,    47,    66,    70,    71,    41,    42,    67,    45,
       6,     0,    45,     6,    40,    41,    45,     6,    66,    66,
      30,     6,    38,    36,    42,    72,    66,    43,    68,    40,
      47,    71,    37,     6,    65,    70,    30,    40,     6,    33,
      36,    70,    75,    77,    98,   101,     6,    39,    38,    48,
      30,    32,    41,    43,    41,    73,    76,    80,    82,    84,
      86,    88,    90,    92,    94,    96,   102,    77,    32,    33,
      69,    34,    35,    40,    49,    70,    65,    65,    40,    65,
      77,    42,     9,    10,    11,    12,    13,    14,    28,    29,
      30,     6,   101,    37,    78,    79,    99,   100,     6,    15,
      16,    17,    20,    22,    27,    39,    40,    48,    50,    51,
      54,    58,    62,    71,    74,    77,    81,    83,    85,    87,
      89,    91,    93,    95,    97,    98,    98,   101,   101,    36,
      63,    36,    40,    70,    36,    52,    36,    40,    43,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    37,    36,
      77,    40,    19,    48,    77,    40,    77,    37,    37,    15,
      55,    37,    59,    40,    36,    40,    64,    48,    77,    77,
      48,    60,    37,    56,    24,    61,    53,    40,    48,    40,
      77,    57,    37,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    46,    47,    47,    47,
      48,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    52,    53,    51,    55,    56,    57,
      54,    59,    60,    58,    61,    61,    63,    64,    62,    65,
      65,    65,    65,    65,    65,    67,    68,    69,    66,    66,
      66,    66,    66,    70,    70,    72,    73,    74,    71,    71,
      71,    71,    71,    71,    71,    76,    75,    78,    77,    79,
      77,    77,    80,    81,    77,    82,    83,    77,    84,    85,
      77,    86,    87,    77,    88,    89,    77,    90,    91,    77,
      92,    93,    77,    94,    95,    77,    96,    97,    77,    77,
      99,    98,   100,    98,    98,   101,   102,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     1,     1,     1,
       3,     2,     0,     1,     1,     4,     1,     1,     1,     3,
       2,     1,     5,     1,     0,     0,     9,     0,     0,     0,
      12,     0,     0,     8,     2,     0,     0,     0,     7,     3,
       3,     3,     3,     1,     1,     0,     0,     0,     6,     3,
       3,     1,     1,     1,     1,     0,     0,     0,     8,     2,
       6,     5,     6,     4,     1,     0,     5,     0,     4,     0,
       4,     1,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     1,
       0,     4,     0,     4,     1,     3,     0,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 6: /* Function: Type ID '(' ')' CompoundStmt  */
#line 181 "s_parser.y"
                                        {
	if(strcmp((yyvsp[-3].str),"main")!=0)
	{
		printf("goto F%d\n",lnum1);
	}
	if ((yyvsp[-4].ival)!=returntype_func(ct))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") && strcmp	((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") && strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") && strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush"))) 
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline()); 
	else 
	{ 
		insert((yyvsp[-3].str),FUNCTION,g_addr); 
		insert((yyvsp[-3].str),(yyvsp[-4].ival),g_addr); 
		g_addr+=4;
	}
	}
#line 1589 "y.tab.c"
    break;

  case 19: /* stmt: RETURN consttype ';'  */
#line 220 "s_parser.y"
                               {
					if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) 
						storereturn(ct,FLOAT); 
					else 
						storereturn(ct,INT); ct++;
					}
#line 1600 "y.tab.c"
    break;

  case 20: /* stmt: RETURN ';'  */
#line 226 "s_parser.y"
                     {storereturn(ct,VOID); ct++;}
#line 1606 "y.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 232 "s_parser.y"
             {dw1();}
#line 1612 "y.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 232 "s_parser.y"
                                                   {dw2();}
#line 1618 "y.tab.c"
    break;

  case 27: /* $@3: %empty  */
#line 235 "s_parser.y"
                    {f1();}
#line 1624 "y.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 235 "s_parser.y"
                                  {f2();}
#line 1630 "y.tab.c"
    break;

  case 29: /* $@5: %empty  */
#line 235 "s_parser.y"
                                               {f3();}
#line 1636 "y.tab.c"
    break;

  case 30: /* for: FOR '(' E $@3 ';' E $@4 ';' E $@5 ')' CompoundStmt  */
#line 235 "s_parser.y"
                                                                        {f4();}
#line 1642 "y.tab.c"
    break;

  case 31: /* $@6: %empty  */
#line 238 "s_parser.y"
                      {if1();}
#line 1648 "y.tab.c"
    break;

  case 32: /* $@7: %empty  */
#line 238 "s_parser.y"
                                            {if2();}
#line 1654 "y.tab.c"
    break;

  case 34: /* else: ELSE CompoundStmt  */
#line 241 "s_parser.y"
                         {if3();}
#line 1660 "y.tab.c"
    break;

  case 36: /* $@8: %empty  */
#line 245 "s_parser.y"
              {w1();}
#line 1666 "y.tab.c"
    break;

  case 37: /* $@9: %empty  */
#line 245 "s_parser.y"
                               {w2();}
#line 1672 "y.tab.c"
    break;

  case 38: /* while: WHILE $@8 '(' E ')' $@9 CompoundStmt  */
#line 245 "s_parser.y"
                                                    {w3();}
#line 1678 "y.tab.c"
    break;

  case 45: /* $@10: %empty  */
#line 256 "s_parser.y"
                 {push((yyvsp[0].str));}
#line 1684 "y.tab.c"
    break;

  case 46: /* $@11: %empty  */
#line 256 "s_parser.y"
                                 {strcpy(st1[++top],"=");}
#line 1690 "y.tab.c"
    break;

  case 47: /* $@12: %empty  */
#line 256 "s_parser.y"
                                                             {codegen_assign();}
#line 1696 "y.tab.c"
    break;

  case 48: /* assignment1: ID $@10 '=' $@11 E $@12  */
#line 257 "s_parser.y"
        {
		int sct=returnscope((yyvsp[-5].str),stack[index1-1]); 
		int type=returntype((yyvsp[-5].str),sct); 
		if((!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && type==258 && fl==0) 
			printf("\nError : Type Mismatch : Line %d\n",printline()); 
		if(!lookup((yyvsp[-5].str))) 
		{ 
			int currscope=stack[index1-1]; 
			int scope=returnscope((yyvsp[-5].str),currscope); 
			if((scope<=currscope && end[scope]==0) && !(scope==0)) 
			{
				check_scope_update((yyvsp[-5].str),(yyvsp[-1].str),currscope);
			}
		} 
		}
#line 1716 "y.tab.c"
    break;

  case 49: /* assignment1: ID ',' assignment1  */
#line 273 "s_parser.y"
                                {
					if(lookup((yyvsp[-2].str))) 
						printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
				}
#line 1725 "y.tab.c"
    break;

  case 51: /* assignment1: ID  */
#line 278 "s_parser.y"
              {
		if(lookup((yyvsp[0].str))) 
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
		}
#line 1734 "y.tab.c"
    break;

  case 55: /* $@13: %empty  */
#line 289 "s_parser.y"
                      {push((yyvsp[0].str));}
#line 1740 "y.tab.c"
    break;

  case 56: /* $@14: %empty  */
#line 289 "s_parser.y"
                                      {strcpy(st1[++top],"=");}
#line 1746 "y.tab.c"
    break;

  case 57: /* $@15: %empty  */
#line 289 "s_parser.y"
                                                                  {codegen_assign();}
#line 1752 "y.tab.c"
    break;

  case 58: /* Declaration: Type ID $@13 '=' $@14 E $@15 ';'  */
#line 290 "s_parser.y"
        {
		if( (!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival)==258 && (fl==0)) 
		{
			printf("\nError : Type Mismatch : Line %d\n",printline());
			fl=1;
		} 
		if(!lookup((yyvsp[-6].str))) 
		{
			int currscope=stack[index1-1]; 
			int previous_scope=returnscope((yyvsp[-6].str),currscope); 
			if(currscope==previous_scope) 
				printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-6].str),printline()); 
			else 
			{
				insert_dup((yyvsp[-6].str),(yyvsp[-7].ival),g_addr,currscope);
				check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
				int sg=returnscope((yyvsp[-6].str),stack[index1-1]); 
				g_addr+=4;
			}
		} 
		else 
		{ 
			int scope=stack[index1-1];  
			insert((yyvsp[-6].str),(yyvsp[-7].ival),g_addr); 
			insertscope((yyvsp[-6].str),scope); 
			check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
			g_addr+=4;
		}
	}
#line 1786 "y.tab.c"
    break;

  case 59: /* Declaration: assignment1 ';'  */
#line 320 "s_parser.y"
                           {
				if(!lookup((yyvsp[-1].str))) 
				{ 
					int currscope=stack[index1-1]; 
					int scope=returnscope((yyvsp[-1].str),currscope); 
					if(!(scope<=currscope && end[scope]==0) || scope==0) 
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				} 
				else 
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline()); 
				}
#line 1802 "y.tab.c"
    break;

  case 60: /* Declaration: Type ID '[' assignment ']' ';'  */
#line 332 "s_parser.y"
                                         {
						insert((yyvsp[-4].str),ARRAY,g_addr); 
						insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr); 
						g_addr+=4; 
					}
#line 1812 "y.tab.c"
    break;

  case 62: /* Declaration: STRUCT ID '{' Declaration '}' ';'  */
#line 338 "s_parser.y"
                                            {
						insert((yyvsp[-4].str),STRUCT,g_addr); 
						g_addr+=4; 
						}
#line 1821 "y.tab.c"
    break;

  case 63: /* Declaration: STRUCT ID ID ';'  */
#line 342 "s_parser.y"
                           {
				insert((yyvsp[-1].str),STRUCT_VAR,g_addr); 
				g_addr+=4;
				}
#line 1830 "y.tab.c"
    break;

  case 65: /* $@16: %empty  */
#line 349 "s_parser.y"
           {push((yyvsp[0].str));}
#line 1836 "y.tab.c"
    break;

  case 67: /* $@17: %empty  */
#line 352 "s_parser.y"
         {strcpy(st1[++top],"+");}
#line 1842 "y.tab.c"
    break;

  case 68: /* E: E '+' $@17 T  */
#line 352 "s_parser.y"
                                    {codegen();}
#line 1848 "y.tab.c"
    break;

  case 69: /* $@18: %empty  */
#line 353 "s_parser.y"
          {strcpy(st1[++top],"-");}
#line 1854 "y.tab.c"
    break;

  case 70: /* E: E '-' $@18 T  */
#line 353 "s_parser.y"
                                     {codegen();}
#line 1860 "y.tab.c"
    break;

  case 72: /* $@19: %empty  */
#line 355 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1866 "y.tab.c"
    break;

  case 73: /* $@20: %empty  */
#line 355 "s_parser.y"
                       {strcpy(st1[++top],"<=");}
#line 1872 "y.tab.c"
    break;

  case 74: /* E: ID $@19 LE $@20 E  */
#line 355 "s_parser.y"
                                                    {codegen();}
#line 1878 "y.tab.c"
    break;

  case 75: /* $@21: %empty  */
#line 356 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1884 "y.tab.c"
    break;

  case 76: /* $@22: %empty  */
#line 356 "s_parser.y"
                       {strcpy(st1[++top],">=");}
#line 1890 "y.tab.c"
    break;

  case 77: /* E: ID $@21 GE $@22 E  */
#line 356 "s_parser.y"
                                                    {codegen();}
#line 1896 "y.tab.c"
    break;

  case 78: /* $@23: %empty  */
#line 357 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1902 "y.tab.c"
    break;

  case 79: /* $@24: %empty  */
#line 357 "s_parser.y"
                       {strcpy(st1[++top],"==");}
#line 1908 "y.tab.c"
    break;

  case 80: /* E: ID $@23 EQ $@24 E  */
#line 357 "s_parser.y"
                                                    {codegen();}
#line 1914 "y.tab.c"
    break;

  case 81: /* $@25: %empty  */
#line 358 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1920 "y.tab.c"
    break;

  case 82: /* $@26: %empty  */
#line 358 "s_parser.y"
                        {strcpy(st1[++top],"!=");}
#line 1926 "y.tab.c"
    break;

  case 83: /* E: ID $@25 NEQ $@26 E  */
#line 358 "s_parser.y"
                                                     {codegen();}
#line 1932 "y.tab.c"
    break;

  case 84: /* $@27: %empty  */
#line 359 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1938 "y.tab.c"
    break;

  case 85: /* $@28: %empty  */
#line 359 "s_parser.y"
                        {strcpy(st1[++top],"&&");}
#line 1944 "y.tab.c"
    break;

  case 86: /* E: ID $@27 AND $@28 E  */
#line 359 "s_parser.y"
                                                     {codegen();}
#line 1950 "y.tab.c"
    break;

  case 87: /* $@29: %empty  */
#line 360 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1956 "y.tab.c"
    break;

  case 88: /* $@30: %empty  */
#line 360 "s_parser.y"
                       {strcpy(st1[++top],"||");}
#line 1962 "y.tab.c"
    break;

  case 89: /* E: ID $@29 OR $@30 E  */
#line 360 "s_parser.y"
                                                    {codegen();}
#line 1968 "y.tab.c"
    break;

  case 90: /* $@31: %empty  */
#line 361 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1974 "y.tab.c"
    break;

  case 91: /* $@32: %empty  */
#line 361 "s_parser.y"
                        {strcpy(st1[++top],"<");}
#line 1980 "y.tab.c"
    break;

  case 92: /* E: ID $@31 '<' $@32 E  */
#line 361 "s_parser.y"
                                                    {codegen();}
#line 1986 "y.tab.c"
    break;

  case 93: /* $@33: %empty  */
#line 362 "s_parser.y"
        {push((yyvsp[0].str));}
#line 1992 "y.tab.c"
    break;

  case 94: /* $@34: %empty  */
#line 362 "s_parser.y"
                        {strcpy(st1[++top],">");}
#line 1998 "y.tab.c"
    break;

  case 95: /* E: ID $@33 '>' $@34 E  */
#line 362 "s_parser.y"
                                                    {codegen();}
#line 2004 "y.tab.c"
    break;

  case 96: /* $@35: %empty  */
#line 363 "s_parser.y"
        {push((yyvsp[0].str));}
#line 2010 "y.tab.c"
    break;

  case 97: /* $@36: %empty  */
#line 363 "s_parser.y"
                        {strcpy(st1[++top],"||");}
#line 2016 "y.tab.c"
    break;

  case 98: /* E: ID $@35 '=' $@36 E  */
#line 363 "s_parser.y"
                                                     {codegen_assign();}
#line 2022 "y.tab.c"
    break;

  case 99: /* E: array  */
#line 364 "s_parser.y"
           {array1();}
#line 2028 "y.tab.c"
    break;

  case 100: /* $@37: %empty  */
#line 366 "s_parser.y"
         {strcpy(st1[++top],"*");}
#line 2034 "y.tab.c"
    break;

  case 101: /* T: T '*' $@37 F  */
#line 366 "s_parser.y"
                                    {codegen();}
#line 2040 "y.tab.c"
    break;

  case 102: /* $@38: %empty  */
#line 367 "s_parser.y"
          {strcpy(st1[++top],"/");}
#line 2046 "y.tab.c"
    break;

  case 103: /* T: T '/' $@38 F  */
#line 367 "s_parser.y"
                                     {codegen();}
#line 2052 "y.tab.c"
    break;

  case 105: /* F: '(' E ')'  */
#line 370 "s_parser.y"
              {(yyval.str)=(yyvsp[-1].str);}
#line 2058 "y.tab.c"
    break;

  case 106: /* $@39: %empty  */
#line 371 "s_parser.y"
        {strcpy(st1[++top],"-");}
#line 2064 "y.tab.c"
    break;

  case 107: /* F: '-' $@39 F  */
#line 371 "s_parser.y"
                                   {codegen_umin();}
#line 2070 "y.tab.c"
    break;

  case 108: /* F: ID  */
#line 372 "s_parser.y"
        {push((yyvsp[0].str));fl=1;}
#line 2076 "y.tab.c"
    break;

  case 109: /* F: consttype  */
#line 373 "s_parser.y"
               {push((yyvsp[0].str));}
#line 2082 "y.tab.c"
    break;


#line 2086 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 376 "s_parser.y"


#include "lex.yy.c"
#include<ctype.h>


int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	yyparse();
	if(!yyparse())
	{
		printf("Parsing done\n");
		print();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

void yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}
int printline()
{
	return yylineno;
}
