package frontend.parser.block;

import frontend.parser.block.statement.Statement;

public class Stmt implements BItem {
    private final String name = "<Stmt>";
    private Statement statement;

    public Stmt(Statement statement) {
        this.statement = statement;
    }

    @Override
    public String getOutPut() {
        return statement.getOutPut() + name + "\n";
    }

    @Override
    public String getError() {
        return statement.getError();
    }
}
