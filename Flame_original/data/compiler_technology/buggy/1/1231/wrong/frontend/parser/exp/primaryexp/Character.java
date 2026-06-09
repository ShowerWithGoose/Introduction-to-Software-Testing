package frontend.parser.exp.primaryexp;

import frontend.TokenIterator;
import nodes.Token;
import nodes.TokenType;

// 字符		    Character      ==> CharConst
public class Character implements PrimaryExpNode {
    private static String name = "<Character>";
    private TokenIterator tokens;
    private Token token;

    public Character(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return token.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        token = tokens.next();
        if (token.getType() == TokenType.CHRCON) {
            return true;
        } else {
            tokens.stepBack(1);
            return false;
        }
    }

}
