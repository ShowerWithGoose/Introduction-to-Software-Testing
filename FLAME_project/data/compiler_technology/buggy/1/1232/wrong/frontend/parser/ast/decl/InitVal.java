package frontend.parser.ast.decl;

import frontend.lexer.Token;
import frontend.parser.ast.exp.Exp;

import java.util.ArrayList;

public class InitVal {
    private String type = "<InitVal>";
    private Exp exp;
    private Token lBrace;
    private Exp firstExp ;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rBrace;
    private Token stringConst;

    public InitVal(Exp exp){
        this.exp = exp;
        this.lBrace = null;
        this.firstExp = null;
        this.commas = null;
        this.exps = null;
        this.rBrace = null;
        this.stringConst = null;
    }

    public InitVal(Token lBrace, Token rBrace) {
        this.exp = null;
        this.lBrace = lBrace;
        this.firstExp = null;
        this.commas = null;
        this.exps = null;
        this.rBrace = rBrace;
        this.stringConst = null;
    }

    public InitVal(Token lBrace, Exp firstExp, Token rBrace) {
        this.exp = null;
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.commas = null;
        this.exps = null;
        this.rBrace = rBrace;
        this.stringConst = null;
    }
    
    public InitVal(Token lBrace, Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> exps, Token rBrace) {
        this.exp = null;
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = exps;
        this.rBrace = rBrace;
        this.stringConst = null;
    }

    public InitVal(Token stringConst){
        this.exp = null;
        this.lBrace = null;
        this.firstExp = null;
        this.commas = null;
        this.exps = null;
        this.rBrace = null;
        this.stringConst = stringConst;
    }

    public int getLineno() {
        if (exp != null) {
            return exp.getLineno();
        } else if (stringConst != null) {
            return stringConst.getLineno();
        } else {
            return rBrace.getLineno();
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        if (exp != null) {
            out.append(exp.getOutput());
        } else if (stringConst != null) {
            out.append(stringConst.getOutput());
        } else {
            out.append(lBrace.getOutput());
            if (firstExp != null) {
                out.append(firstExp.getOutput());

                for (int i = 0; i < exps.size(); i++) {
                    out.append(commas.get(i).getOutput());
                    out.append(exps.get(i).getOutput());
                }
            }
            out.append(rBrace.getOutput());
        }
        out.append(type + "\n");

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (exp != null) {
            out.append(exp.getError());
        } else if (stringConst != null) {
            out.append("");
        } else {
            out.append(firstExp.getError());
            for (Exp i : exps) {
                out.append(i.getError());
            }
        }
        return out.toString();
    }
    
}
