package frontend.parser.declaration.variable.initval;

import frontend.parser.SyntaxNode;

/**
 * InitVal 变量初值类
 * <InitVal> -> <Exp> | '{' [ <Exp> { ',' <Exp> } ] '}' | StringConst
 */
public class InitVal implements SyntaxNode {
    private final String name = "<InitVal>";
    private InitValEle initValEle;

    public InitVal(InitValEle initValEle) {
        this.initValEle = initValEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.initValEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
