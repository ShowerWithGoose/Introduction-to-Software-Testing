package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;

public class VarDef {
    private final String name = "<VarDef>";
    private Token ident;
    private Token lBracket;
    private ConstExp constExp;
    private Token rBracket;
    private Token eq;
    private InitVal initVal;
    private String errorLog;

    public VarDef(Token ident, Token lBracket, ConstExp constExp,
                    Token rBracket, Token eq, InitVal initVal) {
        this.ident = ident;
        this.lBracket = lBracket;
        this.constExp = constExp;
        this.rBracket = rBracket;
        this.eq = eq;
        this.initVal = initVal;
        if (rBracket == null) {
            errorLog = constExp.getLineno() + " k\n";
        } else {
            errorLog = "";
        }
    }

    public VarDef(Token ident, Token lBracket, ConstExp constExp, Token rBracket) {
        this.ident = ident;
        this.lBracket = lBracket;
        this.constExp = constExp;
        this.rBracket = rBracket;
        this.eq = null;
        this.initVal = null;
        if (rBracket == null) {
            errorLog = constExp.getLineno() + " k\n";
        } else {
            errorLog = "";
        }
    }

    public VarDef(Token ident, Token eq, InitVal initVal) {
        this.ident = ident;
        this.lBracket = null;
        this.constExp = null;
        this.rBracket = null;
        this.eq = eq;
        this.initVal = initVal;
        this.errorLog = "";
    }

    public VarDef(Token ident) {
        this.ident = ident;
        this.lBracket = null;
        this.constExp = null;
        this.rBracket = null;
        this.eq = null;
        this.initVal = null;
        this.errorLog = "";
    }

    public int getLineno() {
        if (eq != null) {
            return initVal.getLineno();
        } else if (lBracket != null) {
            return constExp.getLineno();
        } else {
            return ident.getLineno();
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.getOutPut());
        if (lBracket != null) {
            sb.append(lBracket.getOutPut());
            sb.append(constExp.getOutPut());
            sb.append(rBracket.getOutPut());
        }
        if (eq != null) {
            sb.append(eq.getOutPut());
            sb.append(initVal.getOutPut());
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        if (lBracket != null) {
            sb.append(constExp.getError());
        }
        sb.append(errorLog);
        if (eq != null) {
            sb.append(initVal.getError());
        }
        return sb.toString();
    }
}
