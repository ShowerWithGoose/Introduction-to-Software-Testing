package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class Btype extends TreeNode {
    private Token typeToken = null;
    public Btype(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setTypeToken(Token token) {
        this.typeToken = token;
    }
}
