package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:53
 */
public class EqExp implements SyntaxNode{
    private final String name = "<EqExp>";
    private RelExp necRelExp;
    private ArrayList<Token> eqOps; // eqOps  == / !=
    private ArrayList<RelExp> relExps; // relExps

    public EqExp(RelExp necRelExp, ArrayList<Token> eqOps, ArrayList<RelExp> relExps) {
        this.necRelExp = necRelExp;
        this.eqOps = eqOps;
        this.relExps = relExps;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necRelExp.output());
        sb.append(this.name + "\n");
        if (!this.eqOps.isEmpty() && !this.relExps.isEmpty() && this.eqOps.size() == this.relExps.size()) {
            int len = this.eqOps.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.eqOps.get(i).output());
                sb.append(this.relExps.get(i).output());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
