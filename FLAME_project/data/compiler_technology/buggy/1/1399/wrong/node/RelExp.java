/********************************************************************************
 * @FileName     : RelExp.java
 * @Author       :
 * @Description  : 关系表达式
 * @Notice       : RelExp -> AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

public class RelExp implements ASTNode{
    private AddExp addExpNode;
    private Token operator;
    private RelExp relExp;


    public RelExp(AddExp addExpNode, Token operator, RelExp relExp) {
        this.addExpNode = addExpNode;
        this.operator = operator;
        this.relExp = relExp;
    }

    @Override
    public void printInfo() {
        addExpNode.printInfo();
        IOTools.parserOutput(ASTNodeType.RelExp.toString());
        if (operator != null) {
            IOTools.parserOutput(operator.toString());
            relExp.printInfo();
        }
    }
}
