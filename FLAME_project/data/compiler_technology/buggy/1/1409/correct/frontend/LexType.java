package frontend;

public enum LexType {

    IDENFR,
    INTCON,
    STRCON,
    CHRCON,
    MAINTK,
    CONSTTK,
    INTTK,
    CHARTK,
    BREAKTK,
    CONTINUETK,
    IFTK,
    ELSETK,
    NOT,
    AND,
    OR,
    FORTK,
    GETINTTK,
    GETCHARTK,
    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    VOIDTK,
    MULT,
    DIV,
    MOD,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE;

    public String get_LexType_s_value() {
        switch (this) {
            case IDENFR:return "Ident";
            case INTCON:return "IntConst";
            case STRCON:return "StringConst";
            case CHRCON:return "CharConst";
            case MAINTK:return "main";
            case CONSTTK:return "const";
            case INTTK:return "int";
            case CHARTK:return "char";
            case BREAKTK:return "break";
            case CONTINUETK:return "continue";
            case IFTK:return "if";
            case ELSETK:return "else";
            case NOT:return "!";
            case AND:return "&&";
            case OR:return "||";
            case FORTK:return "for";
            case GETINTTK:return "getint";
            case GETCHARTK:return "getchar";
            case PRINTFTK:return "printf";
            case RETURNTK:return "return";
            case PLUS:return "+";
            case MINU:return "-";
            case VOIDTK:return "void";
            case MULT:return "*";
            case DIV:return "/";
            case MOD:return "%";
            case LSS:return "<";
            case LEQ:return "<=";
            case GRE:return ">";
            case GEQ:return ">=";
            case EQL:return "==";
            case NEQ:return "!=";
            case ASSIGN:return "=";
            case SEMICN:return ";";
            case COMMA:return ",";
            case LPARENT:return "(";
            case RPARENT:return ")";
            case LBRACK:return "[";
            case RBRACK:return "]";
            case LBRACE:return "{";
            case RBRACE:return "}";
            default:return null;
        }
    }

}
