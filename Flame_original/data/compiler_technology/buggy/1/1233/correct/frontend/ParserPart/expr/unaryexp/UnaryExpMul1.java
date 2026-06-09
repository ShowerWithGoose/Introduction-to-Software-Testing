package frontend.ParserPart.expr.unaryexp;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.term.Ident;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class UnaryExpMul1 implements UnaryExpInterface{
    private TokenList tokenList;
    private Ident ident;
    private Token leftPARENT;
    private FuncRParams funcRParams;//可能存在
    private Token rightPARENT;
    public UnaryExpMul1(TokenList tokenList){
        this.tokenList = tokenList;
        ident = new Ident(tokenList);
        leftPARENT = new Token(TokenType.LPARENT,"(");
        funcRParams = null;
        rightPARENT = new Token(TokenType.RPARENT,")");
    }
    public void parseUnaryExpMul1(){
        ident.parseIdent();
        //指向(
        tokenList.next();
        if (isExpStart()){
            funcRParams = new FuncRParams(tokenList);
            funcRParams.parseFuncRParams();
        }
        //指向)
        if (tokenList.peek().getType().equals(TokenType.RPARENT)){
            tokenList.next(); }
        else {
            Error error = new Error(ErrorType.j,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
    }
    public boolean isExpStart(){
        return (tokenList.peek().getType().equals(TokenType.LPARENT) ||
                tokenList.peek().getType().equals(TokenType.IDENFR) ||
                tokenList.peek().getType().equals(TokenType.INTCON) ||
                tokenList.peek().getType().equals(TokenType.CHRCON) ||
                tokenList.peek().getType().equals(TokenType.PLUS) ||
                tokenList.peek().getType().equals(TokenType.MINU) ||
                tokenList.peek().getType().equals(TokenType.NOT) );
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        sb.append(leftPARENT.toString());
        if (funcRParams != null){
            sb.append(funcRParams.toString());
        }
        sb.append(rightPARENT.toString());
        return sb.toString();
    }

}
