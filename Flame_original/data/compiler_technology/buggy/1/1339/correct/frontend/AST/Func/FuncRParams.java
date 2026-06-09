package frontend.AST.Func;

import frontend.AST.AST;
import frontend.AST.Exp.Exp;
import frontend.AST.SyntaxNode;
import frontend.TokenType;

import java.util.ArrayList;

//FuncRParams â†’ Exp { ',' Exp }
public class FuncRParams implements SyntaxNode {
    private ArrayList<Exp> exps;

    public FuncRParams(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    @Override
    public void print() {
        exps.get(0).print();
        for (int i = 1; i < exps.size(); i++) {
            AST.ast.addLine(TokenType.COMMA + " ,");
            exps.get(i).print();
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<FuncRParams>";
    }
}
