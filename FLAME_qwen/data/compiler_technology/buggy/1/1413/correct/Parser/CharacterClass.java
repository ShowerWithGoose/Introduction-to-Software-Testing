package Parser;

import Lexer.Token;

/**
 * @Description:
 * @date 2024/10/13
 */
public class CharacterClass implements TreeNode{
    private final String value="<Character>";
    private Token charConst;
    public CharacterClass(Token charConst)
    {
        this.charConst=charConst;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.charConst.toStringprint());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
