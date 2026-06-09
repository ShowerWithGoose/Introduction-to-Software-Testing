/********************************************************************************
 * @FileName     : Number.java
 * @Author       :
 * @Description  : 数值
 * @Notice       : Number -> IntConst
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.ASTNodeType;
import utils.IOTools;

public class Number implements ASTNode{

    IntConst intConst;

    public Number(IntConst intConst) {
        this.intConst = intConst;
    }

    public IntConst getIntConst() {
        return intConst;
    }

    @Override
    public void printInfo() {
        intConst.printInfo();
        IOTools.parserOutput(ASTNodeType.Number.toString());
    }
}
