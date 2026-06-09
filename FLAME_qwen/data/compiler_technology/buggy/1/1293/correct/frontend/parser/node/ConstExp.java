package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class ConstExp extends TreeNode {
    private AddExp addExp = null;
    public ConstExp(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }
}
