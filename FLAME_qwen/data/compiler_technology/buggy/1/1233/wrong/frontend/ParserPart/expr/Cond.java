package frontend.ParserPart.expr;

import frontend.Factor;
import frontend.ParserPart.expr.multiexp.LOrExp;
import frontend.TokenPart.TokenList;

public class Cond implements Factor {
    private String name = "<Cond>";
    private TokenList tokenList;
    private LOrExp lOrExp;
    public Cond(TokenList tokenList){
        this.tokenList = tokenList;
        lOrExp = new LOrExp(tokenList);
    }
    public void parseCond(){
        lOrExp.parseLOrExp();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(lOrExp.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
