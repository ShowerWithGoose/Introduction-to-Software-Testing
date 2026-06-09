package frontend.lexer;

public class Token {
    public enum TokenType {
        IDENFR, INTCON, STRCON, CHRCON, // 标识符，整型常量，字符串常量，字符常量
        MAINTK, CONSTTK, INTTK, CHARTK, // main,const,int,char
        BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK,// break,continue,if,else,for
        GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, VOIDTK,
        AND, OR, LSS, LEQ, GRE, GEQ, EQL, ASSIGN, NOT, NEQ,
        PLUS, MINU, MULT, DIV, MOD,
        SEMICN, COMMA,
        LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
    }
    private TokenType type; // TokenType为表示token类型的枚举类
    private String value; // 该Token的字符串本身
    private int lineNumber; // 该Token所在的行号

    public Token(TokenType type, String value, int lineNumber) {
        this.type = type;
        this.value = value;
        this.lineNumber = lineNumber;
    }

    public TokenType getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLineNumber() {
        return lineNumber;
    }

}
