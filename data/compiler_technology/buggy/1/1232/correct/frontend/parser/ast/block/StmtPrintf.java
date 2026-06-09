package frontend.parser.ast.block;

import frontend.lexer.Token;

import frontend.parser.ast.exp.Exp;

import java.util.ArrayList;

public class StmtPrintf implements Statement {
    private Token printfToken;
    private Token lParent;
    private Token stringConst;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rParent;
    private Token semicolon;
    private String error;

    public StmtPrintf(Token printfToken, Token lParent, Token stringConst, ArrayList<Token> commas, ArrayList<Exp> exps, Token rParent, Token semicolon) {
        this.printfToken = printfToken;
        this.lParent = lParent;
        this.stringConst = stringConst;
        this.commas = commas;
        this.exps = exps;
        this.rParent = rParent;
        this.semicolon = semicolon;
        this.error = "";
        if (rParent == null) {
            this.error += exps.get(exps.size() - 1).getLineno() + " j\n";
        }
        if (semicolon == null) {
            if (rParent == null) {
                this.error += exps.get(exps.size() - 1).getLineno() + " i\n";
            } else {
                this.error += rParent.getLineno() + " i\n";
            }
        }
    }

    public StmtPrintf(Token printfToken, Token lParent, Token stringConst, Token rParent, Token semicolon) {
        this.printfToken = printfToken;
        this.lParent = lParent;
        this.stringConst = stringConst;
        this.commas = null;
        this.exps = null;
        this.rParent = rParent;
        this.semicolon = semicolon;
        this.error = "";
        if (rParent == null) {
            this.error += stringConst.getLineno() + " j\n";
        }
        if (semicolon == null) {
            if (rParent == null) {
                this.error += stringConst.getLineno() + " i\n";
            } else {
                this.error += rParent.getLineno() + " i\n";
            }
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(printfToken.getOutput());
        out.append(lParent.getOutput());
        out.append(stringConst.getOutput());
        if (exps != null && !exps.isEmpty()) {
            for (int i = 0; i < exps.size(); ++i) {
                out.append(commas.get(i).getOutput());
                out.append(exps.get(i).getOutput());
            }
        }
        if (rParent != null) {
            out.append(rParent.getOutput());
        }
        if (semicolon != null) {
            out.append(semicolon.getOutput());
        }

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (exps != null && !exps.isEmpty()) {
            for (Exp exp : exps) {
                out.append(exp.getError());
            }
        }
        out.append(error);

        return out.toString();
    }
}
