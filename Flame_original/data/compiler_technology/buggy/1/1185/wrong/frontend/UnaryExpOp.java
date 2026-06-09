package frontend;

public class UnaryExpOp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token OP;
    private UnaryExp unaryExp;

    public UnaryExpOp(TokenItaretor itaretor, ParserFile file) {
        this.itaretor = itaretor;
        this.file = file;
        this.OP = null;
        this.unaryExp = null;
    }

    public void getUnaryExpOP(Token next) {
        file.addToken(next);
        file.addToken(new Token("<UnaryOp>"));
        unaryExp = new UnaryExp(itaretor,file);
        unaryExp.getUnaryExp();
    }
}
