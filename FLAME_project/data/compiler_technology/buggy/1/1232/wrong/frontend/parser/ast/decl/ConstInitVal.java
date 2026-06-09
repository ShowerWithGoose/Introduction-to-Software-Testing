package frontend.parser.ast.decl;

import frontend.lexer.Token;
import frontend.parser.ast.exp.ConstExp;

import java.util.ArrayList;

public class ConstInitVal {
    private String type = "<ConstInitVal>";
    private ConstExp constExp;
    private Token lBrace;
    private ConstExp firstExp ;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExps;
    private Token rBrace;
    private Token stringConst;

    public ConstInitVal(ConstExp constExp){
        this.constExp = constExp;
        this.lBrace = null;
        this.firstExp = null;
        this.commas = null;
        this.constExps = null;
        this.rBrace = null;
        this.stringConst = null;
    }

    public ConstInitVal(Token lBrace, Token rBrace) {
        this.constExp = null;
        this.lBrace = lBrace;
        this.firstExp = null;
        this.commas = null;
        this.constExps = null;
        this.rBrace = rBrace;
        this.stringConst = null;
    }

    public ConstInitVal(Token lBrace, ConstExp firstExp, Token rBrace) {
        this.constExp = null;
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.commas = null;
        this.constExps = null;
        this.rBrace = rBrace;
        this.stringConst = null;
    }
    
    public ConstInitVal(Token lBrace, ConstExp firstExp, ArrayList<Token> commas, ArrayList<ConstExp> constExps, Token rBrace) {
        this.constExp = null;
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.commas = commas;
        this.constExps = constExps;
        this.rBrace = rBrace;
        this.stringConst = null;
    }

    public ConstInitVal(Token stringConst){
        this.constExp = null;
        this.lBrace = null;
        this.firstExp = null;
        this.commas = null;
        this.constExps = null;
        this.rBrace = null;
        this.stringConst = stringConst;
    }

    public int getLineno() {
        if (constExp != null) {
            return constExp.getLineno();
        } else if (stringConst != null) {
            return stringConst.getLineno();
        } else {
            return rBrace.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        if (constExp != null) {
            out.append(constExp.getOutput());
        } else if (stringConst != null) {
            out.append(stringConst.getOutput());
        } else {
            out.append(lBrace.getOutput());
            if (firstExp != null) {
                out.append(firstExp.getOutput());

                for (int i = 0; i < constExps.size(); i++) {
                    out.append(commas.get(i).getOutput());
                    out.append(constExps.get(i).getOutput());
                }
            }
            out.append(rBrace.getOutput());
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (constExp != null) {
            out.append(constExp.getError());
        } else if (stringConst != null) {
            out.append("");
        } else {
            out.append(firstExp.getError());
            for (ConstExp i : constExps) {
                out.append(i.getError());
            }
        }
        return out.toString();
    }
    
}
