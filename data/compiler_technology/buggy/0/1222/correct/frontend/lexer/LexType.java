package frontend.lexer;


public enum LexType {
    IDENFR("Ident", "IDENFR"),
    INTCON("IntConst", "INTCON"),
    STRCON("StringConst", "STRCON"),
    CHRCON("CharConst", "CHRCON"),
    MAINTK("main", "MAINTK"),
    CONSTTK("const", "CONSTTK"),
    INTTK("int", "INTTK"),
    CHARTK("char", "CHARTK"),
    BREAKTK("break", "BREAKTK"),
    CONTINUETK("continue", "CONTINUETK"),
    IFTK("if", "IFTK"),
    ELSETK("else", "ELSETK"),
    NOT("!", "NOT"),
    AND("&&", "AND"),
    OR("||", "OR"),
    FORTK("for", "FORTK"),
    GETINTTK("getint", "GETINTTK"),
    GETCHARTK("getchar", "GETCHARTK"),
    PRINTFTK("printf", "PRINTFTK"),
    RETURNTK("return", "RETURNTK"),
    PLUS("+", "PLUS"),
    MINU("-", "MINU"),
    VOIDTK("void", "VOIDTK"),
    MULT("*", "MULT"),
    DIV("/", "DIV"),
    MOD("%", "MOD"),
    LSS("<", "LSS"),
    LEQ("<=", "LEQ"),
    GRE(">", "GRE"),
    GEQ(">=", "GEQ"),
    EQL("==", "EQL"),
    NEQ("!=", "NEQ"),
    ASSIGN("=", "ASSIGN"),
    SEMICN(";", "SEMICN"),
    COMMA(",", "COMMA"),
    LPARENT("(", "LPARENT"),
    RPARENT(")", "RPARENT"),
    LBRACK("[", "LBRACK"),
    RBRACK("]", "RBRACK"),
    LBRACE("{", "LBRACE"),
    RBRACE("}", "RBRACE");

    private String nameString;
    private String kindString;

    LexType(String nameString, String kindString) {
        this.nameString = nameString;
        this.kindString = kindString;

    }

    public String getKindString() {
        return kindString;
    }

    public String getNameString() {
        return nameString;
    }

    public void setKindString(String kindString) {
        this.kindString = kindString;
    }

    public void setNameString(String nameString) {
        this.nameString = nameString;
    }

    @Override
    public String toString() {
        return kindString;
    }
}
