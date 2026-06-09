package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/12 21:35
 */
public class Number implements SyntaxNode{
    private final String name = "<Number>";
    private Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }


    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intConst.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
