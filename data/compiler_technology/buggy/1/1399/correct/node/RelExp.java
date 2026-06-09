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

import java.util.ArrayList;
import java.util.List;

public class RelExp implements ASTNode{
    private List<Token> opList=null;
    private List<AddExp> addExpList=null;


    public RelExp(List<AddExp> addExpList, List<Token> opList) {
        this.opList = opList;
        this.addExpList = addExpList;
    }

    @Override
    public void printInfo() {
        addExpList.get(0).printInfo();
        IOTools.parserOutput(ASTNodeType.RelExp.toString());
        if (opList != null) {
            for (int i = 0; i < opList.size(); i++) {
                IOTools.parserOutput(opList.get(i).toString());
                addExpList.get(i + 1).printInfo();
                IOTools.parserOutput(ASTNodeType.RelExp.toString());
            }
        }
    }
}
