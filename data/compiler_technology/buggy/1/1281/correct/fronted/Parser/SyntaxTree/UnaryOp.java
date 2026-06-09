package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/12 23:31
 */
public class UnaryOp implements SyntaxNode{
    private final String name = "<UnaryOp>";
    private Token token; //  + / - / !

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
