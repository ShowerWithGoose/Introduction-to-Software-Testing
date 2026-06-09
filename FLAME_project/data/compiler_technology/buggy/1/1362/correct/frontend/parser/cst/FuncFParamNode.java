package frontend.parser.cst;

import frontend.lexer.TokenType;

import java.util.ArrayList;

public class FuncFParamNode extends CSTNode {
    private TokenNode ident = null;
    private final ArrayList<TokenNode> leftBrackets = new ArrayList<>();
    private final ArrayList<ConstExpNode> constExps = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof TokenNode && ((TokenNode) node).isSameType(TokenType.IDENFR)) {
            ident = (TokenNode) node;
        } else if (node instanceof TokenNode && ((TokenNode) node).isSameType(TokenType.LBRACK)) {
            leftBrackets.add((TokenNode) node);
        } else if (node instanceof ConstExpNode) {
            constExps.add((ConstExpNode) node);
        }
    }
}
