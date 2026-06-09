package frontend.ParserPart.expr.unaryexp;

import frontend.TokenPart.TokenList;

public class UnaryExpMul2 implements UnaryExpInterface{
    private TokenList tokenList;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;
    public UnaryExpMul2(TokenList tokenList){
        this.tokenList = tokenList;
        unaryOp = new UnaryOp(tokenList);
        unaryExp = new UnaryExp(tokenList);
    }
    public void parseUnaryExpMul2(){
        unaryOp.parseUnaryOp();
        unaryExp.parseUnaryExp();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(unaryOp.toString());
        sb.append(unaryExp.toString());
        return sb.toString();
    }
}
