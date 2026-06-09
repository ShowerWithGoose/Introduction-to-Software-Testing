package frontend;

public enum TokenType {
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
    Not("NOT"),
    And("AND"),
    Or("OR"),
    For("FORTK"),
    Getint("GETINTTK"),
    Getchar("GETCHARTK"),
    Printf("PRINTFTK"),
    Return("RETURNTK"),
    Plus("PLUS"),
    Minu("MINU"),
    Void("VOIDTK"),
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

    private String value;

    TokenType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }
}
