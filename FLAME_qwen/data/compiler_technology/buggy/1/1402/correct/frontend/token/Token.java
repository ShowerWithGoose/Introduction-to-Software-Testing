package frontend.token;

public class Token {
    public enum TokenType {
        IDENFR, //标识符
        INTCON, STRCON,  CHRCON, //常量
        MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, //保留字
        NOT, AND, OR, PLUS, MINU, VOIDTK, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE, //其他符号
    }

    public TokenType type;
    public String content;
    public int lineNumber;

    public Token(TokenType type, String content, int lineNumber) {
        this.type = type;
        this.content = content;
        this.lineNumber = lineNumber;
    }

    public String getTypeAndContent() {
        return this.type + " " + this.content;
    }
}
