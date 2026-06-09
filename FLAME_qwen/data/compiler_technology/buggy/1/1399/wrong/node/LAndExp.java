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

public class LAndExp implements ASTNode{

    private EqExp eqExp;
    private Token andToken;
    private LAndExp lAndExp;

    public LAndExp(EqExp eqExp, Token operator, LAndExp lAndExp) {
        this.eqExp = eqExp;
        this.andToken = operator;
        this.lAndExp = lAndExp;
    }

    public EqExp getEqExpNode() {
        return eqExp;
    }

    public Token getAndToken() {
        return andToken;
    }

    public LAndExp getLAndExpNode() {
        return lAndExp;
    }

    @Override
    public void printInfo() {
        eqExp.printInfo();
        IOTools.parserOutput(ASTNodeType.LAndExp.toString());
        if (andToken != null) {
            IOTools.parserOutput(andToken.toString());
            lAndExp.printInfo();
        }
    }
}
