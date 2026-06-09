package parser_part.function;

import lexer_part.Token;
import parser_part.Node;
import parser_part.expression.Exp;

import java.util.ArrayList;

public class FuncRParams implements Node {
    private Exp exp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;

    public FuncRParams(Exp exp, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.exp = exp;
        this.commas = commas;
        this.exps = exps;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder(exp.toString());
        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i).toString());
            sb.append(exps.get(i).toString());
        }
        sb.append("<FuncRParams>\n");
        return sb.toString();
    }

    public int getParamsCnt() {
        return exps.size() + 1;
    }

    public ArrayList<Exp> getAllExps() {
        ArrayList<Exp> ret = new ArrayList<>();
        ret.add(exp);
        ret.addAll(exps);
        return ret;
    }
}
