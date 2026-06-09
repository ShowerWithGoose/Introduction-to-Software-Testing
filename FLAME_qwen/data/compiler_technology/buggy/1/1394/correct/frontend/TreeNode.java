package frontend;

import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class TreeNode {

    private List<TreeNode> children;

    private Token token;
    private Component NodeType;

    private TreeNode father;
    public TreeNode(Token token , Component nodeType){
        this.children = new ArrayList<>();
        this.token = token;
        this.NodeType = nodeType;
    }
    public void addChild(TreeNode node){
        children.add(node);
    }
    public void removeChild(){
        if(children.isEmpty())
            return;
        children.remove(children.get(children.size()-1));
    }
    public List<TreeNode> getChildren(){
        return children;
    }

    public TreeNode getNextNode(){
        int index = children.size() - 1;
        children.get(index).setFather(this);
        return children.get(index);
    }

    public void setFather(TreeNode father){
        this.father = father;
    }
    public TreeNode getFather(){
        return father;
    }

    public void print(FileWriter stdWriter){
        try {
            for(int i = 0; i < children.size(); i++){
                children.get(i).print(stdWriter);
            }
            if(NodeType != Component.Terminal && NodeType != Component.BlockItem
                && NodeType != Component.Decl && NodeType != Component.BType){
                stdWriter.write(NodeType.toString() + "\n");
            }
            else{
                token.print(stdWriter);
            }
        } catch (Exception e) {}
    }
}
