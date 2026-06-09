package frontend.parser.ast.block;

import frontend.lexer.Token;

public class StmtBreak implements Statement {
    private Token breakToken;
    private Token semicolon;
    private String error;

    public StmtBreak(Token breakToken, Token semicolon) {   
        this.breakToken = breakToken;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            this.error = breakToken.getLineno() + " i\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(breakToken.getOutput());
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }
        return out.toString();
    }

    public String getError() {
        return error;
    }

}
