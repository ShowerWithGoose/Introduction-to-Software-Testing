package Tree;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Branch implements Node{
    private ArrayList<Node> children = new ArrayList<>();
    
    String branchName;
    
    public Branch(String branchName) {
        this.branchName = branchName;
    }
    
    public void add(Node child) {
        children.add(child);
    }
    
    @Override
    public void postOrderTraversal(BufferedWriter writer) {
        // 先遍历所有子节点
        for (Node child : children) {
            child.postOrderTraversal(writer);
        }
        // 最后访问当前节点
        try {
            writer.write("<");
            writer.write(branchName);
            writer.write(">");
            writer.newLine(); // 写入一个新行字符
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    
    @Override
    public void postOrderTraversal() {
        for (Node child : children) {
            child.postOrderTraversal();
        }
        System.out.println("<" + branchName + ">");
        
    }
}
