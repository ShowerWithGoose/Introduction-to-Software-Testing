package frontend;

import java.util.ArrayList;
import java.util.ListIterator;

import nodes.Token;

public class TokenIterator {
    private ArrayList<Token> tokenList;
    private ListIterator<Token> iterator;
    private Token lastToken;

    public Token getLastToken() {
        return lastToken;
    }

    public TokenIterator(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        this.iterator = tokenList.listIterator();
    }

    public boolean hasNext() {
        return iterator.hasNext();
    }

    public Token next() {
        return lastToken = iterator.next();
    }

    public boolean stepBack(int steps) {
        int cnt = steps;
        while (cnt > 0) {
            cnt--;
            if (this.iterator.hasPrevious()) {
                lastToken = iterator.previous();
            } else {
                break;
            }
        }
        return true;
    }

    @Override
    public String toString() {
        return iterator.nextIndex() + " " + lastToken.toString();
    }

    public int curIndex() {
        return iterator.nextIndex();
    }
}
