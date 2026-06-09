package frontend.lexer;

import java.util.ArrayList;
import java.util.ListIterator;

public class TokenIterator {
    private ArrayList<Token> tokenList;
    private ListIterator<Token> iterator;
    private Token nowToken;

    public TokenIterator(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        this.iterator = this.tokenList.listIterator();
    }

    public Token getNextToken() {
        nowToken = iterator.next();
        return nowToken;
    }

    public int nextIndex() {
        return iterator.nextIndex();
    }

    public void ungetToken(int n) {
        int i = n;
        while (i > 0) {
            i--;
            if (this.iterator.hasPrevious()) {
                nowToken = iterator.previous();
                //iterator向前移动，且返回该值
            } else {
                break;
            }
        }
    }

    public Boolean hasNext() {
        return iterator.hasNext();
    }
}
