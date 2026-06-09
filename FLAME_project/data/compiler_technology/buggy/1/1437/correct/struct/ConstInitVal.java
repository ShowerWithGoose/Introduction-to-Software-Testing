package struct;

import token.Token;

import java.util.List;

/* ConstInitVal â†’ ConstExp
* | '{' [ ConstExp { ',' ConstExp } ] '}'
* | StringConst
*/
public class ConstInitVal {
    private List<ConstExp> constExp;
    private Token lBraceToken;
    private List<Token> commaToken;
    private Token rBraceToken;
    private Token stringConst;

    public ConstInitVal(List<ConstExp> constExp) {
        this.constExp = constExp;
    }

    public ConstInitVal(List<ConstExp> constExp, Token lBraceToken, List<Token> commaToken, Token rBraceToken) {
        this.constExp = constExp;
        this.lBraceToken = lBraceToken;
        this.commaToken = commaToken;
        this.rBraceToken = rBraceToken;
    }

    public ConstInitVal(Token stringConst) {
        this.stringConst = stringConst;
    }

    public List<ConstExp> getConstExp() {
        return constExp;
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
            if (!constExp.isEmpty()) {
                sb.append(constExp.get(0).toString());
                for (int i = 1; i < constExp.size(); i++) {
                    sb.append(commaToken.get(i - 1).toString());
                    sb.append(constExp.get(i).toString());
                }
            }
            sb.append(rBraceToken.toString());
        } else {
            sb.append(constExp.get(0).toString());
        }
        sb.append("<ConstInitVal>\n");
        return sb.toString();
    }
}
