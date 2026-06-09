package frontend.ParserPart.expr.primaryexp;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.Factor;
import frontend.ParserPart.expr.Exp;
import frontend.ParserPart.term.Ident;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class LVal implements PrimaryExpInterface {
    private String name = "<LVal>";
    private TokenList tokenList;
    private Ident ident;
    private Token leftBRACK;//可能存在
    private Exp exp;//可能存在
    private Token rightBRACK;//可能存在
    public LVal(TokenList tokenList){
        this.tokenList = tokenList;
        ident = new Ident(tokenList);
        leftBRACK = null;
        exp = null;
        rightBRACK = null;
    }
    public void parseLVal(){
        ident.parseIdent();
        if (tokenList.peek().getType().equals(TokenType.LBRACK)){
            //指向[符号
            leftBRACK = new Token(TokenType.LBRACK,"[");
            tokenList.next();
            exp = new Exp(tokenList);
            exp.parseExp();
            //指向]符号
            if (tokenList.peek().getType().equals(TokenType.RBRACK)){
                rightBRACK = new Token(TokenType.RBRACK,"]");
                tokenList.next(); }
            else {
                Error error = new Error(ErrorType.k,tokenList.preRead(-1).getLineNum());
                ErrorList.addError(error);
            }
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (leftBRACK != null){
            sb.append(leftBRACK.toString());
            sb.append(exp.toString());
            sb.append(rightBRACK.toString());
        }
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
