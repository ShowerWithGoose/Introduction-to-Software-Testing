package frontend.tree;

import frontend.lexer.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Tree {
    private final Node root;

    public Tree(Node root) {
        this.root = root;
    }

    public void postOrderPrint() throws IOException {
        List<Node> result = new ArrayList<>();
        postOrderRecur(root, result);
        try (FileWriter fw = new FileWriter("parser.txt")) {
            for (Node node : result) {
                fw.write(nodeToString(node) + "\n");
            }
        }
    }

    private void postOrderRecur(Node node, List<Node> result) {
        if (node instanceof Token) {
            result.add(node);
            return;
        }
        for (Node child : node.getChildren()) {
            postOrderRecur(child, result);
        }
        result.add(node);
    }

    public String nodeToString(Node node) {
        if (node instanceof Token) {
            return ((Token) node).getLexType() + " " + ((Token) node).getValue();
        } else {
            String tmp = node.getClass().getSimpleName();
            return "<" + tmp + ">";
        }
    }
}
