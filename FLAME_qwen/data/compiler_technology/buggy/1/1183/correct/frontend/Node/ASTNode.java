package frontend.Node;

import java.io.BufferedWriter;
import java.io.IOException;

public class ASTNode {

    public void postOrderTraversal(ASTNode node, BufferedWriter writer) {
        if (node instanceof Node) {
            Node internalNode = (Node) node;
            for (ASTNode child : internalNode.getChildNode()) {
                postOrderTraversal(child,writer);
            }
            try {
                if (((Node) node).getParType() != ParType.BlockItem && ((Node) node).getParType() != ParType.Decl &&
                        ((Node) node).getParType() != ParType.BType) {
                    writer.write(node.toString());
                    writer.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else if (node instanceof LeafNode) {
            LeafNode leaf = (LeafNode) node;
            try {
                writer.write(leaf.toString());
                writer.newLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
