package frontend.Lexer;

import java.util.ArrayList;

//记录已经解析出的Tokens
public class TokenResolved {
    private final ArrayList<Token> tokenList;

    public TokenResolved() {
        this.tokenList = new ArrayList<>();
    }

    public void addToken(Token token) {
        this.tokenList.add(token);
    }

    public ArrayList<Token> getTokenList() {
        return tokenList;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        for (Token token : this.tokenList) {
            sb.append(token.getTokenType().name()+" "+token.getValue()+"\n");
        }
        return sb.toString();
    }
}
