package node;

import frontend.Token;

import java.util.ArrayList;

public class MyPrintfStmt extends Stmt {
    private String stringConst;
    private ArrayList<Exp> expList;

    public MyPrintfStmt(String stringConst, ArrayList<Exp> expList) {
        super(Token.TokenType.PRINTFTK);
        this.stringConst = stringConst;
        this.expList = expList;
    }

    public String getStringConst() {
        return stringConst;
    }

    public ArrayList<Exp> getExpList() {
        return expList;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + getNodeType() + ">");
        ret.append("\n").append(getType());
        ret.append("\n").append(stringConst);
        for (Exp exp : expList) ret.append("\n").append(exp);
        ret.append("\n<").append(getNodeType()).append("> <END>");
        return ret.toString();
    }
}
