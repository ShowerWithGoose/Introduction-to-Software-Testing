package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: StmtContinue (continue 语句)
 * 对应文法: StmtContinue -> 'continue' ';'
 *
 * 解析 continue 语句，表示在循环中跳过当前迭代并继续下一次迭代。
 */
public class StmtContinueParser {
    private final TokenListIterator iterator;

    public StmtContinueParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析 continue 语句。
     * @return 解析后的 StmtContinue 对象
     */
    public StmtContinue parseStmtContinue() {
        // 解析 'continue' 关键字
        Token continueTk = this.iterator.readNextToken();
        if (continueTk.getType() != TokenType.CONTINUETK) {
            System.err.println("ERROR: Expected 'continue' keyword (CONTINUETK), but found: " + continueTk);
        }

        // 解析分号 ';'
        Token semicn = this.iterator.readNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            // 处理 i 类错误：缺少分号 ';'
            this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);
            ErrorTable.addError(error);
        }

        // 返回解析后的 StmtContinue 对象
        return new StmtContinue(continueTk, semicn);
    }
}
