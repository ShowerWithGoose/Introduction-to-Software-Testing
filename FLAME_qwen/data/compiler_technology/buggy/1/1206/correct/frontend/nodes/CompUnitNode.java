package frontend.nodes;

import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:31
 */
public class CompUnitNode {
    //CompUnit → {Decl} {FuncDef} MainFuncDef
    ArrayList<DeclNode> declNodes;
    ArrayList<FunDefNode> funDefNodes;
    MainFuncDefNode mainFuncDefNode;
    public CompUnitNode(ArrayList<DeclNode> list1, ArrayList<FunDefNode> list2, MainFuncDefNode mainFuncDefNode){
        this.declNodes=list1;
        this.funDefNodes=list2;
        this.mainFuncDefNode=mainFuncDefNode;
    }
    public void output() throws IOException{
        for(DeclNode decl:declNodes){
            decl.output();
        }
        for(FunDefNode funDefNode:funDefNodes){
            funDefNode.output();
        }
        mainFuncDefNode.output();
        out.write("<CompUnit>");
    }
}
