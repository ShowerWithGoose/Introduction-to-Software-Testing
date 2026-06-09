package parse;

public class ForStmt {
    private final String name = "<ForStmt>";
    private LVal lval;
    private Token eq;
    private Exp exp;

    public String getName() {
        return name;
    }

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

    public Exp getExp() {
        return exp;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public ForStmt(TokenList list,WrongList wrongs) {
        this.lval = new LVal(list,wrongs);
        this.eq = list.readNextToken();
        this.exp = new Exp(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.printout());
        sb.append(this.eq.printout());
        sb.append(this.exp.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
