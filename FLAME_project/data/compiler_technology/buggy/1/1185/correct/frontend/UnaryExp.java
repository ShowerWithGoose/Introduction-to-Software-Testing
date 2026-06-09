package frontend;

public class UnaryExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private int type;
    private UnaryExpOp unaryExpOp = null;
    private UnraryFuncExp funcExp = null;
    private PrimaryExp primaryExp = null;

    public UnaryExp(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
        this.type = 0; // 1:Primary 2:函数调用 3:Op+Exp
    }


    public void getUnaryExp() {

        Token next = itaretor.getNext();
        if (next.getString().equals("+") || next.getString().equals("-") || next.getString().equals("!")) {
            type = 3;
            this.unaryExpOp = new UnaryExpOp(itaretor, file);
            unaryExpOp.getUnaryExpOP(next);
        } else if (next.getType().equals("IDENFR")) {
            Token second = itaretor.getNext();
            if (second.getString().equals("(")) {
                type = 2;
                this.funcExp = new UnraryFuncExp(itaretor, file);
                funcExp.getFuncExp(next, second);
            } else {
                type = 1;
                itaretor.getPrevious(2);
                this.primaryExp = new PrimaryExp(file, itaretor);
                primaryExp.getPrimaryExp();
            }
        } else {
            type = 1;
            itaretor.getPrevious(1);
            this.primaryExp = new PrimaryExp(file, itaretor);
            primaryExp.getPrimaryExp();
        }
        file.addToken(new Token("<UnaryExp>"));
    }
}
