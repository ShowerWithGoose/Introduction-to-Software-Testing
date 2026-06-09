package Parser;

import Lexer.Token;

/**
 * @Description:
 * @date 2024/10/11
 */
public class BType implements TreeNode{
    private String value="<BType>";
    private Token bType;
    public BType(Token token)
    {
        this.bType=token;
    }

    @Override
    public String print_tree() {
        return this.bType.getType() + " " + this.bType.getValue() + "\n";
    }
}
