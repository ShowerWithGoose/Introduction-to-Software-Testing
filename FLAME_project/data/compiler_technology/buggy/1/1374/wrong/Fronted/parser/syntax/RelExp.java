package Fronted.parser.syntax;

import Fronted.lexer.Token;
import java.util.ArrayList;

// RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
public class RelExp {

    private static final String name = "<RelExp>";

    private ArrayList<AddExp> addExpList;

    private ArrayList<Token> operatorList;

    public RelExp(ArrayList<AddExp> addExpList, ArrayList<Token> operatorList) {
        this.addExpList = addExpList;
        this.operatorList = operatorList;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(addExpList.get(0));
        for (int i = 0; i < addExpList.size() - 1; i++) {
            out.append(name).append("\n");
            out.append(operatorList.get(i));
            out.append(addExpList.get(i + 1));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public ArrayList<AddExp> getAddExpList() {
        return addExpList;
    }

    public ArrayList<Token> getOperatorList() {
        return operatorList;
    }

    public void setOperatorList(ArrayList<Token> operatorList) {
        this.operatorList = operatorList;
    }

    public void setAddExpList(ArrayList<AddExp> addExpList) {
        this.addExpList = addExpList;
    }
}
