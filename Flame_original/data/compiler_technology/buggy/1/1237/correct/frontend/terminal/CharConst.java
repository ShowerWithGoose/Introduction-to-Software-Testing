package frontend.terminal;

import frontend.Token;
import frontend.TokenType;
import frontend.SyntaxNode;
import frontend.expression.primaryexp.PrimaryExpEle;

/**
 * 字符常量 CharConst
 */
public class CharConst implements SyntaxNode, PrimaryExpEle {
    private final Token token;

    public CharConst(Token token) {
        if (token == null || token.getType() != TokenType.CHRCON) {
            throw new IllegalArgumentException("Token must be of type CHRCON");
        }
        this.token = token;
    }

    public CharConst(String charStr, int lineNum) {
        if (charStr == null || charStr.isEmpty()) {
            throw new IllegalArgumentException("Character string cannot be null or empty");
        }
        if (!charStr.matches("'([^\\\\']|\\\\.)'")) {
            throw new IllegalArgumentException("Invalid character constant format: " + charStr);
        }
        this.token = new Token(TokenType.CHRCON, lineNum, charStr);
    }

    public char getChar() {
        String content = this.token.getContent();
        if (content.length() == 3) {  // 普通字符，如 'a'
            return content.charAt(1);
        } else if (content.startsWith("'\\") && content.length() == 4) {  // 转义字符，如 '\n'
            return content.charAt(2);  // 返回转义后的字符
        } else {
            throw new IllegalArgumentException("Invalid character constant: " + content);
        }
    }

    public int getLineIndex() {
        return this.token.getLineIndex();
    }

    @Override
    public String syntaxOutput() {
        return token.syntaxOutput();
    }

    @Override
    public String toString() {
        return token.getContent();
    }
}
