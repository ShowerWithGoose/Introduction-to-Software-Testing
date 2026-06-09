package common;

/**
 * @author
 * @Description：
 * @date
 */
public enum GComponent {
    CompUnit,
    ConstDecl,
    VarDecl,
    ConstDef,
    ConstInitVal,
    VarDef,
    InitVal,
    FuncDef,
    MainFuncDef,
    FuncType,
    FuncFParams,
    FuncFParam,
    Block,
    Stmt,
    Exp,
    ForStmt,
    Cond,
    LVal,
    PrimaryExp,
    Number,
    Character,
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
    // 以下都是不需要输出的类型
    BlockItem,
    BType,
    Decl,
}
