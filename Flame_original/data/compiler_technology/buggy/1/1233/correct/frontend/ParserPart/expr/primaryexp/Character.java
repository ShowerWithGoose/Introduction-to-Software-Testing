package frontend.ParserPart.expr.primaryexp;

import frontend.Factor;
import frontend.ParserPart.term.CharConst;
import frontend.TokenPart.TokenList;

public class Character implements PrimaryExpInterface {
    private String name = "<Character>";
    private TokenList tokenList;
    private CharConst charConst;
    public Character(TokenList tokenList){
        this.tokenList = tokenList;
        charConst = new CharConst(tokenList);
    }
    public void parseCharacter(){
        charConst.parseCharConst();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
