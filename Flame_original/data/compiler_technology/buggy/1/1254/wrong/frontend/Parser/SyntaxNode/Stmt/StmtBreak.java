package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;

public class StmtBreak extends Stmt {
    private Token token;
    private Token semicn;

    public StmtBreak(Token token, Token semicn) {
        this.token = token;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        return token.toString() + semicn.toString() + name + "\n";
    }
}
