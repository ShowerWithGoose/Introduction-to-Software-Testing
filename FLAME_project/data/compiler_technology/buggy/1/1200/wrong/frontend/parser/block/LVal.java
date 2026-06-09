package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primary.PExp;

public class LVal implements PExp {
    private final String name = "<LVal>";
    private Token ident;
    private Token lBracket = null;
    private Exp exp = null;
    private Token rBracket = null;
    private String errorLog = "";

    public LVal(Token ident) {
        this.ident = ident;
    }

    public LVal(Token ident, Token lBracket, Exp exp, Token rBracket) {
        this.ident = ident;
        this.lBracket = lBracket;
        this.exp = exp;
        this.rBracket = rBracket;
        if (rBracket == null) {
            this.errorLog = exp.getLineno() + " k\n";
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

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.getOutPut());
        if (lBracket != null) {
            sb.append(lBracket.getOutPut());
            sb.append(exp.getOutPut());
            if (rBracket != null) {
                sb.append(rBracket.getOutPut());
            }
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        if (exp != null) {
            return exp.getError() + errorLog;
        } else {
            return errorLog;
        }
    }
}
