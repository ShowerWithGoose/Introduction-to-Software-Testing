package frontend.parser.expression;

import frontend.lexer.Token;

import java.util.ArrayList;

public class LOrExp {
    private final String name = "<LOrExp>";
    private LAndExp first;
    private ArrayList<Token> operators;
    private ArrayList<LAndExp> exps;

    public LOrExp(LAndExp first, ArrayList<Token> operators, ArrayList<LAndExp> exps) {
        this.first = first;
        this.operators = operators;
        this.exps = exps;
    }

    public int getLineno() {
        if (exps != null) {
            return exps.get(exps.size() - 1).getLineno();
        } else {
            return first.getLineno();
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.getOutPut());
        for (int i = 0; i < operators.size(); i++) {
            sb.append(operators.get(i).getOutPut());
            sb.append(exps.get(i).getOutPut());
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.getError());
        for (int i = 0; i < operators.size(); i++) {
            if (operators.get(i).getContent().equals("|")) {
                sb.append(operators.get(i).getLineno());
                sb.append(" a\n");
            }
            sb.append(exps.get(i).getError());
        }
        return sb.toString();
    }
}
