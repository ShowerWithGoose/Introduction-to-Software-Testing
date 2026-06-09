package frontend;

import java.util.ArrayList;

public class TokenList {
    ArrayList<Token> tokenArrayList;
    public TokenList(){
        tokenArrayList = new ArrayList<>();
    }
    public ArrayList<Token> getTokenArrayList(){
        return tokenArrayList;
    }
    public void addToken(Token token){
        tokenArrayList.add(token);
    }
}
