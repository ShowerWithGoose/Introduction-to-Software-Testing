package frontend.parser.ast.exp;

import frontend.lexer.Token;

import java.util.ArrayList;

public class EqExp {
    private String type = "<EqExp>";
    private RelExp firstExp;
    private ArrayList<Token> operators;
    private ArrayList<RelExp> exps;

    public EqExp(RelExp first, ArrayList<Token> operators, ArrayList<RelExp> exps) {
        this.firstExp = first;
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
        for (RelExp exp : exps) {
            out.append(exp.getError());
        }
        return out.toString();
    }
}
