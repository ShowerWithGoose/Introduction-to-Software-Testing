package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.expr.Exp;
import frontend.ParserPart.expr.primaryexp.LVal;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtExp1 implements StmtInterface{
    private TokenList tokenList;
    private LVal lVal;
    private Token equal;
    private Exp exp;
    private Token semicn;
    public StmtExp1(TokenList tokenList){
        this.tokenList = tokenList;
        lVal = new LVal(tokenList);
        equal = new Token(TokenType.ASSIGN,"=");
        exp = new Exp(tokenList);
        semicn = new Token(TokenType.SEMICN,";");
    }
    public void parseStmtExp1(){
        lVal.parseLVal();
        //指向=符号
        tokenList.next();
        exp.parseExp();
        //指向;符号
        if (tokenList.peek().getType().equals(TokenType.SEMICN)) {
        tokenList.next();
        }
        else {
            //说明出错了
            Error error = new Error(ErrorType.i,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(equal.toString());
        sb.append(exp.toString());
        sb.append(semicn.toString());
        return sb.toString();
    }
}
