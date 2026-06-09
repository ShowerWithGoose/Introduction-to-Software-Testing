package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Cond;
import frontend.expression.CondParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: StmtCond (条件语句)
 * 对应文法: StmtCond -> 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
 *
 * 解析条件语句结构，包括 'if' 分支和可选的 'else' 分支。
 */
public class StmtCondParser {
    private final TokenListIterator iterator;
    private Token ifTK = null; // 'if'
    private Token leftParent = null; // '('
    private Cond cond = null; // 条件表达式
    private Token rightParent = null; // ')'
    private Stmt ifStmt = null; // if 分支的语句
    private Token elseTk = null; // 可选的 'else'
    private Stmt elseStmt = null; // 可选的 else 分支语句

    public StmtCondParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析条件语句。
     * @return 解析后的 StmtCond 对象
     */
    public StmtCond parseStmtCond() {
        // 解析 'if' 关键字
        this.ifTK = this.iterator.readNextToken();
        if (!this.ifTK.getType().equals(TokenType.IFTK)) {
            System.err.println("ERROR: Expected 'if' keyword (IFTK) in StmtCondParser.");
        }

        // 解析左括号 '('
        this.leftParent = this.iterator.readNextToken();
        if (!this.leftParent.getType().equals(TokenType.LPARENT)) {
            System.err.println("ERROR: Expected '(' (LPARENT) in StmtCondParser.");
        }

        // 解析条件表达式
        CondParser condParser = new CondParser(this.iterator);
        this.cond = condParser.parseCond();

        // 解析右括号 ')'
        this.rightParent = this.iterator.readNextToken();
        if (!this.rightParent.getType().equals(TokenType.RPARENT)) {
            // 处理 j 类错误：缺少右括号 ')'
            this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_PARENT);
            ErrorTable.addError(error);
        }

        // 解析 if 分支的语句
        StmtParser stmtParser = new StmtParser(this.iterator);
        this.ifStmt = stmtParser.parseStmt();

        // 检查是否存在 'else' 分支
        this.elseTk = this.iterator.readNextToken();
        if (this.elseTk.getType().equals(TokenType.ELSETK)) {
            // 解析 else 分支的语句
            this.elseStmt = stmtParser.parseStmt();
            return new StmtCond(this.ifTK, this.leftParent, this.cond, this.rightParent, this.ifStmt, this.elseTk, this.elseStmt);
        } else {
            // 如果没有 'else'，回退 Token
            this.iterator.unReadToken(1);
            return new StmtCond(this.ifTK, this.leftParent, this.cond, this.rightParent, this.ifStmt);
        }
    }
}
