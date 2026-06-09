package frontend.parser.ast.decl;

import frontend.lexer.Token;
import frontend.parser.ast.exp.ConstExp;

public class ConstDef {
    private String type = "<ConstDef>";
    private Token Ident;
    private Token lBracket;
    private ConstExp constExp;
    private Token rBracket;
    private Token eql;
    private ConstInitVal constInitVal;
    private String error;

    public ConstDef(Token Ident, Token eql, ConstInitVal constInitVal) {
        this.Ident = Ident;
        this.lBracket = null;
        this.constExp = null;
        this.rBracket = null;
        this.eql = eql;
        this.constInitVal = constInitVal;
        this.error = "";

    }
    
    public ConstDef(Token Ident, Token lBracket, ConstExp constExp, Token rBracket, Token eql, ConstInitVal constInitVal) {
        this.Ident = Ident;
        this.lBracket = lBracket;
        this.constExp = constExp;
        this.rBracket = rBracket;
        this.eql = eql;
        this.constInitVal = constInitVal;
        this.error = "";

        if (rBracket == null) {
            this.error = constExp.getLineno() + "k\n";
        }
    }
    
    public int getLineno() {
        return constInitVal.getLineno();
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(Ident.getOutput());
        if (lBracket != null) {
            out.append(lBracket.getOutput());
            out.append(constExp.getOutput());
            out.append(rBracket.getOutput());
        }
        out.append(eql.getOutput());
        out.append(constInitVal.getOutput());
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (lBracket != null) {
            out.append(constExp.getError());
        }
        out.append(error);
        out.append(constInitVal.getError());

        return out.toString();
    }

}
