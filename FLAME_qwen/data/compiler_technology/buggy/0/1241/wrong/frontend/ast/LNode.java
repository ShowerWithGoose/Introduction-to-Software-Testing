package frontend.ast;

import common.Token;
import common.TokenType;

import java.util.ArrayList;

/**
 * @author
 * @Description：
 * @date
 */
public class LNode implements Node{
    private Node parent;
    //深度
    private Integer level;
    private Token value;
    private TokenType type;
    //额外储存是否存在语法错误
    private boolean correct;

    public LNode(TokenType type, Token token, Boolean isCorrect) {
        this.parent = null;
        this.level = -1;
        this.value = token;
        this.correct = isCorrect;
        this.type = type;
    }

    @Override
    public void addChild(Node child) {
        System.out.println("这是叶节点");
    }

    @Override
    public void setParent(Node parent) {
        this.parent = parent;
        this.level = parent.getLevel() + 1;
    }

    @Override
    public ArrayList<Node> getChildren() {
        System.out.println("这是叶节点");
        return null;
    }

    @Override
    public Node getParent() {
        return this.parent;
    }

    @Override
    public Boolean isCorrect() {
        return correct;
    }

    public Token getToken() {
        return value;
    }



    @Override
    public Integer getLevel() {
        return level;
    }
}
