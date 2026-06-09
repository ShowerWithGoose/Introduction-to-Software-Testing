package frontend.terminal;

import frontend.Token;
import frontend.TokenType;
import frontend.SyntaxNode;
import frontend.declaration.constant.constinitval.ConstInitValEle;
import frontend.declaration.variable.initval.InitValEle;

/**
 * 字符串常量 StringConst
 */
public class StringConst implements SyntaxNode , ConstInitValEle {
    private final Token token;

    public StringConst(Token token) {
        if (token == null || token.getType() != TokenType.STRCON) {
            throw new IllegalArgumentException("Token must be of type STRCON");
        }
        this.token = token;
    }

    public StringConst(String str, int lineNum) {
        if (str == null || str.isEmpty()) {
            throw new IllegalArgumentException("String cannot be null or empty");
        }
        if (!str.matches("\"([^\"\\\\]|\\\\.)*\"")) {
            throw new IllegalArgumentException("Invalid string constant format: " + str);
        }
        this.token = new Token(TokenType.STRCON, lineNum, str);
    }

    public String getString() {
        String content = this.token.getContent();
        return content.substring(1, content.length() - 1);  // 去掉两端的引号
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
