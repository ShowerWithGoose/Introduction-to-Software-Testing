package struct;

import token.Token;

import java.util.List;

/* VarDecl â†’ BType VarDef { ',' VarDef } ';' */
public class VarDecl {
    private final BType bType;
    private final List<VarDef> varDef;
    private final List<Token> commaToken;
    private final Token semicnToken;

    public VarDecl(BType bType, List<VarDef> varDef, List<Token> commaToken, Token semicnToken) {
        this.bType = bType;
        this.varDef = varDef;
        this.commaToken = commaToken;
        this.semicnToken = semicnToken;
    }

    public BType getBType() {
        return bType;
    }

    public List<VarDef> getVarDef() {
        return varDef;
    }

    public List<Token> getCommaToken() {
        return commaToken;
    }

    public Token getSemicnToken() {
        return semicnToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.toString());
        sb.append(varDef.get(0).toString());
        for (int i = 1; i < varDef.size(); i++) {
            sb.append(commaToken.get(i - 1).toString());
            sb.append(varDef.get(i).toString());
        }
        sb.append(semicnToken.toString());
        sb.append("<VarDecl>\n");
        return sb.toString();
    }
}
