package frontend.node;

import frontend.Parser;
import utils.MyIO;
import java.util.ArrayList;

public class CompUnitNode {
    // 编译单元 CompUnit -> {Decl} {FuncDef} MainFuncDef
    private ArrayList<DeclNode> declNodes;
    private ArrayList<FuncDefNode> funcDefNodes;
    private MainFuncDefNode mainFuncDefNode;

    public CompUnitNode(ArrayList<DeclNode> declNodes, ArrayList<FuncDefNode> funcDefNodes, MainFuncDefNode mainFuncDefNode) {
        this.declNodes = declNodes;
        this.funcDefNodes = funcDefNodes;
        this.mainFuncDefNode = mainFuncDefNode;
    }

    public ArrayList<DeclNode> getDeclNodes() {
        return declNodes;
    }
    public ArrayList<FuncDefNode> getFuncDefNodes() {
        return funcDefNodes;
    }
    public MainFuncDefNode getMainFuncDefNode() {
        return mainFuncDefNode;
    }

    public void print() {
        for (DeclNode declNode : declNodes) {
            declNode.print();
        }
        for (FuncDefNode funcDefNode : funcDefNodes) {
            funcDefNode.print();
        }
        mainFuncDefNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.CompUnit));
    }
}
