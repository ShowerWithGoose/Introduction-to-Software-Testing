package parser_part.function;

import lexer_part.Token;
import parser_part.Node;

import java.util.ArrayList;

public class FuncFParams implements Node {
    private FuncFParam funcFParam;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> funcFParams;

    private boolean isPredeclared;

    public FuncFParams(FuncFParam funcFParam, ArrayList<Token> commas, ArrayList<FuncFParam> funcFParams) {
        this.funcFParam = funcFParam;
        this.commas = commas;
        this.funcFParams = funcFParams;
        isPredeclared = false;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(funcFParam.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i));
            sb.append(funcFParams.get(i));
        }
        sb.append("<FuncFParams>\n");
        return sb.toString();
    }
}
