package parse;

public class UnaryExpOp implements UnaryExpEle {
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryOp getUnaryOp() {
        return unaryOp;
    }

    public void setUnaryOp(UnaryOp unaryOp) {
        this.unaryOp = unaryOp;
    }

    public UnaryExp getUnaryExp() {
        return unaryExp;
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public UnaryExpOp(TokenList list,WrongList wrongs) {
        this.unaryOp = new UnaryOp(list,wrongs);
        this.unaryExp = new UnaryExp(list,wrongs);
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryOp.printout());
        sb.append(this.unaryExp.printout());
        return sb.toString();
    }
}
