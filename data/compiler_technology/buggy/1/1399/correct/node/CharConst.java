/********************************************************************************
 * @FileName     : CharConst.java
 * @Author       :
 * @Description  : 字符常量
 * @Notice       : CharConst -> '\''ASCII'\''
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/


package node;

import type.LexType;
import frontend.Token;
import utils.IOTools;

public class CharConst implements ASTNode {
    private Token token;
    private LexType lexType;

    public CharConst(Token token) {
        this.token = token;
        this.lexType = token.getTokenType();
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(this.token.toString());
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
