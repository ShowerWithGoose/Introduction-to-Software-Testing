package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.block.Block;

public class MainFuncDef extends FuncDef {
    public MainFuncDef(FuncType funcType, Token ident, Token lParent,
                       Token rParent, Block block) {
        super("<MainFuncDef>", funcType, ident, lParent, rParent, block);
    }

}
