package frontend.parser.ast.block;

public class Stmt implements BItem {
    private String type = "<Stmt>";
    private Statement statement;

    public Stmt(Statement statement) {
        this.statement = statement;
    }

    public String getOutput() {
        return statement.getOutput() + type + "\n";
    }

    public String getError() {
        return statement.getError();
    }
}
