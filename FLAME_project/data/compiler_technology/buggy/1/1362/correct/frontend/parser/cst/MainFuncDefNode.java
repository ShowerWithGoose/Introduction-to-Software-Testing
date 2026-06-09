package frontend.parser.cst;

public class MainFuncDefNode extends FuncDefNode {
    private BlockNode block = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof BlockNode) {
            block = (BlockNode) node;
        }
    }
}
