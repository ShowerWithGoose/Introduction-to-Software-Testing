package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

import java.util.ArrayList;

//MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
//消除左递归
public class MulExp implements SyntaxNode {
    private ArrayList<UnaryExp> unaryExps;
    private ArrayList<Token> ops;

    public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<Token> ops) {
        this.unaryExps = unaryExps;
        this.ops = ops;
    }

    @Override
    public void print() {
        unaryExps.get(0).print();
        AST.ast.addLine(getName());
        for (int i = 1; i < unaryExps.size(); i++) {
            AST.ast.addLine(ops.get(i - 1).toString());
            unaryExps.get(i).print();
            AST.ast.addLine(getName());
        }
    }

    @Override
    public String getName() {
        return "<MulExp>";
    }
}
