package frontend.parser.expression;

import frontend.lexer.Token;

import java.util.ArrayList;

public class RelExp {
    private final String name = "<RelExp>";
    private AddExp first;
    private ArrayList<Token> operators;
    private ArrayList<AddExp> exps;

    public RelExp(AddExp first, ArrayList<Token> operators, ArrayList<AddExp> exps) {
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
        for (AddExp exp : exps) {
            sb.append(exp.getError());
        }
        return sb.toString();
    }
}
