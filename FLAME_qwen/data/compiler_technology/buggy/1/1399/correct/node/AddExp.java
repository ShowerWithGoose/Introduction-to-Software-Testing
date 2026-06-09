/********************************************************************************
 * @FileName     : AddExp.java
 * @Author       :
 * @Description  : 加减表达式
 * @Notice       : AddExp -> MulExp | AddExp ('+' | '−') MulExp
 *              => AddExp -> MulExp { ('+' | '−') MulExp }
 *              => AddExp -> MulExp { '+' MulExp | '−' MulExp }
 * @Time         : 2024-10-14 10:54
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;

import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class AddExp implements ASTNode {
    private List<Token> opList;
    private List<MulExp> mulExpList;

    public AddExp(List<Token> opList,List<MulExp> mulExpList)
    {
        this.opList=opList;
        this.mulExpList =mulExpList;
    }

    @Override
    public void printInfo() {
        mulExpList.get(0).printInfo();
        IOTools.parserOutput(ASTNodeType.AddExp.toString());
        if (opList != null) {
            for (int i = 0; i < opList.size(); i++) {
                IOTools.parserOutput(opList.get(i).toString());
                mulExpList.get(i + 1).printInfo();
                IOTools.parserOutput(ASTNodeType.AddExp.toString());
            }
        }
    }


    public static boolean isAddExp(LexType lexType) {
        return lexType == LexType.IDENFR ||
                lexType == LexType.PLUS ||
                lexType == LexType.MINU ||
                lexType == LexType.NOT ||
                lexType == LexType.LPARENT ||
                lexType == LexType.INTCON ||
                lexType == LexType.CHRCON;
    }
}
