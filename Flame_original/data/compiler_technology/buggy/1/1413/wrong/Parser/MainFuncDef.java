package Parser;

import Lexer.Token;

/**
 * @Description:
 * @date 2024/10/10
 */
public class MainFuncDef implements TreeNode{
    private final String name = "<MainFuncDef>";
    private Token intTk; // 'int'
    private Token mainTk; // 'main'
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Block block;

    public MainFuncDef(Token intTk, Token mainTk, Token leftParent, Token rightParent, Block block) {
        this.intTk = intTk;
        this.mainTk = mainTk;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.intTk.toStringprint());
        sb.append(this.mainTk.toStringprint());
        sb.append(this.leftParent.toStringprint());
        sb.append(this.rightParent.toStringprint());
        sb.append(this.block.print_tree());
        sb.append(this.name).append("\n");
        return sb.toString();
    }
}
