package struct;

import token.Token;

/* FuncFParam â†’ BType Ident ['[' ']'] */
public class FuncFParam {
    private final BType bType;
    private final Token ident;
    private final Token lBrackToken;
    private final Token rBrackToken;

    public FuncFParam(BType bType, Token ident, Token lBrackToken, Token rBrackToken) {
        this.bType = bType;
        this.ident = ident;
        this.lBrackToken = lBrackToken;
        this.rBrackToken = rBrackToken;
    }

    public BType getBType() {
        return bType;
    }

    public Token getIdent() {
        return ident;
    }

    public Token getlBrackToken() {
        return lBrackToken;
    }

    public Token getrBrackToken() {
        return rBrackToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.toString());
        sb.append(ident.toString());
        if (lBrackToken != null) {
            sb.append(lBrackToken.toString());
            sb.append(rBrackToken.toString());
        }
        sb.append("<FuncFParam>\n");
        return sb.toString();
    }
}
