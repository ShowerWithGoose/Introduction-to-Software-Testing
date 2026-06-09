package Parser;

import Lexer.Token;

/**
 * @Description:
 * @date 2024/10/13
 */
public class UnaryOp implements TreeNode{
    private final String name = "<UnaryOp>";
    private Token op;

    public UnaryOp(Token token) {
        this.op = token;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.op.toStringprint());
        sb.append(this.name).append("\n");
        return sb.toString();
    }
}
