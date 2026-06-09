package frontend.Parser.Class;

import java.util.ArrayList;

public class Exp {
    private AddExp addExp;
    public Exp(AddExp addExp, ArrayList<String> outputList){
        this.addExp= addExp;
        outputList.add("<Exp>");
    }
}
