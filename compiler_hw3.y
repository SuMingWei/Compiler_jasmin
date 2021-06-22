/*	Definition section */
%{
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

%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    char *id;
    char *type;
    char *operator;
}

/* Token without return */
%token AND OR
%token QUO REM 
%token INC DEC
%token EQL NEQ LSS LEQ GTR GEQ
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token TRUE FALSE
%token INT FLOAT BOOL STRING
%token PRINT IF ELSE FOR WHILE
%token SEMICOLON

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <id> IDENT
/* Nonterminal with return, which need to sepcify type */
%type <type> Type TypeName
%type <operator> Unary_op Cmp_op Add_op Mul_op Assign_op
%type <type> Expression Logical_OR_Expr Logical_And_Expr Comparison_Expr Addition_Expr Multiplication_Expr
%type <type> AssignmentExpr UnaryExpr PrimaryExpr Operand Literal IndexExpr ConversionExpr 

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList 
;

StatementList
    : Statement StatementList 
    | Statement
;

Statement
    : DeclarationStmt
    | ExpressionStmt
    | AssignmentStmt
    | IncDecStmt
    | Block
    | IfStmt
    | WhileStmt
    | ForStmt
    | PrintStmt
;

DeclarationStmt
    : Type IDENT SEMICOLON {
        // id has been declared
        if(check_id($2) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        $2, check_id($2));
            yyerror(errorMessage);
        }else{
            if(strcmp($1,"int") == 0){
                codegen("ldc 0\n");
                codegen("istore %d\n",cur_addr);
            }else if(strcmp($1,"float") == 0){
                codegen("ldc 0.0\n");
                codegen("fstore %d\n",cur_addr);
            }else if(strcmp($1,"string") == 0){
                codegen("ldc \"\"\n");
                codegen("astore %d\n",cur_addr);
            }
            // else if(strcmp($1,"bool") == 0){
            //     codegen("ldc \"true\"\n");
            //     codegen("astore %d\n",cur_addr);
            // }

            insert_symbol($2,$1,"-");
        }
        
    }
    | Type IDENT '[' Expression ']' SEMICOLON {
        // id has been declared
        if(check_id($2) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        $2, check_id($2));
            yyerror(errorMessage);
        }else{
            char *type;
            if(strcmp($1,"int") == 0){
                type = "int";
            }else if(strcmp($1,"float") == 0){
                type = "float";
            }
            codegen("newarray %s\n", type);
            codegen("astore %d\n",cur_addr);
            
            insert_symbol($2,"array",$1);
        }
    }
    | Type IDENT ASSIGN Expression SEMICOLON {
        // id has been declared
        if(check_id($2) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        $2, check_id($2));
            yyerror(errorMessage);
        }else{
            if(strcmp($1,"int") == 0){
                codegen("istore %d\n",cur_addr);
            }else if(strcmp($1,"float") == 0){
                codegen("fstore %d\n",cur_addr);
            }else if(strcmp($1,"string") == 0){
                codegen("astore %d\n",cur_addr);
            }
            // else if(strcmp($1,"bool") == 0){
            //     codegen("astore %d\n",cur_addr);
            // }
            insert_symbol($2,$1,"-");
        }
    }    
    | Type IDENT '[' Expression ']' ASSIGN Expression SEMICOLON {
        // id has been declared
        if(check_id($2) != -1){
            char errorMessage[100] = "";        
            snprintf(errorMessage,sizeof(errorMessage),
                        "%s redeclared in this block. previous declaration at line %d",
                        $2, check_id($2));
            yyerror(errorMessage);
        }else{
            char *type;
            if(strcmp($1,"int") == 0){
                type = "int";
            }else if(strcmp($1,"float") == 0){
                type = "float";
            }
            codegen("newarray %s\n", type);
            codegen("astore %d\n",cur_addr);

            insert_symbol($2,"array",$1);
        }
    }
;

ExpressionStmt
    : Expression SEMICOLON
;

AssignmentStmt
    : AssignmentExpr SEMICOLON
