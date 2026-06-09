/********************************************************************************
 * @FileName     : PrimaryExp.java
 * @Author       :
 * @Description  : 基本表达式
 * @Notice       : PrimaryExp -> '(' Exp ')' | LVal | Numberr | Character
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

public class PrimaryExp implements ASTNode {

    private Token leftParentToken = null;
    private Exp exp = null;
    private Token rightParentToken = null;
    private LVal lVal = null;
    private Number number = null;
    private Character character = null;

    public PrimaryExp(Token leftParentToken, Exp exp, Token rightParentToken, LVal lVal, Number number, Character character) {
        this.leftParentToken = leftParentToken;
        this.exp = exp;
        this.rightParentToken = rightParentToken;
        this.lVal = lVal;
        this.number = number;
        this.character = character;
    }

    @Override
    public void printInfo() {
        if (exp != null) {
            IOTools.parserOutput(leftParentToken.toString());
            exp.printInfo();
            IOTools.parserOutput(rightParentToken.toString());
        }
        else if (lVal != null) {
            lVal.printInfo();
        }
        else if (character != null) {
            character.printInfo();
        }
        else {
            number.printInfo();
        }
        IOTools.parserOutput(ASTNodeType.PrimaryExp.toString());
    }

//    public static boolean isPrimaryExp(LexType lexType) {
//        return lexType == LexType.LPARENT || Exp.isExp(lexType) || Character.isValid(lexType);
//    }
}
