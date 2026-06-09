package frontend.ParserPart.expr;

import frontend.Factor;
import frontend.ParserPart.decl.constant.constinitval.ConstInitValInterface;
import frontend.ParserPart.expr.multiexp.AddExp;
import frontend.TokenPart.TokenList;

public class ConstExp implements ConstInitValInterface {
    private String name = "<ConstExp>";
    private TokenList tokenList;
    private AddExp addExp;
    public ConstExp(TokenList tokenList){
        this.tokenList = tokenList;
        addExp = new AddExp(tokenList);
    }
    public void parseConstExp(){
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
