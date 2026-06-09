/********************************************************************************
 * @FileName     : Exp.java
 * @Author       :
 * @Description  : 表达式
 * @Notice       : Exp -> AddExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import type.ASTNodeType;
import utils.IOTools;

public class Exp implements ASTNode {
    private AddExp addExpNode;

    public Exp(AddExp addExpNode) {
        this.addExpNode = addExpNode;
    }

    public AddExp getAddExpNode() {
        return addExpNode;
    }

    @Override
    public void printInfo() {
        addExpNode.printInfo();
        IOTools.parserOutput(ASTNodeType.Exp.toString());
    }

    public static boolean isExp(LexType lexType) {
        return AddExp.isAddExp(lexType);
    }
}
