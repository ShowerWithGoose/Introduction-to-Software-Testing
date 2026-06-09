package frontend.Node;

import frontend.Token.LexType;

public class LeafNode extends ASTNode{
    private int lineNum;
    private String name;
    private int number;
    private LexType lexType;
    private Node parentNode;

    public LeafNode(int lineNum, String name, int number, LexType lexType, Node parentNode) {
        this.lineNum = lineNum;
        this.name = name;
        this.number = number;
        this.lexType = lexType;
        this.parentNode = parentNode;
    }

    public String getName() {
        return name;
    }

    public int getLineNum() {
        return lineNum;
    }

    public LexType getLexType() {
        return lexType;
    }

    public int getNumber() {
        return number;
    }

    @Override
    public String toString() {
        return lexType.toString() + ' ' + name;
    }
}
