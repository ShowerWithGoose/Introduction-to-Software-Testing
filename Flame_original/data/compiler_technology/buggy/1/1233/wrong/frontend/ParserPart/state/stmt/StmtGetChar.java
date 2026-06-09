package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.expr.primaryexp.LVal;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtGetChar implements StmtInterface{
    private TokenList tokenList;
    private LVal lVal;
    private Token equal;
    private Token getcharToken;
    private Token leftPARENT;
    private Token rightPARENT;
    private Token secimn;
    public StmtGetChar(TokenList tokenList){
        this.tokenList = tokenList;
        lVal = new LVal(tokenList);
        equal = new Token(TokenType.ASSIGN,"=");
        getcharToken = new Token(TokenType.GETCHARTK,"getchar");
        leftPARENT = new Token(TokenType.LPARENT,"(");
        rightPARENT = new Token(TokenType.RPARENT,")");
        secimn = new Token(TokenType.SEMICN,";");
    }
    public void parseStmtGetChar(){
        lVal.parseLVal();
        //指向=
        tokenList.next();
        //指向getchar
        tokenList.next();
        //指向(
        tokenList.next();
        //指向)
        if (tokenList.peek().getType().equals(TokenType.RPARENT)){
            tokenList.next(); }
        else {
            Error error = new Error(ErrorType.j,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
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
        sb.append(lVal.toString());
        sb.append(equal.toString());
        sb.append(getcharToken.toString());
        sb.append(leftPARENT.toString());
        sb.append(rightPARENT.toString());
        sb.append(secimn.toString());
        return sb.toString();
    }
}
