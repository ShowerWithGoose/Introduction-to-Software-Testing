/********************************************************************************
 * @FileName     : EqExp.java
 * @Author       :
 * @Description  : 相等性表达式
 * @Notice       : EqExp -> RelExp | EqExp ('==' | '!=') RelExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class EqExp implements ASTNode {

    private List<RelExp> relExpList = null;
    private List<Token> opList = null;

    public EqExp(List<RelExp> relExpList, List<Token> opList) {
        this.relExpList = relExpList;
        this.opList = opList;
    }

    @Override
    public void printInfo() {
        relExpList.get(0).printInfo();
        IOTools.parserOutput(ASTNodeType.EqExp.toString());
        if (opList != null) {
            for (int i = 0; i < opList.size(); i++) {
                IOTools.parserOutput(opList.get(i).toString());
                relExpList.get(i + 1).printInfo();
                IOTools.parserOutput(ASTNodeType.EqExp.toString());
            }
        }
    }
}
