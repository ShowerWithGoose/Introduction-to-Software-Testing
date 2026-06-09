package frontend.ParserPart.term;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;

public class CharConst implements Factor {
    private TokenList tokenList;
    private Token charConstToken;
    public CharConst(TokenList tokenList){
        this.tokenList = tokenList;
        charConstToken = null;
    }
    public void parseCharConst(){
        //指向intConst
        charConstToken = tokenList.peek();
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(charConstToken.toString());
        return sb.toString();
    }
}
