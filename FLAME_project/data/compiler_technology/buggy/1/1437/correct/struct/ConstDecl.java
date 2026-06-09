package struct;

import token.Token;

import java.util.List;

/* ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';' */
public class ConstDecl {
    private final Token constToken;
    private final BType btype;
    private final List<ConstDef> constDef;
    private final List<Token> commaToken;
    private final Token semicnToken;

    public ConstDecl(Token constToken, BType btype, List<ConstDef> constDef, List<Token> commaToken, Token semicnToken) {
        this.constToken = constToken;
        this.btype = btype;
        this.constDef = constDef;
        this.commaToken = commaToken;
        this.semicnToken = semicnToken;
    }

    public Token getConstToken() {
        return constToken;
    }

    public BType getBtype() {
        return btype;
    }

    public List<ConstDef> getConstDef() {
        return constDef;
    }

    public List<Token> getCommaToken() {
        return commaToken;
    }

    public Token getSemicnToken() {
        return semicnToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(constToken.toString());
        sb.append(btype.toString());
        sb.append(constDef.get(0).toString());
        for (int i = 1; i < constDef.size(); i++) {
            sb.append(commaToken.get(i - 1).toString());
            sb.append(constDef.get(i).toString());
        }
        sb.append(semicnToken.toString());
        sb.append("<ConstDecl>\n");
        return sb.toString();
    }
}
