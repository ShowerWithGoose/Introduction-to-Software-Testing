package token;

import utils.IO;

/**
 * @Description 就是Token呢
 * @Author
 * @Date 2024/9/17
 */
public class Token {
    public String content;
    public int lineNum;
    public TokenType type;

    public Token(String content, int lineNum, TokenType type) {
        this.content = content;
        this.lineNum = lineNum;
        this.type = type;
    }

    @Override
    public String toString() {
        return type + " " + content;
    }

    // 将当前token输出至文件
    public void print() {
        if (type != TokenType.ERROR) {
            IO.write(IO.IOType.LEXER, this.toString(), true, true);
        }
    }
}
