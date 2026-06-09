package frontend.Parser.Expression;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

import java.util.ArrayList;

public class LAndExp implements ASTNode {
    private EqExp firstEqExp;
    private ArrayList<Token> operators; // '&&'
    private ArrayList<EqExp> eqExps;

    public LAndExp(EqExp firstEqExp, ArrayList<Token> operators, ArrayList<EqExp> eqExps) {
        this.firstEqExp = firstEqExp;
        this.operators = operators;
        this.eqExps = eqExps;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstEqExp.printString());
        sb.append("<" + "LAndExp" + ">\n");
        for (int i = 0; i < operators.size(); i++) {
            sb.append(operators.get(i));
            sb.append(eqExps.get(i).printString());
            sb.append("<" + "LAndExp" + ">\n");
        }
        return sb.toString();
    }
}
