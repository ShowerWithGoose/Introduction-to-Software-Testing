package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.SyntaxNode;

public class CharConst implements SyntaxNode {
    public Token token;

    public CharConst(Token token) {
        this.token = token;
    }

    public CharConst(String name, int lineNum) {
        this.token = new Token(TokenType.CHRCON, lineNum, name);
    }


    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return token.linenum;
    }
}
