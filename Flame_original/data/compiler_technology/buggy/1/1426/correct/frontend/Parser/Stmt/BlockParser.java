package frontend.Parser.Stmt;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

public class BlockParser {
    private TokenListReader reader;
    private Token lbrace = null;
    private ArrayList<BlockItem> blockItems = new ArrayList<>();
    private Token rbrace = null;

    public BlockParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Block parseBlock() {
        this.lbrace = this.reader.getnextToken();
        BlockItemParser blockItemParser = new BlockItemParser(this.reader);
        Token token = this.reader.getnextToken();
        while (!token.getType().equals(TokenType.RBRACE)) {
            this.reader.backward(1);
            this.blockItems.add(blockItemParser.parseBlockItem());
            token = this.reader.getnextToken();
        }
        this.rbrace = token;
        Block block = new Block(this.lbrace, this.blockItems, this.rbrace);
        return block;
    }


}
