package frontend.parser.expression;

import frontend.lexer.Token;

import java.util.ArrayList;

public class FuncRParams {
    private final String name = "<FuncRParams>";
    private Exp firstExp;
    private ArrayList<Token> commas = null;
    private ArrayList<Exp> params = null;

    public FuncRParams(Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> params) {
        this.firstExp = firstExp;
        this.commas = commas;
        this.params = params;
    }

    public FuncRParams(Exp firstExp) {
        this.firstExp = firstExp;
    }

    public int getLineno() {
        if (commas != null && !commas.isEmpty()) {
            return params.get(params.size() - 1).getLineno();
        } else {
            return firstExp.getLineno();
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstExp.getOutPut());
        if (params != null && !params.isEmpty()) {
            for (int i = 0; i < params.size(); i++) {
                sb.append(commas.get(i).getOutPut());
                sb.append(params.get(i).getOutPut());
            }
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstExp.getError());
        if (params != null && !params.isEmpty()) {
            for (Exp exp : params) {
                sb.append(exp.getError());
            }
        }
        return sb.toString();
    }
}
