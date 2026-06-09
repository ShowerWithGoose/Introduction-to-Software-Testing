package frontend.ParserPart.expr.unaryexp;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;

public class UnaryOp implements Factor {
    private String name = "<UnaryOp>";
    private TokenList tokenList;
    private Token token;
    public UnaryOp(TokenList tokenList){
        this.tokenList = tokenList;
        token = null;
    }
    public void parseUnaryOp(){
        token = tokenList.peek();
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(token.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