;
AssignmentExpr
    : Expression {
        // assign later
        assignFlag = 0;
        assign_id = cur_id;
    } Assign_op Expression { 
        // intLit/floatLit cannot be assigned
        if(strcmp($1,"intLit") == 0 || strcmp($1, "floatLit") == 0){
            char errorMessage[100] = "";
            snprintf(errorMessage,sizeof(errorMessage),
                        "cannot assign to %s", getType($4));
            yyerror(errorMessage);
        }
        // mismatched types
        else if(strcmp(getType($1),getType($4)) != 0){
            char errorMessage[100] = "";
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: %s (mismatched types %s and %s)",
                        $3, getType($1),getType($4));
            yyerror(errorMessage);
        }else{
            $$ = $1;
        }

        if(strcmp($3,"ADD_ASSIGN") == 0){
            codegen("%cadd\n",getType($4)[0]);
        }else if(strcmp($3,"SUB_ASSIGN") == 0){
            codegen("%csub\n",getType($4)[0]);
        }else if(strcmp($3,"MUL_ASSIGN") == 0){
            codegen("%cmul\n",getType($4)[0]);
        }else if(strcmp($3,"QUO_ASSIGN") == 0){
            codegen("%cdiv\n",getType($4)[0]);
        }else if(strcmp($3,"REM_ASSIGN") == 0){
            codegen("%crem\n",getType($4)[0]);
        }
        update_symbol(assign_id);
        assignFlag = 1;
    }
;

IncDecStmt  
    : IncDecExpr SEMICOLON
;
IncDecExpr 
    : Expression INC { 
        if(strcmp(getType($1),"int") == 0){
            codegen("ldc 1\n");
            codegen("iadd\n");
        }else{
            codegen("ldc 1.0\n");
            codegen("fadd\n");
        }
        update_symbol(cur_id);
    }
    | Expression DEC { 
        if(strcmp(getType($1),"int") == 0){
            codegen("ldc 1\n");
            codegen("isub\n");
        }else{
            codegen("ldc 1.0\n");
            codegen("fsub\n");
        }
        update_symbol(cur_id);
    }
;

Block
    : '{' { create_symbol(); }
        StatementList 
      '}' { dump_symbol(); }
;

