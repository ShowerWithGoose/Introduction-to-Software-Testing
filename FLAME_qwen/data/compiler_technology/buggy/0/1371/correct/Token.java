public class Token {
    private final Type type;
    private final String content;
    public Token(Type type ,String content) {
        this.type = type;
        this.content = content;
    }

    public enum Type {
        ERROR_A,KEYWORD,INTCON,IDENFR,STRCON,CHRCON,MAINTK,COSNTTK,INTTK,CHARTK,BREAKTK,CONTINUETK,IFTK,ELSETK,FORTK,
        GETINTTK,GETCHARTK,PRINTFTK,RETURNTK,VOIDTK,AND,NOT,OR,PLUS,MINU,MULT,DIV,MOD,LSS,LEQ,GRE,GEQ,EQL,NEQ,ASSIGN,SEMICN,COMMA,LPARENT,RPARENT,LBRACK,RBRACK,LBRACE,RBRACE
    }

    public String getType() {
        return this.type.toString();
    }

    public String getContent() {
        return this.content;
    }


}
