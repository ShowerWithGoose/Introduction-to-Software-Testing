package frontend.Parser.Expression;

import frontend.Parser.ASTNode;
import frontend.Lexer.Token;

import java.util.ArrayList;

public class EqExp implements ASTNode {
    private RelExp firstRelExp;
    private ArrayList<Token> operators; // '==' or '!='
    private ArrayList<RelExp> relExps;

    public EqExp(RelExp firstRelExp, ArrayList<Token> operators, ArrayList<RelExp> relExps) {
        this.firstRelExp = firstRelExp;
        this.operators = operators;
        this.relExps = relExps;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstRelExp.printString());
        sb.append("<" + "EqExp" + ">\n");
        for (int i = 0; i < operators.size(); i++) {
            sb.append(operators.get(i));
            sb.append(relExps.get(i).printString());
            sb.append("<" + "EqExp" + ">\n");
        }
        sb.append("<" + "EqExp" + ">\n");
        return sb.toString();
    }
}
