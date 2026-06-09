package frontend.Parser.Expression;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

import java.util.ArrayList;

public class MulExp implements ASTNode {
    private UnaryExp firstUnaryExp;
    private ArrayList<Token> operators; // '*', '/' or '%'
    private ArrayList<UnaryExp> unaryExps;

    public MulExp(UnaryExp firstUnaryExp, ArrayList<Token> operators, ArrayList<UnaryExp> unaryExps) {
        this.firstUnaryExp = firstUnaryExp;
        this.operators = operators;
        this.unaryExps = unaryExps;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstUnaryExp.printString());
        sb.append("<" + "MulExp" + ">\n");
        for (int i = 0; i < operators.size(); i++) {
            sb.append(operators.get(i));
            sb.append(unaryExps.get(i).printString());
            sb.append("<" + "MulExp" + ">\n");
        }
        return sb.toString();
    }
}
