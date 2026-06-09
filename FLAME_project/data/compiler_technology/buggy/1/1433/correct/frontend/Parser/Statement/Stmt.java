package frontend.Parser.Statement;

import frontend.Parser.ASTNode;

public class Stmt implements ASTNode, BlockItemEle {
    private StmtEle stmtEle;

    public Stmt(StmtEle stmtEle) {
        this.stmtEle = stmtEle;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(stmtEle.printString());
        sb.append("<" + "Stmt" + ">\n");
        return sb.toString();
    }
}
