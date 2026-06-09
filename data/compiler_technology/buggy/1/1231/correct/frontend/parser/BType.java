package frontend.parser;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

/*
 *基本类型		BType          ==> 'int' | 'char'
 */
public class BType implements SyntaxNode {
    private static String name = "<BType>";
    private TokenIterator tokens;
    private Token token;

    public BType(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        // NOTE: BType no need to output
        return token.syntaxPrinter();
    }

    @Override
    public boolean parse() {
        token = tokens.next();
        return isBType(token);
    }

    public static boolean isBType(Token token) {
        return token.getType().equals(TokenType.INTTK) || token.getType().equals(TokenType.CHARTK);
    }
}
