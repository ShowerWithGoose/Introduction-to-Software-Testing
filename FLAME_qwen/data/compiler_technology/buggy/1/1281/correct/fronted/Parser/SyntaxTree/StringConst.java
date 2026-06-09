package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 1:18
 */
public class StringConst implements SyntaxNode{
    private Token token;
    public StringConst(Token token) {
        this.token = token;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.output());
        return sb.toString();
    }
}
