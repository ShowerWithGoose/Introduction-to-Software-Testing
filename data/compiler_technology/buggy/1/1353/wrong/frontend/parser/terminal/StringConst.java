package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.declaration.constant.constInitVal.ConstInitValEle;
import frontend.parser.declaration.variable.initval.InitValEle;

/**
 * 字符串常量 String-Const
 */
public class StringConst implements ConstInitValEle, InitValEle {
    private Token token;

    public StringConst(Token token) {
        this.token = token;
    }

    public StringConst(String str, int lineNum) {
        this.token = new Token(TokenType.STRCON, lineNum, str);
    }

    public String getString() {
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
