package frontend.parser.ast.decl;

import frontend.lexer.Token;

import java.util.ArrayList;

public class FuncFParams {
    private String type = "<FuncFParams>";
    private FuncFParam firstParam;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> params;

    public FuncFParams(FuncFParam firstParam, ArrayList<Token> commas, ArrayList<FuncFParam> params) {
        this.firstParam = firstParam;
        this.commas = commas;
        this.params = params;
    }

    public FuncFParams(FuncFParam firstParam) {
        this.firstParam = firstParam;
        this.commas = null;
        this.params = null;
    }

    public int getLineno() {
        if (params != null) {
            return params.get(params.size() - 1).getLineno();
        } else {
            return firstParam.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(firstParam.getOutput());
        if (params != null) {
            for (int i = 0; i < params.size(); ++i) {
                out.append(commas.get(i).getOutput());
                out.append(params.get(i).getOutput());
            }
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(firstParam.getError());
        if (params != null) {
            for (FuncFParam param : params) {
                out.append(param.getError());
            }
        }
        return out.toString();
    }

}
