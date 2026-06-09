package frontend.Tree;

public class UnaryExp {
    private PrimaryExp primaryExp;
    private Ident ident;
    private FuncRParams funcRParams;
    private UnaryOp op;
    private UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public UnaryExp(Ident ident, FuncRParams funcRParams) {
        this.ident = ident;
        this.funcRParams = funcRParams;
    }

    public UnaryExp(UnaryOp op, UnaryExp unaryExp) {
        this.op = op;
        this.unaryExp = unaryExp;
    }
}
