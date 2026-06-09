package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

import java.util.ArrayList;

//LAndExp â†’ EqExp | LAndExp '&&' EqExp
public class LAndExp implements SyntaxNode {
    private ArrayList<EqExp> eqExps;
    private ArrayList<Token> ops;

    public LAndExp(ArrayList<EqExp> eqExps, ArrayList<Token> ops) {
        this.eqExps = eqExps;
        this.ops = ops;
    }

    @Override
    public void print() {
        eqExps.get(0).print();
        AST.ast.addLine(getName());
        for(int i = 1; i < eqExps.size(); i++) {
            AST.ast.addLine(ops.get(i - 1).toString());
            eqExps.get(i).print();
            AST.ast.addLine(getName());
        }
    }

    @Override
    public String getName() {
        return "<LAndExp>";
    }
}
