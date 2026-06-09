package parser_part.block;

import lexer_part.Token;
import parser_part.declaration.Decl;
import parser_part.statement.Stmt;
import parser_part.statement.StmtComponent.StmtComponent;
import parser_part.statement.StmtComponent.StmtFor;
import parser_part.statement.StmtComponent.StmtIf;
import parser_part.statement.StmtComponent.StmtReturn;

import javax.swing.text.html.BlockView;
import java.util.ArrayList;

public class Block implements StmtComponent {
    private Token leftBrace;
    private ArrayList<BlockItem> blockItems;
    private Token rightBrace;

    public Block(Token leftBrace, ArrayList<BlockItem> blockItems, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.blockItems = blockItems;
        this.rightBrace = rightBrace;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(leftBrace.toString());
        int len = blockItems.size();
        for (int i = 0; i < len; i++) {
            sb.append(blockItems.get(i));
        }
        sb.append(rightBrace.toString()).append("<Block>\n");
        return sb.toString();
    }

    public BlockItem getLastBlockItem() {
        if (blockItems.isEmpty()){
            return null;
        }
        return blockItems.get(blockItems.size() - 1);
    }

    public int getRightBraceLineIndex() {
        return rightBrace.getLineIndex();
    }

    public boolean haveReturn() {
        boolean haveReturn = false;
        for (BlockItem blockItem : blockItems) {
            BlockItemComponent blockItemComponent = blockItem.getBlockItemComponent();
            if (blockItemComponent instanceof Stmt stmt && stmt.getStmtComponent() instanceof StmtReturn stmtReturn && stmtReturn.checkReturn() == 1) {
                haveReturn = true;
                break;
            } else if (blockItemComponent instanceof Stmt stmt && stmt.getStmtComponent() instanceof StmtIf stmtIf) {
                Stmt stmtInIf = stmtIf.getStmt();
                Stmt stmtInElse = stmtIf.getElseStmt();
                if (stmtInIf.getStmtComponent() instanceof Block block) {
                    haveReturn = block.haveReturn();
                }
                if (stmtInElse != null && stmtInElse.getStmtComponent() instanceof Block block) {
                    haveReturn = block.haveReturn();
                }
            } else if (blockItemComponent instanceof Stmt stmt && stmt.getStmtComponent() instanceof StmtFor stmtFor){
                Stmt stmtInFor = stmtFor.getStmt();
                if (stmtInFor.getStmtComponent() instanceof Block block){
                    haveReturn = block.haveReturn();
                }
            }
            if (haveReturn){
                break;
            }
        }
        return haveReturn;
    }

    public ArrayList<BlockItem> getBlockItems() {
        return blockItems;
    }
}


