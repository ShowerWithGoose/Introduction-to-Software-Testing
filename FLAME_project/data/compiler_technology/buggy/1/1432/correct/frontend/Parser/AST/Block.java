package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class Block extends AstNode{
    public void parse() {
        append(1);
        while (getNowTokenType() != TokenType.RBRACE) {
            BlockItem blockItem = new BlockItem();
            blockItem.parse();
        }
        append(1);
        stringBuilder.append("<Block>").append("\n");
    }
}
