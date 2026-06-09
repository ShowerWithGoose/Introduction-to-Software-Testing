package Frontend;

import java.util.*;

import Utils.Token;

public class TokenList {
    public final ArrayList<Token> tokens = new ArrayList<>();
    private int index = 0;
    private LinkedList<Integer> history = new LinkedList<>();

    public void add(Token token) { tokens.add(token); }

    public Token last() { return tokens.get(tokens.size() - 1); }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) sb.append(token).append('\n');
        return sb.toString();
    }

    public int nowat() { return index; }

    public boolean hasNext() { return index < tokens.size(); }

    public Token get() { return this.ahead(0); }

    public Token ahead(int count) { return tokens.get(index + count); }

    public Token consume() {
        Token token = this.get();
        index++;
        return token;
    }

    public Token consume(Token.Type... types){
        if (!hasNext()) return null;
        Token token = tokens.get(index);
        for (Token.Type type : types) {
            if (token.getType().equals(type)) {
                index++;
                return token;
            }
        } return null;
    }

    public Token tryConsume(Token.Type... types){
        if (!hasNext()) return null;
        Token token = tokens.get(index);
        for (Token.Type type : types) {
            if (token.getType().equals(type)) {
                return token;
            }
        } return null;
    }

    public void rollback() { index = history.getLast(); }

    public void commit() { history.removeLast(); }

    public void stamp() { history.add(index); }

    public Token previousToken() {
        if (index == 0) return null;
        return tokens.get(index - 1);
    }
}
