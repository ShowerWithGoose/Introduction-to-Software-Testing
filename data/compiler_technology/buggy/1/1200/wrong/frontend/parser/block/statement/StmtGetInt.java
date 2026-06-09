package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.block.LVal;

public class StmtGetInt implements Statement {
    private LVal lVal;
    private Token eq;
    private Token getIntTk;
    private Token lParent;
    private Token rParent;
    private Token semi;
    private String errorLog = "";

    public StmtGetInt(LVal lVal, Token eq, Token getIntTk,
                      Token lParent, Token rParent, Token semi) {
        this.lVal = lVal;
        this.eq = eq;
        this.getIntTk = getIntTk;
        this.lParent = lParent;
        this.rParent = rParent;
        this.semi = semi;
        if (rParent == null) {
            errorLog += lParent.getLineno() + " j\n";
        }
        if (semi == null) {
            if (rParent == null) {
                errorLog += lParent.getLineno() + " i\n";
            } else {
                errorLog += rParent.getLineno() + " i\n";
            }
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.getOutPut());
        sb.append(eq.getOutPut());
        sb.append(getIntTk.getOutPut());
        sb.append(lParent.getOutPut());
        if (rParent != null) {
            sb.append(rParent.getOutPut());
        }
        if (semi != null) {
            sb.append(semi.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        return lVal.getError() + errorLog;
    }
}
