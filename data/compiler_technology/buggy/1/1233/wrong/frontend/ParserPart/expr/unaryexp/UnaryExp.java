package frontend.ParserPart.expr.unaryexp;

import frontend.Factor;
import frontend.ParserPart.expr.primaryexp.PrimaryExp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class UnaryExp implements Factor {
    private String name = "<UnaryExp>";
    private TokenList tokenList;
    private UnaryExpInterface unaryExpInterface;
    public UnaryExp(TokenList tokenList){
        this.tokenList = tokenList;
        unaryExpInterface = null;
    }
    public void parseUnaryExp(){
        Token token = tokenList.peek();
        if (isUnaryOpStart()){
            //对应Mul2情况
            UnaryExpMul2 unaryExpMul2 = new UnaryExpMul2(tokenList);
            unaryExpMul2.parseUnaryExpMul2();
            unaryExpInterface = unaryExpMul2;
        } else if (token.getType().equals(TokenType.IDENFR) && tokenList.preRead(1).getType().equals(TokenType.LPARENT)) {
            //Ident开头，对应Mul1情况
            UnaryExpMul1 unaryExpMul1 = new UnaryExpMul1(tokenList);
            unaryExpMul1.parseUnaryExpMul1();
            unaryExpInterface = unaryExpMul1;
        }else {
            //(开头，对应PrimaryExp情况
            PrimaryExp primaryExp = new PrimaryExp(tokenList);
            primaryExp.parsePrimaryExp();
            unaryExpInterface = primaryExp;
        }
    }
    public boolean isUnaryOpStart(){
        return (tokenList.peek().getType().equals(TokenType.PLUS) || tokenList.peek().getType().equals(TokenType.MINU) ||
                tokenList.peek().getType().equals(TokenType.NOT));
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExpInterface.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
