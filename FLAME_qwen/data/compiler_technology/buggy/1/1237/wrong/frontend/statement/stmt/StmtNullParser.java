package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

/**
 * 解析器: StmtNull (空语句)
 * 对应文法: StmtNull -> ';'
 *
 * 解析空语句，表示没有任何操作的语句。
 */
public class StmtNullParser {
    private final TokenListIterator iterator;

    public StmtNullParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析空语句。
     * @return 解析后的 StmtNull 对象
     */
    public StmtNull parseStmtNull() {
        // 解析分号 ';'
        Token semicn = this.iterator.readNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            System.err.println("ERROR: Expected ';' (SEMICN), but found: " + semicn);
        }
        return new StmtNull(semicn);
    }
}