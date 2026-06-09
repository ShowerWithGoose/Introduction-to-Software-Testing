package frontend.Lexer;

public enum TokenType {
    // 标识符和常量类型
    IDENFR,    // 标识符 Ident
    INTCON,     // 整型常量 IntConst
    STRCON,     // 字符串常量 StringConst
    CHRCON,     // 字符常量 CharConst

    // 保留字
    MAINTK,     // main
    CONSTTK,    // const
    INTTK,      // int
    CHARTK,     // char
    BREAKTK,    // break
    CONTINUETK, // continue
    IFTK,       // if
    ELSETK,     // else
    VOIDTK,     // void
    FORTK,      // for
    GETINTTK,   // getint
    GETCHARTK,  // getchar
    PRINTFTK,   // printf
    RETURNTK,   // return

    // 运算符和符号
    PLUS,       // +
    MINU,       // -
    MULT,       // *
    DIV,        // /
    MOD,        // %
    LSS,        // <
    LEQ,        // <=
    GRE,        // >
    GEQ,        // >=
    EQL,        // ==
    NEQ,        // !=
    ASSIGN,     // =
    NOT,        // !
    AND,        // &&
    OR,         // ||

    // 界符
    SEMICN,     // ;
    COMMA,      // ,
    LBRACK,     // [
    RBRACK,     // ]
    LBRACE,     // {
    RBRACE,     // }
    LPARENT,     // (
    RPARENT,     // )

    // 终结符号
    EOF,        // 文件结束

    // 词法错误
    a,      // & |
    // 语法错误
    i,      // 缺少 ;
    j,      // 缺少 )
    k,      // 缺少 ]
}
