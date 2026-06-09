package parser_part.expression.unaryExpression;

import lexer_part.Token;
import lexer_part.TokenList;

public class UnaryOpParser {
    private TokenList tokenList;

    public UnaryOpParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public UnaryOp parseUnaryOp() {
        Token token = tokenList.getNextToken();
        if (token.getType() != Token.TokenType.PLUS &&
                token.getType() != Token.TokenType.MINU &&
                token.getType() != Token.TokenType.NOT) {
            System.err.println("UnaryOp error: expect '+', '-' or ''!");
        }
        return new UnaryOp(token);
    }
}
