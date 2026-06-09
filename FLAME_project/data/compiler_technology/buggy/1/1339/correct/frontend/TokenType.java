package frontend;

public enum TokenType {
    // Keywords: if else for return break continue int char void
    GETINTTK, GETCHARTK, PRINTFTK, MAINTK, CONSTTK,
    IFTK, ELSETK, FORTK, RETURNTK, BREAKTK, CONTINUETK, INTTK, CHARTK, VOIDTK,
    // Operators: + - * / % = == != < <= > >= && || !
    PLUS, MINU, MULT, DIV, MOD, ASSIGN, EQL, NEQ, LSS, LEQ, GRE, GEQ, AND, OR, NOT,
    // Separators: , ; ( ) [ ] { }
    COMMA, SEMICN, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
    // Literals:
    INTCON, CHRCON, STRCON,
    // Identifiers
    IDENFR,
    // End of file
    EOF
}
