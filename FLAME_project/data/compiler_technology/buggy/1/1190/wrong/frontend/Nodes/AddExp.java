package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class AddExp implements Node {
    private List<MulExp> mulExpList;
    private List<Token> opList;

    public AddExp() {
        this.mulExpList = new ArrayList<>();
        this.opList = new ArrayList<>();
    }

    public void addMulExp(MulExp mulExp) {
        mulExpList.add(mulExp);
    }

    public void addOp(Token op) {
        opList.add(op);
    }

    public MulExp getMulExp() {
        return mulExpList.get(0);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(mulExpList.get(0).error());
        for (int i = 0; i < opList.size(); i++) {
            sb.append(opList.get(i).error());
            sb.append(mulExpList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(mulExpList.get(0).toString());
        for (int i = 0; i < opList.size(); i++) {
            sb.append("<AddExp>\n");
            sb.append(opList.get(i).toString());
            sb.append(mulExpList.get(i + 1).toString());
        }
        sb.append("<AddExp>\n");
        return sb.toString();
    }
}
