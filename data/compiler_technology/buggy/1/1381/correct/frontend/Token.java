package frontend;

public class Token {
    public enum TokenType {
        // Literals
        // Ident IntConst StringConst CharConst
        IDENFR, INTCON, STRCON, CHRCON,

        // Keywords
        // main, const, int, char, break, continue, if. else, for, return, void
        // getint, getchar, printf
        MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK, FORTK, RETURNTK, VOIDTK,
        GETINTTK, GETCHARTK, PRINTFTK,

        // Operators
        // !  &&  ||
        NOT, AND, OR,
        // +    -     *     /   %
        PLUS, MINU, MULT, DIV, MOD,
        // <  <=   >    >=   ==  !=
        LSS, LEQ, GRE, GEQ, EQL, NEQ,

        // Delimiters
        //  =      ;      ,       (         )       [       ]       {       }
        ASSIGN, SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,

        // Others
        ERROR, EOF, COMMENT
    }

    private final TokenType type;
    private final String value;

    public Token(TokenType type, String value) {
        this.type = type;
        this.value = value;
    }

    public Token(TokenType type) {
        this.type = type;
        this.value = "";
    }

    public TokenType getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public String toString() {
        return type + " " + value + "\n";
    }
}
