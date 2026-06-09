package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
  LOrExp â†’ LAndExp | LOrExp '||' LAndExp
 */
public class LOrExp implements SyntaxNode {
    private final String name = "<LOrExp>";
    private LAndExp firstLAndExp;
    private ArrayList<Token> ops;
    private ArrayList<LAndExp> lAndExps;

    public LOrExp(LAndExp firstLAndExp, ArrayList<Token> ops,
                   ArrayList<LAndExp> lAndExps) {
        this.firstLAndExp = firstLAndExp;
        this.ops = ops;
        this.lAndExps = lAndExps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstLAndExp);
        sb.append(name + "\n");

        for (int i = 0; i < ops.size(); i++) {
            sb.append(ops.get(i));
            sb.append(lAndExps.get(i));
            sb.append(name + "\n");
        }
        return sb.toString();
    }
}
