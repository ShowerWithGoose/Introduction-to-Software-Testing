/********************************************************************************
 * @FileName     : ConstInitVal.java
 * @Author       :
 * @Description  : 常量初值
 * @Notice       : ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
 * @Time         : 2024-10-03 19:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class ConstInitVal implements ASTNode {
    private ConstExp constExpNode;
    private Token leftBraceToken;
    private List<ConstExp> constInitVals;
    private List<Token> commas;
    private Token rightBraceToken;
    private StringConst stringConst;

    public ConstInitVal(ConstExp constExpNode, Token leftBraceToken, List<ConstExp> constInitVals, List<Token> commas, Token rightBraceToken, StringConst stringConst) {
        this.constExpNode = constExpNode;
        this.leftBraceToken = leftBraceToken;
        this.constInitVals = constInitVals;
        this.commas = commas;
        this.rightBraceToken = rightBraceToken;
        this.stringConst = stringConst;
    }

    @Override
    public void printInfo() {
        if (leftBraceToken == null && constExpNode != null) {
            constExpNode.printInfo();
        }
        else if (stringConst != null) {
            stringConst.printInfo();
        }
        else {
            IOTools.parserOutput(leftBraceToken.toString());
            if (!constInitVals.isEmpty()) {
                constInitVals.get(0).printInfo();
                for (int i = 1; i < constInitVals.size(); i++) {
                    IOTools.parserOutput(commas.get(i - 1).toString());
                    constInitVals.get(i).printInfo();
                }
            }
            IOTools.parserOutput(rightBraceToken.toString());
        }
        IOTools.parserOutput(ASTNodeType.ConstInitVal.toString());
    }
}
