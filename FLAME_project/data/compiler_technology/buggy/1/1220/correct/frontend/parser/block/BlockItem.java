package frontend.parser.block;

import frontend.parser.SyntaxUnit;

public class BlockItem implements SyntaxUnit {
    //BlockItem → Decl | Stmt
    private String name = "<BlockItem>";
    private BlockItemUnit blockItemUnit;

    public BlockItem(BlockItemUnit blockItemUnit) {
        this.blockItemUnit = blockItemUnit;
    }

    @Override
    public String syntaxPrint() {
        //不输出名字
        StringBuilder sb = new StringBuilder();
        sb.append(blockItemUnit.syntaxPrint());
        //sb.append(name + "\n");
        return sb.toString();
    }
    //BlockItem → Decl | Stmt
}
