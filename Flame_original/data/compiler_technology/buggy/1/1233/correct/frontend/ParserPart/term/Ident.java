package frontend.ParserPart.term;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;

public class Ident implements Factor {
    private String name = "<Ident>";
    private TokenList tokenList;
    private Token identName;
    public Ident(TokenList tokenList){
        this.tokenList = tokenList;
        identName = null;
    }
    public void parseIdent(){
        identName = tokenList.peek();
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(identName.toString());
        return sb.toString();
    }
}
