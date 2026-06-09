package frontend.parser.terminal;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

public class Ident implements SyntaxNode {
    private TokenIterator tokens;
    private Token token;

    public Ident(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return token.syntaxPrinter();
    }

    @Override
    public boolean parse() {
        token = tokens.next();
        return token.getType().equals(TokenType.IDENFR);
    }

}
