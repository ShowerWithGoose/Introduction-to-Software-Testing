package frontend.ParserModule.BlockItem;

import java.util.ArrayList;

public class Block implements BlockItem{
    private ArrayList<BlockItem> blockItems = new ArrayList<>();
    public void addBlockItem(BlockItem item){
        blockItems.add(item);
    }

    @Override
    public void printRes() {
        printBlockRes();
        System.out.println("<Stmt>");
    }

    @Override
    public void checkGrammarError() {
        for (BlockItem blockItem:blockItems){
            blockItem.checkGrammarError();
        }
    }

    public void printBlockRes() {
        System.out.println("LBRACE {");
        for(BlockItem blockItem:blockItems){
            blockItem.printRes();
        }
        System.out.println("RBRACE }");
        System.out.println("<Block>");
    }
}
