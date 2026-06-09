package frontend.parser.block.statement;

import frontend.lexer.Token;

public class StmtBreak implements Statement {
    private Token breakTk;
    private Token semi;
    private String errorLog = "";

    public StmtBreak(Token breakTk, Token semi) {
        this.breakTk = breakTk;
        this.semi = semi;
        if (semi == null) {
            errorLog = breakTk.getLineno() + " i\n";
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(breakTk.getOutPut());
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
