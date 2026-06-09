package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.block.LVal;

public class StmtGetChar implements Statement {
    private LVal lVal;
    private Token eq;
    private Token getCharTk;
    private Token lParent;
    private Token rParent;
    private Token semi;
    private String errorLog = "";

    public StmtGetChar(LVal lVal, Token eq, Token getCharTk,
                      Token lParent, Token rParent, Token semi) {
        this.lVal = lVal;
        this.eq = eq;
        this.getCharTk = getCharTk;
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
        sb.append(getCharTk.getOutPut());
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
