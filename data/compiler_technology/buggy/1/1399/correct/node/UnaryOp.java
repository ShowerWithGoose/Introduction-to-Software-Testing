/********************************************************************************
 * @FileName     : UnaryOp.java
 * @Author       :
 * @Description  : 单目运算符
 * @Notice       : UnaryOp -> '+' | '−' | '!'
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

public class UnaryOp implements ASTNode {
    Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(token.toString());
        IOTools.parserOutput(ASTNodeType.UnaryOp.toString());
    }

    public String getStr() {
        return token.getContent();
    }

    public static boolean isUnaryOp(LexType lexType) {
        return lexType == LexType.PLUS || lexType == LexType.MINU || lexType == LexType.NOT;
    }

    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }
}
