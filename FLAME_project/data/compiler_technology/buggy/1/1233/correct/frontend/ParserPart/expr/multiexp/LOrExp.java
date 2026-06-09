package frontend.ParserPart.expr.multiexp;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class LOrExp implements Factor {
    private String name = "<LOrExp>";
    private TokenList tokenList;
    private LAndExp lAndExp;
    private ArrayList<Token> symbolList;//可能存在
    private ArrayList<LAndExp> lAndExpArrayList;//可能存在
    public LOrExp(TokenList tokenList){
        this.tokenList = tokenList;
        lAndExp = new LAndExp(tokenList);
        symbolList = new ArrayList<>();
        lAndExpArrayList = new ArrayList<>();
    }
    public void parseLOrExp(){
        lAndExp.parseLAndExp();
        while (isLOrExpStart()){
            symbolList.add(tokenList.peek());
            tokenList.next();
            LAndExp tem = new LAndExp(tokenList);
            tem.parseLAndExp();
            lAndExpArrayList.add(tem);
        }
    }
    public boolean isLOrExpStart(){
        return tokenList.peek().getType().equals(TokenType.OR);
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(lAndExp.toString());
        sb.append(name);
        sb.append("\n");
        for (int i = 0; i < symbolList.size(); i++) {
            sb.append(symbolList.get(i).toString());
            sb.append(lAndExpArrayList.get(i).toString());
            sb.append(name);
            sb.append("\n");
        }
        return sb.toString();
    }
}
