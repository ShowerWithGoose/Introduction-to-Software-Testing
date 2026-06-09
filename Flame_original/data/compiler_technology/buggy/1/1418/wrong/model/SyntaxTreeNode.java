package model;

import java.util.List;

public class SyntaxTreeNode {
    private String name;
    private Token token;
    private List<SyntaxTreeNode> children;

    public SyntaxTreeNode(){}
    public SyntaxTreeNode(String name, Token token, List<SyntaxTreeNode> children) {
        this.name = name;
        this.token = token;
        this.children = children;
    }
    public void setToken(Token tt) {
        this.token = tt;
    }
    public Token getToken() {
        return this.token;
    }
    public List<SyntaxTreeNode> getChildren() {
        return this.children;
    }
    public String getName() {
        return this.name;
    }
}
