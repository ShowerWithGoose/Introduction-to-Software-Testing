package frontend.tree.exp;

import frontend.tree.Node;

/**
 * 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
 */
public class MulExp extends Node {
    @Override
    public Node getFirstLeaf() {
        return children.get(0).getFirstLeaf();
    }
}
