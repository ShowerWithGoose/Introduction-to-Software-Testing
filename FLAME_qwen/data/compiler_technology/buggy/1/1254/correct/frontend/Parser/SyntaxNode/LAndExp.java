package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
 LAndExp â†’ EqExp | LAndExp '&&' EqExp
 */
public class LAndExp implements SyntaxNode {
    private final String name = "<LAndExp>";
    private EqExp firstEqExp;
    private ArrayList<Token> ops;
    private ArrayList<EqExp> eqExps;

    public LAndExp(EqExp firstEqExp, ArrayList<Token> ops,
                   ArrayList<EqExp> eqExps) {
        this.firstEqExp = firstEqExp;
        this.ops = ops;
        this.eqExps = eqExps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstEqExp);
        sb.append(name + "\n");
        for (int i = 0; i < ops.size(); i++) {
            sb.append(ops.get(i));
            sb.append(eqExps.get(i));
            sb.append(name + "\n");
        }
        return sb.toString();
    }
}
