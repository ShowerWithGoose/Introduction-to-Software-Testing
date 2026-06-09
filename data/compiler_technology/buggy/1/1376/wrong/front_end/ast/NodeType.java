package front_end.ast;

public enum NodeType {
    // 编译单元
    CompUnit,

    // 声明
    Decl,
    ConstDecl,
    VarDecl,

    // 常量声明相关
    BType,
    ConstDef,
    ConstInitVal,

    // 变量声明相关
    VarDef,
    InitVal,

    // 函数定义相关
    FuncDef,
    MainFuncDef,
    FuncType,
    FuncFParams,
    FuncFParam,

    // 语句块
    Block,
    BlockItem,
    Stmt,

    // 语句类型
    AssignStmt,       // LVal '=' Exp ';'
    ExprStmt,         // [Exp] ';'
    IfStmt,           // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    ForStmt,          // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    BreakStmt,        // 'break' ';'
    ContinueStmt,     // 'continue' ';'
    ReturnStmt,       // 'return' [Exp] ';'
    GetIntStmt,       // LVal '=' 'getint' '(' ')' ';'
    GetCharStmt,      // LVal '=' 'getchar' '(' ')' ';'
    PrintfStmt,       // 'printf' '(' StringConst {',' Exp} ')' ';'

    // 表达式
    Exp,
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
}