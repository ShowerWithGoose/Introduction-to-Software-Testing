package frontend.parser.cst;

import frontend.lexer.TokenType;

public class UnaryOpNode extends CSTNode {
    public boolean isPlus() {
        return (((TokenNode) (children.get(0))).isSameType(TokenType.PLUS));
    }
    
    public boolean isMinus() {
        return (((TokenNode) (children.get(0))).isSameType(TokenType.MINU));
    }
    
    public boolean isNot() {
        return (((TokenNode) (children.get(0))).isSameType(TokenType.NOT));
    }
}
