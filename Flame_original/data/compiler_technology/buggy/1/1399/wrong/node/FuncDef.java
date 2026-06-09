/********************************************************************************
 * @FileName     : FuncDef.java
 * @Author       :
 * @Description  : 函数定义
 * @Notice       : FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

public class FuncDef implements ASTNode{
    private FuncType funcType;
    private Ident ident;
    private Token leftParentToken;
    private FuncFParams funcFParams;
    private Token rightParentToken;
    private Block block;

    public FuncDef(FuncType funcType, Ident ident, Token leftParentToken, FuncFParams funcFParams, Token rightParentToken, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParentToken = leftParentToken;
        this.funcFParams = funcFParams;
        this.rightParentToken = rightParentToken;
        this.block = block;
    }

    @Override
    public void printInfo() {
        funcType.printInfo();
        ident.printInfo();
        IOTools.parserOutput(leftParentToken.toString());
        if (funcFParams != null) {
            funcFParams.printInfo();
        }
        IOTools.parserOutput(rightParentToken.toString());
        block.printInfo();
        IOTools.parserOutput(ASTNodeType.FuncDef.toString());
    }
}
