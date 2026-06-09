/********************************************************************************
 * @FileName     : LAndExp.java
 * @Author       :
 * @Description  : 逻辑与表达式
 * @Notice       : LAndExp -> EqExp | LAndExp '&&' EqExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class LAndExp implements ASTNode{

    private List<EqExp> eqExpList = null;
    private List<Token> opList = null;

    public LAndExp(List<EqExp> eqExpList, List<Token> opList) {
        this.eqExpList = eqExpList;
        this.opList = opList;
    }

    @Override
    public void printInfo() {
        eqExpList.get(0).printInfo();
        IOTools.parserOutput(ASTNodeType.LAndExp.toString());
        if (opList != null) {
            for (int i = 0; i < opList.size(); i++) {
                IOTools.parserOutput(opList.get(i).toString());
                eqExpList.get(i + 1).printInfo();
                IOTools.parserOutput(ASTNodeType.LAndExp.toString());
            }
        }
    }
}
