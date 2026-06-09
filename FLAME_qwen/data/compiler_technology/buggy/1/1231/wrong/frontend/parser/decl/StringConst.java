package frontend.parser.decl;

import frontend.TokenIterator;
import frontend.parser.decl.constdecl.constinitval.ConstInitValNode;
import frontend.parser.decl.vardecl.InitValNode;
import nodes.Token;
import nodes.TokenType;

public class StringConst implements ConstInitValNode, InitValNode {
    private TokenIterator tokens;
    private Token token;

    public StringConst(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return token.syntaxPrinter();
    }

    @Override
    public boolean parse() {
        token = tokens.next();
        if (token.getType() == TokenType.STRCON) {
            return true;
        } else {
            tokens.stepBack(1);
            return false;
        }
    }

}
