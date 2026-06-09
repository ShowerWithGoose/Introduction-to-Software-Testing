package frontend.statement;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.statement.blockitem.BlockItem;
import frontend.statement.blockitem.BlockItemParser;

import java.util.ArrayList;
import java.util.List;

/**
 * 解析器: Block (语句块)
 * 对应文法: Block → '{' {BlockItem} '}'
 *
 * 解析语句块，语句块以左花括号 '{' 开始，包含零个或多个 BlockItem，
 * 并以右花括号 '}' 结束。
 */
public class BlockParser {
    private final TokenListIterator iterator; // 迭代器
    private Token leftBrace; // 左花括号 '{'
    private final ArrayList<BlockItem> blockItems = new ArrayList<>(); // BlockItem 列表
    private Token rightBrace; // 右花括号 '}'

    public BlockParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Block parseBlock() {
        // 解析左花括号 '{'
        leftBrace = iterator.readNextToken();
        if (!leftBrace.getType().equals(TokenType.LBRACE)) {
            throw new IllegalArgumentException("ERROR: EXPECTING '{', BUT FOUND: " + leftBrace);
        }

        // 解析 {BlockItem}
        BlockItemParser blockItemParser = new BlockItemParser(iterator);
        Token token = iterator.readNextToken();

        // 添加死循环检查相关变量
        int loopCounter = 0;
        final int MAX_LOOP_COUNT = 2; // 自定义一个合理的最大循环次数
        final int SKIP_TOKENS = 1;

        while (!token.getType().equals(TokenType.RBRACE)) { // 遇到右花括号 '}' 则结束
            if (loopCounter++ > MAX_LOOP_COUNT) {
//                for (int i = 0; i < SKIP_TOKENS; i++) {
//                    token = iterator.readNextToken(); // 跳过指定数量的 token
//                    System.out.println("Skipped token: " + token);
//                }
//                continue;  // 跳过指定 token 后继续解析
                 this.iterator.unReadToken(9);
                TokenType type = this.iterator.readNextToken().getType();
                TokenType type2 = this.iterator.readNextToken().getType();
                 TokenType type3 = this.iterator.readNextToken().getType();
                 TokenType type4 = this.iterator.readNextToken().getType();
                 TokenType type5 = this.iterator.readNextToken().getType();
                TokenType type6 = this.iterator.readNextToken().getType();
                TokenType type7 = this.iterator.readNextToken().getType();
                TokenType type8 = this.iterator.readNextToken().getType();
                TokenType type9 = this.iterator.readNextToken().getType();

                TokenType type10 = this.iterator.readNextToken().getType();

                if ( ( type8.equals(TokenType.RPARENT) && type9.equals(TokenType.RPARENT))
                 && (   type7.equals(TokenType.LPARENT))
                 && (type6.equals(TokenType.IDENFR))
                 && (type5.equals(TokenType.RPARENT))
                 &&( type4.equals(TokenType.LPARENT))
                        && (type3.equals(TokenType.IDENFR))
                        && (type2.equals(TokenType.LPARENT))
                        && (type.equals(TokenType.IFTK))

                        //&& (type10.equals(TokenType.LBRACE))
                ) {

                    //break; // 一旦匹配，跳出循环
                }


            }

            iterator.unReadToken(1); // 回退到 BlockItem 的第一个 token
            blockItems.add(blockItemParser.parseBlockItem()); // 解析 BlockItem
            token = iterator.readNextToken(); // 继续读取下一个 token
        }

        // 解析右花括号 '}'
        rightBrace = token;
//        if (!rightBrace.getType().equals(TokenType.RBRACE)) {
//            throw new IllegalArgumentException("ERROR: EXPECTING '}', BUT FOUND: " + rightBrace);
//        }

        // 返回解析后的 Block 对象
        return new Block(leftBrace, blockItems, rightBrace);
    }



}
