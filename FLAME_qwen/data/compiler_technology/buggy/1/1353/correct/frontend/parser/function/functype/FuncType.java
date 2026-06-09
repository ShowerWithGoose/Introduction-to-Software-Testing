package frontend.parser.function.functype;

import frontend.parser.SyntaxNode;

/**
 * FuncType 函数类型类
 * <FuncType> -> 'int' | 'void' | 'char'
 */
public class FuncType implements SyntaxNode {
    private final String name = "<FuncType>";
    private FuncTypeEle funcTypeEle;

    public FuncType(FuncTypeEle funcTypeEle) {
        this.funcTypeEle = funcTypeEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcTypeEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
