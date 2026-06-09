package frontend.declaration.constant.constinitval;

import frontend.SyntaxNode;
import frontend.terminal.StringConst;

/**
 * 常量初值 ConstInitVal
 */
public class ConstInitVal implements SyntaxNode {
    private final String name = "<ConstInitVal>";
    private final ConstInitValEle constInitValEle;  // 仍然保留对 ConstInitValEle 的支持
    private final StringConst stringConst;          // 新增对 StringConst 的支持

    // 构造函数允许传入 ConstInitValEle 或 StringConst
    public ConstInitVal(ConstInitValEle constInitValEle) {
        if (constInitValEle == null) {
            throw new IllegalArgumentException("ConstInitValEle cannot be null");
        }
        this.constInitValEle = constInitValEle;
        this.stringConst = null;  // 非字符串常量时为 null
    }

    public ConstInitVal(StringConst stringConst) {
        if (stringConst == null) {
            throw new IllegalArgumentException("StringConst cannot be null");
        }
        this.stringConst = stringConst;
        this.constInitValEle = null;  // 非 ConstInitValEle 时为 null
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (constInitValEle != null) {
            sb.append(constInitValEle.syntaxOutput());
        } else if (stringConst != null) {
            sb.append(stringConst.syntaxOutput());  // 输出字符串常量
        }
        sb.append(name).append("\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
