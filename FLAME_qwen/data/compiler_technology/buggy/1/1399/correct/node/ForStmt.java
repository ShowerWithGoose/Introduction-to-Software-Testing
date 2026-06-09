/********************************************************************************
 * @FileName     : ForStmt.java
 * @Author       :
 * @Description  : 语句
 * @Notice       : ForStmt -> LVal '=' Exp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import type.LexType;
import utils.IOTools;

public class ForStmt implements ASTNode {
    private LVal lval;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lval, Token assign, Exp exp) {
        this.lval = lval;
        this.assign = assign;
        this.exp = exp;
    }
    public static boolean isForStmt(LexType lexType) {
        return lexType == LexType.IDENFR;
    }

    @Override
    public void printInfo() {
        this.lval.printInfo();
        IOTools.parserOutput(assign.toString());
        this.exp.printInfo();
        IOTools.parserOutput(ASTNodeType.ForStmt.toString());
    }
}
