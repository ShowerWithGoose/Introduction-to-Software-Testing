package frontend.tree.exp;

import frontend.lexer.Token;
import frontend.tree.Node;

/**
 * PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
 */
public class PrimaryExp extends Node {
    @Override
    public Node getFirstLeaf() {
        if (children.get(0) instanceof Token) {
            return children.get(1).getFirstLeaf();
        } else if (children.get(0) instanceof LVal) { // 特殊
            return children.get(0);
        } else {
            return children.get(0).getChildren().get(0);
        }
    }
}
