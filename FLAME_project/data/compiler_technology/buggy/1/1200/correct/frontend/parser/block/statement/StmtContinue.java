package frontend.parser.block.statement;

import frontend.lexer.Token;

public class StmtContinue implements Statement {
    private Token continueTk;
    private Token semi;
    private String errorLog = "";

    public StmtContinue(Token continueTk, Token semi) {
        this.continueTk = continueTk;
        this.semi = semi;
        if (semi == null) {
            errorLog = continueTk.getLineno() + " i\n";
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(continueTk.getOutPut());
        if (semi != null) {
            sb.append(semi.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        return errorLog;
    }
}
