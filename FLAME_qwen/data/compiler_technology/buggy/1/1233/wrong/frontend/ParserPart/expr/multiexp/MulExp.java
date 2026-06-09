package frontend.ParserPart.expr.multiexp;

import frontend.Factor;
import frontend.ParserPart.expr.unaryexp.UnaryExp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class MulExp implements Factor {
    private String name = "<MulExp>";
    private TokenList tokenList;
    private UnaryExp unaryExp;
    private ArrayList<UnaryExp> unaryExpArrayList;//可能存在
    private ArrayList<Token> symbolList;//乘除余符号表
    public MulExp(TokenList tokenList){
        this.tokenList = tokenList;
        unaryExp = new UnaryExp(tokenList);
        unaryExpArrayList = new ArrayList<>();
        symbolList = new ArrayList<>();
    }
    public void parseMulExp(){
        unaryExp.parseUnaryExp();
        while (isMulExpStart()){
            //如果存在之后的乘除余
            symbolList.add(tokenList.peek());
            tokenList.next();
            UnaryExp tem = new UnaryExp(tokenList);
            tem.parseUnaryExp();
            unaryExpArrayList.add(tem);
        }
    }
    public boolean isMulExpStart(){
        return (tokenList.peek().getType().equals(TokenType.MULT) || tokenList.peek().getType().equals(TokenType.DIV)
                || tokenList.peek().getType().equals(TokenType.MOD));
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExp.toString());
        sb.append(name);
        sb.append("\n");
        for (int i = 0; i < symbolList.size(); i++) {
            sb.append(symbolList.get(i).toString());
            sb.append(unaryExpArrayList.get(i).toString());
            sb.append(name);
            sb.append("\n");
        }
        return sb.toString();
    }
}
