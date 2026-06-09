package Tree;

import java.io.BufferedWriter;

public interface Node {
    void postOrderTraversal(BufferedWriter writer); // 定义后续遍历方法
    
    void postOrderTraversal(); // 定义后续遍历方法
}
