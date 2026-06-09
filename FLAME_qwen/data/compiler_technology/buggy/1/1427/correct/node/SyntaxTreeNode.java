package node;

import token.Token;

import java.io.PrintStream;
import java.util.List;
public class SyntaxTreeNode {
    protected NodeType nodeType;
    protected List<SyntaxTreeNode> subNodes;
    protected Token token;

    public SyntaxTreeNode(NodeType nodeType,List<SyntaxTreeNode> subNodes) {
        this.nodeType = nodeType;
        this.subNodes = subNodes;
    }
    public SyntaxTreeNode(NodeType nodeType,Token subToken) {
        this.nodeType = nodeType;
        this.token = subToken;
    }

    public void print(PrintStream lexerOutputStream) {
        if (nodeType != NodeType.LEAF_NODE) {
            for (SyntaxTreeNode node:subNodes) {
                node.print(lexerOutputStream);
            }
            lexerOutputStream.println("<"+nodeType.getCode()+">");
        } else {
            lexerOutputStream.println(token.toString());
        }
    }

    public void addChild(SyntaxTreeNode syntaxTreeNode) {
        subNodes.add(syntaxTreeNode);
    }
}
