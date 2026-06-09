package ast;

import lexical.TokenType;

public class UnaryOp extends Symbol {

    public static Symbol of() {
        Symbol unaryOp = new UnaryOp();
        if (token.getType().equals(TokenType.PLUS) ||
            token.getType().equals(TokenType.MINU) ||
            token.getType().equals(TokenType.NOT)) {
            unaryOp.add(token);
            token = lexer.nextToken();
            return unaryOp;
        }
        return null;
    }
}
