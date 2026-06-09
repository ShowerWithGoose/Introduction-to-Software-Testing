package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/11 17:40
 */
public class MainFuncDef implements SyntaxNode{
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
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.output());
        sb.append(this.mainTk.output());
        sb.append(this.leftParent.output());
        sb.append(this.rightParent.output());
        sb.append(this.block.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
