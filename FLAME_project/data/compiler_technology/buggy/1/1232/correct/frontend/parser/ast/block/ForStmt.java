package frontend.parser.ast.block;

import frontend.lexer.Token;
import frontend.parser.ast.exp.Exp;
import frontend.parser.ast.exp.LVal;

public class ForStmt {
    private String type = "<ForStmt>";
    private LVal lVal;
    private Token eql;
    private Exp exp;

    public ForStmt(LVal lVal, Token eql, Exp exp) {
        this.lVal = lVal;
        this.eql = eql;
        this.exp = exp;
    }

    public int getLineno() {
        return exp.getLineno();
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(lVal.getOutput());
        out.append(eql.getOutput());
        out.append(exp.getOutput());
        out.append(type + "\n");
        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(lVal.getError());
        out.append(exp.getError());
        return out.toString();
    }

}
