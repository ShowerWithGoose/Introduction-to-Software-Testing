package frontend.Parser;

public enum NonterminalType
{
    CompUnit("<CompUnit>"),
    Decl("<Decl>"),
    ConstDecl("<ConstDecl>"),
    VarDecl("<VarDecl>"),
    BType("<BType>"),
    ConstDef("<ConstDef>"),
    VarDef("<VarDef>"),
    FuncDef("<FuncDef>"),
    FuncType("<FuncType>"),
    MainFuncDef("<MainFuncDef>"),
    ConstExp("<ConstExp>"),
    ConstInitVal("<ConstInitVal>"),
    InitVal("<InitVal>"),
    AddExp("<AddExp>"),
    MulExp("<MulExp>"),
    UnaryExp("<UnaryExp>"),
    UnaryOp("<UnaryOp>"),
    FuncRParams("<FuncRParams>"),
    Exp("<Exp>"),
    LVal("<LVal>"),
    Number("<Number>"),
    Character("<Character>"),
    PrimaryExp("<PrimaryExp>"),
    FuncFParams("<FuncFParams>"),
    FuncFParam("<FuncFParam>"),
    Block("<Block>"),
    BlockItem("<BlockItem>"),
    Stmt("<Stmt>"),
    ForStmt("<ForStmt>"),
    Cond("<Cond>"),
    LOrExp("<LOrExp>"),
    LAndExp("<LAndExp>"),
    EqExp("<EqExp>"),
    RelExp("<RelExp>"),
    ;

    final String name;

    NonterminalType(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }
}
