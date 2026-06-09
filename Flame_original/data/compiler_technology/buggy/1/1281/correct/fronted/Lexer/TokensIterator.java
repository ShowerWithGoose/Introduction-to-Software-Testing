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

    public TokensIterator(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        this.iterator = this.tokenList.listIterator();
    }

    public ListIterator<Token> getIterator() {
        return iterator;
    }

    public Token readNextToken() {
        return last = this.iterator.next();
    }

    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    public Token peekPreviousToken() {
        Token prevToken;
        if (this.iterator.hasPrevious()) {
            this.iterator.previous();
            prevToken = this.iterator.previous();
            this.iterator.next(); // 将迭代器恢复到原来的位置
            this.iterator.next();
            return prevToken;
        } else {
            return null; // 如果没有前一个元素，返回 null 或者你可以抛出异常
        }
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
