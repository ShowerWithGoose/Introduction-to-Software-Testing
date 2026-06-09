package parse;

public class StmtGet implements StmtEle {
    private LVal lval;
    private Token eq; 
    private Token getfunc; 
    private Token leftParent;
    private Token rightParent; 
    private Token end;

    public LVal getLval() {
        return lval;
    }

    public void setLval(LVal lval) {
        this.lval = lval;
    }

    public Token getEq() {
        return eq;
    }

    public void setEq(Token eq) {
        this.eq = eq;
    }

    public Token getGetfunc() {
        return getfunc;
    }

    public void setGetfunc(Token getfunc) {
        this.getfunc = getfunc;
    }

    public Token getLeftParent() {
        return leftParent;
    }

    public void setLeftParent(Token leftParent) {
        this.leftParent = leftParent;
    }

    public Token getRightParent() {
        return rightParent;
    }

    public void setRightParent(Token rightParent) {
        this.rightParent = rightParent;
    }

    public Token getEnd() {
        return end;
    }

    public void setEnd(Token end) {
        this.end = end;
    }

    public StmtGet (TokenList list,WrongList wrongs) {
        this.lval = new LVal(list,wrongs);
        this.eq = list.readNextToken();
        this.getfunc = list.readNextToken();
        this.leftParent = list.readNextToken();
        this.rightParent = HandleError.handleJ(list.readNextToken(),list,wrongs);
        this.end = HandleError.handleI(list.readNextToken(),list,wrongs);
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.printout());
        sb.append(this.eq.printout());
        sb.append(this.getfunc.printout());
        sb.append(this.leftParent.printout());
        sb.append(this.rightParent.printout());
        sb.append(this.end.printout());
        return sb.toString();
    }
}
