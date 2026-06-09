package frontend.ParserPart.term;

import frontend.Factor;
import frontend.ParserPart.decl.constant.constinitval.ConstInitValInterface;
import frontend.ParserPart.decl.variable.varinitval.InitValInterface;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StringConst implements ConstInitValInterface, InitValInterface {
    private String name = "<StringConst>";
    private TokenList tokenList;
    private Token stringToken;
    public StringConst(TokenList tokenList){
        this.tokenList = tokenList;
        stringToken = null;
    }
    public void parseStringConst(){
        stringToken = tokenList.peek();
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(stringToken.toString());
        return sb.toString();
    }
}
