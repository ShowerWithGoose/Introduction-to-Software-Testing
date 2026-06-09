package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.statement.blockitem.BlockItem;
import frontend.parser.statement.blockitem.BlockItemParser;

import java.util.ArrayList;

public class BlockParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* Block Attributes */
    public Token leftBrace = null;// '{'
    public ArrayList<BlockItem> blockItems = new ArrayList<>();
    public Token rightBrace = null; // '}'

    public BlockParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public Block parseBlock() {
        this.leftBrace = this.iterator.readNextToken();
        BlockItemParser blockItemParser = new BlockItemParser(this.iterator,this.error_tokens);
        Token token = this.iterator.readNextToken();
        while (!token.type.equals(TokenType.RBRACE)) {
            this.iterator.unReadToken(1);
            BlockItemParser blockItemParser1 = new BlockItemParser(this.iterator,this.error_tokens);
            this.blockItems.add(blockItemParser1.parseBlockItem());
            token = this.iterator.readNextToken();
        }
        this.rightBrace = token;
        Block block = new Block(this.leftBrace, this.blockItems, this.rightBrace);
        return block;
    }
}
