package frontend.Token;

public enum TokenType {
    // 关键字
    INTTK, CHARTK, VOIDTK, CONSTTK, IFTK, ELSETK, FORTK, BREAKTK, CONTINUETK, RETURNTK, GETINTTK, GETCHARTK, PRINTFTK, MAINTK,
    // 标识符
    IDENFR,
    // 常量
    INTCON, CHRCON, STRCON,
    // 运算符
    PLUS, MINU, MULT, DIV, MOD, NOT, AND, OR, EQL, NEQ, LSS, GRE, LEQ, GEQ, ASSIGN,
    // 分隔符
    SEMICN, COMMA, LPARENT, RPARENT, LBRACE, RBRACE, LBRACK, RBRACK,
    // 文件结束
    EOF,
    // 其他（如果有）
    COLON // 如果需要处理 ':'
}
