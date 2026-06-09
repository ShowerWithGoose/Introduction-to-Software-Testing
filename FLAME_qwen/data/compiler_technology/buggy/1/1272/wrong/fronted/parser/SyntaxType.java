package fronted.parser;

import java.util.Locale;

public enum SyntaxType {
    AddExp,
    ConstExp,
    EqExp,
    Exp,
    LAndExp,
    LOrExp,
    MulExp,
    Number,
    PrimaryExp,
    RelExp,
    UnaryExp,
    UnaryOp,
    Cond,
    Character,
    Lval,
    FuncDef,
    FuncFParam,
    FuncFParams,
    FuncRParams,
    FuncType,
    MainFuncDef,
    BlockItem,
    Stmt,
    ForStmt,
    StringConst,
    Decl,
    ConstDef,
    ConstInitVal,
    InitVal,
    VarDecl,
    ConstDecl,
    VarDef,
    BType,
    Block,
    CompUnit,
    Token;

    @Override
    public String toString(){
        return this.name().toUpperCase(Locale.ROOT);
    }
}
