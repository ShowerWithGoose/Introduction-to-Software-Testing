package frontend.Parser.Class;

import java.util.ArrayList;

public class FuncFParams {
    private ArrayList<FuncFParam> funcFParams;
    public FuncFParams(ArrayList<FuncFParam> funcFParams,ArrayList<String> outputList) {
        this.funcFParams = funcFParams;
        outputList.add("<FuncFParams>");
    }
}
