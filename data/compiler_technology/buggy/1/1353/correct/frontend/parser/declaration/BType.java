package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

/**
 * BType 基本类型类
 * <BType> -> 'int | 'char'
 */
public class BType implements SyntaxNode {
    private final String name = "<BType>";
    private Token token; // be INTTK or CHARTK

    public BType(Token token) {
        this.token = token;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        /* not output BType according to assignment requirement */
        return sb.toString();
    }
}
