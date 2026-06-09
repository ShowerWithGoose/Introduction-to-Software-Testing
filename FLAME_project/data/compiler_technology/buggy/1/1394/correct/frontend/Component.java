package frontend;

public enum Component{
    Terminal("Terminal"),//终结符
    CompUnit("<CompUnit>"),
    MainFuncDef("<MainFuncDef>"),
    FuncDef("<FuncDef>"),
    Decl("<Decl>"),
    ConstDecl("<ConstDecl>"),
    VarDecl("<VarDecl>"),
    BType("<BType>"),
    ConstDef("<ConstDef>"),
    Ident("<Ident>"),
    ConstInitVal("<ConstInitVal>"),
    ConstExp("<ConstExp>"),
    StringConst("<StringConst>"),
    VarDef("<VarDef>"),
    InitVal("<InitVal>"),
    FuncType("<FuncType>"),
    FuncFParams("<FuncFParams>"),
    FuncFParam("<FuncFParam>"),
    Block("<Block>"),
    BlockItem("<BlockItem>"),
    Stmt("<Stmt>"),
    Cond("<Cond>"),
    ForStmt("<ForStmt>"),
    Exp("<Exp>"),
    LVal("<LVal>"),
    AddExp("<AddExp>"),
    LOrExp("<LOrExp>"),
    PrimaryExp("<PrimaryExp>"),
    Number("<Number>"),
    Character("<Character>"),
    IntConst("<IntConst>"),
    CharConst("<CharConst>"),
    UnaryExp("<UnaryExp>"),
    FuncRParams("<FuncRParams>"),
    UnaryOp("<UnaryOp>"),
    MulExp("<MulExp>"),
    RelExp("<RelExp>"),
    EqExp("<EqExp>"),
    LAndExp("<LAndExp>");
    private String value;
    Component(String value) {this.value = value;}

    @Override
    public String toString() {
        return value;
    }
}
