package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class LAndExp implements Node {
    private List<EqExp> eqExpList;
    private List<Token> opList;

    public LAndExp() {
        this.eqExpList = new ArrayList<>();
        this.opList = new ArrayList<>();
    }

    public void addEqExp(EqExp eqExp) {
        eqExpList.add(eqExp);
    }

    public void addOp(Token op) {
        opList.add(op);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(eqExpList.get(0).error());
        for (int i = 0; i < opList.size(); i++) {
            sb.append(opList.get(i).error());
            sb.append(eqExpList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(eqExpList.get(0).toString());
        for (int i = 0; i < opList.size(); i++) {
            sb.append("<LAndExp>\n");
            sb.append(opList.get(i).toString());
            sb.append(eqExpList.get(i + 1).toString());
        }
        sb.append("<LAndExp>\n");
        return sb.toString();
    }
}
