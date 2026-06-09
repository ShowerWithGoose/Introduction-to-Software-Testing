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
 * 解析器: StmtGetChar (getchar 语句)
 * 对应文法: StmtGetChar -> LVal '=' 'getchar' '(' ')' ';'
 *
 * 解析 getchar 语句，表示从输入获取字符并赋值给左值。
 */
public class StmtGetCharParser {
    private final TokenListIterator iterator;

    public StmtGetCharParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析 getchar 语句。
     * @return 解析后的 StmtGetChar 对象
     */
    public StmtGetchar parseStmtGetChar() {
        // 解析 LVal
        LValParser lvalParser = new LValParser(this.iterator);
        LVal lval = lvalParser.parseLVal();

        // 解析 '='
        Token eq = this.iterator.readNextToken();
        if (eq.getType() != TokenType.ASSIGN) {
            System.err.println("ERROR: Expected '=' after LVal in getchar statement, but found: " + eq);
        }

        // 解析 'getchar'
        Token getchar = this.iterator.readNextToken();
        if (getchar.getType() != TokenType.GETCHARTK) {
            System.err.println("ERROR: Expected 'getchar' keyword, but found: " + getchar);
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

        // 返回解析后的 StmtGetchar 对象
        return new StmtGetchar(lval, eq, getchar, leftParent, rightParent, semicn);
    }
}
