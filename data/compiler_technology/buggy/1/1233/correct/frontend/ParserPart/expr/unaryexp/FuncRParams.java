package frontend.ParserPart.expr.unaryexp;

import frontend.Factor;
import frontend.ParserPart.expr.Exp;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class FuncRParams implements Factor {
    private String name = "<FuncRParams>";
    private TokenList tokenList;
    private Exp exp;//开头的一个
    private ArrayList<Token> commas;//可能存在
    private ArrayList<Exp> expArrayList;//可能存在
    public FuncRParams(TokenList tokenList){
        this.tokenList = tokenList;
        exp = new Exp(tokenList);
        commas = new ArrayList<>();
        expArrayList = new ArrayList<>();
    }
    public void parseFuncRParams(){
        exp.parseExp();
        while (tokenList.peek().getType().equals(TokenType.COMMA)){
            //指向,
            Token token = new Token(TokenType.COMMA,",");
            commas.add(token);
            tokenList.next();
            Exp tem = new Exp(tokenList);
            tem.parseExp();
            expArrayList.add(tem);
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(exp.toString());
        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i).toString());
            sb.append(expArrayList.get(i).toString());
        }
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
