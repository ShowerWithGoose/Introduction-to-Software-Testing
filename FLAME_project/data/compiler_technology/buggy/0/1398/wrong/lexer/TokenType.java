package lexer;

enum TokenType {
    MAIN("MAINTK"), CONST("CONSTTK"), INT("INTTK"), CHAR("CHARTK"),
    BREAK("BREAKTK"), CONTINUE("CONTINUETK"), IF("IFTK"), ELSE("ELSETK"),
    NOT("NOT"), AND("AND"), OR("OR"), FOR("FORTK"), GETINT("GETINTTK"),
    GETCHAR("GETCHARTK"), PRINTF("PRINTFTK"), RETURN("RETURNTK"), PLUS("PLUS"),
    MINU("MINU"), VOID("VOIDTK"), MULT("MULT"), DIV("DIV"), MOD("MOD"),
    LSS("LSS"), LEQ("LEQ"), GRE("GRE"), GEQ("GEQ"), EQL("EQL"), NEQ("NEQ"),
    ASSIGN("ASSIGN"), SEMICN("SEMICN"), COMMA("COMMA"), LPARENT("LPARENT"),
    RPARENT("RPARENT"), LBRACK("LBRACK"), RBRACK("RBRACK"), LBRACE("LBRACE"), RBRACE("RBRACE");

    private final String value;

    TokenType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }
}
