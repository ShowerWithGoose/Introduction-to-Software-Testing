package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class VarDecl implements Node {
    private BType bType;
    private List<VarDef> varDefList;
    private List<Token> commaList;
    private Token semicn;

    public VarDecl() {
        this.varDefList = new ArrayList<>();
        this.commaList = new ArrayList<>();
        this.semicn = null;
        this.bType = null;
    }

    public void addBType(BType bType) {
        this.bType = bType;
    }

    public void addVarDef(VarDef varDef) {
        this.varDefList.add(varDef);
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
        sb.append(bType.error());
        sb.append(varDefList.get(0).error());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).error());
            sb.append(varDefList.get(i + 1).error());
        }
        sb.append(semicn.error());
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.toString());
        sb.append(varDefList.get(0).toString());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).toString());
            sb.append(varDefList.get(i + 1).toString());
        }
        sb.append(semicn.toString());
        sb.append("<VarDecl>\n");
        return sb.toString();
    }
}
