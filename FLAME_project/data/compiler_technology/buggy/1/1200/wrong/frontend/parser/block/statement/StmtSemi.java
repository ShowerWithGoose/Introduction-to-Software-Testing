package frontend.parser.block.statement;

import frontend.lexer.Token;

public class StmtSemi implements Statement {
    private Token semi;

    public StmtSemi(Token semi) {
        this.semi = semi;
    }

    @Override
    public String getOutPut() {
        return semi.getOutPut();
    }

    @Override
    public String getError() {
        return "";
    }
}
