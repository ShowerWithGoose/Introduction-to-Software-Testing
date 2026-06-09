package frontend.parser.ast.decl;

import frontend.lexer.Token;
import frontend.parser.ast.block.Block;

public class MainFuncDef extends FuncDef {
    public MainFuncDef(FuncType funcType, Token ident, Token lParent, Token rParent, Block block) {
        super("<MainFuncDef>", funcType, ident, lParent, rParent, block);
    }
}
