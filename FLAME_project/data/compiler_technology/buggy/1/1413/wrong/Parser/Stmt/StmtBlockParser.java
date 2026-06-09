package Parser.Stmt;

import Lexer.TokenListIterator;
import Parser.Block;
import Parser.BlockParser;

/**
 * @Description:
 * @date 2024/10/13
 */
public class StmtBlockParser {
    private TokenListIterator iterator;
    private Block block;

    public StmtBlockParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public StmtBlock stmtBlockParse()
    {
        BlockParser blockParser=new BlockParser(iterator);
        this.block=blockParser.parseBlock();
        return new StmtBlock(block);
    }
}
