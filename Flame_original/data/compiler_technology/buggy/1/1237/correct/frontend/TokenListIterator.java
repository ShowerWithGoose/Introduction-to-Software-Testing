package frontend;

import java.util.ListIterator;

public class TokenListIterator {
    private final ListIterator<Token> iterator;
    private Token last;

    /**
     * 使用提供的 TokenList 构造一个 TokenListIterator。
     *
     * @param tokenList 要遍历的 TokenList。
     * @throws IllegalArgumentException 如果 tokenList 或其底层的标记集合为空。
     */
    public TokenListIterator(TokenList tokenList) {
        if (tokenList == null || tokenList.getTokens() == null) {
            throw new IllegalArgumentException("TokenList cannot be null");
        }
        this.iterator = tokenList.getTokens().listIterator();
    }

    // 返回下一个标记，并更新最近读取的标记
    public Token readNextToken() {
        if (iterator.hasNext()) {
            last = iterator.next();
            return last;
        }
        throw new IllegalStateException("No more tokens available");
    }

    // 判断是否有更多标记
    public boolean hasNext() {
        return iterator.hasNext();
    }

    /**
     * 将迭代器回退指定次数。
     *
     * @param k 要回退的标记次数。
     *          如果 {@code k} 大于可以回退的次数，则尽可能多地回退。
     */
    public void unReadToken(int k) {
        for (int i = 0; i < k && iterator.hasPrevious(); i++) {
            last = iterator.previous();
        }
    }

    /**
     * 返回最近读取的标记的字符串表示。
     *
     * @return 如果已读取标记，则返回该标记的字符串表示；如果尚未读取任何标记，则返回提示信息。
     */
    @Override
    public String toString() {
        return last != null ? last.toString() : "No token has been read yet";
    }
}
