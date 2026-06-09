package frontend.lexicAnalysis;

/**
 * 单词信息封装类
 */
public class Token {
    private TokenType tokenType; // 单词类型
    private int tokenRow; // 单词行号（从0开始，输出时注意）
    private int tokenCol; // 单词列号（从0开始，输出时注意）
    private String content; // 单词原始信息

    public Token(TokenType tokenType, int tokenRow, int tokenCol, String content) {
        this.tokenType = tokenType;
        this.tokenRow = tokenRow;
        this.tokenCol = tokenCol;
        this.content = content;
    }

    public TokenType getTokenType() {
        return tokenType;
    }

    public void setTokenType(TokenType tokenType) {
        this.tokenType = tokenType;
    }

    public int getTokenRow() {
        return tokenRow;
    }

    public void setTokenRow(int tokenRow) {
        this.tokenRow = tokenRow;
    }

    public int getTokenCol() {
        return tokenCol;
    }

    public void setTokenCol(int tokenCol) {
        this.tokenCol = tokenCol;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
