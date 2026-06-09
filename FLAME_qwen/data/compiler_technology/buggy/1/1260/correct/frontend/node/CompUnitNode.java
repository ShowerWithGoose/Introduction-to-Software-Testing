package frontend.node;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class CompUnitNode {
    private List<DeclNode> declNodeList;
    private List<FuncDefNode> funcDefNodeList;
    private MainFuncDefNode mainFuncDefNode;
    public CompUnitNode(List<DeclNode> declNodes, List<FuncDefNode> funcDefNodes, MainFuncDefNode mainFuncDefNode) {
        this.declNodeList = declNodes;
        this.funcDefNodeList = funcDefNodes;
        this.mainFuncDefNode = mainFuncDefNode;
    }
    public List<DeclNode> getDeclNodes() {
        return declNodeList;
    }

    public List<FuncDefNode> getFuncDefNodes() {
        return funcDefNodeList;
    }

    public MainFuncDefNode getMainFuncDefNode() {
        return mainFuncDefNode;
    }
    public void print(){
        for(DeclNode declNode: declNodeList){
            declNode.print();
        }
        for(FuncDefNode funcDefNode: funcDefNodeList){
            funcDefNode.print();
        }
        mainFuncDefNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<CompUnit>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

}
