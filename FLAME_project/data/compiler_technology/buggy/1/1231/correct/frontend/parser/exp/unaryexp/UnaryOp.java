package frontend.parser.exp.unaryexp;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 单目运算符		UnaryOp        ==> '+' | '−' | '!'
public class UnaryOp implements SyntaxNode {
    private static String name = "<UnaryOp>";
    private TokenIterator tokens;
    private Token token;

    public UnaryOp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return token.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        token = tokens.next();
        if (isUnaryOp(token)) {
            return true;
        } else {
            tokens.stepBack(1);
            return false;
        }
    }

    public static boolean isUnaryOp(Token token) {
        return token.getType() == TokenType.PLUS || token.getType() == TokenType.MINU
                || token.getType() == TokenType.NOT;
    }
}
