package frontend.Parser;

import java.io.PrintWriter;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/14 16:57
 */
public class NonTerminalNode extends TreeNode{
    private String type;
    private ArrayList<TreeNode> myNodes;

    public NonTerminalNode(String type){
        this.type = type;
        this.myNodes = new ArrayList<>();
    }

    public void addNode(TreeNode node){
        this.myNodes.add(node);
    }
    public String getType(){
        return this.type;
    }
    public ArrayList<TreeNode> getMyNodes(){
        return this.myNodes;
    }
    public void print_tree(){
        if(this.myNodes.isEmpty()){
            return ;
        }
        for(TreeNode node : this.myNodes){
            node.print_tree();
        }
        System.out.println("<" + this.type  + ">");
    }
    public void removeNode(){
        this.myNodes.remove(this.myNodes.size() - 1);
    }
    public void print_tree_to_file(PrintWriter printWriter){
        if(this.myNodes.isEmpty()){
            return ;
        }
        for(TreeNode node : this.myNodes){
            node.print_tree_to_file(printWriter);
        }
        if(this.type.equals("BlockItem") || this.type.equals("Decl") || this.type.equals("BType")){
            return ;
        }
        printWriter.println("<" + this.type  + ">");
    }
}
