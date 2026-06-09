package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
 RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
 */

public class RelExp implements SyntaxNode {
    private final String name = "<RelExp>";
    private AddExp firstAddExp;
    private ArrayList<Token> ops;
    private ArrayList<AddExp> addExps;

    public RelExp(AddExp firstAddExp, ArrayList<Token> ops,
                 ArrayList<AddExp> addExps) {
        this.firstAddExp = firstAddExp;
        this.ops = ops;
        this.addExps = addExps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstAddExp);
        sb.append(name + "\n");
        for (int i = 0; i < ops.size(); i++) {
            sb.append(ops.get(i));
            sb.append(addExps.get(i));
            sb.append(name + "\n");
        }
        return sb.toString();
    }
}
