package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;

import java.util.ArrayList;

public class ConstInitVal {
    private final String name = "<ConstInitVal>";
    private ConstExp constExp = null;
    private Token lBrace = null;
    private ConstExp firstExp = null;
    private ArrayList<Token> commas = null;
    private ArrayList<ConstExp> exps = null;
    private Token rBrace = null;
    private Token strConst = null;

    public ConstInitVal(ConstExp constExp) {
        this.constExp = constExp;
    }

    public ConstInitVal(Token lBrace, Token rBrace) {
        this.lBrace = lBrace;
        this.rBrace = rBrace;
    }

    public ConstInitVal(Token lBrace, ConstExp firstExp, Token rBrace) {
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.rBrace = rBrace;
    }

    public ConstInitVal(Token lBrace, ConstExp firstExp, ArrayList<Token> commas,
                        ArrayList<ConstExp> exps, Token rBrace) {
        this.lBrace = lBrace;
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = exps;
        this.rBrace = rBrace;
    }

    public ConstInitVal(Token strConst) {
        this.strConst = strConst;
    }

    public int getLineno() {
        if (constExp != null) {
            return constExp.getLineno();
        } else if (strConst != null) {
            return strConst.getLineno();
        } else {
            return rBrace.getLineno();
        }
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        if (constExp != null) {
            sb.append(constExp.getOutPut());
        } else if (strConst != null) {
            sb.append(strConst.getOutPut());
        } else {
            sb.append(lBrace.getOutPut());
            if (firstExp != null) {
                sb.append(firstExp.getOutPut());
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
        if (constExp != null) {
            sb.append(constExp.getError());
        } else if (firstExp != null) {
            sb.append(firstExp.getError());
            for (ConstExp exp : exps) {
                sb.append(exp.getError());
            }
        }
        return sb.toString();
    }
}
