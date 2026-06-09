package parse;

public class StmtExp implements StmtEle {
    private Exp exp;
    private Token end;

    public Exp getExp() {
        return exp;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public StmtExp(TokenList list,WrongList wrongs) {
        this.exp = new Exp(list,wrongs);
        this.end = HandleError.handleI(list.readNextToken(),list,wrongs);
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.exp.printout());
        sb.append(this.end.printout());
        return sb.toString();
    }
}
