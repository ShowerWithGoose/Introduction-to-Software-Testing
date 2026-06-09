package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class FuncType extends TreeNode {
    private Token typeToken = null;

    public void setTypeToken(Token typeToken) {
        this.typeToken = typeToken;
    }

    public FuncType(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
