package frontend.Parser.expression.unaryexp;

import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;

public class ParserOfUnaryOp {
    private TokenListManager tokenListManager;
    private Token token;
    public ParserOfUnaryOp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public UnaryOp parseUnaryOp() {
        Token token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.PLUS)
                || token.getTokenType().equals(TokenType.MINU)
                || token.getTokenType().equals(TokenType.NOT)){
            this.token = token;
        } else {
            System.out.println("not + - ! in parseUnaryOp");
        }
        return new UnaryOp(this.token);
    }
}
