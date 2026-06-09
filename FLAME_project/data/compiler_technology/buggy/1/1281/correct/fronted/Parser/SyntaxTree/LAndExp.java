package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:53
 */
public class LAndExp implements SyntaxNode{
    private final String name = "<LAndExp>";
    private EqExp necEqExp;
    private ArrayList<Token> lAndOps; // lAndOps  &&
    private ArrayList<EqExp> eqExps; // EqExps

    public LAndExp(EqExp necEqExp, ArrayList<Token> lAndOps, ArrayList<EqExp> EqExps) {
        this.necEqExp = necEqExp;
        this.lAndOps = lAndOps;
        this.eqExps = EqExps;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necEqExp.output());
        sb.append(this.name + "\n");
        if (!this.lAndOps.isEmpty() && !this.eqExps.isEmpty() && this.lAndOps.size() == this.eqExps.size()) {
            int len = this.lAndOps.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.lAndOps.get(i).output());
                sb.append(this.eqExps.get(i).output());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
