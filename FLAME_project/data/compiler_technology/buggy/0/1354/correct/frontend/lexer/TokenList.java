package frontend.lexer;

import java.util.ArrayList;

public class TokenList {
    public final ArrayList<Token> tokens;
    private int index = 0;
    public TokenList() {
        tokens = new ArrayList<>();
    }
    public void append(Token token) {
        tokens.add(token);
    }
    public boolean hasNext() {
        return index < tokens.size();
    }
    public Token getChar() {
        return tokens.get(index++);
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.toString());
        }
        return sb.toString();
    }
}
