package frontend;

import java.util.ArrayList;

public class TokenList {
    public ArrayList<Token> tokenLists = new ArrayList<Token>();
    int index = 0;

    public void append(Token token) {
        tokenLists.add(token);
    }

    public boolean hasNext() {
        return index < tokenLists.size();
    }

    public Token get() {
        return tokenLists.get(index);
    }

    public Token ahead(int cnt) {
        return tokenLists.get(index + cnt);
    }

    public Token consumeExpect(TokenType type) {
        Token token = tokenLists.get(index);
        if (token.type != type) {
            throw new RuntimeException("Expected " + type + " but got " + token.type);
        }
        index++;
        return token;
    }

}
