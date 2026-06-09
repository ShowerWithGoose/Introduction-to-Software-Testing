package AST;

public class UnaryExp {
    private PrimaryExp primaryExp;
    private Ident ident;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;
    private  FuncRParams funcRParams;
    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }
    public UnaryExp(Ident ident, FuncRParams funcRParams) {
        this.ident = ident;
        this.funcRParams = funcRParams;
    }
    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }
}
