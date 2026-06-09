package frontend.declaration.variable.vardef;

import frontend.Token;
import frontend.terminal.Ident;
import frontend.expression.ConstExp;

/**
 * 空变量定义 VarDefNull
 */
public class VarDefNull implements VarDefEle {
    private final Ident ident;
    private final Token leftBrace; // '['
    private final ConstExp constExp; // 数组下标
    private final Token rightBrace; // ']'

    public VarDefNull(Ident ident, Token leftBrace, ConstExp constExp, Token rightBrace) {
        if (ident == null) {
            throw new IllegalArgumentException("Ident cannot be null");
        }
        if ((leftBrace != null || rightBrace != null) && constExp == null) {
            throw new IllegalArgumentException("Array definition must include a ConstExp");
        }
        this.ident = ident;
        this.leftBrace = leftBrace;
        this.constExp = constExp;
        this.rightBrace = rightBrace;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (leftBrace != null && constExp != null && rightBrace != null) {
            sb.append(leftBrace.syntaxOutput());
            sb.append(constExp.syntaxOutput());
            sb.append(rightBrace.syntaxOutput());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
