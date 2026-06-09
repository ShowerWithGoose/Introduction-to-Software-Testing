package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.TokenType;

import java.util.ArrayList;

//Block â†’ '{' { BlockItem } '}'
public class Block extends Stmt {

    private ArrayList<BlockItem> blockItems;

    public Block(ArrayList<BlockItem> blockItems) {
        this.blockItems = blockItems;
    }

    @Override
    public void print() {
        AST.ast.addLine(TokenType.LBRACE + " {");
        for (BlockItem blockItem : blockItems) {
            blockItem.print();
        }
        AST.ast.addLine(TokenType.RBRACE + " }");
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<Block>";
    }
}
