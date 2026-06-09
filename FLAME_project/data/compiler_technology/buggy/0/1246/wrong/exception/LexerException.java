package exception;

/**
 * @Description 没有被报错约束的错饭
 * @Author
 * @Date 2024/9/20
 */
public class LexerException extends Exception {
    private int lineNum;

    public LexerException(int lineNum) {
        super("坏了，这下到死匹配不上了(T_T):  " + lineNum);
        this.lineNum = lineNum;
    }
}
