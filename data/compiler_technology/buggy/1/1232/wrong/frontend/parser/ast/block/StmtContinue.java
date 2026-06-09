package frontend.parser.ast.block;

import frontend.lexer.Token;

public class StmtContinue implements Statement {
    private Token continueToken;
    private Token semicolon;
    private String error;

    public StmtContinue(Token continueToken, Token semicolon) {   
        this.continueToken = continueToken;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            this.error = continueToken.getLineno() + " i\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(continueToken.getOutput());
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }
        return out.toString();
    }

    public String getError() {
        return error;
    }

}
