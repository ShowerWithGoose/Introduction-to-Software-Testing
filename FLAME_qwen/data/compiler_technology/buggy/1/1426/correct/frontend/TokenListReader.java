package frontend;

import java.util.ArrayList;
import java.util.ListIterator;

public class TokenListReader {
    private ArrayList<Token> tokens;
    private ListIterator<Token> iterator;
    private Token preToken;

    public TokenListReader(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.iterator = this.tokens.listIterator();
    }
    public Token getPreviousToken() {
        Token toReturn = null;
        // 记录当前位置
        int currentIndex = this.iterator.nextIndex();

        // 检查是否可以向前移动两次
        if (currentIndex > 1) {
            // 移动两步并获取再上一个Token
            this.iterator.previous();  // 移动到上一个
            toReturn = this.iterator.previous();  // 获取再上一个
        }

        // 恢复iterator位置
        while (this.iterator.nextIndex() < currentIndex) {
            this.iterator.next();
        }

        return toReturn;
    }
    public Token getnextToken() {
        if (this.iterator.hasNext()) {
            preToken = iterator.next();
            return preToken;
        } else {
            // 这里返回一个 null，表示没有更多的 tokens 可供读取
            return null;
        }
    }
    public boolean hasNextToken() {
        return this.iterator.hasNext();
    }
    public void backward(int k){
        int n = k;
        while(n > 0)
        {
            n = n - 1;
            if(this.iterator.hasPrevious())
            {
                preToken = this.iterator.previous();
            }else{
                break;
            }
        }
    }

    @Override
    public String toString()
    {
        return preToken.toString();
    }


}
