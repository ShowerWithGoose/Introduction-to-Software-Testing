package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:52
 */
public class LOrExp implements SyntaxNode{
    private final String name = "<LOrExp>";
    private LAndExp necLAndExp;
    private ArrayList<Token> lOrOps; // lOrOps  ||
    private ArrayList<LAndExp> LAndExps; // LAndExps

    public LOrExp(LAndExp necLAndExp, ArrayList<Token> lOrOps, ArrayList<LAndExp> LAndExps) {
        this.necLAndExp = necLAndExp;
        this.lOrOps = lOrOps;
        this.LAndExps = LAndExps;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necLAndExp.output());
        sb.append(this.name + "\n");
        if (!this.lOrOps.isEmpty() && !this.LAndExps.isEmpty() && this.lOrOps.size() == this.LAndExps.size()) {
            int len = this.lOrOps.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.lOrOps.get(i).output());
                sb.append(this.LAndExps.get(i).output());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
