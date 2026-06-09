package frontend;

/**
 * @author
 * @Description
 * @date 2024/10/4 17:16
 */
public class Token {
    public enum TokenType {
        IDENFR, INTCON, STRCON, CHRCON,
        MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK,
        IFTK, ELSETK, NOT, AND, OR,
        FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK,
        PLUS, MINU, VOIDTK, MULT, DIV, MOD,
        LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
        EOF, NONTERM
    }

    private TokenType type;
    private String content;
    private Integer lineno;


    public Token(){}

    public Token(TokenType type, String content, Integer lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }


    public TokenType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public Integer getLineno() {
        return lineno;
    }


    @Override
    public String toString() {
        if(this.type != TokenType.NONTERM) {
            return type.name() + " " + content;
        } else {
            return content;
        }
    }
}
