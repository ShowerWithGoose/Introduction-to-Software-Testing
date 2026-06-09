package frontend.tree.exp;

import frontend.tree.Node;

/**
 * AddExp → MulExp | AddExp ('+' | '−') MulExp
 */
public class AddExp extends Node {
    @Override
    public Node getFirstLeaf() {
        return children.get(0).getFirstLeaf();
    }
}
