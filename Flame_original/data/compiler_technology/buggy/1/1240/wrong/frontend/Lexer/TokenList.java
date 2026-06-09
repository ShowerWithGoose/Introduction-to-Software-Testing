package frontend.Lexer;

import java.util.ArrayList;

public class TokenList {
    ArrayList<LexType> tokens = new ArrayList<>();
    private int index;

    public TokenList() {
        this.index = 0;
    }

    public ArrayList<LexType> getTokens() {
        return tokens;
    }

    public void add(LexType token) {
        tokens.add(token);
    }

    public LexType getToken() {
        return tokens.get(index);
    }

    public LexType getAndMove() {
        return tokens.get(index++);
    }

    public void retreat(int n) {
        index -= n;
    }

    public LexType getlastToken(int a) {
        int n = index - a;
        return tokens.get(n);
    }

    public boolean isEnd() {
        return index >= tokens.size();
    }

    public void forward(int n) {
        index += n;
    }
}
