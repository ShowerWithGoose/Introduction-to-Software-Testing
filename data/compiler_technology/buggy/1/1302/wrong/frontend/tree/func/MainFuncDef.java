package frontend.tree.func;

import frontend.error.ErrorList;
import frontend.tree.Node;

/**
 * MainFuncDef → 'int' 'main' '(' ')' Block // g
 */
public class MainFuncDef extends Node {
    private Block block;

    @Override
    public void semanticAnalysis() {
        block = (Block) children.get(children.size() - 1);

        super.semanticAnalysis();

        boolean hasReturn = false;
        Node penult = block.getChildren().get(block.getChildren().size() - 2);
        if (penult instanceof Stmt) {
            if (((Stmt) penult).isReturnValue()) {
                hasReturn = true;
            }
        }
        if (!hasReturn) { // 有返回值的函数缺少return语句
            ErrorList.getInstance().addError("g", endLine);
        }
    }
}
