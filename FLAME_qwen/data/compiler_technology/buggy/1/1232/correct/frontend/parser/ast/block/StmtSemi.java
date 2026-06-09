package frontend.parser.ast.block;

import frontend.lexer.Token;

public class StmtSemi implements Statement {
    private Token semicolon;

    public StmtSemi(Token semicolon) {
        this.semicolon = semicolon;
    }

    public String getOutput() {
        return semicolon.getOutput();
    }

    public String getError() {
        return "";
    }
}
