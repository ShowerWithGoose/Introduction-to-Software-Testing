package src.AST.BLOCK;

import src.AST.DECL.Decl;
import src.AST.STMT.Stmt;
import src.AST.Type.BlockItemType;
import src.fronted.LexicAnalysis.WordType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class BlockItem {
    private BlockItemType blockItemType;
    private Decl decl;
    private Stmt stmts;

    public BlockItem() {
    }

    public BlockItem analyse() {
        if (utils.preRead(1) == WordType.INTTK
                || utils.preRead(1) == WordType.CHARTK
                || utils.preRead(1) == WordType.CONSTTK) {
            this.blockItemType = BlockItemType.DECL;
            this.decl = new Decl().analyse();
        } else {
            this.blockItemType = BlockItemType.Stmt;
            this.stmts = new Stmt().analyse();
        }
        return this;
    }
}
