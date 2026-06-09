package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

public class InitVal {
    private final String name = "<InitVal>";
    private Exp exp = null;
    private Token lBrace = null;
    private Exp firstExp = null;
    private ArrayList<Token> commas = null;
    private ArrayList<Exp> exps = null;
    private Token rBrace = null;
    private Token strConst = null;

    public InitVal(Exp exp) {
        this.exp = exp;
    }

    public InitVal(Token lBrace, Token rBrace) {
        this.lBrace = lBrace;
        this.rBrace = rBrace;
    }

    public InitVal(Token lBrace, Exp firstExp, Token rBrace) {
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.rBrace = rBrace;
    }

    public InitVal(Token lBrace, Exp firstExp, ArrayList<Token> commas,
                        ArrayList<Exp> exps, Token rBrace) {
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = exps;
        this.rBrace = rBrace;
    }

    public InitVal(Token strConst) {
        this.strConst = strConst;
    }

    public int getLineno() {
        if (exp != null) {
            return exp.getLineno();
        } else if (strConst != null) {
            return strConst.getLineno();
        } else {
            return rBrace.getLineno();
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.getOutPut());
        } else if (strConst != null) {
            sb.append(strConst.getOutPut());
        } else {
            sb.append(lBrace.getOutPut());
            if (firstExp != null) {
                sb.append(exp.getOutPut());
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).getOutPut());
                    sb.append(exps.get(i).getOutPut());
                }
            }
            sb.append(rBrace.getOutPut());
        }
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.getError());
        } else if (firstExp != null) {
            sb.append(firstExp.getError());
            for (Exp exp : exps) {
                sb.append(exp.getError());
            }
        }
        return sb.toString();
    }
}
