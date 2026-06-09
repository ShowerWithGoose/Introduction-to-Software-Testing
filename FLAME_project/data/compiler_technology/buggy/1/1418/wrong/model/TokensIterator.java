package model;

import java.util.List;

public class TokensIterator {
    private List<Token> tokens;
    private int cursor = -1;
    public TokensIterator(List<Token> tokens){
        this.tokens = tokens;
    }
    public Token next() {
        if(cursor < tokens.size()-1) {
            cursor++;
            return tokens.get(cursor);
        }
        else return null;
    }
    public void unread(int n) {
        while(n > 0) {
            if(cursor > -1) {
                cursor--;
                n--;
            }
            else break;
        }
    }
    public boolean isEnd() {
        return cursor >= tokens.size()-1;
    }
    public int getCursor() {
        return this.cursor;
    }
    public void setCursor(int c) {
        this.cursor = c;
    }
}
