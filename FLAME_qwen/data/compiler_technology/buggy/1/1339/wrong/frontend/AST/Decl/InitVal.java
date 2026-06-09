package frontend.AST.Decl;

import frontend.AST.AST;
import frontend.AST.Exp.Exp;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

import java.util.ArrayList;

//InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitVal implements SyntaxNode {
    private Exp exp;
    private ArrayList<Exp> exps;
    private Token stringConst;

    public InitVal(Exp exp) {
        this.exp = exp;
    }

    public InitVal(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    public InitVal(Token stringConst) {
        assert stringConst.isOf(TokenType.STRCON);
        this.stringConst = stringConst;
    }

    @Override
    public void print() {
        if (exp != null) {
            exp.print();
        } else if (exps != null) {
            AST.ast.addLine(TokenType.LBRACE + " {");
            if(!exps.isEmpty()) {
                exps.get(0).print();
                for (int i = 1; i < exps.size(); i++) {
                    AST.ast.addLine(TokenType.COMMA + " ,");
                    exps.get(i).print();
                }
            }
            AST.ast.addLine(TokenType.RBRACE + " }");
        } else {
            AST.ast.addLine(stringConst.toString());
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<InitVal>";
    }
}
