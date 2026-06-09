package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

public class ForStmt {
    private String nodeName;
    private LVal lVal;
    private Token assignToken;
    private Exp exp;

    public ForStmt(String nodeName, LVal lVal, Token assignToken, Exp exp) {
        this.nodeName = nodeName;
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.exp = exp;
    }

    public void print() throws IOException {
        lVal.print();
        writeParser(assignToken.toString());
        exp.print();
        writeParser(nodeName);
    }
}
