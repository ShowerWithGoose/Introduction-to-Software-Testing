/********************************************************************************
 * @FileName     : IntConst.java
 * @Author       :
 * @Description  : 数值常量
 * @Notice       : None
 * @Time         : 2024-10-16 11:09
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import utils.IOTools;

public class IntConst implements ASTNode {
    private Token token;
    private LexType lexType;

    public IntConst(Token token) {
        this.token = token;
        this.lexType = token.getTokenType();
    }

    // 判断是IntConst
    public static boolean isIntConst(LexType lexType) {
        return lexType == LexType.INTCON;
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(token.toString());
    }
}
