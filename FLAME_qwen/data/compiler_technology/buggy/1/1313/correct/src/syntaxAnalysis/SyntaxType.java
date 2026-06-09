package src.syntaxAnalysis;

/**
 * 语法成分枚举类
 */
public enum SyntaxType {
    //    编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    CompUnit,
    //    声明 Decl → ConstDecl | VarDecl
    Decl,
    //    常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    // i
    ConstDecl,
    //    基本类型 BType → 'int' | 'char'
    BType,
    //    常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    // k
    ConstDef,
    //    常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    ConstInitVal,
    //    变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
    // i
    VarDecl,
    //    变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    // k
    VarDef,
    //    变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    InitVal,
    //    函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    // j
    FuncDef,
    //    主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block
    // j
    MainFuncDef,
    //    函数类型 FuncType → 'void' | 'int' | 'char'
    FuncType,
    //    函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
    FuncFParams,
    //    函数形参 FuncFParam → BType Ident ['[' ']']
    // k
    FuncFParam,
    //    语句块 Block → '{' { BlockItem } '}'
    Block,
    //    语句块项 BlockItem → Decl | Stmt
    BlockItem,
    //    语句 Stmt → LVal '=' Exp ';' // i
    //            | [Exp] ';' // i
    //            | Block
    //            | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    //            | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //            | 'break' ';' | 'continue' ';' // i
    //            | 'return' [Exp] ';' // i
    //            | LVal '=' 'getint''('')'';' // i j
    //            | LVal '=' 'getchar''('')'';' // i j
    //            | 'printf''('StringConst {','Exp}')'';' // i j
    Stmt,
    //    语句 ForStmt → LVal '=' Exp
    ForStmt,
    //    表达式 Exp → AddExp
    Exp,
    //    条件表达式 Cond → LOrExp
    Cond,
    //    左值表达式 LVal → Ident ['[' Exp ']']
    // k
    LVal,
    //    基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
    // j
    PrimaryExp,
    //    数值 Number → IntConst
    Number,
    //    字符 Character → CharConst
    Character,
    //    一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    // j
    UnaryExp,
    //    单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    UnaryOp,
    //    函数实参表 FuncRParams → Exp { ',' Exp }
    FuncRParams,
    //    乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    MulExp,
    //    加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    AddExp,
    //    关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    RelExp,
    //    相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    EqExp,
    //    逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    LAndExp,
    //    逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
    LOrExp,
    //    常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量
    ConstExp
}
