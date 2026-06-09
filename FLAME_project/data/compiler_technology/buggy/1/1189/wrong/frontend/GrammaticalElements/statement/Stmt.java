package frontend.GrammaticalElements.statement;

public class Stmt {
    private final String name = "<Stmt>";
    private StmtEle stmtEle;

    public Stmt(StmtEle stmtEle) {
        this.stmtEle = stmtEle;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(stmtEle.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
