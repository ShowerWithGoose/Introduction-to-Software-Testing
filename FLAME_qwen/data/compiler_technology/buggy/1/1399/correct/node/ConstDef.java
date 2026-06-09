/********************************************************************************
 * @FileName     : ConstDef.java
 * @Author       :
 * @Description  : 常量定义
 * @Notice       : ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
 * @Time         : 2024-10-03 19:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class ConstDef implements ASTNode {
    private Ident ident;
    private List<Token> leftBracketList;
    private List<ConstExp> constExpList;
    private List<Token> rightBracketList;
    private Token equalToken;
    private ConstInitVal constInitVal;

    public ConstDef(Ident ident, List<Token> leftBracketList, List<ConstExp> constExpList, List<Token> rightBracketList, Token equalToken, ConstInitVal constInitVal) {
        this.ident = ident;
        this.leftBracketList = leftBracketList;
        this.constExpList = constExpList;
        this.rightBracketList = rightBracketList;
        this.equalToken = equalToken;
        this.constInitVal = constInitVal;
    }

    @Override
    public void printInfo() {
        ident.printInfo();
        for (int i = 0; i < constExpList.size(); i++) {
            IOTools.parserOutput(leftBracketList.get(i).toString());
            constExpList.get(i).printInfo();
            IOTools.parserOutput(rightBracketList.get(i).toString());
        }
        IOTools.parserOutput(equalToken.toString());
        constInitVal.printInfo();
        IOTools.parserOutput(ASTNodeType.ConstDef.toString());
    }
}
