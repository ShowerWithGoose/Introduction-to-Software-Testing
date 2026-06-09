package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/11 17:40
 */
public class FuncDef implements SyntaxNode{
    private final String name = "<FuncDef>";
    private FuncType funcType;
    private Token ident;
    private Token leftParent; // '(
    private FuncFParams funcFParams = null; // may
    private Token rightParent; // ')'
    private Block block;

    public FuncDef(FuncType funcType, Token ident, Token leftParent, FuncFParams funcFParams, Token rightParent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParent = leftParent;
        this.funcFParams = funcFParams;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcType.output());
        sb.append(this.ident.output());
        sb.append(this.leftParent.output());
        if (this.funcFParams != null) {
            sb.append(this.funcFParams.output());
        }
        sb.append(this.rightParent.output());
        sb.append(this.block.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
