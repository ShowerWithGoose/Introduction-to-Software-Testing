/********************************************************************************
 * @FileName     : FuncFParam.java
 * @Author       :
 * @Description  : 函数形参
 * @Notice       : FuncFParam -> BType Ident [ '[' ']' ]
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class FuncFParam implements ASTNode {

    private BType bTypeNode;
    private Ident ident;
    private List<Token> leftBrackets;
    private List<Token> rightBrackets;

    public FuncFParam(BType bTypeNode, Ident ident, List<Token> leftBrackets, List<Token> rightBrackets) {
        this.bTypeNode = bTypeNode;
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.rightBrackets = rightBrackets;
    }

    @Override
    public void printInfo() {
        bTypeNode.printInfo();
        ident.printInfo();
        // todo 搞清楚为什么只判断一个时会报错？

        for (int i = 0; i < leftBrackets.size(); i++) {
            IOTools.parserOutput(leftBrackets.get(i).toString());
            IOTools.parserOutput(rightBrackets.get(i).toString());
        }
        IOTools.parserOutput(ASTNodeType.FuncFParam.toString());
    }
}
