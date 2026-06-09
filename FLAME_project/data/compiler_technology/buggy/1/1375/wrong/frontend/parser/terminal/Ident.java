package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.SyntaxNode;

public class Ident implements SyntaxNode {
    public Token token;

    public Ident(Token token) {
        this.token = token;
    }

    public Ident(String name, int lineNum) {
        this.token = new Token(TokenType.IDENFR, lineNum, name);
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return this.token.linenum;
    }

}
