package frontend.parser;

import frontend.lexer.Token;

import java.util.ArrayList;

public class TreeNode {
    private ParserType parserType;
    private Token token;
    private ArrayList<TreeNode> children = new ArrayList<>();

    public TreeNode(ParserType parserType, Token token) {
        this.parserType = parserType;
        this.token = token;
    }

    public ParserType getParserType() {
        return parserType;
    }

    public Token getToken() {
        return token;
    }

    public ArrayList<TreeNode> getChildren() {
        return children;
    }

    public void setChildren(TreeNode child) {
        this.children.add(child);
    }
}
