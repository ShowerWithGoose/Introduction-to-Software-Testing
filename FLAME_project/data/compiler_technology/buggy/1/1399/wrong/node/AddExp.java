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

public class AddExp implements ASTNode {
    private MulExp mulExp;
    private Token operator;
    private AddExp addExp;

    public AddExp(MulExp mulExp, Token operator, AddExp addExp) {
        this.mulExp = mulExp;
        this.operator = operator;
        this.addExp = addExp;
    }

    @Override
    public void printInfo() {
        mulExp.printInfo();
        IOTools.parserOutput(ASTNodeType.AddExp.toString());
        if (operator != null) {
            IOTools.parserOutput(operator.toString());
            addExp.printInfo();
        }
    }

    public MulExp getMulExp() {
        return mulExp;
    }

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public Token getOperator() {
        return operator;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public AddExp getAddExp() {
        return addExp;
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
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
