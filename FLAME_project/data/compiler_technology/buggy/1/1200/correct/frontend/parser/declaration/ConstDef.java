package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;

public class ConstDef {
    private final String name = "<ConstDef>";
    private Token ident;
    private Token lBracket;
    private ConstExp constExp;
    private Token rBracket;
    private Token eq;
    private ConstInitVal constInitVal;
    private String errorLog;

    public ConstDef(Token ident, Token lBracket, ConstExp constExp,
                    Token rBracket, Token eq, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lBracket = lBracket;
        this.constExp = constExp;
        this.rBracket = rBracket;
        this.eq = eq;
        this.constInitVal = constInitVal;
        if (rBracket == null) {
            errorLog = constExp.getLineno() + " k\n";
        } else {
            errorLog = "";
        }
    }

    public ConstDef(Token ident, Token eq, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lBracket = null;
        this.constExp = null;
        this.rBracket = null;
        this.eq = eq;
        this.constInitVal = constInitVal;
        this.errorLog = "";
    }

    public int getLineno() {
        return constInitVal.getLineno();
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.getOutPut());
        if (lBracket != null) {
            sb.append(lBracket.getOutPut());
            sb.append(constExp.getOutPut());
            sb.append(rBracket.getOutPut());
        }
        sb.append(eq.getOutPut());
        sb.append(constInitVal.getOutPut());
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        if (lBracket != null) {
            sb.append(constExp.getError());
        }
        sb.append(errorLog);
        sb.append(constInitVal.getError());
        return sb.toString();
    }
}
