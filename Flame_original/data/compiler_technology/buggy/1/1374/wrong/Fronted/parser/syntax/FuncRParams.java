package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// FuncRParams â†’ Exp { ',' Exp }
public class FuncRParams {

    private static final String name = "<FuncRParams>";

    private ArrayList<Exp> expList = null;

    private ArrayList<Token> commaList = null;

    public FuncRParams(ArrayList<Exp> expList, ArrayList<Token> commaList) {
        this.expList = expList;
        this.commaList = commaList;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(expList.get(0));
        for (int i = 1; i < expList.size(); i++) {
            out.append(commaList.get(i - 1));
            out.append(expList.get(i));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public ArrayList<Exp> getExpList() {
        return expList;
    }

    public ArrayList<Token> getCommaList() {
        return commaList;
    }

    public void setExpList(ArrayList<Exp> expList) {
        this.expList = expList;
    }

    public void setCommaList(ArrayList<Token> commaList) {
        this.commaList = commaList;
    }
}
