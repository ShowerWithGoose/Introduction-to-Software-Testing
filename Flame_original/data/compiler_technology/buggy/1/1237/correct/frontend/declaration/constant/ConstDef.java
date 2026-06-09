package frontend.declaration.constant;

import frontend.Token;
import frontend.terminal.Ident;
import frontend.SyntaxNode;
import frontend.declaration.constant.constinitval.ConstInitVal;
import frontend.expression.ConstExp;

/**
 * 常量定义 ConstDef
 */
public class ConstDef implements SyntaxNode {
    private final String name = "<ConstDef>";
    private final Ident ident;  // 标识符
    private final Token leftBracket;  // '['
    private final ConstExp constExp;  // 数组索引
    private final Token rightBracket;  // ']'
    private final Token eq;  // '='
    private final ConstInitVal constInitval;  // 常量初值

    public ConstDef(Ident ident,
                    Token leftBracket,
                    ConstExp constExp,
                    Token rightBracket,
                    Token eq,
                    ConstInitVal constInitval) {
        if (ident == null || eq == null || constInitval == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }
         //确保数组维度为一维
        if ((leftBracket == null && (constExp != null || rightBracket != null)) ||
                (leftBracket != null && (constExp == null || rightBracket == null))) {
            throw new IllegalArgumentException("Invalid array syntax, only one-dimensional arrays are supported.");
        }

        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExp = constExp;
        this.rightBracket = rightBracket;
        this.eq = eq;
        this.constInitval = constInitval;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());

        // 输出一维数组的内容（如果存在）
        if (leftBracket != null && rightBracket != null && constExp != null) {
            sb.append(leftBracket.syntaxOutput());   // 输出左括号
            sb.append(constExp.syntaxOutput());      // 输出表达式（下标）
            sb.append(rightBracket.syntaxOutput());  // 输出右括号
        }

        sb.append(eq.syntaxOutput());
        sb.append(constInitval.syntaxOutput());
        sb.append(name).append("\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
