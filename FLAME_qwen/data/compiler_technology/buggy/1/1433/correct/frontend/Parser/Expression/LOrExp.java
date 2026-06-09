package frontend.Parser.Expression;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

import java.util.ArrayList;

public class LOrExp implements ASTNode {
    private LAndExp firstLAndExp;
    private ArrayList<Token> operators; // '||'
    private ArrayList<LAndExp> lAndExps;

    public LOrExp(LAndExp firstLAndExp, ArrayList<Token> operators, ArrayList<LAndExp> lAndExps) {
        this.firstLAndExp = firstLAndExp;
        this.operators = operators;
        this.lAndExps = lAndExps;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstLAndExp.printString());
        sb.append("<" + "LOrExp" + ">\n");
        for (int i = 0; i < operators.size(); i++) {
            sb.append(operators.get(i));
            sb.append(lAndExps.get(i).printString());
            sb.append("<" + "LOrExp" + ">\n");
        }
        return sb.toString();
    }
}
