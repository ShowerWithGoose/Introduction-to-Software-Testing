package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:54
 */
public class RelExp implements SyntaxNode{
    private final String name = "<RelExp>";
    private AddExp necAddExp;
    private ArrayList<Token> relOps; // relOps  > / < / >= / <=
    private ArrayList<AddExp> addExps; // addExps

    public RelExp(AddExp necAddExp, ArrayList<Token> relOps, ArrayList<AddExp> addExps) {
        this.necAddExp = necAddExp;
        this.relOps = relOps;
        this.addExps = addExps;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necAddExp.output());
        sb.append(this.name + "\n");
        if (!this.relOps.isEmpty() && !this.addExps.isEmpty() && this.relOps.size() == this.addExps.size()) {
            int len = this.relOps.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.relOps.get(i).output());
                sb.append(this.addExps.get(i).output());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
