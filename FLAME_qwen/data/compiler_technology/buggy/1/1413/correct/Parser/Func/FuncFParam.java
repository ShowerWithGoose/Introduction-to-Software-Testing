package Parser.Func;

import Lexer.Token;
import Parser.BType;
import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncFParam implements TreeNode {
    private final String name = "<FuncFParam>";
    private BType btype;
    private Token ident;
    private Token leftBracketFirst = null; // '[' MAY exist
    private Token rightBracketFirst = null; // ']' MAY exist

    public FuncFParam(BType btype, Token ident, Token leftBracketFirst, Token rightBracketFirst) {
        this.btype = btype;
        this.ident = ident;
        this.leftBracketFirst = leftBracketFirst;
        this.rightBracketFirst = rightBracketFirst;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.btype.print_tree());
        sb.append(this.ident.toStringprint());
        if(leftBracketFirst!=null){
            sb.append(leftBracketFirst.toStringprint());
            sb.append(rightBracketFirst.toStringprint());
        }else {
            System.out.println("死了");
        }
        sb.append(this.name).append("\n");
        return sb.toString();
    }
}
