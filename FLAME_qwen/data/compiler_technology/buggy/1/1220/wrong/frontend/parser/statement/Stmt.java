package frontend.parser.statement;

import frontend.parser.SyntaxUnit;
import frontend.parser.block.BlockItemUnit;

public class Stmt implements BlockItemUnit, SyntaxUnit {
    private String name = "<Stmt>";
    private StmtUnit stmtUnit;

    public Stmt(StmtUnit stmtUnit) {
        this.stmtUnit = stmtUnit;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(stmtUnit.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
