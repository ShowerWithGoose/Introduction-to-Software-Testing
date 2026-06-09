package Datas;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description: Astnode类声明
 * @date 2024/9/29 13:14
 */
public class AstNode extends MiddleData {
    // root of AstNode, <CompUnit>
    public static AstNode root;
    public String value;
    public ArrayList<AstNode> children = new ArrayList<AstNode>();

    public AstNode(String value) {
        this.value = value;
    }

    public void addChild(AstNode child) {
        children.add(child);
    }

    /**
     * @Description 删除最后一个节点并返回，用于左递归文法改造后需要在cur和最后节点中间插入一个AstNode的情况
    **/

    public void insertLast(AstNode nodeToInsert) {
        AstNode last = children.get(children.size() - 1);
        children.remove(children.size() - 1);
        children.add(nodeToInsert);
        nodeToInsert.addChild(last);
    }

    public void output(FileWriter writer) {
        try {
            for (AstNode child : children) {
                child.output(writer);
            }
            writer.write(this.value + "\n");
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
