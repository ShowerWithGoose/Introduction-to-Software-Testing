package parser_part.function.funcType;

import lexer_part.Token;
import parser_part.Node;

public class FuncType implements Node {
    private Token type;

    public FuncType(Token type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return type.toString() + "<FuncType>\n";
    }

    public Token.TokenType getType() {
        return type.getType();
    }

    public boolean isVoid() {
        return type.getType() == Token.TokenType.VOIDTK;
    }

    public boolean isInt() {
        return type.getType() == Token.TokenType.INTTK;
    }

    public boolean isChar() {
        return type.getType() == Token.TokenType.CHARTK;
    }

}
