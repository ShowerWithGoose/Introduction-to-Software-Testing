package frontend.ParserPart.expr.multiexp;

import frontend.Factor;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class RelExp implements Factor {
    private String name = "<RelExp>";
    private TokenList tokenList;
    private AddExp addExp;//开头的第一个
    private ArrayList<Token> symbolList;//四种符号的符号表，可能存在
    private ArrayList<AddExp> addExpArrayList;//可能存在
    public RelExp(TokenList tokenList){
        this.tokenList = tokenList;
        addExp = new AddExp(tokenList);
        symbolList = new ArrayList<>();
        addExpArrayList = new ArrayList<>();
    }
    public void parseRelExp(){
        addExp.parseAddExp();
        while (isRelExpStart()){
            symbolList.add(tokenList.peek());
            tokenList.next();
            AddExp tem = new AddExp(tokenList);
            tem.parseAddExp();
            addExpArrayList.add(tem);
        }
    }
    public boolean isRelExpStart(){
        return (tokenList.peek().getType().equals(TokenType.LSS) || tokenList.peek().getType().equals(TokenType.LEQ) ||
                tokenList.peek().getType().equals(TokenType.GRE) || tokenList.peek().getType().equals(TokenType.GEQ));
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toString());
        sb.append(name);
        sb.append("\n");
        for (int i = 0; i < symbolList.size(); i++) {
            sb.append(symbolList.get(i).toString());
            sb.append(addExpArrayList.get(i).toString());
            sb.append(name);
            sb.append("\n");
        }
        return sb.toString();
    }
}
