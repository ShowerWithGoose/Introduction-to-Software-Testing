/********************************************************************************
 * @FileName     : StringConst.java
 * @Author       :
 * @Description  : 字符串常量
 * @Notice       : None
 * @Time         : 2024-10-16 11:09
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import utils.IOTools;

public class StringConst implements ASTNode {
    private Token token;
    private LexType lexType;

    public StringConst(Token token) {
        this.token = token;
        this.lexType = token.getTokenType();
    }

    // 判断是StringConst
    public static boolean isStringConst(LexType lexType) {
        return lexType == LexType.STRCON;
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(token.toString());
    }

    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }

    public LexType getLexType() {
        return lexType;
    }

    public void setLexType(LexType lexType) {
        this.lexType = lexType;
    }
}
