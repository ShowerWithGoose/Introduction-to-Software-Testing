package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.expr.Exp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtExp2 implements StmtInterface{
    private TokenList tokenList;
    private Exp exp;//可能存在
    private Token semicn;
    public StmtExp2(TokenList tokenList){
        this.tokenList = tokenList;
        exp = null;
        semicn = new Token(TokenType.SEMICN,";");
    }
    public void parseStmtExp2(){
        if (isExpStart()){
            exp = new Exp(tokenList);
            exp.parseExp();
        }
        //指向;符号
        if (tokenList.peek().getType().equals(TokenType.SEMICN)){
        tokenList.next();
        }
        else {
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
        if (exp != null){
            sb.append(exp.toString());
        }
        sb.append(semicn.toString());
        return sb.toString();
    }
}
