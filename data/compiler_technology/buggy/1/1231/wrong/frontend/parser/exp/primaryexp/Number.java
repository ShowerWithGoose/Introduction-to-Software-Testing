package frontend.parser.exp.primaryexp;

import frontend.TokenIterator;
import nodes.Token;
import nodes.TokenType;

//数值		    Number         ==> IntConst
public class Number implements PrimaryExpNode {

    private static String name = "<Number>";
    private TokenIterator tokens;
    private Token token;

    public Number(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return token.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        token = tokens.next();
        if (token.getType() == TokenType.INTCON) {
            return true;
        } else {
            tokens.stepBack(1);
            return false;
        }
    }

}
