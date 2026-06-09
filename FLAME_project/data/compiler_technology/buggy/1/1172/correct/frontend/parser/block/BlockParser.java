package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.LinkedList;

/**
 * 解析代码块的解析器类。
 */
public class BlockParser {
    // Token 列表迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public BlockParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析代码块。
     *
     * @return 解析得到的 Block 对象
     */
    public Block parseBlock() {
        Token leftBraceToken = tokenStream.readNextToken();
        if (leftBraceToken.getType() != TokenType.LBRACE) {
            throw new Error("Expected '{' at the beginning of a block.");
        }

        BlockItemParser blockItemParser = new BlockItemParser(tokenStream);
        LinkedList<BlockItem> blockItemList = new LinkedList<>();

        while (true) {
            Token currentToken = tokenStream.readNextToken();
            if (currentToken.getType() == TokenType.RBRACE) {
                // 找到右大括号，结束解析
                Token rightBraceToken = currentToken;
                return new Block(leftBraceToken, blockItemList, rightBraceToken);
            } else {
                // 回退一个 Token，解析下一个 BlockItem
                tokenStream.unReadTokens(1);
                BlockItem blockItem = blockItemParser.parseBlockItem();
                if (blockItem != null) { // 仅在非空的情况下添加
                    blockItemList.add(blockItem);
                    System.out.println("Added BlockItem: " + blockItem);
                }
            }
        }
    }

}
