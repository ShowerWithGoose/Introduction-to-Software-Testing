package frontend.parser.ast.block;

import frontend.lexer.Token;

import frontend.parser.ast.exp.LVal;

public class StmtGetchar implements Statement {
    private LVal lVal;
    private Token eql;
    private Token getcharToken;
    private Token lParent;
    private Token rParent;
    private Token semicolon;
    private String error;

    public StmtGetchar(LVal lVal, Token eql, Token getcharToken, Token lParent, Token rParent, Token semicolon) {
        this.lVal = lVal;
        this.eql = eql;
        this.getcharToken = getcharToken;
        this.lParent = lParent;
        this.rParent = rParent;
        this.semicolon = semicolon;
        this.error = "";
        if (rParent == null) {
            this.error += lParent.getLineno() + " j\n";
        }
        if (semicolon == null) {
            if (rParent == null) {
                this.error += lParent.getLineno() + " i\n";
            } else {
                this.error += rParent.getLineno() + " i\n";
            }
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(lVal.getOutput());
        out.append(eql.getOutput());
        out.append(getcharToken.getOutput());
        out.append(lParent.getOutput());
        if (rParent != null) {
            out.append(rParent.getOutput());
        }
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }

        return out.toString();
    }

    public String getError() {
        return lVal.getError() + error;
    }
}
