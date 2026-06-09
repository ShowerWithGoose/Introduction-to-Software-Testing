package frontend.parser.ast.block;

import frontend.lexer.Token;
import frontend.parser.ast.exp.Exp;

public class StmtExp implements Statement {
    private Exp exp;
    private Token semicolon;
    private String error;

    public StmtExp(Exp exp, Token semicolon) {
        this.exp = exp;
        this.semicolon = semicolon;
        this.error = "";
        if (semicolon == null) {
            this.error = exp.getLineno() + " i\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(exp.getOutput());
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }
        return out.toString();
    }

    public String getError() {
        return exp.getError() + error;
    }
}
