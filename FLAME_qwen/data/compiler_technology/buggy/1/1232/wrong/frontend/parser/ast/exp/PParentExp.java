package frontend.parser.ast.exp;

import frontend.lexer.Token;

public  class PParentExp implements PExp {
    private Token lParent;
    private Exp exp;
    private Token rParent;
    private String error;

    public PParentExp(Token lParent, Exp exp, Token rParent) {
        this.lParent = lParent;
        this.exp = exp;
        this.rParent = rParent;
        this.error = null;
        if (rParent == null){
            this.error = exp.getLineno() + " j\n";
        }
    }

    public int getLineno() {
        if (rParent != null) {
            return rParent.getLineno();
        } else {
            return exp.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(lParent.getOutput());
        out.append(exp.getOutput());
        if (rParent != null) {
            out.append(rParent.getOutput());
        }
        return out.toString();
    }

    public String getError() {
        return exp.getError() + error;
    }

}
