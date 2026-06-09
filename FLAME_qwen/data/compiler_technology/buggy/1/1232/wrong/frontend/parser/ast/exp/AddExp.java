package frontend.parser.ast.exp;

import frontend.lexer.Token;

import java.util.ArrayList;

public class AddExp {
    private String type = "<AddExp>";
    private MulExp first;
    private ArrayList<Token> operators;
    private ArrayList<MulExp> exps;

    public AddExp(MulExp first, ArrayList<Token> operators, ArrayList<MulExp> exps) {
        this.first = first;
        this.operators = operators;
        this.exps = exps;
    }

    public int getLineno() {
        if (exps != null && !exps.isEmpty()){
            return exps.get(exps.size() - 1).getLineno();
        } else {
            return first.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(first.getOutput());
        for (int i = 0; i < operators.size(); ++i) {
            out.append(type + "\n");
            out.append(operators.get(i).getOutput());
            out.append(exps.get(i).getOutput());
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(first.getError());
        for (MulExp exp : exps) {
            out.append(exp.getError());
        }
        return out.toString();
    }

}
