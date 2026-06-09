package frontend.Parser.expression.primaryexp;

import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.terminal.CharConst;

public class ParserOfCharacter {
    private TokenListManager tokenListManager;
    private CharConst charConst;
    public ParserOfCharacter(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public Character parseCharacter(){
        Token token = this.tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.CHRCON)){
            this.charConst = new CharConst(token);
        } else {
            System.out.println("expected a CHRCON in parseCharacter");
        }
        return new Character(this.charConst);
    }
}
