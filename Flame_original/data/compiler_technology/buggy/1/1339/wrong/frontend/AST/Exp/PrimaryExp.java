package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.TokenType;

//PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character// j
public class PrimaryExp implements SyntaxNode {
    private Exp exp;
    private LVal lval;
    private Number number;
    private Character character;

    public PrimaryExp(Exp exp) {
        this.exp = exp;
    }

    public PrimaryExp(LVal lval) {
        this.lval = lval;
    }

    public PrimaryExp(Number number) {
        this.number = number;
    }

    public PrimaryExp(Character character) {
        this.character = character;
    }

    @Override
    public void print() {
        if (exp != null) {
            AST.ast.addLine(TokenType.LPARENT + " (");
            exp.print();
            AST.ast.addLine(TokenType.RPARENT + " )");
        } else if (lval != null) {
            lval.print();
        } else if (number != null) {
            number.print();
        } else if (character != null) {
            character.print();
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<PrimaryExp>";
    }
}
