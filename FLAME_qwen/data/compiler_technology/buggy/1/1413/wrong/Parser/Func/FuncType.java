package Parser.Func;

import Lexer.Token;
import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncType implements TreeNode {
    private String value="<FuncType>";
    private Token funcType;
    public FuncType(Token token)
    {
        this.funcType=token;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.funcType.toStringprint());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
