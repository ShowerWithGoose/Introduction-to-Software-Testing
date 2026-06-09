package frontend.Parser.Class;

import java.util.ArrayList;

public class ConstInitVal {
    ConstExp constExp;
    ArrayList<ConstExp> constExps;
    String stringConst;
    public ConstInitVal(ConstExp constExp,ArrayList<String> outputList){
        this.constExp = constExp;
        outputList.add("<ConstInitVal>");
    }
    public ConstInitVal(ArrayList<ConstExp> constExps,ArrayList<String> outputList){
        this.constExps = constExps;
        outputList.add("<ConstInitVal>");
    }
    public ConstInitVal(String stringConst,ArrayList<String> outputList){
        this.stringConst = stringConst;
        outputList.add("<ConstInitVal>");
    }

    public ConstInitVal(ArrayList<String> outputList) {
        outputList.add("<ConstInitVal>");
    }
}
