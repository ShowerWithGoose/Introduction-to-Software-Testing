package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// LAndExp â†’ EqExp | LAndExp '&&' EqExp
public class LAndExp {

    private static final String name = "<LAndExp>";

    private ArrayList<EqExp> eqExpList;

    private ArrayList<Token> operatorList;

    public LAndExp(ArrayList<EqExp> eqExpList, ArrayList<Token> operatorList) {
        this.eqExpList = eqExpList;
        this.operatorList = operatorList;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(eqExpList.get(0));
        for (int i = 0; i < eqExpList.size() - 1; i++) {
            out.append(name).append("\n");
            out.append(operatorList.get(i));
            out.append(eqExpList.get(i + 1));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public ArrayList<EqExp> getEqExpList() {
        return eqExpList;
    }

    public ArrayList<Token> getOperatorList() {
        return operatorList;
    }

    public void setEqExpList(ArrayList<EqExp> eqExpList) {
        this.eqExpList = eqExpList;
    }

    public void setOperatorList(ArrayList<Token> operatorList) {
        this.operatorList = operatorList;
    }
}
