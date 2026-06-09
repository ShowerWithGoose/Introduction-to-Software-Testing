package frontend.AST.Decl;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.TokenType;

import java.util.ArrayList;

//VarDecl â†’ BType VarDef { ',' VarDef } ';' // i
public class VarDecl implements SyntaxNode {
    private BType btype;
    private ArrayList<VarDef> varDefs;

    public VarDecl(BType btype, ArrayList<VarDef> varDefs) {
        this.btype = btype;
        this.varDefs = varDefs;
    }

    @Override
    public void print() {
        btype.print();
        varDefs.get(0).print();
        for (int i = 1; i < varDefs.size(); i++) {
            AST.ast.addLine(TokenType.COMMA + " ,");
            varDefs.get(i).print();
        }
        AST.ast.addLine(TokenType.SEMICN + " ;");
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<VarDecl>";
    }
}
