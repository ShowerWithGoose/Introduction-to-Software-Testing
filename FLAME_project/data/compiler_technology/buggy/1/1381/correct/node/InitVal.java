package node;

import frontend.Parser;

import java.util.ArrayList;

public class InitVal {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.InitVal;
    private Exp exp;
    private String stringConst;
    private ArrayList<Exp> initList;

    public InitVal(Exp exp) {
        this.exp = exp;
        this.stringConst = null;
        this.initList = null;
    }

    public InitVal(ArrayList<Exp> initList) {
        this.exp = null;
        this.stringConst = null;
        this.initList = initList;
    }

    public InitVal(String stringConst) {
        this.exp = null;
        this.stringConst = stringConst;
        this.initList = null;
    }

    public Exp getExp() {
        return exp;
    }

    public String getStringConst() {
        return stringConst;
    }

    public ArrayList<Exp> getInitList() {
        return initList;
    }

    public boolean isExp() {
        return exp != null;
    }

    public boolean isStringConst() {
        return stringConst != null;
    }

    public boolean isInitList() {
        return initList != null;
    }


    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (isExp()) {
            ret.append("\n").append(exp);
        } else if (isStringConst()) {
            ret.append("\n").append(stringConst);
        } else if (isInitList()) {
            for (Exp exp : initList) {
                ret.append("\n").append(exp);
            }
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
