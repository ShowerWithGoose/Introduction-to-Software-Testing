package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.statement.blockitem.BlockItem;
import frontend.parser.statement.blockitem.BlockItemEle;
import frontend.parser.statement.blockitem.BlockItemParser;

import java.util.ArrayList;

/**
 * BlockParser 语句块解析器类
 * <Block> -> '{' { <BlockItem> } '}'
 */
public class BlockParser {
    private TokenListIterator iterator;
    /* Block Attributes */
    private Token leftBrace = null;// '{'
    private ArrayList<BlockItem> blockItems = new ArrayList<>();
    private Token rightBrace = null; // '}'

    public BlockParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Block parseBlock() {
        this.leftBrace = this.iterator.next();
        BlockItemParser blockItemParser = new BlockItemParser(this.iterator);
        Token token = this.iterator.next();
        while (!token.getTokenType().equals(TokenType.RBRACE)) {
            this.iterator.unRead(1);
            BlockItem blockItem = blockItemParser.parseBlockItem();
            this.blockItems.add(blockItem);
            token = this.iterator.next();
        }
        this.rightBrace = token;
        Block block = new Block(this.leftBrace, this.blockItems, this.rightBrace);
        return block;
    }
}
