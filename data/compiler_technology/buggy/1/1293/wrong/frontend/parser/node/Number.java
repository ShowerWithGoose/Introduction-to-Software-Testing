package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class Number extends TreeNode {
    private Token intConstToken = null;

    public void setIntConstToken(Token intConstToken) {
        this.intConstToken = intConstToken;
    }

    public Number(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
