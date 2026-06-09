package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class FuncRParams implements Node {
    private List<Exp> expList;
    private List<Token> commaList;

    public FuncRParams() {
        this.expList = new ArrayList<>();
        this.commaList = new ArrayList<>();
    }

    public void addExp(Exp exp) {
        this.expList.add(exp);
    }

    public void addComma(Token comma) {
        this.commaList.add(comma);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(expList.get(0).error());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).error());
            sb.append(expList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(expList.get(0).toString());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).toString());
            sb.append(expList.get(i + 1).toString());
        }
        sb.append("<FuncRParams>\n");
        return sb.toString();
    }
}
