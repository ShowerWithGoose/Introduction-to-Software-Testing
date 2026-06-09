package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.UnaryExp.UnaryExp;

import java.util.ArrayList;

public class MulExp implements SyntaxNode {
    private final String name = "<MulExp>";
    private UnaryExp firstUnaryExp;
    private ArrayList<Token> ops;
    private ArrayList<UnaryExp> unaryExps;

    public MulExp(UnaryExp firstUnaryExp, ArrayList<Token> ops,
                  ArrayList<UnaryExp> unaryExps) {
        this.firstUnaryExp = firstUnaryExp;
        this.ops = ops;
        this.unaryExps = unaryExps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstUnaryExp);
        sb.append(name + "\n");
        for (int i = 0; i < ops.size(); i++) {
            sb.append(ops.get(i));
            sb.append(unaryExps.get(i));
            sb.append(name + "\n");
        }

        return sb.toString();
    }
}
