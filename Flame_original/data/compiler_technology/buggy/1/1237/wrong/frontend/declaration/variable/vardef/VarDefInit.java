package frontend.declaration.variable.vardef;

import frontend.Token;
import frontend.terminal.Ident;
import frontend.declaration.variable.initval.InitVal;
import frontend.expression.ConstExp;

/**
 * 变量定义初始化 VarDefInit
 */
public class VarDefInit implements VarDefEle {
    private final Ident ident;
    private final Token leftBrace; // '['
    private final ConstExp constExp; // 数组下标
    private final Token rightBrace; // ']'
    private final Token eq; // '='
    private final InitVal initVal;

    public VarDefInit(Ident ident, Token leftBrace, ConstExp constExp, Token rightBrace, Token eq, InitVal initVal) {
        if (ident == null || eq == null || initVal == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }
        if ((leftBrace != null || rightBrace != null) && constExp == null) {
            throw new IllegalArgumentException("Array definition must include a ConstExp");
        }
        this.ident = ident;
        this.leftBrace = leftBrace;
        this.constExp = constExp;
        this.rightBrace = rightBrace;
        this.eq = eq;
        this.initVal = initVal;
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
        sb.append(eq.syntaxOutput());
        sb.append(initVal.syntaxOutput());
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
