package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

import java.util.ArrayList;

//EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
public class EqExp implements SyntaxNode {
    private ArrayList<RelExp> relExps;
    private ArrayList<Token> ops;

    public EqExp(ArrayList<RelExp> relExps, ArrayList<Token> ops) {
        this.relExps = relExps;
        this.ops = ops;
    }

    @Override
    public void print() {
        relExps.get(0).print();
        AST.ast.addLine(getName());
        for(int i = 1;i < relExps.size(); i++) {
            AST.ast.addLine(ops.get(i - 1).toString());
            relExps.get(i).print();
            AST.ast.addLine(getName());
        }
    }

    @Override
    public String getName() {
        return "<EqExp>";
    }
}
