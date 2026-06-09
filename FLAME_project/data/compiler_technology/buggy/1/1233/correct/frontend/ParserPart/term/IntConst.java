package frontend.ParserPart.term;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;

public class IntConst implements Factor {
    private TokenList tokenList;
    private Token intConstToken;
    public IntConst(TokenList tokenList){
        this.tokenList = tokenList;
        intConstToken = null;
    }
    public void parseIntConst(){
        //指向intConst
        intConstToken = tokenList.peek();
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(intConstToken.toString());
        return sb.toString();
    }
}
