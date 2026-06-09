package frontend.parser.ast.block;

import frontend.lexer.Token;
import frontend.parser.ast.exp.Exp;

public class StmtReturn implements Statement {
    private Token returnToken;
    private Exp exp;
    private Token semicolon;
    private String error;

    public StmtReturn(Token returnToken, Exp exp, Token semicolon) {
        this.returnToken = returnToken;
        this.exp = exp;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            if (exp != null) {
                this.error = exp.getLineno() + " i\n";
            } else {
                this.error = returnToken.getLineno() + " i\n";
            }
        }
    }

    public StmtReturn(Token returnToken, Token semicolon) {
        this.returnToken = returnToken;
        this.exp = null;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            this.error = returnToken.getLineno() + " i\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(returnToken.getOutput());
        if (exp != null) {
            out.append(exp.getOutput());
        }
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (exp != null) {
            out.append(exp.getError());
        }
        out.append(error);

        return out.toString();
    }
}
