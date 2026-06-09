package frontend.Parser.Stmt;

public class Stmt implements StmtInf,BlockItemInf{
    private final String name = "<Stmt>";
    private StmtInf stmtInf;

    public Stmt(StmtInf stmtInf){
        this.stmtInf = stmtInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.stmtInf.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
