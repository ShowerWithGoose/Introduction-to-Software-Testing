/********************************************************************************
 * @FileName     : Cond.java
 * @Author       :
 * @Description  : 条件表达式
 * @Notice       : Cond -> LOrExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.ASTNodeType;
import utils.IOTools;

public class Cond implements ASTNode{
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public LOrExp getLOrExpNode() {
        return lOrExp;
    }

    @Override
    public void printInfo() {
        lOrExp.printInfo();
        IOTools.parserOutput(ASTNodeType.Cond.toString());
    }
}
