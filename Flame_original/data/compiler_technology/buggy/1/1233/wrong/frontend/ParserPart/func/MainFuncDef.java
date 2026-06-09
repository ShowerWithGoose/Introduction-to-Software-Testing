package frontend.ParserPart.func;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.Factor;
import frontend.ParserPart.state.Block;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class MainFuncDef implements Factor {
    private String name = "<MainFuncDef>";
    private TokenList tokenList;
    private Token intToken;
    private Token mainToken;
    private Token leftPARENT;
    private Token rightPARENT;
    private Block block;
    public MainFuncDef(TokenList tokenList){
        this.tokenList = tokenList;
        intToken = new Token(TokenType.INTTK,"int");
        mainToken = new Token(TokenType.MAINTK,"main");
        leftPARENT = new Token(TokenType.LPARENT,"(");
        rightPARENT = new Token(TokenType.RPARENT,")");
        block = new Block(tokenList);
    }
    public void parseMainFuncDef(){
        //指向int
        tokenList.next();
        //指向main
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
        block.parseBlock();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(intToken.toString());
        sb.append(mainToken.toString());
        sb.append(leftPARENT.toString());
        sb.append(rightPARENT.toString());
        sb.append(block.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
