package frontend.Lexer;
public  class LexType {
    public enum TokenType {
        IDENFR, INTCON,STRCON,CHRCON,MAINTK,CONSTTK,INTTK,
        CHARTK, BREAKTK,CONTINUETK,IFTK,ELSETK,
        NOT,AND,OR,FORTK, GETINTTK,GETCHARTK,PRINTFTK,RETURNTK,
        PLUS,MINU,VOIDTK, MULT,DIV,MOD, LSS,LEQ,GRE,GEQ,EQL,NEQ,
        ASSIGN,SEMICN,COMMA,LPARENT,
        RPARENT,LBRACK,RBRACK,LBRACE,RBRACE
    }

    private final TokenType type;
    private final String text;
    private final Integer line;

    public LexType(TokenType type, String text, Integer line) {
        this.type = type;
        this.text = text;
        this.line = line;
    }

    public TokenType getType() {
        return type;
    }

    public String getText() {
        return text;
    }

    public Integer getLine() {
        return line;
    }

    @Override
    public String toString() {
        return this.getType() + " " + this.getText() + "\n";
    }

    public boolean isFirstExp() {
        return (type == TokenType.LPARENT) || (type == TokenType.IDENFR) ||
                (type == TokenType.INTCON) || (type == TokenType.CHRCON) ||
                (type == TokenType.PLUS) || (type == TokenType.MINU) ||
                (type == TokenType.NOT);
    }
}