package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: StmtBreak (break 语句)
 * 对应文法: StmtBreak -> 'break' ';'
 *
 * 解析 break 语句，表示在循环或 switch 结构中退出当前流程。
 */
public class StmtBreakParser {
    private final TokenListIterator iterator;
    private Token breakTk; // 'break'
    private Token semicn; // ';'

    public StmtBreakParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析 break 语句。
     * @return 解析后的 StmtBreak 对象
     */
    public StmtBreak parseStmtBreak() {
        // 解析 'break' 关键字
        this.breakTk = this.iterator.readNextToken();
        if (!this.breakTk.getType().equals(TokenType.BREAKTK)) {
            System.err.println("ERROR: Expected 'break' keyword (BREAKTK) in StmtBreakParser.");
        }

        // 解析分号 ';'
        this.semicn = this.iterator.readNextToken();
        if (!this.semicn.getType().equals(TokenType.SEMICN)) {
            // 处理 i 类错误：缺少分号 ';'
            this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);
            ErrorTable.addError(error);
        }

        // 返回解析后的 StmtBreak 对象
        return new StmtBreak(this.breakTk, this.semicn);
    }
}
