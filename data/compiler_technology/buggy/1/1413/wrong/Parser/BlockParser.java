package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
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
        this.leftBrace = this.iterator.readNextToken();
        BlockItemParser blockItemParser = new BlockItemParser(this.iterator);
        Token token = this.iterator.readNextToken();
        while (!token.getType().equals("RBRACE")) {
            System.out.println(token.getValue());
            this.iterator.unReadToken(1);
            this.blockItems.add(blockItemParser.blockItemParse());
            if(this.iterator.hasNext())
            token = this.iterator.readNextToken();
            else {
                System.out.println("block 越界");
                break;
            }
        }
        this.rightBrace = token;
        return new Block(this.leftBrace, this.blockItems, this.rightBrace);
    }
}
