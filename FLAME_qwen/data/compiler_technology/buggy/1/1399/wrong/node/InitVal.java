/********************************************************************************
 * @FileName     : InitVal.java
 * @Author       :
 * @Description  : 变量初值
 * @Notice       : InitVal ->  Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class InitVal implements ASTNode{
    private Exp exp;
    private Token leftBraceToken;
    private List<Exp> expList;
    private List<Token> commas;
    private Token rightBraceToken;
    private StringConst stringConst;

    public InitVal(Exp exp, Token leftBraceToken, List<Exp> expList, List<Token> commas, Token rightBraceToken,StringConst stringConst) {
        this.exp = exp;
        this.leftBraceToken = leftBraceToken;
        this.expList = expList;
        this.commas = commas;
        this.rightBraceToken = rightBraceToken;
        this.stringConst = stringConst;
    }

    @Override
    public void printInfo() {
        if (exp != null) {
            exp.printInfo();
        }
        else if(stringConst != null){
            stringConst.printInfo();
        }
        else {
            IOTools.parserOutput(leftBraceToken.toString());
            if (!expList.isEmpty()) {
                for (int i = 0; i < expList.size(); i++) {
                    expList.get(i).printInfo();
                    if (i != expList.size() - 1) {
                        IOTools.parserOutput(commas.get(i).toString());
                    }
                }
            }
            IOTools.parserOutput(rightBraceToken.toString());
        }
        IOTools.parserOutput(ASTNodeType.InitVal.toString());
    }
}
