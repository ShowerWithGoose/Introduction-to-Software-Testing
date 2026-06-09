public class Token {
    TokenType type;
    String content;
    int lineno;

    public Token(TokenType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    public enum TokenType{
        Ident("IDENFR"),
        IntConst("INTCON"),
        StringConst("STRCON"),
        CharConst("CHRCON"),
        Main("MAINTK"),
        Const("CONSTTK"),
        Int("INTTK"),
        Char("CHARTK"),
        Break("BREAKTK"),
        Continue("CONTINUETK"),
        If("IFTK"),
        Else("ELSETK"),
        For("FORTK"),
        Getint("GETINTTK"),
        Getchar("GETCHARTK"),
        Printf("PRINTFTK"),
        Return("RETURNTK"),
        Void("VOIDTK"),
        Not("NOT"),
        And("AND"),
        Or("OR"),
        Plus("PLUS"),
        Minu("MINU"),
        Mult("MULT"),
        Div("DIV"),
        Mod("MOD"),
        Lss("LSS"),
        Leq("LEQ"),
        Gre("GRE"),
        Geq("GEQ"),
        Eql("EQL"),
        Neq("NEQ"),
        Assign("ASSIGN"),
        Semicn("SEMICN"),
        Comma("COMMA"),
        Lparent("LPARENT"),
        Rparent("RPARENT"),
        Lbrack("LBRACK"),
        Rbrack("RBRACK"),
        Lbrace("LBRACE"),
        Rbrace("RBRACE");

        private final String value;

        private TokenType(String value) {
            this.value = value;
        }

        public String getValue() {
            return value;
        }

        public static TokenType fromValue(String value) {
            for (TokenType type : TokenType.values()) {
                if (type.value.equals(value)) {
                    return type;
                }
            }
            return null;
        }
    }

    public String toString(int lineno) {
        return String.valueOf(lineno);
    }

    public String toString(TokenType type) {
        return String.valueOf(type);
    }
}
