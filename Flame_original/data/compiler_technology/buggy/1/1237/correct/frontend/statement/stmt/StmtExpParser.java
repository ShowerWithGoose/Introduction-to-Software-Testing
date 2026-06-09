package frontend.statement.stmt;

import frontend.TokenType;
import frontend.Token;
import frontend.TokenListIterator;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: StmtExp (表达式语句)
 * 对应文法: StmtExp -> Exp ';'
 *
 * 解析表达式语句，表示一个完整的表达式以分号结尾。
 */
public class StmtExpParser {
    private final TokenListIterator iterator;

    public StmtExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析表达式语句。
     * @return 解析后的 StmtExp 对象
     */
    public StmtExp parseStmtExp() {
        // 解析表达式
        ExpParser expParser = new ExpParser(this.iterator);
        Exp exp = expParser.parseExp();

        // 解析分号 ';' 并处理 i 类错误
        Token semicn = this.iterator.readNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            // 处理缺少分号的情况 (i 类错误)
            this.iterator.unReadToken(2); // 回退两次，获取前一个非终结符的行号
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);
            ErrorTable.addError(error);
        }

        // 返回解析后的 StmtExp 对象
        return new StmtExp(exp, semicn);
    }
}
