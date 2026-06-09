package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/12 16:46
 */
public class AddExp implements SyntaxNode{
    private final String name = "<AddExp>";
    private MulExp necMulExp;
    private ArrayList<Token> addOps; // addOps
    private ArrayList<MulExp> mulExps; // mulExps

    public AddExp(MulExp necMulExp, ArrayList<Token> addOps, ArrayList<MulExp> mulExps) {
        this.necMulExp = necMulExp;
        this.addOps = addOps;
        this.mulExps = mulExps;
    }


    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necMulExp.output());
        sb.append(this.name + "\n");
        if (!this.addOps.isEmpty() && !this.mulExps.isEmpty() && this.addOps.size() == this.mulExps.size()) {
            int len = this.addOps.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.addOps.get(i).output());
                sb.append(this.mulExps.get(i).output());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
