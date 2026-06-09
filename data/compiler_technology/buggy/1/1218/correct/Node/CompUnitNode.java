package Node;

import frontend.Parser;

import java.util.ArrayList;

public class CompUnitNode {
    //CompUnit -> {Decl} {FuncDef} MainFuncDef
    private ArrayList<DeclNode> declNodes;
    private ArrayList<FuncDefNode> funcDefNodes;
    private MainFuncDefNode mainFuncDefNode;

    public CompUnitNode(ArrayList<DeclNode> decl, ArrayList<FuncDefNode> func, MainFuncDefNode mainf){
        this.declNodes = decl;
        this.funcDefNodes = func;
        this.mainFuncDefNode = mainf;
    }

    public void print(){
        for(DeclNode d : declNodes){
            d.print();
        }
        for(FuncDefNode f : funcDefNodes){
            f.print();
        }
        mainFuncDefNode.print();
        Parser.getInstance().output(NodeType.CompUnit);
    }
}
