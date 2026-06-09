package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtBreak implements StmtInterface{
    private TokenList tokenList;
    private Token breakToken;
    private Token secimn;
    public StmtBreak(TokenList tokenList){
        this.tokenList = tokenList;
        breakToken = new Token(TokenType.BREAKTK,"break");
        secimn = new Token(TokenType.SEMICN,";");
    }
    public void parseStmtBreak(){
        //指向break
        tokenList.next();
        //指向;
        if (tokenList.peek().getType().equals(TokenType.SEMICN)){
        tokenList.next(); }
        else {
            Error error = new Error(ErrorType.i,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(breakToken.toString());
        sb.append(secimn.toString());
        return sb.toString();
    }
}
