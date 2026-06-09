package frontend.AST.Decl;

import frontend.AST.AST;
import frontend.AST.Exp.ConstExp;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

import java.util.ArrayList;

//ConstInitVal â†’ ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
public class ConstInitVal implements SyntaxNode {
    private ConstExp constExp;
    private ArrayList<ConstExp> constExps;
    private Token stringConst;

    public ConstInitVal(ConstExp constExp) {
        this.constExp = constExp;
    }

    public ConstInitVal(ArrayList<ConstExp> constExps) {
        this.constExps = constExps;
    }

    public ConstInitVal(Token stringConst) {
        assert stringConst.isOf(TokenType.STRCON);
        this.stringConst = stringConst;
    }

    @Override
    public void print() {
        if (constExp != null) {
            constExp.print();
        } else if (constExps != null) {
            AST.ast.addLine(TokenType.LBRACE + " {");
            if(!constExps.isEmpty()) {
                constExps.get(0).print();
                for (int i = 1; i < constExps.size(); i++) {
                    AST.ast.addLine(TokenType.COMMA + " ,");
                    constExps.get(i).print();
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
        return "<ConstInitVal>";
    }
}
