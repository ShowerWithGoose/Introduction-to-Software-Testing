package token;

import java.util.ArrayList;

public class TokenList {
    public ArrayList<Token> tokenList = new ArrayList<>();

    public void addToken(Token token) {
        tokenList.add(token);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokenList) {
            sb.append(token.toString() + "\n");
        }
        return sb.toString();
    }
}
