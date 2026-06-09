package frontend.parser.cst;

import frontend.lexer.TokenType;

public class FuncDefNode extends CSTNode {
    private FuncTypeNode funcType = null;
    private TokenNode funcName = null;
    private FuncFParamsNode params = null;
    private BlockNode block = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof FuncTypeNode) {
            funcType = (FuncTypeNode) node;
        } else if (node instanceof TokenNode) {
            TokenNode tokenNode = (TokenNode) node;
            if (tokenNode.isSameType(TokenType.IDENFR)) {
                funcName = tokenNode;
            }
        } else if (node instanceof FuncFParamsNode) {
            params = (FuncFParamsNode) node;
        } else if (node instanceof BlockNode) {
            block = (BlockNode) node;
        }
    }
}
