package frontend.parser.ast.exp;

import frontend.lexer.Token;

import java.util.ArrayList;

public class FuncRParams {
    private String type = "<FuncRParams>";
    private Exp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;

    public FuncRParams(Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = exps;
    }

    public FuncRParams(Exp firstExp) {
        this.firstExp = firstExp;
        this.commas = null;
        this.exps = null;
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
        if (exps!= null && !exps.isEmpty()) {
            for (int i = 0; i < exps.size(); ++i) {
                out.append(commas.get(i).getOutput());
                out.append(exps.get(i).getOutput());
            }
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(firstExp.getError());
        if (exps!= null && !exps.isEmpty()) {
            for (int i = 0; i < exps.size(); ++i) {
                out.append(exps.get(i).getError());
            }
        }

        return out.toString();
    }

}
