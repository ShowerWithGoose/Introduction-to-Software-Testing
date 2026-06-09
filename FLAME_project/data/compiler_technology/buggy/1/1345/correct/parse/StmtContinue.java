package parse;

public class StmtContinue implements StmtEle {
    private Token continueTk; 
    private Token end;

    public Token getContinueTk() {
        return continueTk;
    }

    public void setContinueTk(Token continueTk) {
        this.continueTk = continueTk;
    }

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public StmtContinue(TokenList list,WrongList wrongs) {
        this.continueTk = list.readNextToken();
        this.end = HandleError.handleI(list.readNextToken(),list,wrongs);
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.continueTk.printout());
        sb.append(this.end.printout());
        return sb.toString();
    }
}
