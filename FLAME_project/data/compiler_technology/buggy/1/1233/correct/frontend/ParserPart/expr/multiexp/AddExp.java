package frontend.ParserPart.expr.multiexp;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class AddExp implements Factor {
    private String name = "<AddExp>";
    private TokenList tokenList;
    private MulExp mulExp;//代表结尾的一个
    private ArrayList<MulExp> mulExpArrayList;//代表剩下的mul
    private ArrayList<Token> symbolList;//加减符号表
    public AddExp(TokenList tokenList){
        this.tokenList = tokenList;
        mulExp = new MulExp(tokenList);
        mulExpArrayList = new ArrayList<>();
        symbolList = new ArrayList<>();
    }
    public void parseAddExp(){
        mulExp.parseMulExp();
        while (isAddExpStart()){
            //如果存在之后的加减
            symbolList.add(tokenList.peek());
            tokenList.next();
            MulExp tem = new MulExp(tokenList);
            tem.parseMulExp();
            mulExpArrayList.add(tem);
        }
    }
    public boolean isAddExpStart(){
        return (tokenList.peek().getType().equals(TokenType.PLUS) || tokenList.peek().getType().equals(TokenType.MINU));
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(mulExp.toString());
        sb.append(name);
        sb.append("\n");
        for (int i = 0; i < symbolList.size(); i++) {
            sb.append(symbolList.get(i).toString());
            sb.append(mulExpArrayList.get(i).toString());
            sb.append(name);
            sb.append("\n");
        }
        return sb.toString();
    }
}
