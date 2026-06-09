package Node;

import IOcontrol.IO;
import LexParser.Parser;

import java.util.ArrayList;

public class CompUnitNode {
    //编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    private ArrayList<DeclNode> declNodes;
    private ArrayList<FuncDefNode> funcDefNodes;
    private MainFuncDefNode mainFuncDefNode;

    public CompUnitNode(ArrayList<DeclNode> declNodes,
                        ArrayList<FuncDefNode> funcDefNodes,MainFuncDefNode mainFuncDefNode) {
        this.declNodes = declNodes;
        this.funcDefNodes = funcDefNodes;
        this.mainFuncDefNode = mainFuncDefNode;
    }

    public void print() {
        for (int i = 0;i < declNodes.size();i++) {
            declNodes.get(i).print();
        }
        for (int i = 0;i < funcDefNodes.size();i++) {
            funcDefNodes.get(i).print();
        }
        mainFuncDefNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.CompUnit));
    }
}
