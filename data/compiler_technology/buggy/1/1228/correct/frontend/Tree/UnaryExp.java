package frontend.Tree;

import frontend.Symbol.Symbol;
import frontend.Symbol.SymbolTree;

public class UnaryExp {
    private PrimaryExp primaryExp;
    private Ident ident;
    private FuncRParams funcRParams;
    private UnaryOp op;
    private UnaryExp unaryExp;
    int type;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
        type = 0;
    }

    public UnaryExp(Ident ident, FuncRParams funcRParams) {
        this.ident = ident;
        this.funcRParams = funcRParams;
        type = 1;
    }

    public UnaryExp(UnaryOp op, UnaryExp unaryExp) {
        this.op = op;
        this.unaryExp = unaryExp;
        type = 2;
    }
}
