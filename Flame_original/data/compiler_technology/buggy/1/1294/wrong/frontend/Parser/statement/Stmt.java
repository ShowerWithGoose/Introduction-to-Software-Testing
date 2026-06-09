package frontend.Parser.statement;

import frontend.Parser.GrammarNode;

public class Stmt implements GrammarNode {
    private final String grammarName = "<Stmt>";
    private StmtPort stmtElement;
    public Stmt(StmtPort stmtElement) {
        this.stmtElement = stmtElement;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.stmtElement.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }

}
