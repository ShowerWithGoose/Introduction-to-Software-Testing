package frontend.lexer;

import java.util.Iterator;
import java.util.ListIterator;

/**
 * TokenList迭代器
 * 实现对符号表的顺序读取
 */
public class TokenListIterator implements Iterator<Token> {
    private TokenList tokenList;
    private ListIterator<Token> iterator;
    private Token lastToken;

    public TokenListIterator(TokenList tokenList) {
        this.tokenList = tokenList;
        this.iterator = this.tokenList.getTokens().listIterator();
    }

    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    public Token next() {
        lastToken = this.iterator.next();
        return lastToken;
    }

    public void unRead(int k) {
        while (k > 0) {
            k--;
            if (this.iterator.hasPrevious()) {
                this.iterator.previous();
            }else {
                break;
            }
        }
    }

    @Override
    public String toString() {
        return lastToken.toString();
    }
}
