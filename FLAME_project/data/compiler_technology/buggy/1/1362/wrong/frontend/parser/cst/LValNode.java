package frontend.parser.cst;

import frontend.lexer.TokenType;

import java.util.ArrayList;

public class LValNode extends CSTNode {
    private final ArrayList<ExpNode> expNodes = new ArrayList<>();
    private TokenNode ident = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof TokenNode && ((TokenNode) node).isSameType(TokenType.IDENFR)) {
            ident = (TokenNode) node;
        }
        if (node instanceof ExpNode) {
            expNodes.add((ExpNode) node);
        }
    }
}
