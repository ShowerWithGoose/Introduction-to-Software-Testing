package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

import java.util.ArrayList;

//LOrExp â†’ LAndExp | LOrExp '||' LAndExp
public class LOrExp implements SyntaxNode {
    private ArrayList<LAndExp> lAndExps;
    private ArrayList<Token> ops;

    public LOrExp(ArrayList<LAndExp> lAndExps, ArrayList<Token> ops) {
        this.lAndExps = lAndExps;
        this.ops = ops;
    }

    @Override
    public void print() {
        lAndExps.get(0).print();
        AST.ast.addLine(getName());
        for(int i = 1;i < lAndExps.size(); i++) {
            AST.ast.addLine(ops.get(i - 1).toString());
            lAndExps.get(i).print();
            AST.ast.addLine(getName());
        }
    }

    @Override
    public String getName() {
        return "<LOrExp>";
    }
}
