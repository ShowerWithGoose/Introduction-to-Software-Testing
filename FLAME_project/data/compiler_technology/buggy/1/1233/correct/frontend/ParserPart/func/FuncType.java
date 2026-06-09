package frontend.ParserPart.func;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;

public class FuncType implements Factor {
    private String name = "<FuncType>";
    private TokenList tokenList;
    private Token token;//void或者int或者char
    public FuncType(TokenList tokenList){
        this.tokenList = tokenList;
        token = null;
    }
    public void parseFuncType(){
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
