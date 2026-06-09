package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;

//ConstExp → AddExp
// 注：使用的 Ident 必须是常量
public class ConstExp implements SyntaxNode {
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public void print() {
        addExp.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<ConstExp>";
    }
}
