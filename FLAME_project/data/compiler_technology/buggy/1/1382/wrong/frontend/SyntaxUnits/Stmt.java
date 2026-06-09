package frontend.SyntaxUnits;

import frontend.SyntaxUnits.StmtUnits.StmtUnit;

public class Stmt implements BlockItemUnit{
    private final StmtUnit stmtUnit;

    public Stmt(StmtUnit stmtUnit) {
        this.stmtUnit = stmtUnit;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(stmtUnit.toPrint());
        stringBuilder.append("<Stmt>\n");
        return stringBuilder.toString();
    }
}
