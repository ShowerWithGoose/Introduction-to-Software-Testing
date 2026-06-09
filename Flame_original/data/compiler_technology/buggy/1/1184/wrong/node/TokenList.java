package node;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokens;
    private int index;

    public TokenList() {
        this.tokens = new ArrayList<>();
        this.index = 0;
    }

    public void add(Token t) {
        tokens.add(t);
    }

    public void print() {
        for(Token token:tokens) {
            System.out.println(token);
        }
    }

    public Token getNext() {
        index++;
        return tokens.get(index-1);
    }

    public Token backLast() {
        index--;
        return tokens.get(index-1);
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int i) {
        index = i;
    }
}
