package parse;

public class StmtReturn implements StmtEle {
    private Token returnTk;
    private Exp exp; 
    private Token end;

    public Token getReturnTk() {
        return returnTk;
    }

    public void setReturnTk(Token returnTk) {
        this.returnTk = returnTk;
    }

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

    public StmtReturn(TokenList list,WrongList wrongs) {
        this.returnTk = list.readNextToken();
        this.end = list.readNextToken();
        if (!this.end.getType().equals("SEMICN")) {
            list.unReadToken(1);
            this.exp = new Exp(list,wrongs);
            this.end = list.readNextToken();
        } else {
            this.exp = null;
        }
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.returnTk.printout());
        if (exp != null) {
            sb.append(this.exp.printout());
        }
        sb.append(this.end.printout());
        return sb.toString();
    }
}
