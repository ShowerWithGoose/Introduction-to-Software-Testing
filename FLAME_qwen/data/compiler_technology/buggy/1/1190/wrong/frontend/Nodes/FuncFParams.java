package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class FuncFParams implements Node {
    private List<FuncFParam> funcFParamList;
    private List<Token> commaList;

    public FuncFParams() {
        this.funcFParamList = new ArrayList<>();
        this.commaList = new ArrayList<>();
    }

    public void addFuncFParam(FuncFParam funcFParam) {
        funcFParamList.add(funcFParam);
    }

    public void addComma(Token comma) {
        commaList.add(comma);
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcFParamList.get(0).error());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).error());
            sb.append(funcFParamList.get(i + 1).error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcFParamList.get(0).toString());
        for (int i = 0; i < commaList.size(); i++) {
            sb.append(commaList.get(i).toString());
            sb.append(funcFParamList.get(i + 1).toString());
        }
        sb.append("<FuncFParams>\n");
        return sb.toString();
    }
}
