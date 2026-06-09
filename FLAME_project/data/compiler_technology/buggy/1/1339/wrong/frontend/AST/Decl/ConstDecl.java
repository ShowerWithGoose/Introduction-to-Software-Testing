package frontend.AST.Decl;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.TokenType;

import java.util.ArrayList;

// ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';' // i
public class ConstDecl implements SyntaxNode {
    private BType btype;
    private ArrayList<ConstDef> constDefs;

    public ConstDecl(BType btype, ArrayList<ConstDef> constDefs) {
        this.btype = btype;
        this.constDefs = constDefs;
    }

    @Override
    public void print() {
        AST.ast.addLine(TokenType.CONSTTK + " const");
        btype.print();
        constDefs.get(0).print();
        for(int i= 1; i < constDefs.size(); i++){
            AST.ast.addLine(TokenType.COMMA + " ,");
            constDefs.get(i).print();
        }
        AST.ast.addLine(TokenType.SEMICN + " ;");
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<ConstDecl>";
    }
}
