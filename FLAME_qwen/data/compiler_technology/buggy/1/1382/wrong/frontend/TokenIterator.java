package frontend;

import java.util.ArrayList;
import java.util.ListIterator;

public class TokenIterator{
    private ListIterator<Token> iterator;
    private final Token theEnd;
    private Token cur;

    public TokenIterator(ArrayList<Token> tokenList) {
        iterator = tokenList.listIterator();
        iterator.next();
        theEnd = new Token(LexType.END, null, null, tokenList.get(tokenList.size()-1).getLineNum());
    }

    public Token getNext() {
        if (iterator.hasNext())  {
            return cur = iterator.next();
        }
        else return theEnd;
    }

    public boolean hasNext() {
        return iterator.hasNext();
    }

    public Token getPrevious() {
        if (iterator.hasPrevious()) {
            iterator.previous();
        }
        if (iterator.hasPrevious()) {
            iterator.previous();
        }
        return getNext();
    }

    public void getBack(int n) {
        for (int i = 0; i < n; i++) {
            getPrevious();
        }
    }
}
