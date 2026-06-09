/********************************************************************************
 * @FileName     : LOrExp.java
 * @Author       :
 * @Description  : 逻辑或表达式
 * @Notice       : LOrExp -> LAndExp | LOrExp '||' LAndExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class LOrExp implements ASTNode{

    private List<LAndExp> lAndExpList = null;
    private List<Token> opList = null;

    public LOrExp(List<LAndExp> lAndExpList, List<Token> opList) {
        this.lAndExpList = lAndExpList;
        this.opList = opList;
    }

    @Override
    public void printInfo() {
        lAndExpList.get(0).printInfo();
        IOTools.parserOutput(ASTNodeType.LOrExp.toString());
        if (opList != null) {
            for (int i = 0; i < opList.size(); i++) {
                IOTools.parserOutput(opList.get(i).toString());
                lAndExpList.get(i + 1).printInfo();
                IOTools.parserOutput(ASTNodeType.LOrExp.toString());
            }
        }
    }
}
