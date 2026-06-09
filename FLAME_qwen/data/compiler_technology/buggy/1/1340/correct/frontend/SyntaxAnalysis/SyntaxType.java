package frontend.SyntaxAnalysis;

public enum SyntaxType {
    CompUnit,
    Decl,
    ConstDecl,
    BType,
    ConstDef,
    ConstInitVal,
    VarDecl,
    VarDef,
    InitVal,
    FuncDef,
    MainFuncDef,
    FuncType,
    FuncFParams,
    FuncFParam,
    Block,
    BlockItem,
    Stmt,
    ForStmt,
    Exp,
    Cond,
    LVal,
    PrimaryExp,
    Number, //IntConst
    Character, //CharConst
    UnaryExp,
    UnaryOp,
    FuncRParams,
    MulExp,
    AddExp,
    RelExp,
    EqExp,
    LAndExp,
    LOrExp,
    ConstExp,
    FormatString
}
