package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class EqExp implements Node {
    private List<RelExp> relExpList;
    private List<Token> opList;

    public EqExp() {
        this.relExpList = new ArrayList<>();
        this.opList = new ArrayList<>();
    }

    public void addRelExp(RelExp relExp) {
        relExpList.add(relExp);
    }

    public void addOp(Token op) {
        opList.add(op);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(relExpList.get(0).error());
        for (int i = 0; i < opList.size(); i++) {
            sb.append(opList.get(i).error());
            sb.append(relExpList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(relExpList.get(0).toString());
        for (int i = 0; i < opList.size(); i++) {
            sb.append("<EqExp>\n");
            sb.append(opList.get(i).toString());
            sb.append(relExpList.get(i + 1).toString());
        }
        sb.append("<EqExp>\n");
        return sb.toString();
    }
}
