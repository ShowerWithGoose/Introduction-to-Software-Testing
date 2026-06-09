package frontend.parser.ast.exp;

import frontend.lexer.Token;

import java.util.ArrayList;

public class LAndExp {
    private String type = "<LAndExp>";
    private EqExp firstExp;
    private ArrayList<Token> operators;
    private ArrayList<EqExp> exps;

    public LAndExp(EqExp firstExp, ArrayList<Token> operators, ArrayList<EqExp> exps) {
        this.firstExp = firstExp;
        this.operators = operators;
        this.exps = exps;
    }

    public int getLineno() {
        if (exps != null && !exps.isEmpty()) {
            return exps.get(exps.size() - 1).getLineno();
        } else {
            return firstExp.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(firstExp.getOutput());
        for (int i = 0; i < exps.size(); i++) {
            out.append(type + "\n");
            out.append(operators.get(i).getOutput());
            out.append(exps.get(i).getOutput());
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(firstExp.getError());
        for (int i = 0; i < operators.size(); i++) {
            if (operators.get(i).getContent().equals("&")) {
                out.append(operators.get(i).getLineno() + " a\n");
            }
            out.append(exps.get(i).getError());
        }
        return out.toString();
    }
}
