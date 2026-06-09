package frontend.ParserPart.expr;

import frontend.Factor;
import frontend.ParserPart.decl.variable.varinitval.InitValInterface;
import frontend.ParserPart.expr.multiexp.AddExp;
import frontend.ParserPart.expr.primaryexp.PrimaryExpInterface;
import frontend.TokenPart.TokenList;

public class Exp implements InitValInterface {
    private String name = "<Exp>";
    private TokenList tokenList;
    private AddExp addExp;
    public Exp(TokenList tokenList){
        this.tokenList = tokenList;
        addExp = new AddExp(tokenList);
    }
    public void parseExp(){
        addExp.parseAddExp();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
