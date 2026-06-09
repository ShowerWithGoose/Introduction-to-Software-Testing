package parser;

public enum NodeType {
    CompUnit("<CompUnit>"), Decl("<Decl>"), ConstDecl("<ConstDecl>"), BType("<BType>"),
    ConstDef("<ConstDef>"), ConstInitVal("<ConstInitVal>"), VarDecl("<VarDecl>"), VarDef("<VarDef>"),
    InitVal("<InitVal>"), FuncDef("<FuncDef>"), MainFuncDef("<MainFuncDef>"), FuncType("<FuncType>"),
    FuncFParams("<FuncFParams>"), FuncFParam("<FuncFParam>"), Block("<Block>"), BlockItem("<BlockItem>"),
    Stmt("<Stmt>"), ForStmt("<ForStmt>"), Exp("<Exp>"), Cond("<Cond>"), LVal("<LVal>"),
    PrimaryExp("<PrimaryExp>"), Number("<Number>"), Character("<Character>"), UnaryExp("<UnaryExp>"),
    UnaryOp("<UnaryOp>"), FuncRParams("<FuncRParams>"), MulExp("<MulExp>"), AddExp("<AddExp>"),
    RelExp("<RelExp>"), EqExp("<EqExp>"), LAndExp("<LAndExp>"), LOrExp("<LOrExp>"), ConstExp("<ConstExp>");
    private final String value;

    NodeType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }
}
