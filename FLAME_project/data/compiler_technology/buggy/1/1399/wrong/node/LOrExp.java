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

public class LOrExp implements ASTNode{

    private LAndExp lAndExp;
    private Token orToken;
    private LOrExp lOrExp;

    public LOrExp(LAndExp lAndExp, Token operator, LOrExp lOrExp) {
        this.lAndExp = lAndExp;
        this.orToken = operator;
        this.lOrExp = lOrExp;
    }


    @Override
    public void printInfo() {
        lAndExp.printInfo();
        IOTools.parserOutput(ASTNodeType.LOrExp.toString());
        if (orToken != null) {
            IOTools.parserOutput(orToken.toString());
            lOrExp.printInfo();
        }
    }
}
