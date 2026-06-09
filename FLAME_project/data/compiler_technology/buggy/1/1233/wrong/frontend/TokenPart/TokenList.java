package frontend.TokenPart;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokenArrayList;
    private int position;//标识进行语法处理的token位置
    public TokenList(){
        tokenArrayList = new ArrayList<>();
        position = 0;
    }
    public ArrayList<Token> getTokenArrayList(){
        return tokenArrayList;
    }
    public void addToken(Token token){
        tokenArrayList.add(token);
    }
    public Token peek(){
        if (position < tokenArrayList.size()){
        return tokenArrayList.get(position); }
        else {
            return new Token(TokenType.END,"end");
        }
    }
    public void next(){
        position++;
    }
    public Token preRead(int prePosition){
        //prePosition代表要预读第几个
        return tokenArrayList.get(prePosition + position);
    }
    public boolean hasNext(){
        return (position < tokenArrayList.size());
    }
}
