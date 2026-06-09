package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// MulExp â†’ UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
public class MulExp {

    private static final String name = "<MulExp>";

    private ArrayList<UnaryExp> unaryExpList;

    private ArrayList<Token> operatorList;

    public MulExp(ArrayList<UnaryExp> unaryExpList, ArrayList<Token> operatorList) {
        this.unaryExpList = unaryExpList;
        this.operatorList = operatorList;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(unaryExpList.get(0));
        for (int i = 0; i < unaryExpList.size() - 1; i++) {
            out.append(name).append("\n");
            out.append(operatorList.get(i));
            out.append(unaryExpList.get(i + 1));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public ArrayList<UnaryExp> getUnaryExpList() {
        return unaryExpList;
    }

    public ArrayList<Token> getOperatorList() {
        return operatorList;
    }

    public void setOperatorList(ArrayList<Token> operatorList) {
        this.operatorList = operatorList;
    }

    public void setUnaryExpList(ArrayList<UnaryExp> unaryExpList) {
        this.unaryExpList = unaryExpList;
    }
}
