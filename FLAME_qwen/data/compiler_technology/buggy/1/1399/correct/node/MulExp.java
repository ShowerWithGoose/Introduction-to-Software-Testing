/********************************************************************************
 * @FileName     : MulExp.java
 * @Author       :
 * @Description  : 乘除模表达式
 * @Notice       : MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.ArrayList;
import java.util.List;

public class MulExp implements ASTNode {

    private List<Token> opList = null;
    private List<UnaryExp> unaryExpArrayList = null;

    public MulExp(List<Token> opList, List<UnaryExp> unaryExpArrayList) {
        this.opList = opList;
        this.unaryExpArrayList = unaryExpArrayList;
    }


    @Override
    public void printInfo() {
        unaryExpArrayList.get(0).printInfo();
        IOTools.parserOutput(ASTNodeType.MulExp.toString());
        if (opList != null) {
            for (int i = 0; i < opList.size(); i++) {
                IOTools.parserOutput(opList.get(i).toString());
                unaryExpArrayList.get(i + 1).printInfo();
                IOTools.parserOutput(ASTNodeType.MulExp.toString());
            }
        }
    }
}
