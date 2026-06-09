package frontend.Parser.function;

import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;

public class ParserOfFuncType {
    private TokenListManager tokenListManager;
    private Token token;
    public ParserOfFuncType(TokenListManager tokenListManager){
        this.tokenListManager = tokenListManager;
    }
    public FuncType parseFuncType(){
        Token token = this.tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.INTTK)
        ||token.getTokenType().equals(TokenType.CHARTK)
        ||token.getTokenType().equals(TokenType.VOIDTK)){
            this.token = token;
        } else {
            System.out.println("funcType here is not void/int/char!");
        }
        return new FuncType(this.token);
    }
}
