/********************************************************************************
 * @FileName     : FuncType.java
 * @Author       :
 * @Description  : 函数类型
 * @Notice       : FuncType -> 'void' | 'int' | 'char'
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

public class FuncType implements ASTNode {

    private Token token;
    private LexType lexType;

    public FuncType(Token token) {
        this.token = token;
        this.lexType = token.getTokenType();
    }

    public Token getToken() {
        return token;
    }

    public LexType getType() {
        return lexType;
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(token.toString());
        IOTools.parserOutput(ASTNodeType.FuncType.toString());
    }
}


