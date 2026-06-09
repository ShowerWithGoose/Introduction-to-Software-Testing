public enum LexType {
    IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK,
    NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU, VOIDTK,
    MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, 
    SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,
    EOF, ERR;

    public static LexType reserve(String str) {
        switch (str) {
            case "const":
                return CONSTTK;
            case "int":
                return INTTK;
            case "char":
                return CHARTK;
            case "void":
                return VOIDTK;
            case "main":
                return MAINTK;
            case "if":
                return IFTK;
            case "else":
                return ELSETK;
            case "for":
                return FORTK;
            case "getint":
                return GETINTTK;
            case "getchar":
                return GETCHARTK;
            case "printf":
                return PRINTFTK;
            case "return":
                return RETURNTK;
            case "break":
                return BREAKTK;
            case "continue":
                return CONTINUETK;
            default:
                return IDENFR;
        }
    }
}