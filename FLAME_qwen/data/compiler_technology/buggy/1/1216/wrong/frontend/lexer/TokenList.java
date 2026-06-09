package frontend.lexer;

import java.util.ArrayList;

public class TokenList {
    private final ArrayList<Token> tokens = new ArrayList<>();
    public void add(Token token) {
        this.tokens.add(token);
    }
    public Token get(int index) {
        return tokens.get(index);
    }
    public int getSize() {
        return tokens.size();
    }
    public void clear() { this.tokens.clear(); }

    public Token getLast() {
        return this.tokens.get(Math.max(getSize() - 1, 0));
    }
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (Token token: tokens) {
            result.append(token);
        }
        return result.toString();
    }
    public void printInfo() {
        for (Token token: tokens) {
            System.out.println(token.getLine() + " " + token.getType() + " " + token.getName());
        }
    }
}
