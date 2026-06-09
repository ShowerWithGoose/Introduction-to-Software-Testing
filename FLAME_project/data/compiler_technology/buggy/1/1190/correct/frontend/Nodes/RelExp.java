package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class RelExp implements Node {
    private List<AddExp> addExpList;
    private List<Token> opList;

    public RelExp() {
        this.addExpList = new ArrayList<>();
        this.opList = new ArrayList<>();
    }

    public void addAddExp(AddExp addExp) {
        addExpList.add(addExp);
    }

    public void addOp(Token op) {
        opList.add(op);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExpList.get(0).error());
        for (int i = 0; i < opList.size(); i++) {
            sb.append(opList.get(i).error());
            sb.append(addExpList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExpList.get(0).toString());
        for (int i = 0; i < opList.size(); i++) {
            sb.append("<RelExp>\n");
            sb.append(opList.get(i).toString());
            sb.append(addExpList.get(i + 1).toString());
        }
        sb.append("<RelExp>\n");
        return sb.toString();
    }
}
