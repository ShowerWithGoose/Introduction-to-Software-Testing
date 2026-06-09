package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class InitVal implements Node {
    private int type;
    private Exp exp;

    private Token lBrace;
    private List<Exp> expList;
    private List<Token> commaList;
    private Token rBrace;

    private Token stringConst;

    public InitVal() {
        this.expList = new ArrayList<>();
        this.commaList = new ArrayList<>();
        this.type = 0;
        this.exp = null;
        this.lBrace = null;
        this.rBrace = null;
        this.stringConst = null;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void addExp(Exp exp) {
        this.exp = exp;
    }

    public void addLBrace(Token lBrace) {
        this.lBrace = lBrace;
    }

    public void addExpList(Exp exp) {
        this.expList.add(exp);
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
                sb.append(exp.error());
                break;
            case 2:
                sb.append(lBrace.error());
                if (!expList.isEmpty()) {
                    sb.append(expList.get(0).error());
                    for (int i = 0; i < commaList.size(); i++) {
                        sb.append(commaList.get(i).error());
                        sb.append(expList.get(i + 1).error());
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
                sb.append(exp.toString());
                break;
            case 2:
                sb.append(lBrace.toString());
                if (!expList.isEmpty()) {
                    sb.append(expList.get(0).toString());
                    for (int i = 0; i < commaList.size(); i++) {
                        sb.append(commaList.get(i).toString());
                        sb.append(expList.get(i + 1).toString());
                    }
                }
                sb.append(rBrace.toString());
                break;
            case 3:
                sb.append(stringConst.toString());
                break;
        }
        sb.append("<InitVal>\n");
        return sb.toString();
    }
}
