package frontend.parser.ast.decl;

import frontend.lexer.Token;
import frontend.parser.ast.exp.ConstExp;

public class VarDef {
    private String type = "<VarDef>";
    private Token ident;
    private Token lBracket;
    private ConstExp constExp;
    private Token rBracket;
    private Token eql;
    private InitVal initVal;
    private String error;

    public VarDef(Token ident, Token lBracket, ConstExp constExp, Token rBracket, Token eql, InitVal initVal) {
        this.ident = ident;
        this.lBracket = lBracket;
        this.constExp = constExp;
        this.rBracket = rBracket;
        this.eql = eql;
        this.initVal = initVal;
        this.error = "";
        if (rBracket == null) {
            this.error = constExp.getLineno() + " k\n";
        }
    }

    public VarDef(Token ident, Token lBracket, ConstExp constExp, Token rBracket) {
        this.ident = ident;
        this.lBracket = lBracket;
        this.constExp = constExp;
        this.rBracket = rBracket;
        this.eql = null;
        this.initVal = null;
        this.error = "";
        if (rBracket == null) {
            this.error = constExp.getLineno() + " k\n";
        }
    }

    public VarDef(Token ident, Token eql, InitVal initVal) {
        this.ident = ident;
        this.lBracket = null;
        this.constExp = null;
        this.rBracket = null;
        this.eql = eql;
        this.initVal = initVal;
        this.error = "";
    }

    public VarDef(Token ident) {
        this.ident = ident;
        this.lBracket = null;
        this.constExp = null;
        this.rBracket = null;
        this.eql = null;
        this.initVal = null;
        this.error = "";
    }

    public int getLineno() {
        if (eql != null) {
            return initVal.getLineno();
        } else if (lBracket != null) {
            return constExp.getLineno();
        } else {
            return ident.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(ident.getOutput());
        if (lBracket != null) {
            out.append(lBracket.getOutput());
            out.append(constExp.getOutput());
            if (rBracket != null) {
                out.append(rBracket.getOutput());
            }
        }
        if (eql != null) {
            out.append(eql.getOutput());
            if (initVal != null) {
                out.append(initVal.getOutput());
            }
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (lBracket != null) {
            out.append(constExp.getError());
        }
        out.append(error);
        if (eql != null) {
            out.append(initVal.getError());
        }
        return out.toString();
    }
    
}
