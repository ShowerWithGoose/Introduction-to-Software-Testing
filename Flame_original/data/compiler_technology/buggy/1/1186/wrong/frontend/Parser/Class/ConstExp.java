package frontend.Parser.Class;

import java.util.ArrayList;

public class ConstExp {
    private AddExp addExp;

    public ConstExp(AddExp addExp, ArrayList<String> outputList) {
        this.addExp = addExp;
        outputList.add("<ConstExp>");
    }
}
