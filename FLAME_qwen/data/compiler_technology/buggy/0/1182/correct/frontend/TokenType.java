package frontend;

public enum TokenType {
    IDENFR("Ident"),
    ELSETK("else"),
    VOIDTK("void"),
    SEMICN(";"),
    INTCON("IntConst"),
    NOT("!"),
    MULT("*"),
    COMMA(","),
    STRCON("StringConst"),
    AND("&&"),
    DIV("/"),
    LPARENT("("),
    CHRCON("CharConst"),
    OR("||"),
    MOD("%"),
    RPARENT(")"),
    MAINTK("main"),
    FORTK("for"),
    LSS("<"),
    CONSTTK("const"),
    GETINTTK("getint"),
    LEQ("<="),
    RBRACK("]"),
    GETCHARTK("getchar"),
    GRE(">"),
    INTTK("int"),
    PRINTFTK("printf"),
    GEQ(">="),
    CHARTK("char"),
    RETURNTK("return"),
    EQL("=="),
    BREAKTK("break"),
    CONTINUETK("continue"),
    IFTK("if"),
    PLUS("+"),
    MINU("-"),
    ASSIGN("="),
    NEQ("!="),
    LBRACK("["),
    LBRACE("{"),
    RBRACE("}");


    private final String description;

    TokenType(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }

    public static TokenType fromDescription(String des) {
        for (TokenType tokenType : TokenType.values()) {
            if (tokenType.getDescription().equals(des)) {
                return tokenType;
            }
        }
        if (isNum(des)) {
            return INTCON;
        } else if (isIdent(des)) {
            return IDENFR;
        }
        return null;
    }

    public static boolean isNum(String s) {
        if (s.length() == 0)
            return false;
        int flag = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < '0' || s.charAt(i) > '9') {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            return true;
        return false;
    }


    public static boolean isIdent(String s) {
        if (s.isEmpty() || s.charAt(0) == '_' || Character.isLetter(s.charAt(0))) {
            return false;
        }
        if (s.isEmpty() && (s.charAt(0) == ' ' || s.charAt(0) == '\r' || s.charAt(0) == '\n' || s.charAt(0) == '\t'))
            return false;
        if (s.length() == 0)
            return false;
        for (int i = 1; i < s.length(); i++) {
            if (!Character.isLetterOrDigit(s.charAt(i)) && s.charAt(i) != '_' && !isNum(s)) {
                return false;
            }
        }
        return true;
    }

}