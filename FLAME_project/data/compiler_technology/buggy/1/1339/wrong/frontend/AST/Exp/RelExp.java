package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

import java.util.ArrayList;

//RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
public class RelExp implements SyntaxNode {
    private ArrayList<AddExp> addExps;
    private ArrayList<Token> ops;

    public RelExp(ArrayList<AddExp> addExps, ArrayList<Token> ops) {
        this.addExps = addExps;
        this.ops = ops;
    }

    @Override
    public void print() {
        addExps.get(0).print();
        AST.ast.addLine(getName());
        for(int i = 1; i < addExps.size(); i++) {
            AST.ast.addLine(ops.get(i - 1).toString());
            addExps.get(i).print();
            AST.ast.addLine(getName());
        }
    }

    @Override
    public String getName() {
        return "<RelExp>";
    }
}
