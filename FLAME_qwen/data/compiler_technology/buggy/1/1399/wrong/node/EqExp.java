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

public class EqExp implements ASTNode{

    private RelExp relExp;
    private Token operator;
    private EqExp eqExp;

    public EqExp(RelExp relExp, Token operator, EqExp eqExp) {
        this.relExp = relExp;
        this.operator = operator;
        this.eqExp = eqExp;
    }

    @Override
    public void printInfo() {
        relExp.printInfo();
        IOTools.parserOutput(ASTNodeType.EqExp.toString());
        if (operator != null) {
            IOTools.parserOutput(operator.toString());
            eqExp.printInfo();
        }
    }
}
