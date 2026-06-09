package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class ConstDecl implements Node {
    private Token constToken;
    private BType bType;
    private List<ConstDef> constDefList;
    private List<Token> commaList;
    private Token semicn;

    public ConstDecl() {
        this.constDefList = new ArrayList<>();
        this.commaList = new ArrayList<>();
        this.bType = null;
        this.constToken = null;
        this.semicn = null;
    }

    public void addConstToken(Token constToken) {
        this.constToken = constToken;
    }

    public void addBType(BType bType) {
        this.bType = bType;
    }

    public void addConstDef(ConstDef constDef) {
        this.constDefList.add(constDef);
    }

    public void addComma(Token comma) {
        this.commaList.add(comma);
    }

    public void addSemicn(Token semicn) {
        this.semicn = semicn;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(constToken.error());
        sb.append(bType.error());
        sb.append(constDefList.get(0).error());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).error());
            sb.append(constDefList.get(i + 1).error());
        }
        sb.append(semicn.error());
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(constToken.toString());
        sb.append(bType.toString());
        sb.append(constDefList.get(0).toString());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).toString());
            sb.append(constDefList.get(i + 1).toString());
        }
        sb.append(semicn.toString());
        sb.append("<ConstDecl>\n");
        return sb.toString();
    }
}
