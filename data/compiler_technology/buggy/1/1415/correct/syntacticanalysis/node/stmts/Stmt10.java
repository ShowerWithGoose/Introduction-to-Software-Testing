package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.Exp;

import java.util.ArrayList;

public class Stmt10 extends Stmt {
    private String name = "<Stmt>";
    private Token printfTk;
    private Token lparent;
    private Token strCon;
    private ArrayList<Exp> exps;
    private Token rparent;
    private Token semicn;

    public Stmt10(Token printfTk, Token lparent, Token strCon
            , ArrayList<Exp> exps, Token rparent, Token semicn) {
        this.printfTk = printfTk;
        this.lparent = lparent;
        this.strCon = strCon;
        this.exps = exps;
        this.rparent = rparent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(printfTk);
        sb.append("\n");
        sb.append(lparent);
        sb.append("\n");
        sb.append(strCon);
        sb.append("\n");
        if (exps != null) {
            for (Exp exp : exps) {
                sb.append("COMMA ,\n");
                sb.append(exp.syntaxOutput());
                sb.append("\n");
            }
        }
        sb.append(rparent);
        sb.append("\n");
        sb.append(semicn);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
