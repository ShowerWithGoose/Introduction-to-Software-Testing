/********************************************************************************
 * @FileName     : CompUnit.java
 * @Author       :
 * @Description  : 编译单元
 * @Notice       : CompUnit -> {Decl} {FuncDef} MainFuncDef
 * @Time         : 2024-10-14 10:37
 * @Version      : 1.0
 ********************************************************************************/

package node;

import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class CompUnit implements ASTNode {
    private List<Decl> declList;
    private List<FuncDef> funcDefList;
    private MainFuncDef mainFuncDef;

    public CompUnit(List<Decl> declList, List<FuncDef> funcDefList, MainFuncDef mainFuncDef) {
        this.declList = declList;
        this.funcDefList = funcDefList;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public void printInfo() {
        for (Decl declNode : declList) {
            declNode.printInfo();
        }
        for (FuncDef funcDefNode : funcDefList) {
            funcDefNode.printInfo();
        }
        mainFuncDef.printInfo();
        IOTools.parserOutput(ASTNodeType.CompUnit.toString());
    }

    public List<Decl> getDeclList() {
        return declList;
    }

    public void setDeclList(List<Decl> declList) {
        this.declList = declList;
    }

    public List<FuncDef> getFuncDefList() {
        return funcDefList;
    }

    public void setFuncDefList(List<FuncDef> funcDefList) {
        this.funcDefList = funcDefList;
    }

    public MainFuncDef getMainFuncDef() {
        return mainFuncDef;
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }
}
