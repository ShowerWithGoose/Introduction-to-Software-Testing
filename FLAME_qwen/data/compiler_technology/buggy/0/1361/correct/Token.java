/* 管理词类: 内容 类型 所在行 */
public class Token {
    private String content;
    private TOKENTYPE wordType;
    private int lineNum;

    public Token(String content, TOKENTYPE wordType, Integer lineNum) {
        this.content = content;
        this.wordType = wordType;
        this.lineNum = lineNum;
    }

    public Integer getLineNum() {
        return lineNum;
    }

    public String getContent() {
        return content;
    }

    public TOKENTYPE getWordType() {
        return wordType;
    }
}
