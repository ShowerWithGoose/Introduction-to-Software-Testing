package ast;

import IO.IO;
import enum_package.NodeType;

import java.util.List;
import frontend.Parser;

public class CompUnitNode {
    // CompUnit -> {Decl} {FuncDef} MainFuncDef
    public List<DeclNode> decl; // 声明列表
    public List<FuncDefNode> funcDef;  // 函数定义列表
    public MainFuncDefNode mainFuncDef;  // 主函数定义

    public CompUnitNode(List<DeclNode> decl, List<FuncDefNode> funcDef, MainFuncDefNode mainFuncDef) {
        this.decl = decl;
        this.funcDef = funcDef;
        this.mainFuncDef = mainFuncDef;
    }

    public void print(){
        for(DeclNode d : decl){
            d.print();
        }
        for(FuncDefNode f : funcDef){
            f.print();
        }
        mainFuncDef.print();

        IO.write(Parser.nodeTypeLabel.get(NodeType.CompUnit));
    }
}
