/********************************************************************************
 * @FileName     : MainFuncDef.java
 * @Author       :
 * @Description  : 主函数定义节点
 * @Notice       : MainFuncDef -> 'int' 'main' '(' ')' Block
 * @Time         : 2024-10-03 21:30
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

public class MainFuncDef implements ASTNode {
    private Token intToken;
    private Token mainToken;
    private Token leftParentToken;
    private Token rightParentToken;
    private Block block;

    public MainFuncDef(Token intToken, Token mainToken, Token leftParentToken, Token rightParentToken, Block block) {
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.leftParentToken = leftParentToken;
        this.rightParentToken = rightParentToken;
        this.block = block;
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(intToken.toString());
        IOTools.parserOutput(mainToken.toString());
        IOTools.parserOutput(leftParentToken.toString());
        IOTools.parserOutput(rightParentToken.toString());
        block.printInfo();
        IOTools.parserOutput(ASTNodeType.MainFuncDef.toString());
    }
}
