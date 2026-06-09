package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.Func.FuncRParams;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

//UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
public class UnaryExp implements SyntaxNode {
    private PrimaryExp primaryExp;
    private Token ident;
    private FuncRParams funcRParams;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public UnaryExp(Token ident, FuncRParams funcRParams) {
        this.ident = ident;
        this.funcRParams = funcRParams;
    }

    public UnaryExp(Token ident) {
        this.ident = ident;
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public void print() {
        if (primaryExp != null) {
            primaryExp.print();
        } else if (ident != null) {
            AST.ast.addLine(ident.toString());
            AST.ast.addLine(TokenType.LPARENT + " (");
            if (funcRParams != null) {
                funcRParams.print();
            }
            AST.ast.addLine(TokenType.RPARENT + " )");
        } else if (unaryOp != null) {
            unaryOp.print();
            unaryExp.print();
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<UnaryExp>";
    }
}
