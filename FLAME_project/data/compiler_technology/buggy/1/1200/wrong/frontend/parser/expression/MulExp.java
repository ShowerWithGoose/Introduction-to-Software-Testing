package frontend.parser.expression;

import frontend.lexer.Token;

import java.util.ArrayList;

public class MulExp {
    private final String name = "<MulExp>";
    private UnaryExp first;
    private ArrayList<Token> operators;
    private ArrayList<UnaryExp> exps;

    public MulExp(UnaryExp first, ArrayList<Token> operators, ArrayList<UnaryExp> exps) {
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
        for (UnaryExp exp : exps) {
            sb.append(exp.getError());
        }
        return sb.toString();
    }
}
