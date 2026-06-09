package parse;

public class StmtCond implements StmtEle {
    private Token ifTk;
    private Token leftParent;
    private Cond cond;
    private Token rightParent;
    private Stmt ifStmt;
    private Token elseTk;
    private Stmt elseStmt;

    public Token getIfTk() {
        return ifTk;
    }

    public void setIfTk(Token ifTk) {
        this.ifTk = ifTk;
    }

    public Token getLeftParent() {
        return leftParent;
    }

    public void setLeftParent(Token leftParent) {
        this.leftParent = leftParent;
    }

    public Cond getCond() {
        return cond;
    }

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public Token getRightParent() {
        return rightParent;
    }

    public void setRightParent(Token rightParent) {
        this.rightParent = rightParent;
    }

    public Stmt getIfStmt() {
        return ifStmt;
    }

    public void setIfStmt(Stmt ifStmt) {
        this.ifStmt = ifStmt;
    }

    public Token getElseTk() {
        return elseTk;
    }

    public void setElseTk(Token elseTk) {
        this.elseTk = elseTk;
    }

    public Stmt getElseStmt() {
        return elseStmt;
    }

    public void setElseStmt(Stmt elseStmt) {
        this.elseStmt = elseStmt;
    }

    public StmtCond (TokenList list,WrongList wrongs) {
        this.ifTk = list.readNextToken();
        this.leftParent = list.readNextToken();
        this.cond = new Cond(list,wrongs);
        this.rightParent = HandleError.handleJ(list.readNextToken(),list,wrongs);
        this.ifStmt = new Stmt(list,wrongs);
        this.elseTk = list.readNextToken();
        if (this.elseTk.getType().equals("ELSETK")) {
            this.elseStmt = new Stmt(list,wrongs);
        } else {
            list.unReadToken(1);
            this.elseTk = null;
            this.elseStmt = null;
        }
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ifTk.printout());
        sb.append(this.leftParent.printout());
        sb.append(this.cond.printout());
        sb.append(this.rightParent.printout());
        sb.append(this.ifStmt.printout());
        if (elseTk != null) {
            sb.append(this.elseTk.printout());
            sb.append(this.elseStmt.printout());
        }
        return sb.toString();
    }
}
