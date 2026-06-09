package Type;

public enum SyntaxVarType {
    COMP_UNIT("CompUnit"),

    // const
    CONST_DECL("ConstDecl"),
    CONST_DEF("ConstDef"),
    CONST_INITVAL("ConstInitVal"),

    VAR_DECL("VarDecl"),
    VAR_DEF("VarDef"),
    INIT_VAL("InitVal"),

    FUNC_DEF("FuncDef"),
    FUNC_TYPE("FuncType"),
    MAIN_FUNC_DEF("MainFuncDef"),
    FUNC_FORMAL_PARAMS("FuncFParams"),
    FUNC_FORMAL_PARAM("FuncFParam"),
    FUNC_REAL_PARAMS("FuncRParams"),
    BLOCK("Block"),

    STMT("Stmt"),
    ASSIGN_STMT("Stmt"),
    EXP_STMT("Stmt"),
    IF_STMT("Stmt"),
    FOR_STMT("Stmt"),
    BREAK_STMT("Stmt"),
    CONTINUE_STMT("Stmt"),
    RETURN_STMT("Stmt"),
    GETINT_STMT("Stmt"),
    GETCHAR_STMT("Stmt"),
    PRINTF_STMT("Stmt"),
    BLOCK_STMT("Stmt"),


    FOR_STMT_EXP("ForStmt"),
    LVAL_EXP("LVal"),
    PRIMARY_EXP("PrimaryExp"),
    UNARY_EXP("UnaryExp"),
    MUL_EXP("MulExp"),
    ADD_EXP("AddExp"),
    REL_EXP("RelExp"),
    EQ_EXP("EqExp"),
    LAND_EXP("LAndExp"),
    LOR_EXP("LOrExp"),
    CONST_EXP("ConstExp"),
    EXP("Exp"),
    COND_EXP("Cond"),

    // reserved
    NUMBER("Number"),
    CHARACTER("Character"),
    UNARY_OP("UnaryOp"),

    TOKEN("token");

    private final String typeName;

    SyntaxVarType(String typeName) {
        this.typeName = typeName;
    }

    public String toString() {
        return this.typeName;
    }
}
