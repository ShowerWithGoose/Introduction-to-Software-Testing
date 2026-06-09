package frontend.type;

public enum GrammarType {
    COMPUNIT("CompUnit"),
    DECL("Decl"),
    CONSTDECL("ConstDecl"),
    BTYPE("BType"),
    CONSTDEF("ConstDef"),
    CONSTINITVAL("ConstInitVal"),
    VARDECL("VarDecl"),
    VARDEF("VarDef"),
    INITVAL("InitVal"),
    FUNCDEF("FuncDef"),
    MAINFUNCDEF("MainFuncDef"),
    FUNCTYPE("FuncType"),
    FUNCFPARAMS("FuncFParams"),
    FUNCFPARAM("FuncFParam"),
    BLOCK("Block"),
    BLOCKITEM("BlockItem"),
    STMT("Stmt"),
    FORSTMT("ForStmt"),
    EXP("Exp"),
    COND("Cond"),
    LVAL("LVal"),
    PRIMARYEXP("PrimaryExp"),
    NUMBER("Number"),
    CHARACTER("Character"),
    UNARYEXP("UnaryExp"),
    UNARYOP("UnaryOp"),
    FUNCRPARAMS("FuncRParams"),
    MULEXP("MulExp"),
    ADDEXP("AddExp"),
    RELEXP("RelExp"),
    EQEXP("EqExp"),
    LANDEXP("LAndExp"),
    LOREXP("LOrExp"),
    CONSTEXP("ConstExp"),

    TERMINAL("Terminal");


    private final String grammarName;

    private GrammarType(String grammarName) {this.grammarName = grammarName;}

    public String toString() { return grammarName; }
}
