package frontend.ParserPart.expr.primaryexp;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.expr.Exp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class PrimaryExpMul implements PrimaryExpInterface{
    private TokenList tokenList;
    private Token leftPARENT;
    private Exp exp;
    private Token rightPARENT;
    public PrimaryExpMul(TokenList tokenList){
        this.tokenList = tokenList;
        leftPARENT = new Token(TokenType.LPARENT,"(");
        exp = new Exp(tokenList);
        rightPARENT = new Token(TokenType.RPARENT,")");
    }
    public void parsePrimaryExpMul(){
        //指向(
        tokenList.next();
        exp.parseExp();
        //指向)
        if (tokenList.peek().getType().equals(TokenType.RPARENT)){
            tokenList.next(); }
        else {
            Error error = new Error(ErrorType.j,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(leftPARENT.toString());
        sb.append(exp.toString());
        sb.append(rightPARENT.toString());
        return sb.toString();
    }
}
