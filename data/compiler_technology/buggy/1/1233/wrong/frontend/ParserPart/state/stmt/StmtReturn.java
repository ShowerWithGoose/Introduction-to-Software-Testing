package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.expr.Exp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtReturn implements StmtInterface{
    private TokenList tokenList;
    private Token returnToken;
    private Exp exp;//可能存在
    private Token secimn;
    public StmtReturn(TokenList tokenList){
        this.tokenList = tokenList;
        returnToken = new Token(TokenType.RETURNTK,"return");
        exp = null;
        secimn = new Token(TokenType.SEMICN,";");
    }
    public void parseStmtReturn(){
        //指向return
        System.out.println("!!!"+tokenList.peek());
        tokenList.next();

        if (isExpStart()){
            exp = new Exp(tokenList);
            exp.parseExp();
        }
        //指向;
        if (tokenList.peek().getType().equals(TokenType.SEMICN)){
            tokenList.next(); }
        else {
            System.out.println(tokenList.peek().getValue()+"!!!");
            Error error = new Error(ErrorType.i,tokenList.preRead(-1).getLineNum());
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
        sb.append(returnToken.toString());
        if (exp != null){
            sb.append(exp.toString());
        }
        sb.append(secimn.toString());
        return sb.toString();
    }
}
