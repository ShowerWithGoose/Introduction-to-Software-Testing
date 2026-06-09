package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtContinue implements StmtInterface{
    private TokenList tokenList;
    private Token continueToken;
    private Token secimn;
    public StmtContinue(TokenList tokenList){
        this.tokenList = tokenList;
        continueToken = new Token(TokenType.CONTINUETK,"continue");
        secimn = new Token(TokenType.SEMICN,";");
    }
    public void parseStmtContinue(){
        //指向continue
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
        sb.append(continueToken.toString());
        sb.append(secimn.toString());
        return sb.toString();
    }
}
