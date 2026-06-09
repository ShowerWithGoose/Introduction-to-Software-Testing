package frontend.parser.cst;

import frontend.lexer.TokenType;

public class FuncTypeNode extends CSTNode {
    private int type;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof TokenNode) {
            if (((TokenNode) node).isSameType(TokenType.VOIDTK)) {
                type = 0;
            } else if (((TokenNode) node).isSameType(TokenType.INTTK)) {
                type = 1;
            } else if (((TokenNode) node).isSameType(TokenType.CHARTK)) {
                type = 2;
            }
        }
    }
    
    public int getType() {
        return type;
    }
    
}
