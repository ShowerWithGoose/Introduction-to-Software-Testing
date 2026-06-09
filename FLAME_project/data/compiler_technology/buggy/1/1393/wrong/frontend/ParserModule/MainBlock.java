package frontend.ParserModule;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.ParserModule.BlockItem.Block;
import frontend.ParserModule.BlockItem.BlockItem;

public class MainBlock {
    private final BlockItem mainBlock;
    private final int errorLocate;

    public MainBlock(BlockItem mainBlock, int errorLocate) {
        this.mainBlock = mainBlock;
        this.errorLocate = errorLocate;
    }

    public void printRes() {
        System.out.println("INTTK int");
        System.out.println("MAINTK main");
        System.out.println("LPARENT (");
        System.out.println("RPARENT )");
        ((Block) mainBlock).printBlockRes();
        System.out.println("<MainFuncDef>");
    }
    
    public void checkGrammarError() {
        if (errorLocate != -1) {
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'j'));
        }
        mainBlock.checkGrammarError();
    }
}
