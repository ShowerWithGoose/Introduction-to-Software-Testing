package frontend.lex;

import java.util.ArrayList;

public class TokenList {
    public static ArrayList<Token> tokens = new ArrayList<>();
    private int index = 0;
    public void addToken(Token token) {
        tokens.add(token);
    }
    public Token checkAheadChar(int count) {
        return tokens.get(index + count);
    }

    public boolean hasNext() {
        return index < tokens.size();
    }

    public Token getChar() {
        return tokens.get(index++);
    }

    public void skipChar() {
        index++;
    }
}
