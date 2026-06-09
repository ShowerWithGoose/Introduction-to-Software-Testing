package frontend.Parser.Class;

import java.util.ArrayList;

public class LVal {
    private String ident;
    private Exp exp;

    public LVal(String ident, Exp exp, ArrayList<String> outputList) {
        this.ident = ident;
        this.exp = exp;
        outputList.add("<LVal>");
    }

    public LVal(String ident, ArrayList<String> outputList) {
        this.ident = ident;
        outputList.add("<LVal>");
    }

    public String getIdent() {
        return ident;
    }
}
