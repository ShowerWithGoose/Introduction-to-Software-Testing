package frontend.parser.ast.exp;

import frontend.lexer.Token;

public class LVal implements PExp {
    private String type = "<LVal>";
    private Token ident;
    private Token lBracket;
    private Exp exp;
    private Token rBracket;
    private String error;

    public LVal(Token ident) {
        this.ident = ident;
        this.lBracket = null;
        this.exp = null;
        this.rBracket = null;
        this.error = "";
    }

    public LVal(Token ident, Token lBracket, Exp exp, Token rBracket) {
        this.ident = ident;
        this.lBracket = lBracket;
        this.exp = exp;
        this.rBracket = rBracket;
        this.error = "";
        if (rBracket == null) {
            this.error = exp.getLineno() + " k\n";
        }
    }

    public int getLineno() {
        if (rBracket != null) {
            return rBracket.getLineno();
        } else if (exp != null) {
            return exp.getLineno();
        } else {
            return ident.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(ident.getOutput());
        if (lBracket != null) {
            out.append(lBracket.getOutput());
            out.append(exp.getOutput());
            if (rBracket != null) {
                out.append(rBracket.getOutput());
            }
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        if (exp != null) {
            return exp.getError() + error;
        } else {
            return error;
        }
    }
}
