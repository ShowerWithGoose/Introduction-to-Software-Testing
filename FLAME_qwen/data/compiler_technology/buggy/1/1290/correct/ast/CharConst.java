package ast;

import lexical.TokenType;

public class CharConst extends Symbol {

    public static Symbol of() {
        Symbol charConst = new CharConst();
        if (token.getType().equals(TokenType.CHRCON)) {
            charConst.add(token);
            token = lexer.nextToken();
            return charConst;
        }
        return null;
    }

    @Override
    public String toString() {
        return "";
    }
}
