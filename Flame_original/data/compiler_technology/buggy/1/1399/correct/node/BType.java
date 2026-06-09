/********************************************************************************
 * @FileName     : BType.java
 * @Author       :
 * @Description  : 基本类型
 * @Notice       : BType -> 'int' | 'char'
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import type.BTypeEnum;
import utils.IOTools;

public class BType implements ASTNode {

    private BTypeEnum bType;
    private Token token;


    public BType(Token token) {
        this.token = token;
        LexType lexType = token.getTokenType();
        if (lexType == LexType.INTTK) {
            bType = BTypeEnum.INT;
        }
        else if (lexType == LexType.CHARTK) {
            bType = BTypeEnum.CHAR;
        }
    }

    // 判断是否是被定义的类型
    public static boolean isBType(LexType lType) {
        boolean isDefined = false;
        for (BTypeEnum bTypeEnum : BTypeEnum.values()) {
            if (bTypeEnum.getType() == lType) {
                isDefined = true;
                break;
            }
        }
        return isDefined;
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(bType.toString());
    }

    public BTypeEnum getbType() {
        return bType;
    }

    public void setbType(BTypeEnum bType) {
        this.bType = bType;
    }

    public Token getToken() {
        return token;
    }

    public void setToken(Token token) {
        this.token = token;
    }
}
