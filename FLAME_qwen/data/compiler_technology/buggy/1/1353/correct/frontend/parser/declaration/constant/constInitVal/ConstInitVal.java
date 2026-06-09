package frontend.parser.declaration.constant.constInitVal;

import frontend.parser.SyntaxNode;

/**
 * ConstInitVal 常量初值类
 * <ConstInitVal> -> <ConstExp> | '{' [ <ConstExp> { ',' <ConstExp> } '}' | <StringConst>
 */
public class ConstInitVal implements SyntaxNode {
    private final String name = "<ConstInitVal>";
    private ConstInitValEle constInitValEle;

    public ConstInitVal(ConstInitValEle constInitValEle) {
        this.constInitValEle = constInitValEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
