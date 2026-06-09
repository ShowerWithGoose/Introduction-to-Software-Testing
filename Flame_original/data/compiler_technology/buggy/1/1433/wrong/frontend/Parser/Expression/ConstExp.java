package frontend.Parser.Expression;

import frontend.Parser.ASTNode;
import frontend.Parser.Declaration.ConstInitValEle;

public class ConstExp implements ASTNode, ConstInitValEle {
    private AddExp addExp;  // 使用的 Ident 必须是常量

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.printString());
        sb.append("<" + "ConstExp" + ">\n");
        return sb.toString();
    }
}
