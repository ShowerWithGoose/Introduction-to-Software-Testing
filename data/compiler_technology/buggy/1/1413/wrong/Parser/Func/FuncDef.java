package Parser.Func;

import Lexer.Token;
import Parser.Block;
import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/10
 */
public class FuncDef implements TreeNode {
    private final String value = "<FuncDef>";
    private FuncType funcType;
    private Token ident;
    private Token leftParent; // '('
    private FuncFParams funcFParams ; // MAY exist
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
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.funcType.print_tree());
        sb.append(this.ident.toStringprint());
        sb.append(this.leftParent.toStringprint());
        if(this.funcFParams!=null){
            sb.append(this.funcFParams.print_tree());
        }
        sb.append(this.rightParent.toStringprint());
        sb.append(this.block.print_tree());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
