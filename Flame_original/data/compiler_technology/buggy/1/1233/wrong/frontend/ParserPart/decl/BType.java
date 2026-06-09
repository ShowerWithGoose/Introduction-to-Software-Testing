package frontend.ParserPart.decl;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;

public class BType implements Factor {
    private String name = "<BType>";
    private TokenList tokenList;
    private Token token;//表示int或者char
    public BType(TokenList tokenList){
        this.tokenList = tokenList;
        this.token = null;
    }
    public void parseBType(){
        Token token1 = tokenList.peek();
        token = token1;
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(token.toString());
        return sb.toString();
    }
}
