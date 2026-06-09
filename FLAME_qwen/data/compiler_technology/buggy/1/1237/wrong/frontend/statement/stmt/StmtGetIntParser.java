package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenType;
import frontend.TokenListIterator;
import frontend.expression.primaryexp.LVal;
import frontend.expression.primaryexp.LValParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: StmtGetInt (getint 语句)
 * 对应文法: StmtGetInt -> LVal '=' 'getint' '(' ')' ';'
 *
 * 解析 getint 语句，表示从输入获取整数并赋值给左值。
 */
public class StmtGetIntParser {
    private final TokenListIterator iterator;

    public StmtGetIntParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析 getint 语句。
     * @return 解析后的 StmtGetInt 对象
     */
    public StmtGetint parseStmtGetInt() {
        // 解析 LVal
        LValParser lvalParser = new LValParser(this.iterator);
        LVal lval = lvalParser.parseLVal();

        // 解析 '='
        Token eq = this.iterator.readNextToken();
        if (eq.getType() != TokenType.ASSIGN) {
            System.err.println("ERROR: Expected '=' after LVal in getint statement, but found: " + eq);
        }

        // 解析 'getint'
        Token getint = this.iterator.readNextToken();
        if (getint.getType() != TokenType.GETINTTK) {
            System.err.println("ERROR: Expected 'getint' keyword, but found: " + getint);
        }

        // 解析 '(' 并处理 j 类错误
        Token leftParent = this.iterator.readNextToken();
        if (leftParent.getType() != TokenType.LPARENT) {
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_PARENT);  // j 类错误
            ErrorTable.addError(error);
        }

        // 解析 ')'
        Token rightParent = this.iterator.readNextToken();
        if (rightParent.getType() != TokenType.RPARENT) {
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_PARENT);  // j 类错误
            ErrorTable.addError(error);
        }

        // 解析 ';' 并处理 i 类错误
        Token semicn = this.iterator.readNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);  // i 类错误
            ErrorTable.addError(error);
        }

        // 返回解析后的 StmtGetint 对象
        return new StmtGetint(lval, eq, getint, leftParent, rightParent, semicn);
    }
}
