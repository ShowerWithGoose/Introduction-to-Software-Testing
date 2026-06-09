package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: StmtReturn (return 语句)
 * 对应文法: StmtReturn -> 'return' [Exp] ';'
 *
 * 解析 return 语句，表示函数的返回操作，可以包含一个可选的返回表达式。
 */
public class StmtReturnParser {
    private final TokenListIterator iterator;

    public StmtReturnParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析 return 语句。
     * @return 解析后的 StmtReturn 对象
     */
    public StmtReturn parseStmtReturn() {
        // 解析 'return' 关键字
        Token returnTk = this.iterator.readNextToken();
        if (returnTk.getType() != TokenType.RETURNTK) {
            System.err.println("ERROR: Expected 'return' keyword (RETURNTK), but found: " + returnTk);
        }

        // 尝试解析可选的返回表达式
        Token semicn = this.iterator.readNextToken();
        Exp exp = null;
        if (semicn.getType() != TokenType.SEMICN) {
            if (!isValidExpressionStart(semicn)) {
                // 处理 i 类错误：缺少分号 ';'
                this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
                Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);
                ErrorTable.addError(error);
                semicn = new Token(TokenType.SEMICN, semicn.getLineIndex(), ";");
            } else {
                // 合法的表达式，调用 ExpParser 解析
                this.iterator.unReadToken(1);
                ExpParser expParser = new ExpParser(this.iterator);
                exp = expParser.parseExp();
                semicn = this.iterator.readNextToken();

                // 解析分号 ';'
                if (semicn.getType() != TokenType.SEMICN) {
                    // 处理 i 类错误：缺少分号 ';'
                    this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
                    Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);
                    ErrorTable.addError(error);
                }
            }
        }
        // 返回解析后的 StmtReturn 对象
        return (exp != null) ? new StmtReturn(returnTk, exp, semicn) : new StmtReturn(returnTk, semicn);
    }



    private boolean isValidExpressionStart(Token token) {
        return token.getType() == TokenType.IDENFR ||  // 标识符（变量、函数名）
                token.getType() == TokenType.INTCON ||    // 整数常量
                token.getType() == TokenType.CHRCON ||   // 字符常量
                token.getType() == TokenType.LPARENT ||     // 左括号 '('
                token.getType() == TokenType.PLUS ||        // 加号 '+'
                token.getType() == TokenType.MINU ||       // 减号 '-'
                token.getType() == TokenType.MULT ||        // 乘号 '*'
                token.getType() == TokenType.DIV;           // 除号 '/'
    }

}
