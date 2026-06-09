package frontend.Parser.expression.primaryexp;

import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.terminal.IntConst;
import frontend.Lexer.Token;

public class ParserOfNumber {
    private TokenListManager tokenListManager;
    private IntConst intConst;
    public ParserOfNumber(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public Number parseNumber(){
        Token token = this.tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.INTCON)){
            this.intConst = new IntConst(token);
        } else {
            System.out.println("expected a INTCON in parseNumber");
        }
        return new Number(this.intConst);
    }
}
