package ast;

import lexical.TokenType;

public class IntConst extends Symbol {

    public static Symbol of() {
        Symbol intConst = new IntConst();
        if (token.getType().equals(TokenType.INTCON)) {
            intConst.add(token);
            token = lexer.nextToken();
            return intConst;
        }
        return null;
    }

    @Override
    public String toString() {
        return "";
    }

}
