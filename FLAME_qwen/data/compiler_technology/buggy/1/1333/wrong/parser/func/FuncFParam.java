package parser.func;

import lexer.Token;

public class FuncFParam {
    private final Token bType;
    private final String ident;
    private final boolean isArray;

    public FuncFParam(Token bType, String ident, boolean isArray) {
        this.bType = bType;
        this.ident = ident;
        this.isArray = isArray;
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.bType.toString() + "\nIDENFR " + this.ident + "\n");
        if (this.isArray) {
            str.append("LBRACK [\nRBRACK ]\n");
        }
        str.append("<FuncFParam>\n");
        return str.toString();
    }
}
