package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class BlockParser {
    private TokenIterator iterator;
    private Token leftBrace;
    private Token rightBrace;
    private ArrayList<BlockItem> blockItems = new ArrayList<>();

    public BlockParser(TokenIterator iterator) {
        this.iterator = iterator;
    }
    public Block parseBlock() {
        // Block → '{' { BlockItem } '}'
        //BlockItem → Decl | Stmt
        leftBrace = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        while (t1.getType() != TokenType.RBRACE) {
            iterator.ungetToken(1);
            BlockItemParser blockItemParser = new BlockItemParser(iterator);
            blockItems.add(blockItemParser.parseBlockItem());
            t1 = iterator.getNextToken();
        }
        rightBrace = t1;
        return new Block(leftBrace, blockItems, rightBrace);
    }
}
