package frontend.parser.ast.block;

import frontend.lexer.Token;
import frontend.parser.ast.exp.Exp;
import frontend.parser.ast.exp.LVal;

public class StmtLVal implements Statement {
    private LVal lVal;
    private Token eql;
    private Exp exp;
    private Token semicolon;
    private String error;

    public StmtLVal(LVal lVal, Token eql, Exp exp, Token semicolon) {
        this.lVal = lVal;
        this.eql = eql;
        this.exp = exp;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            this.error = exp.getLineno() + " i\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(lVal.getOutput());
        out.append(eql.getOutput());
        out.append(exp.getOutput());
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(lVal.getError());
        out.append(exp.getError());
        out.append(error);

        return out.toString();
    }


}

