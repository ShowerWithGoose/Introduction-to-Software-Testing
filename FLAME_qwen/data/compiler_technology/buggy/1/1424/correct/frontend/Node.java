package frontend;

import java.util.ArrayList;



public class Node {

    private Token token;
    private ArrayList<Node> sons;
    private NodeType type;
    public Node(NodeType type) {
        sons = new ArrayList<>();
        this.type = type;
        this.token = null;
    }
    public Node(Token token) {
        sons = new ArrayList<>();
        this.type = NodeType.End;
        this.token = token;
    }

    public NodeType getType() {
        return type;
    }

    public ArrayList<Node> getSons() {
        return sons;
    }

    public void addSon(Node node) {
        sons.add(node);
    }

    public void print(ArrayList<String> output) {
        if (type == NodeType.End) {
            output.add(token.getType() + " " + token.getVal() + "\n");
        } else if (type == NodeType.MulExp || type == NodeType.AddExp ||
                type == NodeType.RelExp || type == NodeType.EqExp ||
                type == NodeType.LAndExp || type == NodeType.LOrExp) {
            for (Node node : sons) {
                node.print(output);
                if (node.getType() != NodeType.End) {
                    output.add("<" + type + ">\n");
                }
            }
        } else {
            for (Node node : sons) {
                node.print(output);
            }
            if (type != NodeType.BlockItem && type != NodeType.Decl && type != NodeType.BType) {
                output.add("<" + type + ">" + "\n");
            }
        }
    }

}
