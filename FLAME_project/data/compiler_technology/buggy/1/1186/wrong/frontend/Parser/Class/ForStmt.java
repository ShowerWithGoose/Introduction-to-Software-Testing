package frontend.Parser.Class;

import java.util.ArrayList;

public class ForStmt {
    private LVal lVal;
    private Exp exp;
    public ForStmt(LVal lVal, Exp exp, ArrayList<String> outputList){
        this.lVal = lVal;
        this.exp = exp;
        outputList.add("<ForStmt>");
    }
}
