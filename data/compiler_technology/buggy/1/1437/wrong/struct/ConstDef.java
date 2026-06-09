package struct;

import token.Token;

/* ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal */
public class ConstDef {
    private final Token ident;
    private final Token lBrackToken;
    private final ConstExp constExp;
    private final Token rBrackToken;
    private final Token assignToken;
    private final ConstInitVal constInitVal;

    public ConstDef(Token ident, Token lBrackToken, ConstExp constExp, Token rBrackToken, Token assignToken, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lBrackToken = lBrackToken;
        this.constExp = constExp;
        this.rBrackToken = rBrackToken;
        this.assignToken = assignToken;
        this.constInitVal = constInitVal;
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLBrackToken() {
        return lBrackToken;
    }

    public ConstExp getConstExp() {
        return constExp;
    }

    public Token getRBrackToken() {
        return rBrackToken;
    }

    public Token getAssignToken() {
        return assignToken;
    }

    public ConstInitVal getConstInitVal() {
        return constInitVal;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (lBrackToken != null) {
            sb.append(lBrackToken.toString());
            sb.append(constExp.toString());
            sb.append(rBrackToken.toString());
        }
        sb.append(assignToken.toString());
        sb.append(constInitVal.toString());
        sb.append("<ConstDef>\n");
        return sb.toString();
    }
}
