package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
 EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
 */
public class EqExp implements SyntaxNode {
    private final String name = "<EqExp>";
    private RelExp firstRelExp;
    private ArrayList<Token> ops;
    private ArrayList<RelExp> relExps;

    public EqExp(RelExp firstRelExp, ArrayList<Token> ops,
                 ArrayList<RelExp> relExps) {
        this.firstRelExp = firstRelExp;
        this.ops = ops;
        this.relExps = relExps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstRelExp);
        sb.append(name + "\n");
        for (int i = 0; i < ops.size(); i++) {
            sb.append(ops.get(i));
            sb.append(relExps.get(i));
            sb.append(name + "\n");
        }

        return sb.toString();
    }
}
