package frontend.parser.ast.decl;

import frontend.lexer.Token;

public class FuncFParam {
    private String type = "<FuncFParam>";
    private BType bType;
    private Token ident;
    private Token lBracket;
    private Token rBracket;
    private String error;

    public FuncFParam(BType bType, Token ident, Token lBracket, Token rBracket) {
        this.bType = bType;
        this.ident = ident;
        this.lBracket = lBracket;
        this.rBracket = rBracket;
        this.error = "";
        if (rBracket == null) {
            this.error = lBracket.getLineno() + " k\n";
        }
    }

    public FuncFParam(BType bType, Token ident) {
        this.bType = bType;
        this.ident = ident;
        this.lBracket = null;
        this.rBracket = null;
        this.error = "";
    }

    public int getLineno() {
        if (lBracket == null) {
            return ident.getLineno();
        } else {
            return lBracket.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(bType.getOutput());
        out.append(ident.getOutput());
        if (lBracket != null) {
            out.append(lBracket.getOutput());
            if (rBracket != null) {
                out.append(rBracket.getOutput());
            }
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        return error;
    }
}
