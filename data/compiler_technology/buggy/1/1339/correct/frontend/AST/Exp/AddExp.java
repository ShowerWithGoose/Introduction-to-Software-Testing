package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

import java.util.ArrayList;

//AddExp → MulExp | AddExp ('+' | '−') MulExp
public class AddExp implements SyntaxNode {
    private ArrayList<MulExp> mulExps;
    private ArrayList<Token> ops;

    public AddExp(ArrayList<MulExp> mulExps, ArrayList<Token> ops) {
        this.mulExps = mulExps;
        this.ops = ops;
    }

    @Override
    public void print() {
        mulExps.get(0).print();
        AST.ast.addLine(getName());
        for (int i = 1; i < mulExps.size(); i++) {
            AST.ast.addLine(ops.get(i - 1).toString());
            mulExps.get(i).print();
            AST.ast.addLine(getName());
        }
    }

    @Override
    public String getName() {
        return "<AddExp>";
    }
}
