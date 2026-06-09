package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/12 23:19
 */
public class Character implements SyntaxNode{
    private final String name = "<Character>";
    private Token charConst;

    public Character(Token charConst) {
        this.charConst = charConst;
    }


    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.charConst.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
