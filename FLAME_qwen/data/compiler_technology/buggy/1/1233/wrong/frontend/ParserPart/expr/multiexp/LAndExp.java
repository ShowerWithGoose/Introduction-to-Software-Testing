package frontend.ParserPart.expr.multiexp;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class LAndExp implements Factor {
    private String name = "<LAndExp>";
    private TokenList tokenList;
    private EqExp eqExp;
    private ArrayList<Token> symbolList;//可能存在
    private ArrayList<EqExp> expArrayList;//可能存在
    public LAndExp(TokenList tokenList){
        this.tokenList = tokenList;
        eqExp = new EqExp(tokenList);
        symbolList = new ArrayList<>();
        expArrayList = new ArrayList<>();
    }
    public void parseLAndExp(){
        eqExp.parseEqExp();
        while (isLAndExpStart()){
            symbolList.add(tokenList.peek());
            tokenList.next();
            EqExp tem = new EqExp(tokenList);
            tem.parseEqExp();
            expArrayList.add(tem);
        }
    }
    public boolean isLAndExpStart(){
        return tokenList.peek().getType().equals(TokenType.AND);
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(eqExp.toString());
        sb.append(name);
        sb.append("\n");
        for (int i = 0; i < symbolList.size(); i++) {
            sb.append(symbolList.get(i).toString());
            sb.append(expArrayList.get(i).toString());
            sb.append(name);
            sb.append("\n");
        }
        return sb.toString();
    }
}
