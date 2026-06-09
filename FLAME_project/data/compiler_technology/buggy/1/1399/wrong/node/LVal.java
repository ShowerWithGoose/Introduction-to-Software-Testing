/********************************************************************************
 * @FileName     : LVal.java
 * @Author       :
 * @Description  : 左值表达式
 * @Notice       : LVal -> Ident {'[' Exp ']'}
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class LVal implements ASTNode{

    private Ident ident;
    private List<Token> leftBrackets;
    private List<Exp> exps;
    private List<Token> rightBrackets;

    public LVal(Ident ident, List<Token> leftBrackets, List<Exp> exps, List<Token> rightBrackets) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.exps = exps;
        this.rightBrackets = rightBrackets;
    }

    // 判断是否是 LVal
    public static boolean isLVal(LexType lexType) {
        return lexType == LexType.IDENFR;
    }

    @Override
    public void printInfo() {
        ident.printInfo();
        for (int i = 0; i < leftBrackets.size(); i++) {
            IOTools.parserOutput(leftBrackets.get(i).toString());
            exps.get(i).printInfo();
            IOTools.parserOutput(rightBrackets.get(i).toString());
        }
        IOTools.parserOutput(ASTNodeType.LVal.toString());
    }
}
