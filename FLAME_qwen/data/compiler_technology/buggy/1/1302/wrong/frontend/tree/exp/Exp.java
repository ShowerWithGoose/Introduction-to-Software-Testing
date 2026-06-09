package frontend.tree.exp;

import frontend.tree.Node;

/**
 * Exp â†’ AddExp
 */
public class Exp extends Node {
    @Override
    public Node getFirstLeaf() {
        AddExp addExp = (AddExp) children.get(0);
        return addExp.getFirstLeaf();
    }
}
