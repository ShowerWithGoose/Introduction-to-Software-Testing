package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class ConstInitVal implements Node {
    private int type;
    private ConstExp constExp;

    private Token lBrace;
    private List<ConstExp> constExpList;
    private List<Token> commaList;
    private Token rBrace;

    private Token stringConst;

    public ConstInitVal() {
        this.constExpList = new ArrayList<>();
        this.commaList = new ArrayList<>();
        this.type = 0;
        this.constExp = null;
        this.lBrace = null;
        this.rBrace = null;
        this.stringConst = null;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void addConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void addLBrace(Token lBrace) {
        this.lBrace = lBrace;
    }

    public void addConstExpList(ConstExp constExp) {
        this.constExpList.add(constExp);
    }

    public void addCommaList(Token comma) {
        this.commaList.add(comma);
    }

    public void addRBrace(Token rBrace) {
        this.rBrace = rBrace;
    }

    public void addStringConst(Token stringConst) {
        this.stringConst = stringConst;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                sb.append(constExp.error());
                break;
            case 2:
                sb.append(lBrace.error());
                if (!constExpList.isEmpty()) {
                    sb.append(constExpList.get(0).error());
                    for (int i = 0; i < commaList.size(); i++) {
                        sb.append(commaList.get(i).error());
                        sb.append(constExpList.get(i + 1).error());
                    }
                }
                sb.append(rBrace.error());
                break;
            case 3:
                sb.append(stringConst.error());
                break;
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                sb.append(constExp.toString());
                break;
            case 2:
                sb.append(lBrace.toString());
                if (!constExpList.isEmpty()) {
                    sb.append(constExpList.get(0).toString());
                    for (int i = 0; i < commaList.size(); i++) {
                        sb.append(commaList.get(i).toString());
                        sb.append(constExpList.get(i + 1).toString());
                    }
                }
                sb.append(rBrace.toString());
                break;
            case 3:
                sb.append(stringConst.toString());
                break;
        }
        sb.append("<ConstInitVal>\n");
        return sb.toString();
    }
}
