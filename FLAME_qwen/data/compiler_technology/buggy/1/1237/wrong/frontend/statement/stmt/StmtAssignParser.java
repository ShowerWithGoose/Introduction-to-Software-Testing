package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import frontend.expression.primaryexp.LVal;
import frontend.expression.primaryexp.LValParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: StmtAssign (赋值语句)
 * 对应文法: StmtAssign -> LVal '=' Exp ';'
 *
 * 解析赋值语句，包括左值、赋值符号和表达式。
 */
public class StmtAssignParser {
    private final TokenListIterator iterator;

    public StmtAssignParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析赋值语句。
     * @return 解析后的 StmtAssign 对象
     */
    public StmtAssign parseStmtAssign() {
        // 解析左值 (LVal)
        LValParser lvalParser = new LValParser(this.iterator);
        LVal lval = lvalParser.parseLVal();

        // 解析等号 '='
        Token eq = this.iterator.readNextToken();
        if (eq.getType() != TokenType.ASSIGN) {
            System.err.println("ERROR: Expected '=' (ASSIGN), but found: " + eq);
        }

        // 解析右侧的表达式 (Exp)
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

        // 返回解析后的 StmtAssign 对象
        return new StmtAssign(lval, eq, exp, semicn);
    }
}
