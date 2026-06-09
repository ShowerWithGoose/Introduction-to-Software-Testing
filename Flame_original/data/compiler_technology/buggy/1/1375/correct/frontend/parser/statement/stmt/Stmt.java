package frontend.parser.statement.stmt;

import frontend.parser.statement.blockitem.BlockItemEle;

public class Stmt implements BlockItemEle {
    public final String name = "<Stmt>";
    public StmtEle stmtEle;

    public Stmt(StmtEle stmtEle) {
        this.stmtEle = stmtEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.stmtEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num(){
        return this.stmtEle.my_line_num();
    }
}
