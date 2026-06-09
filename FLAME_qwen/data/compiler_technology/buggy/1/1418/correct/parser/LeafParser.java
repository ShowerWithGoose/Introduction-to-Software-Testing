package parser;

import model.SyntaxTreeNode;
import model.Token;

//叶子节点的解析器，包括关键字、标识符等
public class LeafParser {
    public SyntaxTreeNode run(Token token) {
        return new SyntaxTreeNode("leaf", token, null);
    }
}
