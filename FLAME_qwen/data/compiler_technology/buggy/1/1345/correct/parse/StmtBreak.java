package parse;

public class StmtBreak implements StmtEle {
    private Token bre;
    private Token end;

    public Token getBre() {
        return bre;
    }

    public void setBre(Token bre) {
        this.bre = bre;
    }

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public StmtBreak(TokenList list,WrongList wrongs) {
        this.bre = list.readNextToken();
        this.end = HandleError.handleI(list.readNextToken(),list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.bre.printout());
        sb.append(this.end.printout());
        return sb.toString();
    }
}
