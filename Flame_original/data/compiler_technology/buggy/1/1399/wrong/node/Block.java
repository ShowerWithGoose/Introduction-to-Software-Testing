/********************************************************************************
 * @FileName     : Block.java
 * @Author       :
 * @Description  : 语句块
 * @Notice       : Block -> '{' { BlockItem } '}'
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class Block implements ASTNode {
    private Token leftBrace;
    private List<BlockItem> blockItemList;
    private Token rightBrace;

    public Block(Token leftBrace, List<BlockItem> blockItemList, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.blockItemList = blockItemList;
        this.rightBrace = rightBrace;
    }


    @Override
    public void printInfo() {
        IOTools.parserOutput(leftBrace.toString());
        for (BlockItem blockItem : blockItemList) {
            blockItem.printInfo();
        }
        IOTools.parserOutput(rightBrace.toString());
        IOTools.parserOutput(ASTNodeType.Block.toString());
    }

    public Token getLeftBrace() {
        return leftBrace;
    }

    public void setLeftBrace(Token leftBrace) {
        this.leftBrace = leftBrace;
    }

    public List<BlockItem> getBlockItemList() {
        return blockItemList;
    }

    public void setBlockItemList(List<BlockItem> blockItemList) {
        this.blockItemList = blockItemList;
    }

    public Token getRightBrace() {
        return rightBrace;
    }

    public void setRightBrace(Token rightBrace) {
        this.rightBrace = rightBrace;
    }
}
