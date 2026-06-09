package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Cond;
import frontend.expression.CondParser;

public class StmtForParser {
    private TokenListIterator iterator;
    private Token forTk;         // 'for'
    private Token leftParent;    // '('
    private ForStmt initStmt;    // [ForStmt]
    private Token firstSemi;     // 第一分号
    private Cond cond;           // [Cond]
    private Token secondSemi;    // 第二分号
    private ForStmt updateStmt;  // [ForStmt]
    private Token rightParent;   // ')'
    private Stmt stmt;           // 循环体

    public StmtForParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtFor parseStmtFor() {
        this.forTk = this.iterator.readNextToken();
        if (!this.forTk.getType().equals(TokenType.FORTK)) {
            System.out.println("EXPECT FORTK IN STMTFORPARSER");
            return null;
        }

        this.leftParent = this.iterator.readNextToken();
        if (!this.leftParent.getType().equals(TokenType.LPARENT)) {
            System.out.println("EXPECT LEFTPARENT IN STMTFORPARSER");
            return null;
        }

        // 尝试解析 ForStmt (初始语句)
        Token nextToken = this.iterator.readNextToken();
        if (nextToken.getType().equals(TokenType.SEMICN)) {
            // 如果是分号，说明初始化语句缺省，继续处理
            this.initStmt = null;  // 初始化语句缺省
            this.firstSemi = nextToken;
        } else {
            // 如果不是分号，回退并解析 ForStmt
            this.iterator.unReadToken(1);
            ForStmtParser forStmtParser = new ForStmtParser(this.iterator);
            this.initStmt = forStmtParser.parseForStmt();

            // 解析第一个分号
            this.firstSemi = this.iterator.readNextToken();
            if (!this.firstSemi.getType().equals(TokenType.SEMICN)) {
                System.out.println("EXPECT FIRST SEMICOLON IN STMTFORPARSER");
                return null;
            }
        }

        // 尝试解析 Cond (条件语句)
        nextToken = this.iterator.readNextToken();
        if (nextToken.getType().equals(TokenType.SEMICN)) {
            // 如果是分号，说明条件语句缺省
            this.cond = null;  // 条件语句缺省
            this.secondSemi = nextToken;
        } else {
            // 如果不是分号，回退并解析条件语句
            this.iterator.unReadToken(1);
            CondParser condParser = new CondParser(this.iterator);
            this.cond = condParser.parseCond();

            // 解析第二个分号
            this.secondSemi = this.iterator.readNextToken();
            if (!this.secondSemi.getType().equals(TokenType.SEMICN)) {
                System.out.println("EXPECT SECOND SEMICOLON IN STMTFORPARSER");
                return null;
            }
        }

        // 尝试解析 ForStmt (更新语句)
        nextToken = this.iterator.readNextToken();
        if (nextToken.getType().equals(TokenType.RPARENT)) {
            // 如果是右括号，说明更新语句缺省
            this.updateStmt = null;  // 更新语句缺省
            this.rightParent = nextToken;
        } else {
            // 如果不是右括号，回退并解析更新语句
            this.iterator.unReadToken(1);
            ForStmtParser forStmtParser = new ForStmtParser(this.iterator);
            this.updateStmt = forStmtParser.parseForStmt();

            // 解析右括号
            this.rightParent = this.iterator.readNextToken();
            if (!this.rightParent.getType().equals(TokenType.RPARENT)) {
                System.out.println("EXPECT RPARENT IN STMTFORPARSER");
                return null;
            }
        }

        // 解析循环体语句
        StmtParser stmtParser = new StmtParser(this.iterator);
        this.stmt = stmtParser.parseStmt();

        // 返回构造好的 StmtFor 对象
        return new StmtFor(this.forTk, this.leftParent, this.initStmt,
                this.firstSemi, this.cond, this.secondSemi,
                this.updateStmt, this.rightParent, this.stmt);
    }
}