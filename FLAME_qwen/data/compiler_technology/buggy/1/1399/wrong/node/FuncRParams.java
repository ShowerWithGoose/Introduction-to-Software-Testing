/********************************************************************************
 * @FileName     : FuncRParams.java
 * @Author       :
 * @Description  : 函数实参表
 * @Notice       : FuncRParams -> Exp { ',' Exp }
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class FuncRParams implements ASTNode{
    private List<Exp> exps;
    private List<Token> commas;

    public FuncRParams(List<Exp> exps, List<Token> commas) {
        this.exps = exps;
        this.commas = commas;
    }

    @Override
    public void printInfo() {
        exps.get(0).printInfo();
        for (int i = 1; i < exps.size(); i++) {
            IOTools.parserOutput(commas.get(i - 1).toString());
            exps.get(i).printInfo();
        }
        IOTools.parserOutput(ASTNodeType.FuncRParams.toString());
    }

    public static boolean isFuncRParams (LexType lexType){
        return Exp.isExp(lexType);
    }
}
