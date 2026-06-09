package frontend.ast;

import java.util.ArrayList;

/**
 * @author
 * @Descriptionï¼š
 * @date
 */
public interface Node {
    void addChild(Node child);
    void setParent(Node parent);
    ArrayList<Node> getChildren();
    Node getParent();
    Boolean isCorrect();
    Integer getLevel();
}
