package frontend.ParserPart.expr.primaryexp;

import frontend.Factor;
import frontend.ParserPart.term.IntConst;
import frontend.TokenPart.TokenList;

public class Number implements PrimaryExpInterface {
    private String name = "<Number>";
    private TokenList tokenList;
    private IntConst intConst;
    public Number(TokenList tokenList){
        this.tokenList = tokenList;
        intConst = new IntConst(tokenList);
    }
    public void parseNumber(){
        intConst.parseIntConst();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
