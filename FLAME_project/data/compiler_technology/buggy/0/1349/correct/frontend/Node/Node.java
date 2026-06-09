package frontend.Node;

import frontend.Token.Token;

import java.util.ArrayList;

import java.io.BufferedWriter;

public class Node {
    private final NodeType type;

    private final ArrayList<Object> children;

    public Node(NodeType type) {
        this.type = type;
        this.children = new ArrayList<>();
    }

    public void addToken(Token token) {
        this.children.add(token);
    }

    public Node addNewNode(NodeType type) {
        Node node = new Node(type);
        this.children.add(node);
        return node;
    }

    public void print(BufferedWriter writer) {
        if (this.type == NodeType.LOrExp || this.type == NodeType.LAndExp ||
                this.type == NodeType.EqExp || this.type == NodeType.RelExp ||
                this.type == NodeType.AddExp || this.type == NodeType.MulExp) {
            for (Object child : this.children) {
                if (child instanceof Token) {
                    Token token = (Token) child;
                    try {
                        writer.write(token.getType() + " " + token.getValue() + "\n");
                    } catch (Exception e) {
                        throw new RuntimeException("Error writing to file");
                    }
                } else if (child instanceof Node) {
                    Node node = (Node) child;
                    node.print(writer);
                    try {
                        writer.write("<" + this.type + ">\n");
                    } catch (Exception e) {
                        throw new RuntimeException("Error writing to file");
                    }
                }
            }
        } else {
            for (Object child : this.children) {
                if (child instanceof Token) {
                    Token token = (Token) child;
                    try {
                        writer.write(token.getType() + " " + token.getValue() + "\n");
                    } catch (Exception e) {
                        throw new RuntimeException("Error writing to file");
                    }
                } else if (child instanceof Node) {
                    Node node = (Node) child;
                    node.print(writer);
                }
            }
            try {
                writer.write("<" + this.type + ">\n");
            } catch (Exception e) {
                throw new RuntimeException("Error writing to file");
            }
        }
    }
}
