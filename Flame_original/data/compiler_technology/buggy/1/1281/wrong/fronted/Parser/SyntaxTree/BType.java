package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/12 15:35
 */
public class BType implements SyntaxNode{
    private final String name = "<BType>";
    private Token token; //int 或 char

    public BType(Token token) {
        this.token = token;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.output());
        /* not output BType according to assignment requirement */
        return sb.toString();
    }
}
