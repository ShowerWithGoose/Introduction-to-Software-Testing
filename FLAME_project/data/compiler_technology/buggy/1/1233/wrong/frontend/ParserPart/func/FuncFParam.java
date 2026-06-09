package frontend.ParserPart.func;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.Factor;
import frontend.ParserPart.decl.BType;
import frontend.ParserPart.term.Ident;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class FuncFParam implements Factor {
    private String name = "<FuncFParam>";
    private TokenList tokenList;
    private BType bType;
    private Ident ident;
    private Token leftBRACK;//可能存在
    private Token rightBRACK;//可能存在
    public FuncFParam(TokenList tokenList){
        this.tokenList = tokenList;
        bType = new BType(tokenList);
        ident = new Ident(tokenList);
        leftBRACK = null;
        rightBRACK = null;
    }
    public void parseFuncFParam(){
        bType.parseBType();
        ident.parseIdent();
        if (tokenList.peek().getType().equals(TokenType.LBRACK)){
            //存在可选项
            leftBRACK = new Token(TokenType.LBRACK,"[");
            tokenList.next();
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
        sb.append(bType.toString());
        sb.append(ident.toString());
        if (leftBRACK != null){
            sb.append(leftBRACK.toString());
            sb.append(rightBRACK.toString());
        }
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
