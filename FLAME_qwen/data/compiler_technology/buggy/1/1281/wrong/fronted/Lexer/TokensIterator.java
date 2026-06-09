package fronted.Lexer;
import java.util.ArrayList;
import java.util.ListIterator;
/**
 * @author
 * @Description:
 * @date 2024/10/11 15:30
 */
public class TokensIterator {
    private ArrayList<Token> tokenList;
    private ListIterator<Token> iterator;
    private Token last;
    private Token pre;

    public TokensIterator(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        this.iterator = this.tokenList.listIterator();
    }

    public ListIterator<Token> getIterator() {
        return iterator;
    }

    public Token readNextToken() {
        pre = last;
        return last = this.iterator.next();
    }

    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    public Token peekPreviousToken() {
        return pre;
    }

    public void unReadToken(int k) {
        int cnt = k;
        while (cnt > 0) {
            cnt--;
            if (this.iterator.hasPrevious()) {
                last = this.iterator.previous();
            } else {
                break;
            }
        }
    }

    @Override
    public String toString() {
        return last.toString();
    }
}
