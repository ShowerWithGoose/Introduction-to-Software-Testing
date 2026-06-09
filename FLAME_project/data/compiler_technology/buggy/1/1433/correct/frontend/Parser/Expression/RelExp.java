package frontend.Parser.Expression;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

import java.util.ArrayList;

public class RelExp implements ASTNode {
    private AddExp firstAddExp;
    private ArrayList<Token> operators; // '<', '>', '<=', '>='
    private ArrayList<AddExp> addExps;

    public RelExp(AddExp firstAddExp, ArrayList<Token> operators, ArrayList<AddExp> addExps) {
        this.firstAddExp = firstAddExp;
        this.operators = operators;
        this.addExps = addExps;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstAddExp.printString());
        sb.append("<" + "RelExp" + ">\n");
        for (int i = 0; i < operators.size(); i++) {
            sb.append(operators.get(i));
            sb.append(addExps.get(i).printString());
            sb.append("<" + "RelExp" + ">\n");
        }
        return sb.toString();
    }
}
