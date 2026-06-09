package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 10:42
 */
public class FuncType implements SyntaxNode{
    private final String name = "<FuncType>";
    private Token token; //int 或 char 或  void

    public FuncType(Token token) {
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
