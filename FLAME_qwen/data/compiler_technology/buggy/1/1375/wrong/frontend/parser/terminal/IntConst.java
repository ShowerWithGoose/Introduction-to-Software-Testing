package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.SyntaxNode;

public class IntConst implements SyntaxNode {
    public Token token;

    public IntConst(Token token) {
        this.token = token;
    }

    public IntConst(String numStr, int lineNum) {
        this.token = new Token(TokenType.INTCON, lineNum, numStr);
    }

    public int getNum() {
        return Integer.valueOf(this.token.content);
    }

    public int getLineNum() {
        return this.token.linenum;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return this.token.linenum;
    }
}
