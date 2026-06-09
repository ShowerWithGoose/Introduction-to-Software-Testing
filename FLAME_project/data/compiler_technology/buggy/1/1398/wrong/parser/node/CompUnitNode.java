package parser.node;

import parser.NodeType;

import java.util.ArrayList;

public class CompUnitNode {
    ArrayList<DeclNode> declNodes;
    ArrayList<FuncDefNode> funcDefNodes;
    MainFuncDefNode mainFuncDefNode;

    public CompUnitNode(ArrayList<DeclNode> declNodes, ArrayList<FuncDefNode> funcDefNodes, MainFuncDefNode mainFuncDefNode) {
        this.declNodes = declNodes;
        this.funcDefNodes = funcDefNodes;
        this.mainFuncDefNode = mainFuncDefNode;
    }
    public void print() {
        for (DeclNode declNode : declNodes)
        {
            declNode.print();
        }
        for (FuncDefNode funcDefNode : funcDefNodes)
        {
            funcDefNode.print();
        }
        mainFuncDefNode.print();
        System.out.println(NodeType.CompUnit);
    }
}
