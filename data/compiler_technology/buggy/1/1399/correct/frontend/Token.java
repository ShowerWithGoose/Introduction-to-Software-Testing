/********************************************************************************
 * @FileName     : Token.java
 * @Author       :
 * @Description  : Token类
 * @Notice       : None
 * @Time         : 2024-10-03 18:46
 * @Version      : 0.0
 ********************************************************************************/

package frontend;

import type.LexType;

public class Token {
    private LexType tokenType; // 词法单元的类别
    private int lineNumber; // 词法单元在源代码中出现的行号
    private String content; // 词法单元的内容

    public Token(LexType tokenType, String content, int lineNumber) {
        this.tokenType = tokenType;
        this.content = content;
        this.lineNumber = lineNumber;
    }

    /**
     * 获取
     *
     * @return tokenType
     */
    public LexType getTokenType() {
        return tokenType;
    }

    /**
     * 设置
     *
     * @param tokenType
     */
    public void setTokenType(LexType tokenType) {
        this.tokenType = tokenType;
    }

    /**
     * 获取
     *
     * @return lineNumber
     */
    public int getLineNumber() {
        return lineNumber;
    }

    /**
     * 设置
     *
     * @param lineNumber
     */
    public void setLineNumber(int lineNumber) {
        this.lineNumber = lineNumber;
    }

    /**
     * 获取
     *
     * @return content
     */
    public String getContent() {
        return content;
    }

    /**
     * 设置
     *
     * @param content
     */
    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return this.tokenType.toString() + " " + this.content;
    }
}
