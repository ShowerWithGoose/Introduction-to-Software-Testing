package frontend.ParserPart.expr.multiexp;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class EqExp implements Factor {
    private String name = "<EqExp>";
    private TokenList tokenList;
    private RelExp relExp;
    private ArrayList<Token> symbolList;//可能存在
    private ArrayList<RelExp> relExpArrayList;//可能存在
    public EqExp(TokenList tokenList){
        this.tokenList = tokenList;
        relExp = new RelExp(tokenList);
        symbolList = new ArrayList<>();
        relExpArrayList = new ArrayList<>();
    }
    public void parseEqExp(){
        relExp.parseRelExp();
        while (isEqExpStart()){
            symbolList.add(tokenList.peek());
            tokenList.next();
            RelExp tem = new RelExp(tokenList);
            tem.parseRelExp();
            relExpArrayList.add(tem);
        }
    }
    public boolean isEqExpStart(){
        return (tokenList.peek().getType().equals(TokenType.EQL) || tokenList.peek().getType().equals(TokenType.NEQ));
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(relExp.toString());
        sb.append(name);
        sb.append("\n");
        for (int i = 0; i < symbolList.size(); i++) {
            sb.append(symbolList.get(i).toString());
            sb.append(relExpArrayList.get(i).toString());
            sb.append(name);
            sb.append("\n");
        }
        return sb.toString();
    }
}
