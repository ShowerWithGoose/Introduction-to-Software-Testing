/********************************************************************************
 * @FileName     : Ident.java
 * @Author       :
 * @Description  : 标识符
 * @Notice       : None
 * @Time         : 2024-10-16 11:09
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import utils.IOTools;

public class Ident implements ASTNode{
    private Token token;

    public Ident(Token token) {
        this.token = token;
    }

    // 判断是Ident
    public static boolean isIdent(LexType lexType) {
        return lexType == LexType.IDENFR;
    }

    @Override
    public void printInfo(){
        IOTools.parserOutput(token.toString());
    }
}
