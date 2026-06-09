package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/12 19:15
 */
public class MulExp implements SyntaxNode{
    private final String name = "<MulExp>";
    private UnaryExp necUnaryExp;
    private ArrayList<Token> mulOps; // mulOps
    private ArrayList<UnaryExp> UnaryExps; // UnaryExps

    public MulExp(UnaryExp necUnaryExp, ArrayList<Token> mulOps, ArrayList<UnaryExp> unaryExps) {
        this.necUnaryExp = necUnaryExp;
        this.mulOps = mulOps;
        UnaryExps = unaryExps;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necUnaryExp.output());
        sb.append(this.name + "\n");
        if (!this.mulOps.isEmpty()&& !this.UnaryExps.isEmpty() && this.mulOps.size() == this.UnaryExps.size()) {
            int len = this.mulOps.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.mulOps.get(i).output());
                sb.append(this.UnaryExps.get(i).output());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
