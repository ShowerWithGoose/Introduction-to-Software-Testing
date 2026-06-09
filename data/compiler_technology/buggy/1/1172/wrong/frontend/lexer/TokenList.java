package frontend.lexer;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.Collection;
import java.util.Iterator;

/**
 * TokenList 类，使用线程安全的阻塞队列存储 Token。
 */
public class TokenList implements Iterable<Token> {
    private final BlockingQueue<Token> tokenQueue;

    /**
     * 构造函数，初始化 TokenList 对象。
     */
    public TokenList() {
        tokenQueue = new LinkedBlockingQueue<>();
    }

    /**
     * 添加一个 Token 到列表中。
     * @param token 要添加的 Token
     */
    public void addToken(Token token) {
        tokenQueue.offer(token);
    }

    /**
     * 获取所有的 Token。
     * @return Token 的集合
     */
    public Collection<Token> getTokens() {
        return tokenQueue;
    }

    /**
     * 判断列表是否为空。
     * @return 如果为空返回 true，否则返回 false
     */
    public boolean isEmpty() {
        return tokenQueue.isEmpty();
    }

    /**
     * 获取 Token 的数量。
     * @return Token 的数量
     */
    public int size() {
        return tokenQueue.size();
    }

    /**
     * 实现 Iterable 接口，返回迭代器。
     * @return Token 的迭代器
     */
    @Override
    public Iterator<Token> iterator() {
        return tokenQueue.iterator();
    }
}
