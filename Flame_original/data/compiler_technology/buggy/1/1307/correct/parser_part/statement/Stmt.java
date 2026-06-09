package parser_part.statement;

import parser_part.block.Block;
import parser_part.block.BlockItem;
import parser_part.block.BlockItemComponent;
import parser_part.statement.StmtComponent.StmtComponent;
import parser_part.statement.StmtComponent.StmtIf;
import parser_part.statement.StmtComponent.StmtReturn;
import parser_part.statement.StmtComponent.StmtWhile;

public class Stmt implements BlockItemComponent {
    private StmtComponent stmtComponent;

    public Stmt(StmtComponent stmtComponent) {
        this.stmtComponent = stmtComponent;
    }

    public String toString() {
        return stmtComponent.toString() + "<Stmt>\n";
    }

    public int checkReturn() {
        if (stmtComponent instanceof StmtReturn) {
            return ((StmtReturn) stmtComponent).checkReturn();
        } else {
            return -1;
        }
    }

    public StmtComponent getStmtComponent() {
        return stmtComponent;
    }

    public int getLineIndex() {
        return ((StmtReturn) stmtComponent).getLineIndex();
    }
}
