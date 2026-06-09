package parse;

public class StmtNull implements StmtEle {
    private Token end;

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public StmtNull(TokenList list,WrongList wrongs) {
        this.end = HandleError.handleI(list.readNextToken(),list,wrongs);
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.end.printout());
        return sb.toString();
    }
}
