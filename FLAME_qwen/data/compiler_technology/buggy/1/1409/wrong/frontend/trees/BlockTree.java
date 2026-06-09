package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class BlockTree extends Tree {
    public List<BlockItemTree> blockItems = new ArrayList<>();
    public int blockRLineNum = -1;

    public boolean isWithoutReturn() {
        if (blockItems.isEmpty()) {
            return true;
        }
        var lastBlockItem = blockItems.get(blockItems.size() - 1);

        return !(lastBlockItem instanceof BlockItemTreeForStmt blockStmt)
                || !(blockStmt.stmt instanceof StmtTreeForReturn);
    }

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("LBRACE {");
        for (var blockItem : blockItems) {
            blockItem.walk(printStream);
        }

        printStream.println("RBRACE }");
        printStream.println("<Block>");
    }

    @Override
    public String getType() {
        return "Block";
    }
}