IfStmt
    : IFCondition Block {
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
    | IFCondition BlockELSE IfStmt
    | IFCondition BlockELSE Block {
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
;

IFCondition
    : IF Condition {
        labelIF[cur_scope][elseNum[cur_scope]] = label; 
        codegen("ifeq label%d\n",label++);
    }
;

BlockELSE
    : Block ELSE {
        codegen("goto label%d\n",label++);
        INDENT--;
        codegen("label%d:\n",labelIF[cur_scope][elseNum[cur_scope]]);
        INDENT++;
        labelIF[cur_scope][elseNum[cur_scope]++] = label-1;
    } 

WhileStmt
    : WHILE {
        labelWHILE[cur_scope] = label;
        INDENT--;
        codegen("label%d:\n",label++);    
        INDENT++;
    }'(' Condition ')' {
        labelWHILEend[cur_scope] = label;
        codegen("ifeq label%d\n",label++);
    } Block {
        codegen("goto label%d\n",labelWHILE[cur_scope]);
        INDENT--;
        codegen("label%d:\n",labelWHILEend[cur_scope]);
        INDENT++;
    }
;

Condition
    : Expression {
        // condition must be bool
        if(strcmp(getType($1), "bool") != 0){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, getType($1));
        }
    }
;

ForStmt
    : FOR '(' ForClause ')' Block {
        codegen("goto label%d\n",label-2);
        INDENT--;
        codegen("label%d:\n",labelFORend[cur_scope]);
        INDENT++;
    }
;
ForClause 
    : AssignmentStmt {
        labelFOR[cur_scope] = label;
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
    } ExpressionStmt {
        labelFORend[cur_scope] = label;
        codegen("ifeq label%d\n",label++);
        codegen("goto label%d\n",label+1);
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
    } SimpleExpr {
        codegen("goto label%d\n",labelFOR[cur_scope]);
        INDENT--;
        codegen("label%d:\n",label++);
        INDENT++;
    }
;
SimpleExpr
    : AssignmentExpr
    | Expression
    | IncDecExpr
;

PrintStmt
    : PRINT {
        assignFlag = 0;    
    }'(' Expression ')' SEMICOLON {
        if(strcmp(getType($4),"bool") == 0){
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
        if(strcmp(getType($4),"int") == 0){
            codegen("invokevirtual java/io/PrintStream/print(I)V\n");
        }else if(strcmp(getType($4),"float") == 0){
            codegen("invokevirtual java/io/PrintStream/print(F)V\n");
        }else{
            codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
        assignFlag = 1;
    }
;

Expression 
    : Logical_OR_Expr { $$ = $1; }
;

Logical_OR_Expr
    : Logical_And_Expr { $$ = $1; }
    | Logical_OR_Expr OR Logical_And_Expr { 
        if(strcmp(getType($1),"bool") == 0 && strcmp(getType($3),"bool") == 0){
            $$ = "boolLit";
        }
        // operator OR not defined
        else{
            char errorMessage[100] = "";
            char *errorType;
            if(strcmp(getType($1),"bool") == 1){
                errorType = getType($1);
            }else{
                errorType = getType($3);
            }
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: (operator OR not defined on %s)",errorType);
            yyerror(errorMessage);
        }
        codegen("ior\n");
    }
;

Logical_And_Expr
    : Comparison_Expr { $$ = $1; }
    | Logical_And_Expr AND Comparison_Expr { 
        if(strcmp(getType($1),"bool") == 0 && strcmp(getType($3),"bool") == 0){
            $$ = "boolLit";
        }
        // operator AND not defined
        else{
            char errorMessage[100] = "";
            char *errorType;
            if(strcmp(getType($1),"bool") != 0){
                errorType = getType($1);
            }else{
                errorType = getType($3);
            }
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: (operator AND not defined on %s)",errorType);
            yyerror(errorMessage);
        }
        codegen("iand\n"); 
    }
;

Comparison_Expr
    : Addition_Expr { $$ = $1; }
    | Comparison_Expr Cmp_op Addition_Expr { 
        $$ = "boolLit";

        if(strcmp(getType($3),"int") == 0){
            codegen("isub\n");
        }else{
            codegen("fcmpl\n");
        }

        if(strcmp($2,"EQL") == 0){
            codegen("ifeq label%d\n",label);
        }else if(strcmp($2,"NEQ") == 0){
            codegen("ifne label%d\n",label);
        }else if(strcmp($2,"LSS") == 0){
            codegen("iflt label%d\n",label);
        }else if(strcmp($2,"LEQ") == 0){
            codegen("ifle label%d\n",label);
        }else if(strcmp($2,"EQL") == 0){
            codegen("ifeq label%d\n",label);
        }else if(strcmp($2,"GTR") == 0){
            codegen("ifgt label%d\n",label);
        }else if(strcmp($2,"GEQ") == 0){
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
;

Addition_Expr
    : Multiplication_Expr { $$ = $1; }
    | Addition_Expr Add_op Multiplication_Expr { 
        if(strcmp(getType($1),getType($3)) == 0){
            $$ = $1;
        }
        // mismatched types
        else{
            char errorMessage[100] = "";
            char *errorOp = $2;
            snprintf(errorMessage,sizeof(errorMessage),
                        "invalid operation: %s (mismatched types %s and %s)",
                        errorOp, getType($1),getType($3));
            yyerror(errorMessage);
        } 

        if(strcmp($2,"ADD") == 0){
            if(strcmp(getType($3),"int") == 0){
                codegen("iadd\n");
            }else{
                codegen("fadd\n");
            }
        }else if(strcmp($2,"SUB") == 0){
            if(strcmp(getType($3),"int") == 0){
                codegen("isub\n");
            }else{
                codegen("fsub\n");
            }
        }
    }
;

Multiplication_Expr
    : UnaryExpr { $$ = $1; }
    | Multiplication_Expr Mul_op UnaryExpr { 
        char *errorOp = $2;
        if(strcmp(errorOp,"REM") == 0){
            // operator REM not defined on float
            if(strcmp(getType($1),"float") == 0 || strcmp(getType($3),"float") == 0){
                char errorMessage[100] = "";
                snprintf(errorMessage,sizeof(errorMessage),
                            "invalid operation: (operator REM not defined on float)");
                yyerror(errorMessage);
            }else{
                $$ = $1;
            }
        }else{
            if(strcmp(getType($1),getType($3)) == 0){
                $$ = $1;
            }
            // mismatched types
            else{
                char errorMessage[100] = "";
                snprintf(errorMessage,sizeof(errorMessage),
                            "invalid operation: %s (mismatched types %s and %s)",
                            errorOp, getType($1),getType($3));
                yyerror(errorMessage);
            } 
        }
        
        if(strcmp($2,"MUL") == 0){
            if(strcmp(getType($3),"int") == 0){
                codegen("imul\n");
            }else{
                codegen("fmul\n");
            }
        }else if(strcmp($2,"QUO") == 0){
            if(strcmp(getType($3),"int") == 0){
                codegen("idiv\n");
            }else{
                codegen("fdiv\n");
            }
        }else{
            codegen("irem\n");
        }
    }
;

UnaryExpr
    : PrimaryExpr        { $$ = $1; }
    | Unary_op UnaryExpr { 
        $$ = $2;
        
        if(strcmp($1,"POS") == 0){
            codegen(" \n");
        }else if(strcmp($1,"NEG") == 0){
            if(strcmp(getType($2),"int") == 0){
                codegen("ineg\n");
            }else{
                codegen("fneg\n");
            }
        }else if(strcmp($1,"NOT") == 0){
            codegen("iconst_1\n");
            codegen("ixor\n");
        }
        
    }
;

PrimaryExpr
    : Operand         { $$ = $1; }
    | IndexExpr       { $$ = $1; }
    | ConversionExpr
;

Operand
    : Literal            { $$ = $1; }
    | IDENT              { $$ = lookup_symbol($1); }
    | '(' Expression ')' { $$ = $2; }
;

IndexExpr
    : PrimaryExpr '[' Expression ']' { 
        $$ = $1; 
        if(!assignFlag){
            codegen("%caload\n",$1[0]);
        }
    }
;

ConversionExpr
    : '(' Type ')' Expression {
        $$ = $2;

        if(strcmp(getType($4),"int") == 0){
            codegen("i2f\n");
        }else{
            codegen("f2i\n");
        }
    }
;

Literal
    : INT_LIT {
        $$ = "intLit";
        codegen("ldc %d\n", $1);
    }
    | FLOAT_LIT {
        $$ = "floatLit";
        codegen("ldc %.6f\n", $1);
    }
    | '"' STRING_LIT '"' {
        $$ = "stringLit";
        codegen("ldc \"%s\"\n", $2);
    }
    | TRUE {
        $$ = "boolLit";
        codegen("iconst_1\n");
    }
    | FALSE {
        $$ = "boolLit";
        codegen("iconst_0\n");
    }
;

Unary_op
    : '+' { $$ = "POS"; }
    | '-' { $$ = "NEG"; }
    | '!' { $$ = "NOT"; }
;

Cmp_op
    : EQL { $$ = "EQL"; }
    | NEQ { $$ = "NEQ"; }
    | LSS { $$ = "LSS"; }
    | LEQ { $$ = "LEQ"; }
    | GTR { $$ = "GTR"; }
    | GEQ { $$ = "GEQ"; }
;

Add_op
    : '+' { $$ = "ADD"; }
    | '-' { $$ = "SUB"; } 
;
 
Mul_op
    : '*' { $$ = "MUL"; }
    | QUO { $$ = "QUO"; }
    | REM { $$ = "REM"; }
;

Assign_op
    : ASSIGN { $$ = "ASSIGN"; }
    | ADD_ASSIGN { $$ = "ADD_ASSIGN"; }
    | SUB_ASSIGN { $$ = "SUB_ASSIGN"; }
    | MUL_ASSIGN { $$ = "MUL_ASSIGN"; }
    | QUO_ASSIGN { $$ = "QUO_ASSIGN"; }
    | REM_ASSIGN { $$ = "REM_ASSIGN"; }
;

Type
    : TypeName { $$ = $1; }
;

TypeName
    : INT { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    | STRING { $$ = "string"; }
    | BOOL { $$ = "bool"; }
;

%%

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
