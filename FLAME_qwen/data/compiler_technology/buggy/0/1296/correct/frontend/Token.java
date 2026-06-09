package frontend;

public class Token {
    private TokenType type;
    private String str;

    public Token(TokenType type, String str) {
        this.type = type;
        this.str = str;
    }

    public TokenType getType() {
        return type;
    }

    public String getStr() {
        return str;
    }

    public String getTypeStr() {
        switch (type) {
            case IDENFR:
                return "IDENFR";
            case INTCON:
                return "INTCON";
            case STRCON:
                return "STRCON";
            case CHRCON:
                return "CHRCON";
            case MAINTK:
                return "MAINTK";
            case CONSTTK:
                return "CONSTTK";
            case INTTK:
                return "INTTK";
            case CHARTK:
                return "CHARTK";
            case BREAKTK:
                return "BREAKTK";
            case CONTINUETK:
                return "CONTINUETK";
            case IFTK:
                return "IFTK";
            case ELSETK:
                return "ELSETK";
            case NOT:
                return "NOT";
            case AND:
                return "AND";
            case OR:
                return "OR";
            case FORTK:
                return "FORTK";
            case GETINTTK:
                return "GETINTTK";
            case GETCHARTK:
                return "GETCHARTK";
            case PRINTFTK:
                return "PRINTFTK";
            case RETURNTK:
                return "RETURNTK";
            case PLUS:
                return "PLUS";
            case MINU:
                return "MINU";
            case VOIDTK:
                return "VOIDTK";
            case MULT:
                return "MULT";
            case DIV:
                return "DIV";
            case MOD:
                return "MOD";
            case LSS:
                return "LSS";
            case LEQ:
                return "LEQ";
            case GRE:
                return "GRE";
            case GEQ:
                return "GEQ";
            case EQL:
                return "EQL";
            case NEQ:
                return "NEQ";
            case ASSIGN:
                return "ASSIGN";
            case SEMICN:
                return "SEMICN";
            case COMMA:
                return "COMMA";
            case LPARENT:
                return "LPARENT";
            case RPARENT:
                return "RPARENT";
            case LBRACK:
                return "LBRACK";
            case RBRACK:
                return "RBRACK";
            case LBRACE:
                return "LBRACE";
            case RBRACE:
                return "RBRACE";
            default:
                return "";
        }
    }
}
