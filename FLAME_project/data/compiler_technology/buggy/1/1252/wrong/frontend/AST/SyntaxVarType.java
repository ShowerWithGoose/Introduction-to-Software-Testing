package frontend.AST;

// 枚举变量类型
public enum SyntaxVarType {
    /*****************************CompUnit************************/
    COMP_UNIT,

    /****************************BLOCK**************************/
    BLOCK,

    /***************************CONST*************************/
    CONST_DECL,
    CONST_DEF,
    CONST_INITVAL,

    /***************************VAR*************************/
    VAR_DECL,
    VAR_DEF,
    INIT_VAL,

    /***************************FUNC*************************/
    FUNC_DEF,
    MAIN_FUNC_DEF,
    FUNC_TYPE,
    FUNC_F_PARAMS, // 函数形参表
    FUNC_F_PARAM,  // 函数形参
    FUNC_R_PARAMS, // 函数实参

    /***************************Stmt*************************/
    STMT,
    ASSIGN_STMT,
    EXP_STMT,
    BLOCK_STMT,
    IF_STMT,
    FOR_STMT,
    BREAK_STMT,
    CONTINUE_STMT,
    RETURN_STMT,
    GETINT_STMT,
    GETCHAR_STMT,
    PRINTF_STMT,
    FORSTMT,

    /************************EXP************************/
    EXP,
    COND_EXP, // 条件表达式
    LVAL_EXP, // 左值表达式
    PRIMARY_EXP, // 基本表达式
    UNARY_EXP, // 一元表达式
    UNARY_OP,
    MUL_EXP,
    ADD_EXP,
    REL_EXP,
    EQ_EXP,
    LAND_EXP,
    LOR_EXP,
    CONST_EXP,

    NUMBER,
    CHARACTER,

    TOKEN;

    // 根据 SyntaxVarType 返回对应的字符串
    public String toString() {
        switch (this) {
            case COMP_UNIT:
                return "CompUnit";
            case BLOCK:
                return "Block";
            case CONST_DECL:
                return "ConstDecl";
            case CONST_DEF:
                return "ConstDef";
            case CONST_INITVAL:
                return "ConstInitVal";
            case VAR_DECL:
                return "VarDecl";
            case VAR_DEF:
                return "VarDef";
            case INIT_VAL:
                return "InitVal";
            case FUNC_DEF:
                return "FuncDef";
            case MAIN_FUNC_DEF:
                return "MainFuncDef";
            case FUNC_TYPE:
                return "FuncType";
            case FUNC_F_PARAMS:
                return "FuncFParams"; // 函数形参表
            case FUNC_F_PARAM:
                return "FuncFParam"; // 函数形参
            case FUNC_R_PARAMS:
                return "FuncRParams"; // 函数实参
            case STMT:
                return "Stmt";
            case ASSIGN_STMT:
                return "Stmt";
            case EXP_STMT:
                return "Stmt";
            case BLOCK_STMT:
                return "Stmt";
            case IF_STMT:
                return "Stmt";
            case FOR_STMT:
                return "Stmt";
            case BREAK_STMT:
                return "Stmt";
            case CONTINUE_STMT:
                return "Stmt";
            case RETURN_STMT:
                return "Stmt";
            case GETINT_STMT:
                return "Stmt";
            case GETCHAR_STMT:
                return "Stmt";
            case PRINTF_STMT:
                return "Stmt";
            case FORSTMT:
                return "ForStmt";
            case EXP:
                return "Exp";
            case COND_EXP:
                return "Cond";
            case LVAL_EXP:
                return "LVal";
            case PRIMARY_EXP:
                return "PrimaryExp";
            case UNARY_EXP:
                return "UnaryExp";
            case UNARY_OP:
                return "UnaryOp";
            case MUL_EXP:
                return "MulExp";
            case ADD_EXP:
                return "AddExp";
            case REL_EXP:
                return "RelExp";
            case EQ_EXP:
                return "EqExp";
            case LAND_EXP:
                return "LAndExp";
            case LOR_EXP:
                return "LOrExp";
            case CONST_EXP:
                return "ConstExp";
            case NUMBER:
                return "Number";
            case CHARACTER:
                return "Character";
            case TOKEN:
                return "token";
            default:
                return "Unknown Type";
        }
    }
}
