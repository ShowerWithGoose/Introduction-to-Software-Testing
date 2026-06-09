package parser_part.block;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.statement.Stmt;
import parser_part.statement.StmtComponent.StmtReturn;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class BlockParser {
    private TokenList tokenList;
    private SymbolList symbolList;
    private ArrayList<BlockItem> blockItems;
    private boolean isFuncBlock;

    public BlockParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
        blockItems = new ArrayList<>();
        isFuncBlock = false;
    }

    public void setFuncBlock(boolean funcBlock) {
        isFuncBlock = funcBlock;
    }

    public Block parseBlock() {
        Token leftBrace = tokenList.getNextToken();
        if (!isFuncBlock) {
            symbolList = new SymbolList(symbolList);
        }
        Token token = tokenList.getNextToken();
        while (token != null && token.getType() != Token.TokenType.RBRACE) {
            BlockItemParser blockItemParser = new BlockItemParser(tokenList, symbolList);
            tokenList.moveBack(1);
            BlockItem blockItem = blockItemParser.parseBlockItem();
            blockItems.add(blockItem);
            token = tokenList.getNextToken();
        }
        Token rightBrace = token;
        return new Block(leftBrace, blockItems, rightBrace);
    }

    public int checkReturn() {
        if (blockItems.isEmpty()) {
            return 0;
        }
        return blockItems.get(blockItems.size() - 1).checkReturn();
    }

}
