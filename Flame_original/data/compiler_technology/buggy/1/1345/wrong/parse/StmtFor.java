package parse;

public class StmtFor implements StmtEle {
    private Token forTk; 
    private Token leftParent; 
    private ForStmt cond1;
    private Cond cond2;
    private ForStmt cond3;
    private Token depart;
    private Token rightParent; 
    private Stmt stmt;

    public Token getForTk() {
        return forTk;
    }

    public void setForTk(Token forTk) {
        this.forTk = forTk;
    }

    public Token getLeftParent() {
        return leftParent;
    }

    public void setLeftParent(Token leftParent) {
        this.leftParent = leftParent;
    }

    public ForStmt getCond1() {
        return cond1;
    }

    public void setCond1(ForStmt cond1) {
        this.cond1 = cond1;
    }

    public Cond getCond2() {
        return cond2;
    }

    public void setCond2(Cond cond2) {
        this.cond2 = cond2;
    }

    public ForStmt getCond3() {
        return cond3;
    }

    public void setCond3(ForStmt cond3) {
        this.cond3 = cond3;
    }

    public Token getDepart() {
        return depart;
    }

    public void setDepart(Token depart) {
        this.depart = depart;
    }

    public Token getRightParent() {
        return rightParent;
    }

    public void setRightParent(Token rightParent) {
        this.rightParent = rightParent;
    }

    public Stmt getStmt() {
        return stmt;
    }

    public void setStmt(Stmt stmt) {
        this.stmt = stmt;
    }

    public StmtFor(TokenList list,WrongList wrongs) {
        this.forTk = list.readNextToken();
        this.leftParent = list.readNextToken();
        Token x = list.readNextToken();
        if (!x.getType().equals("SEMICN")) {
            list.unReadToken(1);
            this.cond1 = new ForStmt(list,wrongs);
            this.depart = HandleError.handleI(list.readNextToken(),list,wrongs);
        } else {
            this.depart = x;
            this.cond1 = null;
        }
        x = list.readNextToken();
        if (!x.getType().equals("SEMICN")) {
            list.unReadToken(1);
            this.cond2 = new Cond(list,wrongs);
            x = HandleError.handleI(list.readNextToken(),list,wrongs);
        } else {
            this.cond2 = null;
        }
        x = list.readNextToken();
        if (!x.getType().equals("RPARENT")) {
            list.unReadToken(1);
            this.cond3 = new ForStmt(list,wrongs);
            this.rightParent = list.readNextToken();
        } else {
            this.rightParent = x;
            this.cond3 = null;
        }
        this.stmt = new Stmt(list,wrongs);
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.forTk.printout());
        sb.append(this.leftParent.printout());
        if(this.cond1 != null){
            sb.append(this.cond1.printout());
        }
        sb.append(this.depart.printout());
        if(this.cond2 != null){
            sb.append(this.cond2.printout());
        }
        sb.append(this.depart.printout());
        if(this.cond3 != null){
            sb.append(this.cond3.printout());
        }
        sb.append(this.rightParent.printout());
        sb.append(this.stmt.printout());
        return sb.toString();
    }
}
