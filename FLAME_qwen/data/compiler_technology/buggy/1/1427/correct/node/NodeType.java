package node;

public enum NodeType {
    COMP_UNIT("CompUnit"),
    CONST_DECL("ConstDecl"),
    CONST_DEF("ConstDef"),
    CONST_INIT_VAL("ConstInitVal"),
    VAR_DECL("VarDecl"),
    VAR_DEF("VarDef"),
    INIT_VAL("InitVal"),
    FUNC_DEF("FuncDef"),
    MAIN_FUNC_DEF("MainFuncDef"),
    FUNC_TYPE("FuncType"),
    FUNC_FPARAMS("FuncFParams"),
    FUNC_FPARAM("FuncFParam"),
    BLOCK("Block"),
    STMT("Stmt"),
    FOR_STMT("ForStmt"),
    EXP("Exp"),
    COND("Cond"),
    LVAL("LVal"),
    UNARY_EXP("UnaryExp"),
    MUL_EXP("MulExp"),
    ADD_EXP("AddExp"),
    REL_EXP("RelExp"),
    EQ_EXP("EqExp"),
    L_AND_EXP("LAndExp"),
    L_OR_EXP("LOrExp"),
    CONST_EXP("ConstExp"),
    UNARY_OP("UnaryOp"),
    PRIMARY_EXP("PrimaryExp"),
    LEAF_NODE("LeafNode"),
    NUMBER("Number"),
    FUNC_RPARAMS("FuncRParams"),
    CHARACTER("Character");

    private final String code;

    NodeType(String code) {
        this.code = code;
    }

    public String getCode() {
        return code;
    }
}
