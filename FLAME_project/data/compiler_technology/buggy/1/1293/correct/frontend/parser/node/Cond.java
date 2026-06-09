package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class Cond extends TreeNode {
    public LOrExp lOrExp = null;
    public Cond(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setlOrExp(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }
}
