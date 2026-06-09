package node;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CompUnitNode {
    //CompUnit â†’ {Decl} {FuncDef} MainFuncDef
    private ArrayList<DeclNode> declNodes;
    private ArrayList<FuncDefNode> funcDefNodes;
    private MainFuncDefNode mainFuncDefNode;

    public CompUnitNode(ArrayList<DeclNode> declNodes, ArrayList<FuncDefNode> funcDefNodes, MainFuncDefNode mainFuncDefNode) {
        this.declNodes = declNodes;
        this.funcDefNodes = funcDefNodes;
        this.mainFuncDefNode = mainFuncDefNode;
    }
    
    public void print() throws IOException {
        if (!declNodes.isEmpty()) {
            for (DeclNode declNode : declNodes) {
                declNode.print();
            }
        }
        if (!funcDefNodes.isEmpty()) {
            for (FuncDefNode funcDefNode: funcDefNodes) {
                funcDefNode.print();
            }
        }
        mainFuncDefNode.print();
        Io.Text.printWord("<CompUnit>");
    }
    
    
}
