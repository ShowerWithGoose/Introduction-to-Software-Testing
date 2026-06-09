package frontend.parser.ast.exp;

import frontend.lexer.Token;

public class UFuncExp implements UExp {
    private Token ident;
    private Token lParent;
    private FuncRParams funcRParams;
    private Token rParent;
    private String error;

    public UFuncExp(Token ident, Token lParent, FuncRParams funcRParams, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.funcRParams = funcRParams;
        this.rParent = rParent;
        this.error = "";

        if (rParent == null) {
            error = funcRParams.getLineno() + " j\n";
        }
    }

    public UFuncExp(Token ident, Token lParent, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.funcRParams = null;
        this.rParent = rParent;
        this.error = "";

        if (rParent == null) {
            error = lParent.getLineno() + " j\n";
        }
    }

    public int getLineno() {
        if (rParent != null) {
            return rParent.getLineno();
        } else if (funcRParams != null) {
            return funcRParams.getLineno();
        } else {
            return lParent.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(ident.getOutput());
        out.append(lParent.getOutput());
        if (funcRParams!= null) {
            out.append(funcRParams.getOutput());
        }
        if (rParent != null) {
            out.append(rParent.getOutput());
        }

        return out.toString();
    }

    public String getError() {
        if (funcRParams != null) {
            return funcRParams.getError() + error;
        } else {
            return error;
        }
    }
}
