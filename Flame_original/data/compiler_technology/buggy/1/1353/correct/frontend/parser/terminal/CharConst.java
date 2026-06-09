package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.SyntaxNode;

/**
 * 字符常量 Character-Const
 */
public class CharConst implements SyntaxNode {
    private Token token;

    public CharConst(Token token) {
        this.token = token;
    }

    public CharConst(String ch, int lineNum) {
        this.token = new Token(TokenType.CHRCON, lineNum, ch);
    }

    public String getChar() {
        return this.token.getContent();
    }

    public int getLineNum() {
        return this.token.getLine();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        return sb.toString();
    }
}
