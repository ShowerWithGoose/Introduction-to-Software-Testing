/********************************************************************************
 * @FileName     : FuncFParams.java
 * @Author       :
 * @Description  : 函数形参表
 * @Notice       : FuncFParams -> FuncFParam { ',' FuncFParam }
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class FuncFParams implements ASTNode{
    private List<FuncFParam> funcFParamList;
    private List<Token> commas;

    public FuncFParams(List<FuncFParam> funcFParamList, List<Token> commas) {
        this.funcFParamList = funcFParamList;
        this.commas = commas;
    }

    @Override
    public void printInfo() {
        funcFParamList.get(0).printInfo();
        for (int i = 1; i < funcFParamList.size(); i++) {
            IOTools.parserOutput(commas.get(i - 1).toString());
            funcFParamList.get(i).printInfo();
        }
        IOTools.parserOutput(ASTNodeType.FuncFParams.toString());
    }
}
