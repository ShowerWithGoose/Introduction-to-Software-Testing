package parser_part.expression.unaryExpression;

import lexer_part.Token;
import parser_part.Node;

public class UnaryOp implements Node {
    private Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        return token.toString() + "<UnaryOp>" + "\n";
    }

    public boolean isPlus(){
        return token.getType() == Token.TokenType.PLUS;
    }

    public boolean isMinus(){
        return token.getType() == Token.TokenType.MINU;
    }
}
