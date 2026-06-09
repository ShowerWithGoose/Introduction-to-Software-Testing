package Parser;

import Lexer.Token;

/**
 * @Description:
 * @date 2024/10/13
 */
public class NumberClass implements TreeNode{
    private final String name = "<Number>";
    private Token intConst;

    public NumberClass(Token intConst) {
        this.intConst = intConst;
    }

    public Token getIntConst() {
        return intConst;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.intConst.toStringprint());
        sb.append(name).append("\n");
        return sb.toString();
    }
}
