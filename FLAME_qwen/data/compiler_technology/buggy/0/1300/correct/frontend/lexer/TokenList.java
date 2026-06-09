package frontend.lexer;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokens = new ArrayList<>();

    public void addToken(Token t) {
        tokens.add(t);
    }

    public boolean isEmpty() {
        return tokens.isEmpty();
    }

    public int size() {
        return tokens.size();
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }
}
