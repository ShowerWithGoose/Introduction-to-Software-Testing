package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// AddExp → MulExp | AddExp ('+' | '−') MulExp
public class AddExp {

    private static final String name = "<AddExp>";

    private ArrayList<MulExp> mulExpList;

    private ArrayList<Token> operatorList;

    public AddExp(ArrayList<MulExp> mulExpList, ArrayList<Token> operatorList) {
        this.mulExpList = mulExpList;
        this.operatorList = operatorList;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(mulExpList.get(0));
        for (int i = 0; i < mulExpList.size() - 1; i++) {
            out.append(name).append("\n");
            out.append(operatorList.get(i));
            out.append(mulExpList.get(i + 1));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public ArrayList<MulExp> getMulExpList() {
        return mulExpList;
    }

    public ArrayList<Token> getOperatorList() {
        return operatorList;
    }

    public void setOperatorList(ArrayList<Token> operatorList) {
        this.operatorList = operatorList;
    }
}
