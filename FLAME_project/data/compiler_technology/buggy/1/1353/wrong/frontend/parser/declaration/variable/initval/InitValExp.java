package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

/**
 * <InitVal> Exp子节点接口
 * <Exp>
 */
public class InitValExp implements InitValEle {
    private Token leftBrace;
    private Exp first; // may not exist

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxOutput());
        return sb.toString();
    }
}
