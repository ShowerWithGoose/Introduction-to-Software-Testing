package type;

public enum ASTNodeType {
    CompUnit("<CompUnit>", "编译单元"),
    Decl("<Decl>", "声明"),
    ConstDecl("<ConstDecl>", "常量声明"),
    BType("<BType>", "基本类型"),
    ConstDef("<ConstDef>", "常量定义"),
    ConstInitVal("<ConstInitVal>", "常量初值"),
    VarDecl("<VarDecl>", "变量声明"),
    VarDef("<VarDef>", "变量定义"),
    InitVal("<InitVal>", "变量初值"),
    FuncDef("<FuncDef>", "函数定义"),
    MainFuncDef("<MainFuncDef>", "主函数定义"),
    FuncType("<FuncType>", "函数类型"),
    FuncFParams("<FuncFParams>", "函数形参表"),
    FuncFParam("<FuncFParam>", "函数形参"),
    Block("<Block>", "语句块"),
    BlockItem("<BlockItem>", "语句块项"),
    Stmt("<Stmt>", "语句"),
    ForStmt("<ForStmt>","语句"),
    Exp("<Exp>", "表达式"),
    Cond("<Cond>", "条件表达式"),
    LVal("<LVal>", "左值表达式"),
    PrimaryExp("<PrimaryExp>", "基本表达式"),
    Number("<Number>", "数值"),
    Character("<Character>", "字符"),
    UnaryExp("<UnaryExp>", "一元表达式"),
    UnaryOp("<UnaryOp>", "单目运算符"),
    FuncRParams("<FuncRParams>", "函数实参表"),
    MulExp("<MulExp>", "乘除模表达式"),
    AddExp("<AddExp>", "加减表达式"),
    RelExp("<RelExp>", "关系表达式"),
    EqExp("<EqExp>", "相等性表达式"),
    LAndExp("<LAndExp>", "逻辑与表达式"),
    LOrExp("<LOrExp>", "逻辑或表达式"),
    ConstExp("<ConstExp>", "常量表达式");

    private final String tag; // 输出标签
    private final String content; // 标记的含义

    ASTNodeType(String tag, String content) {
        this.tag = tag;
        this.content = content;
    }

    // 比较两个枚举对象是否相同
    public boolean equals(ASTNodeType other) {
        return this == other;
    }


    @Override
    public String toString() {
        return tag;
    }
}
