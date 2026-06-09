package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class MulExp implements Node {
    private List<UnaryExp> unaryExpList;
    private List<Token> opList;

    public MulExp() {
        this.unaryExpList = new ArrayList<>();
        this.opList = new ArrayList<>();
    }

    public void addUnaryExp(UnaryExp unaryExp) {
        this.unaryExpList.add(unaryExp);
    }

    public void addOp(Token op) {
        this.opList.add(op);
    }

    public UnaryExp getUnaryExp() {
        return unaryExpList.get(0);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExpList.get(0).error());
        for (int i = 0; i < opList.size(); i++) {
            sb.append(opList.get(i).error());
            sb.append(unaryExpList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExpList.get(0).toString());
        for (int i = 0; i < opList.size(); i++) {
            sb.append("<MulExp>\n");
            sb.append(opList.get(i).toString());
            sb.append(unaryExpList.get(i + 1).toString());
        }
        sb.append("<MulExp>\n");
        return sb.toString();
    }
}
