package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 13:40
 */
public class StmtNodeOfBC implements SyntaxNode{
    private Token token; // break / continue
    private Token semicn;

    public StmtNodeOfBC(Token token, Token semicn) {
        this.token = token;
        this.semicn = semicn;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.output());
        sb.append(this.semicn.output());
        return sb.toString();
    }
}
