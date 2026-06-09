package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.block.LVal;
import frontend.parser.expression.Exp;

public class StmtAssign implements Statement {
    private LVal lVal;
    private Token eq;
    private Exp exp;
    private Token semi;
    private String errorLog = "";

    public StmtAssign(LVal lVal, Token eq, Exp exp, Token semi) {
        this.lVal = lVal;
        this.eq = eq;
        this.exp = exp;
        this.semi = semi;
        if (semi == null) {
            this.errorLog = exp.getLineno() + " i\n";
        }
    }

    @Override
    public String getOutPut() {
         StringBuilder sb = new StringBuilder();
         sb.append(lVal.getOutPut());
         sb.append(eq.getOutPut());
         sb.append(exp.getOutPut());
         if (semi != null) {
             sb.append(semi.getOutPut());
         }
         return sb.toString();
    }

    @Override
    public String getError() {
        return lVal.getError() + exp.getError() + errorLog;
    }
}
