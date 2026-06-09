package frontend.parser.function;

import frontend.lexer.Token;

import java.util.ArrayList;

public class FuncFParams {
    private final String name = "<FuncFParams>";
    private FuncFParam first;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> params;

    public FuncFParams(FuncFParam first, ArrayList<Token> commas, ArrayList<FuncFParam> params) {
        this.first = first;
        this.commas = commas;
        this.params = params;
    }

    public FuncFParams(FuncFParam first) {
        this.first = first;
        this.commas = null;
        this.params = null;
    }

    public int getLineno() {
        if (commas != null) {
            return params.get(params.size() - 1).getLineno();
        } else {
            return first.getLineno();
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.getOutPut());
        if (commas != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).getOutPut());
                sb.append(params.get(i).getOutPut());
            }
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError(){
        StringBuilder sb = new StringBuilder();
        sb.append(first.getError());
        for (FuncFParam param : params) {
            sb.append(param.getError());
        }
        return sb.toString();
    }
}
