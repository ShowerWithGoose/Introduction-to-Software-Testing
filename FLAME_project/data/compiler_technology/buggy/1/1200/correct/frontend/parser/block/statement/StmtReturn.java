package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class StmtReturn implements Statement {
    private Token returnTk;
    private Exp exp = null;
    private Token semi;
    private String errorLog = "";

    public StmtReturn(Token returnTk, Exp exp, Token semi) {
        this.returnTk = returnTk;
        this.exp = exp;
        this.semi = semi;
        if (semi == null) {
            if (exp != null) {
                errorLog = exp.getLineno() + " i\n";
            } else {
                errorLog = returnTk.getLineno() + " i\n";
            }
        }
    }

    public StmtReturn(Token returnTk,Token semi) {
        this.returnTk = returnTk;
        this.semi = semi;
        if (semi == null) {
            errorLog = returnTk.getLineno() + " i\n";
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(returnTk.getOutPut());
        if (exp != null) {
            sb.append(exp.getOutPut());
        }
        if (semi != null) {
            sb.append(semi.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        if (exp != null) {
            return exp.getError() + errorLog;
        } else {
            return errorLog;
        }
    }
}
