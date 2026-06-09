package struct;

import token.Token;

import java.util.List;

/* InitVal â†’ Exp
* | '{' [ Exp { ',' Exp } ] '}'
* | StringConst
*/
public class InitVal {
    private List<Exp> exp;
    private Token lBraceToken;
    private List<Token> commaToken;
    private Token rBraceToken;
    private Token stringConst;

    public InitVal(List<Exp> exp) {
        this.exp = exp;
    }

    public InitVal(List<Exp> exp, Token lBraceToken, List<Token> commaToken, Token rBraceToken) {
        this.exp = exp;
        this.lBraceToken = lBraceToken;
        this.commaToken = commaToken;
        this.rBraceToken = rBraceToken;
    }

    public InitVal(Token stringConst) {
        this.stringConst = stringConst;
    }

    public List<Exp> getExp() {
        return exp;
    }

    public Token getLBraceToken() {
        return lBraceToken;
    }

    public List<Token> getCommaToken() {
        return commaToken;
    }

    public Token getRBraceToken() {
        return rBraceToken;
    }

    public Token getStringConst() {
        return stringConst;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (stringConst != null) {
            sb.append(stringConst.toString());
        } else if (lBraceToken != null) {
            sb.append(lBraceToken.toString());
            if (!exp.isEmpty()) {
                sb.append(exp.get(0).toString());
                for (int i = 1; i < exp.size(); i++) {
                    sb.append(commaToken.get(i - 1).toString());
                    sb.append(exp.get(i).toString());
                }
            }
            sb.append(rBraceToken.toString());
        } else {
            sb.append(exp.get(0).toString());
        }
        sb.append("<InitVal>\n");
        return sb.toString();
    }
}
