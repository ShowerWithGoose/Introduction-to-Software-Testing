package frontend.statement.blockitem;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.declaration.DeclParser;
import frontend.statement.stmt.StmtParser;

/**
 * 解析器: BlockItem (语句块项)
 * 对应文法: BlockItem → Decl | Stmt
 *
 * 解析 BlockItem，它可能是声明 (Decl) 或语句 (Stmt)。
 * 解析过程：
 * 1. 如果遇到 'const' 或 'int'，则解析为声明 (Decl)。
 * 2. 否则解析为语句 (Stmt)。
 */
public class BlockItemParser {
    private final TokenListIterator iterator;

    public BlockItemParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public BlockItem parseBlockItem() {
        // 读取下一个 token，决定解析声明还是语句
        Token token = this.iterator.readNextToken();

        BlockItemEle blockItemEle;
        if (token.getType().equals(TokenType.CONSTTK) || token.getType().equals(TokenType.INTTK) || token.getType().equals(TokenType.CHARTK)) {
            // 如果 token 是 'const' 或 'int'或'char'，解析为声明
            iterator.unReadToken(1); // 回退以重新读取声明的第一个 token
            DeclParser declParser = new DeclParser(this.iterator);
            blockItemEle = declParser.parseDecl();
        } else {
            // 否则解析为语句
            iterator.unReadToken(1); // 回退以重新读取语句的第一个 token
            StmtParser stmtParser = new StmtParser(this.iterator);
            blockItemEle = stmtParser.parseStmt();
        }

        // 构造并返回 BlockItem 对象
        return new BlockItem(blockItemEle);
    }
}
