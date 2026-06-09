/********************************************************************************
 * @FileName     : ConstExp.java
 * @Author       :
 * @Description  : 常量表达式
 * @Notice       : ConstExp -> AddExp  注：使用的 Ident 必须是常量
 * @Time         : 2024-10-14 10:54
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.ASTNodeType;
import type.LexType;
import utils.IOTools;

public class ConstExp implements ASTNode{
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public static boolean isConstExp(LexType lexType) {
        return AddExp.isAddExp(lexType);
    }

    @Override
    public void printInfo() {
        addExp.printInfo();
        IOTools.parserOutput(ASTNodeType.ConstExp.toString());
    }
}
