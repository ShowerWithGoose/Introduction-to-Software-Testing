package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
 AddExp → MulExp | AddExp ('+' | '−') MulExp
 */
public class AddExp implements SyntaxNode{
    private final String name = "<AddExp>";
    private MulExp firstMulExp;
    private ArrayList<Token> ops;
    private ArrayList<MulExp> mulExps;

    public AddExp(MulExp firstMulExp, ArrayList<Token> ops,
                  ArrayList<MulExp> mulExps) {
        this.firstMulExp = firstMulExp;
        this.ops = ops;
        this.mulExps = mulExps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstMulExp);
        sb.append(name + "\n");
        for (int i = 0; i < ops.size(); i++) {
            sb.append(ops.get(i));
            sb.append(mulExps.get(i));
            sb.append(name + "\n");
        }

        return sb.toString();
    }
}
