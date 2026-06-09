package frontend.Lexer;

public enum TokenType
{
    // <editor-fold desc="类别码">
    Error("Error"),
    Ident("IDENFR"),
    IntConst("INTCON"),
    StringConst("STRCON"),
    CharConst("CHRCON"),
    MainTk("MAINTK"),
    ConstTk("CONSTTK"),
    IntTk("INTTK"),
    CharTk("CHARTK"),
    BreakTk("BREAKTK"),
    ContinueTk("CONTINUETK"),
    IfTk("IFTK"),
    ElseTk("ELSETK"),
    NotTk("NOT"),
    AndTk("AND"),
    OrTk("OR"),
    ForTk("FORTK"),
    GetIntTk("GETINTTK"),
    GetCharTk("GETCHARTK"),
    PrintfTk("PRINTFTK"),
    ReturnTk("RETURNTK"),
    PlusTk("PLUS"),
    MinusTk("MINU"),
    VoidTk("VOIDTK"),
    MulTk("MULT"),
    DivTk("DIV"),
    ModTk("MOD"),
    LessTk("LSS"),
    LessEqTk("LEQ"),
    GreaterTk("GRE"),
    GreaterEqTk("GEQ"),
    EqualTk("EQL"),
    NotEqualTk("NEQ"),
    AssignTk("ASSIGN"),
    Semicolon("SEMICN"),
    Comma("COMMA"),
    LParent("LPARENT"),
    RParent("RPARENT"),
    LBracket("LBRACK"),
    RBracket("RBRACK"),
    LBrace("LBRACE"),
    RBrace("RBRACE")
    ;
    // </editor-fold>

    private String value;

    TokenType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }
}
