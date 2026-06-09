package frontend.parser.cst;

import frontend.lexer.TokenType;

import java.util.ArrayList;

public class OutStmtNode extends CSTNode {
    private String str;
    private final ArrayList<ExpNode> arguments = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof TokenNode && ((TokenNode) node).isSameType(TokenType.STRCON)) {
            str = ((TokenNode) node).getContent();
        } else if (node instanceof ExpNode) {
            arguments.add((ExpNode) node);
        }
    }
}
