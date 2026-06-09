package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class LOrExp implements Node {
    private List<LAndExp> lAndExpList;
    private List<Token> opList;

    public LOrExp() {
        this.lAndExpList = new ArrayList<>();
        this.opList = new ArrayList<>();
    }

    public void addLAndExp(LAndExp lAndExp) {
        lAndExpList.add(lAndExp);
    }

    public void addOp(Token op) {
        opList.add(op);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(lAndExpList.get(0).error());
        for (int i = 0; i < opList.size(); i++) {
            sb.append(opList.get(i).error());
            sb.append(lAndExpList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lAndExpList.get(0).toString());
        for (int i = 0; i < opList.size(); i++) {
            sb.append("<LOrExp>\n");
            sb.append(opList.get(i).toString());
            sb.append(lAndExpList.get(i + 1).toString());
        }
        sb.append("<LOrExp>\n");
        return sb.toString();
    }
}
