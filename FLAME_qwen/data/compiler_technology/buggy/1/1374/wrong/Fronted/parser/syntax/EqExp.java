package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
public class EqExp {

    private static final String name = "<EqExp>";

    private ArrayList<RelExp> relExpList;

    private ArrayList<Token> operatorList;

    public EqExp(ArrayList<RelExp> relExpList, ArrayList<Token> operatorList) {
        this.relExpList = relExpList;
        this.operatorList = operatorList;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(relExpList.get(0));
        for (int i = 0; i < relExpList.size() - 1; i++) {
            out.append(name).append("\n");
            out.append(operatorList.get(i));
            out.append(relExpList.get(i + 1));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public ArrayList<RelExp> getRelExpList() {
        return relExpList;
    }

    public ArrayList<Token> getOperatorList() {
        return operatorList;
    }

    public void setRelExpList(ArrayList<RelExp> relExpList) {
        this.relExpList = relExpList;
    }

    public void setOperatorList(ArrayList<Token> operatorList) {
        this.operatorList = operatorList;
    }
}
