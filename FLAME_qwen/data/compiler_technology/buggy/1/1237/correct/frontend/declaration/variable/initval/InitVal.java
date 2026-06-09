package frontend.declaration.variable.initval;

import frontend.SyntaxNode;
import frontend.expression.Exp;
import frontend.terminal.StringConst;

/**
 * 初始化值 InitVal
 */
public class InitVal implements SyntaxNode {
    private final String name = "<InitVal>";
    private final Exp exp; // 表示一个表达式初值
    private final StringConst stringConst; // 表示一个字符串常量初值
    private final InitVals initVals; // 表示数组初值

    // 用于 Exp 类型的初始化
    public InitVal(Exp exp) {
        if (exp == null) {
            throw new IllegalArgumentException("Exp cannot be null");
        }
        this.exp = exp;
        this.stringConst = null;
        this.initVals = null;
    }

    // 用于 StringConst 类型的初始化
    public InitVal(StringConst stringConst) {
        if (stringConst == null) {
            throw new IllegalArgumentException("StringConst cannot be null");
        }
        this.exp = null;
        this.stringConst = stringConst;
        this.initVals = null;
    }

    // 用于数组类型的初始化
    public InitVal(InitVals initVals) {
        if (initVals == null) {
            throw new IllegalArgumentException("InitVals cannot be null");
        }
        this.exp = null;
        this.stringConst = null;
        this.initVals = initVals;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.syntaxOutput());
        } else if (stringConst != null) {
            sb.append(stringConst.syntaxOutput());
        } else if (initVals != null) {
            sb.append(initVals.syntaxOutput());
        }
        sb.append(name).append("\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
