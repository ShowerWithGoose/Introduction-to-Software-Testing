package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class StmtExp implements Statement {
    private Exp exp;
    private Token semi;
    private String errorLog = "";

    public StmtExp(Exp exp, Token semi) {
        this.exp = exp;
        this.semi = semi;
        if (semi == null) {
            errorLog = exp.getLineno() + " i\n";
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.getOutPut());
        if (semi != null) {
            sb.append(semi.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        return exp.getError() + errorLog;
    }
}
