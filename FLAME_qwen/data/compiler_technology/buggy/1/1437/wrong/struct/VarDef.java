package struct;

import token.Token;

/* VarDef â†’ Ident [ '[' ConstExp ']' ]
* | Ident [ '[' ConstExp ']' ] '=' InitVal
*/
public class VarDef {
    private final Token ident;
    private final Token lBrackToken;
    private final ConstExp constExp;
    private final Token rBrackToken;
    private Token assignToken;
    private InitVal initVal;

    public VarDef(Token ident, Token lBrackToken, ConstExp constExp, Token rBrackToken) {
        this.ident = ident;
        this.lBrackToken = lBrackToken;
        this.constExp = constExp;
        this.rBrackToken = rBrackToken;
    }

    public VarDef(Token ident, Token lBrackToken, ConstExp constExp, Token rBrackToken, Token assignToken, InitVal initVal) {
        this.ident = ident;
        this.lBrackToken = lBrackToken;
        this.constExp = constExp;
        this.rBrackToken = rBrackToken;
        this.assignToken = assignToken;
        this.initVal = initVal;
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

    public Token getrBrackToken() {
        return rBrackToken;
    }

    public Token getAssignToken() {
        return assignToken;
    }

    public InitVal getInitVal() {
        return initVal;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (lBrackToken != null) {
            sb.append(lBrackToken.toString());
            sb.append(constExp.toString());
            sb.append(rBrackToken.toString());
        }
        if (assignToken != null) {
            sb.append(assignToken.toString());
            sb.append(initVal.toString());
        }
        sb.append("<VarDef>\n");
        return sb.toString();
    }
}
