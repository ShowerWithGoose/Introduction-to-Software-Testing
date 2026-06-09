package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.statement.BlockParser;

/**
 * 解析器: Stmt (语句)
 * 对应文法:
 * 1. Stmt → LVal '=' Exp ';'
 * 2. Stmt → [Exp] ';'
 * 3. Stmt → Block
 * 4. Stmt → 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
 * 5. Stmt → 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
 * 6. Stmt → 'break' ';'
 * 7. Stmt → 'continue' ';'
 * 8. Stmt → 'return' [Exp] ';'
 * 9. Stmt → LVal '=' 'getint''('')'';'
 * 10. Stmt → 'printf''('StringConst {','Exp}')'';'
 *
 * 解析语句结构，根据语句类型调用不同的解析方法。
 */
public class StmtParser {
    private final TokenListIterator iterator;
    private StmtEle stmtEle = null;

    public StmtParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 根据语句的类型解析 Stmt。
     * @return 解析后的 Stmt 对象
     */
    public Stmt parseStmt() {
        Token first = this.iterator.readNextToken();
        switch (first.getType()) {
            case FORTK: // 'for'
                this.iterator.unReadToken(1);
                StmtForParser stmtForParser = new StmtForParser(this.iterator);
                this.stmtEle = stmtForParser.parseStmtFor();
                break;
            case IFTK: // 'if'
                this.iterator.unReadToken(1);
                StmtCondParser stmtCondParser = new StmtCondParser(this.iterator);
                this.stmtEle = stmtCondParser.parseStmtCond();
                break;
            case BREAKTK: // 'break'
                this.iterator.unReadToken(1);
                StmtBreakParser stmtBreakParser = new StmtBreakParser(this.iterator);
                this.stmtEle = stmtBreakParser.parseStmtBreak();
                break;
            case CONTINUETK: // 'continue'
                this.iterator.unReadToken(1);
                StmtContinueParser stmtContinueParser = new StmtContinueParser(this.iterator);
                this.stmtEle = stmtContinueParser.parseStmtContinue();
                break;
            case RETURNTK: // 'return'
                this.iterator.unReadToken(1);
                StmtReturnParser stmtReturnParser = new StmtReturnParser(this.iterator);
                this.stmtEle = stmtReturnParser.parseStmtReturn();
                break;
            case PRINTFTK: // 'printf'
                this.iterator.unReadToken(1);
                StmtPrintParser stmtPrintParser = new StmtPrintParser(this.iterator);
                this.stmtEle = stmtPrintParser.parseStmtPrint();
                break;
            case SEMICN: // ';'
                this.iterator.unReadToken(1);
                StmtNullParser stmtNullParser = new StmtNullParser(this.iterator);
                this.stmtEle = stmtNullParser.parseStmtNull();
                break;
            case IDENFR:
                caseIdenfr(first);
                break;
            case LBRACE: // '{'
                this.iterator.unReadToken(1);
                BlockParser blockParser = new BlockParser(this.iterator);
                this.stmtEle = blockParser.parseBlock();
                break;
            case LPARENT: case INTCON: case PLUS: case MINU: case CHRCON:
                this.iterator.unReadToken(1);
                StmtExpParser stmtExpParser = new StmtExpParser(this.iterator);
                this.stmtEle = stmtExpParser.parseStmtExp();
                break;
            default:
                System.err.println("ARRIVE UNEXPECTED DEFAULT BRANCH");
        }
        return new Stmt(this.stmtEle);
    }

    /**
     * 处理以标识符开头的语句，区分 LVal = Exp、LVal = getint、LVal = getchar 以及 [Exp]。
     * @param first 第一个 Token
     */
    private void caseIdenfr(Token first) {
        int cnt = 1;
        int mode = 0; // 0: assign, 1: getint, 2: getchar
        boolean flag = false; // LVal = Exp 或 LVal = getint() 或 LVal = getchar()
        Token token = first;

        // 遍历 Token，找到等号 '='、getint 或 getchar 关键字
        while (!token.getType().equals(TokenType.SEMICN)) {
            token = this.iterator.readNextToken();
            cnt += 1;
            if (token.getType().equals(TokenType.ASSIGN)) {
                flag = true;
            }
            if (token.getType().equals(TokenType.GETINTTK)) {
                mode = 1;
            } else if (token.getType().equals(TokenType.GETCHARTK)) {
                mode = 2;
            }
        }

        // 回退 Token 列表
        this.iterator.unReadToken(cnt);

        // 根据解析结果决定解析 LVal = Exp、LVal = getint() 或 LVal = getchar()
        if (flag) {
            if (mode == 0) {
                StmtAssignParser stmtAssignParser = new StmtAssignParser(this.iterator);
                this.stmtEle = stmtAssignParser.parseStmtAssign();
            } else if (mode == 1) {
                StmtGetIntParser stmtGetIntParser = new StmtGetIntParser(this.iterator);
                this.stmtEle = stmtGetIntParser.parseStmtGetInt();
            } else if (mode == 2) {
                StmtGetCharParser stmtGetCharParser = new StmtGetCharParser(this.iterator);
                this.stmtEle = stmtGetCharParser.parseStmtGetChar();
            } else {
                System.err.println("REACHED UNEXPECTED BRANCH");
            }
        } else {
            StmtExpParser stmtExpParser = new StmtExpParser(this.iterator);
            this.stmtEle = stmtExpParser.parseStmtExp();
        }
    }

}
