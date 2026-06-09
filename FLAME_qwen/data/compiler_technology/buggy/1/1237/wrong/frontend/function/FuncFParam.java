package frontend.function;

import frontend.declaration.BType;
import frontend.terminal.Ident;
import frontend.Token;

/**
 * 函数形参类，表示普通变量或一维数组变量。
 */
public class FuncFParam {
    private final String name = "<FuncFParam>";  // 文法中的标记
    private final BType btype;
    private final Ident ident;
    private final Token leftBracket;  // '[' (仅用于一维数组)
    private final Token rightBracket; // ']' (仅用于一维数组)

    // 构造函数用于普通变量
    public FuncFParam(BType btype, Ident ident) {
        this.btype = btype;
        this.ident = ident;
        this.leftBracket = null;
        this.rightBracket = null;
    }

    // 构造函数用于一维数组
    public FuncFParam(BType btype, Ident ident, Token leftBracket, Token rightBracket) {
        if (btype == null || ident == null || leftBracket == null || rightBracket == null) {
            throw new IllegalArgumentException("Parameters cannot be null for array type parameter");
        }
        this.btype = btype;
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
    }

    // Method to output the syntax representation
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(btype.syntaxOutput());         // 输出 BType
        sb.append(ident.syntaxOutput());         // 输出 Ident
        if (leftBracket != null && rightBracket != null) {
            sb.append(leftBracket.syntaxOutput());  // 输出左括号 '['
            sb.append(rightBracket.syntaxOutput()); // 输出右括号 ']'
        }
        sb.append(name).append("\n");  // 输出文法标记 <FuncFParam>
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
