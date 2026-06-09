package frontend.treenode;

import frontend.token.Token;
import java.io.IOException;
import static frontend.executor.Parser.writeParser;


public class ForStmt {
    public String nodeName;
    public LVal lVal;
    public Token assignToken;
    public Exp exp;

    public ForStmt(String nodeName, LVal lVal, Token assignToken, Exp exp) {
        this.nodeName = nodeName;
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.exp = exp;
    }

    public void print() throws IOException {
        lVal.print();
        writeParser(assignToken.getTypeAndContent());
        exp.print();
        writeParser(nodeName);
    }
}
