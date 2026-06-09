package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class Exp extends TreeNode {
    private AddExp addExp = null;

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public Exp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
