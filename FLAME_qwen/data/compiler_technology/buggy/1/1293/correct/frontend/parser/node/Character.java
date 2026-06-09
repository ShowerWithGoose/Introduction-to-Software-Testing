package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class Character extends TreeNode {
    private Token charConstToken = null;
    public Character(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setCharConstToken(Token charConstToken) {
        this.charConstToken = charConstToken;
    }
}
