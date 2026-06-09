package frontend;

public enum SyntaxType {
    CompUnit("<CompUnit>"),
    MainFuncDef("<MainFuncDef>"),

    ConstDecl("<ConstDecl>"),
    BType("<BType>"),
    ConstDef("<ConstDef>"),
    ConstInitVal("<ConstInitVal>"),
    ConstExp("<ConstExp>"),

    VarDecl("<VarDecl>"),
    VarDef("<VarDef>"),
    InitVal("<InitVal>"),

    FuncDef("<FuncDef>"),
    FuncType("<FuncType>"),
    FuncFParams("<FuncFParams>"),
    FuncFParam("<FuncFParam>"),

    Block("<Block>"),
    BlockItem("<BlockItem>"),

    AddExp("<AddExp>"),
    MulExp("<MulExp>"),
    UnaryExp("<UnaryExp>"),
    PExp("<PrimaryExp>"),
    UnaryOp("<UnaryOp>"),
    Exp("<Exp>"),
    LVal("<LVal>"),
    Number("<Number>\n<PrimaryExp>"),
    Character("<Character>\n<PrimaryExp>"),
    PLVal("<LVal>\n<PrimaryExp>"),
    FuncRParams("<FuncRParams>"),

    Stmt("<Stmt>"),

    Cond("<Cond>"),
    LOrExp("<LOrExp>"),
    LAndExp("<LAndExp>"),
    EqExp("<EqExp>"),
    RelExp("<RelExp>"),

    ForStmt("<ForStmt>"),;

    private final String name;

    SyntaxType(String name) {
        this.name = name;
    }

    public String toString() {
        return this.name;
    }
}
