package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class UnaryOp extends TreeNode {
    private Token opToken = null;

    public void setOpToken(Token opToken) {
        this.opToken = opToken;
    }

    public UnaryOp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
