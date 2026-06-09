package frontend.lexer;

import java.util.List;
import java.util.ArrayList;

/**
 * TokenListIterator 类，用于遍历 TokenList。
 * 该类提供了一种机制，可以对存储在 TokenList 中的 Token 进行迭代、读取、回退以及重置操作。
 */
public class TokenListIterator {
    // 存储 Token 的列表，ArrayList 提供了快速的随机访问
    private final List<Token> tokenArray;

    // 当前迭代的索引位置，指示下一个要读取的 Token
    private int currentIndex;

    /**
     * 构造函数，初始化 TokenListIterator。
     * @param tokenList 要遍历的 TokenList
     */
    public TokenListIterator(TokenList tokenList) {
        // 将 TokenList 中的 Token 集合复制到 ArrayList 中，支持高效的随机访问
        this.tokenArray = new ArrayList<>(tokenList.getTokens());
        // 将当前索引位置初始化为 0，表示从头开始迭代
        this.currentIndex = 0;
    }

    /**
     * 检查是否有下一个 Token。
     * @return 如果有下一个 Token，返回 true；否则返回 false
     */
    public boolean hasNext() {
        // 判断当前索引是否已经超过了 Token 列表的大小
        // 如果索引小于列表大小，说明还有 Token 可以读取
        return currentIndex < tokenArray.size();
    }

    /**
     * 读取下一个 Token。
     * @return 下一个 Token，如果没有则返回 null
     */
    public Token readNextToken() {
        // 检查是否还有未读的 Token
        if (hasNext()) {
            // 返回当前索引处的 Token，并将索引加一，以便下次读取下一个 Token
            return tokenArray.get(currentIndex++);
        } else {
            // 如果没有下一个 Token，则返回 null
            // 可以根据需求改为抛出异常以处理无效读取的情况
            return null;
        }
    }

    /**
     * 回退指定数量的 Token。
     * @param n 要回退的数量
     */
    public void unReadTokens(int n) {
        // 回退 n 个 Token，将 currentIndex 减去 n
        // 使用 Math.max 确保索引不会小于 0，避免越界
        currentIndex = Math.max(0, currentIndex - n);
    }

    /**
     * 获取当前索引位置。
     * @return 当前索引
     */
    public int getCurrentIndex() {
        // 返回当前迭代器的索引位置
        return currentIndex;
    }

    /**
     * 重置迭代器到起始位置。
     * 该方法将迭代器的索引位置重置为 0，以便重新从头开始遍历 Token。
     */
    public void reset() {
        // 将 currentIndex 重置为 0，表示迭代器回到起始位置
        currentIndex = 0;
    }
}
