package frontend.ParserPart.func;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.Factor;
import frontend.ParserPart.state.Block;
import frontend.ParserPart.term.Ident;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class FuncDef implements Factor {
    private String name = "<FuncDef>";
    private TokenList tokenList;
    private FuncType funcType;
    private Ident ident;
    private Token leftPARENT;
    private FuncFParams funcFParams;//可能存在
    private Token rightPARENT;
    private Block block;
    public FuncDef(TokenList tokenList){
        this.tokenList = tokenList;
        funcType = new FuncType(tokenList);
        ident = new Ident(tokenList);
        leftPARENT = new Token(TokenType.LPARENT,"(");
        funcFParams = null;
        rightPARENT = new Token(TokenType.RPARENT,")");
        block = new Block(tokenList);
    }
    public void parseFuncDef(){
        funcType.parseFuncType();
        ident.parseIdent();
        //指向(符号
        tokenList.next();
        if (tokenList.peek().getType().equals(TokenType.INTTK) || tokenList.peek().getType().equals(TokenType.CHARTK)){
            funcFParams = new FuncFParams(tokenList);
            funcFParams.parseFuncParams();
        }
        //指向)符号
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
        sb.append(funcType.toString());
        sb.append(ident.toString());
        sb.append(leftPARENT.toString());
        if (funcFParams != null){
            sb.append(funcFParams.toString());
        }
        sb.append(rightPARENT.toString());
        sb.append(block.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }

}
