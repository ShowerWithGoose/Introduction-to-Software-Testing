package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// FuncFParams â†’ FuncFParam { ',' FuncFParam }
public class FuncFParams {

    private static final String name = "<FuncFParams>";

    private ArrayList<FuncFParam> funcFParamList;

    private ArrayList<Token> commaList;

    public FuncFParams(ArrayList<FuncFParam> funcFParamList, ArrayList<Token> commaList) {
        this.funcFParamList = funcFParamList;
        this.commaList = commaList;
    }

    public String toString() {
        StringBuilder out = new StringBuilder();
        for(int i = 0; i < funcFParamList.size(); i++){
            if(i > 0) out.append(commaList.get(i-1));
            out.append(funcFParamList.get(i));
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public ArrayList<FuncFParam> getFuncFParamList() {
        return funcFParamList;
    }

    public ArrayList<Token> getCommaList() {
        return commaList;
    }

    public void setFuncFParamList(ArrayList<FuncFParam> funcFParamList) {
        this.funcFParamList = funcFParamList;
    }

    public void setCommaList(ArrayList<Token> commaList) {
        this.commaList = commaList;
    }
}
