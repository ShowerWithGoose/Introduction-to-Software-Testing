package Reader;

public class Token {
    public enum TokenType {
        IDENFR("ident"),
        INTCON("IntConst"),
        STRCON("StringConst"),
        CHRCON("CharConst"),
        MAINTK("main"),
        CONSTTK("const"),
        INTTK("int"),
        CHARTK("char"),
        BREAKTK("break"),
        CONTINUETK("continue"),
        IFTK("if"),
        ELSETK("else"),
        NOT("!"),
        AND("&&"),
        OR("||"),
        FORTK("for"),
        GETINTTK("getInt"),
        GETCHARTK("getChar"),
        PRINTFTK("printf"),
        RETURNTK("return"),
        PLUS("+"),
        MINU("-"),
        VOIDTK("void"),
        MULT("*"),
        DIV("/"),
        MOD("%"),
        LSS("<"),
        LEQ("<="),
        GRE(">"),
        GEQ(">="),
        EQL("=="),
        NEQ("!="),
        ASSIGN("="),
        SEMICN(";"),
        COMMA(","),
        LPARENT("("),
        RPARENT(")"),
        LBRACK("["),
        RBRACK("]"),
        LBRACE("{"),
        RBRACE("}");
        private String value;

        TokenType(String value) {
            this.value = value;
        }

        // @Override
        // public String toString() {
        //     return value;
        // }
    }

    private String description;
    private final TokenType type;
    private int lineNum;
    private char err;

    public Token(String description, TokenType type, int lineNum) {
        this.description = description;
        this.type = type;
        this.lineNum = lineNum;
    }

    @Override
    public String toString() {
        return type.toString() + " " + description;
    }

    public TokenType getType() {
        return type;
    }

    public String getDescription() {
        return description;
    }

    public int getLineNumber() {
        return lineNum;
    }

    public void setErr(char err) {
        this.err = err;
    }

    public char getErr() {
        return err;
    }

    public String toStringWithErr() {
        return lineNum + " " + err;
    }
}