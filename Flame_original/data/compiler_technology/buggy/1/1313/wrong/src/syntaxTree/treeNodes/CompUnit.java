package src.syntaxTree.treeNodes;

import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
 */
public class CompUnit extends STNode {
    public ArrayList<Decl> decls;
    public ArrayList<FuncDef> funcDefs;
    public MainFuncDef mainFuncDef;

    public CompUnit() {
        this.decls = new ArrayList<Decl>();
        this.funcDefs = new ArrayList<FuncDef>();
    }
}
