package frontend.ast;

import common.GComponent;

import java.util.ArrayList;

/**
 * @author
 * @Description：
 * @date
 */
public class NLNode implements Node {
    private ArrayList<Node> children;
    private Node parent;
    //深度
    private Integer level;
    private GComponent value;
    //额外储存是否存在语法错误
    private boolean correct;

    public NLNode(GComponent value) {
        this.children = new ArrayList<>();
        this.level = -1;
        this.parent = null;
        this.value = value;
        this.correct = false;
    }


    @Override
    public void addChild(Node child) {
        this.children.add(child);
        child.setParent(this);
    }

    @Override
    public void setParent(Node parent) {
        this.parent = parent;
        this.level = parent.getLevel() + 1;
    }

    @Override
    public ArrayList<Node> getChildren() {
        return this.children;
    }

    @Override
    public Node getParent() {
        return this.parent;
    }

    @Override
    public Boolean isCorrect() {
        return correct;
    }

    @Override
    public Integer getLevel() {
        return level;
    }

    public GComponent getValue(){
        return this.value;
    }

    public void setCorrect(boolean correct){
        this.correct = correct;
    }


}
