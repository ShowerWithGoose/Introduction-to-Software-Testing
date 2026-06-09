package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

public class StmtPrint implements Statement {
    private Token printTk;
    private Token lParent;
    private Token strCon;
    private ArrayList<Token> commas = null;
    private ArrayList<Exp> exps = null;
    private Token rParent;
    private Token semi;
    private String errorLog = "";

    public StmtPrint(Token printTk, Token lParent, Token strCon,
                     Token rParent, Token semi) {
        this.printTk = printTk;
        this.lParent = lParent;
        this.strCon = strCon;
        this.rParent = rParent;
        this.semi = semi;
        if (rParent == null) {
            errorLog += strCon.getLineno() + " j\n";
        }
        if (semi == null) {
            if (rParent == null) {
                errorLog += strCon.getLineno() + " i\n";
            } else {
                errorLog += rParent.getLineno() + " i\n";
            }
        }
    }

    public StmtPrint(Token printTk, Token lParent, Token strCon, ArrayList<Token> commas,
                     ArrayList<Exp> exps, Token rParent, Token semi) {
        this.printTk = printTk;
        this.lParent = lParent;
        this.strCon = strCon;
        this.commas = commas;
        this.exps = exps;
        this.rParent = rParent;
        this.semi = semi;
        if (rParent == null) {
            errorLog += exps.get(exps.size() - 1).getLineno() + " j\n";
        }
        if (semi == null) {
            if (rParent == null) {
                errorLog += exps.get(exps.size() - 1).getLineno() + " i\n";
            } else {
                errorLog += rParent.getLineno() + " i\n";
            }
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(printTk.getOutPut());
        sb.append(lParent.getOutPut());
        sb.append(strCon.getOutPut());
        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i).getOutPut());
            sb.append(exps.get(i).getOutPut());
        }
        if (rParent != null) {
            sb.append(rParent.getOutPut());
        }
        if (semi != null) {
            sb.append(semi.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        StringBuilder sb = new StringBuilder();
        for (Exp exp : exps) {
            sb.append(exp.getError());
        }
        sb.append(errorLog);
        return sb.toString();
    }
}
