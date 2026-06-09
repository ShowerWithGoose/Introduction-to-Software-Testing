package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.statement.BlockParser;

public class StmtParser {
    private TokenListIterator iterator;
    /* Stmt Attributes */
    private StmtEle stmtEle = null;

    public StmtParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Stmt parseStmt() {
        Token first = this.iterator.next();
        switch (first.getTokenType()) {
            case IFTK: // 'if'
                this.iterator.unRead(1);
                StmtCondParser stmtCondParser = new StmtCondParser(this.iterator);
                this.stmtEle = stmtCondParser.parseStmtCond();
                break;
            case BREAKTK: // 'break'
                this.iterator.unRead(1);
                StmtBreakParser stmtBreakParser = new StmtBreakParser(this.iterator);
                this.stmtEle = stmtBreakParser.parseStmtBreak();
                break;
            case CONTINUETK: // 'continue'
                this.iterator.unRead(1);
                StmtContinueParser stmtContinueParser = new StmtContinueParser(this.iterator);
                this.stmtEle = stmtContinueParser.parseStmtContinue();
                break;
            case RETURNTK: // 'return'
                this.iterator.unRead(1);
                StmtReturnParser stmtReturnParser = new StmtReturnParser(this.iterator);
                this.stmtEle = stmtReturnParser.parseStmtReturn();
                break;
            case PRINTFTK: // 'printf'
                this.iterator.unRead(1);
                StmtPrintParser stmtPrintParser = new StmtPrintParser(this.iterator);
                this.stmtEle = stmtPrintParser.parseStmtPrint();
                break;
            case FORTK:
                this.iterator.unRead(1);
                StmtForParser stmtForParser = new StmtForParser(this.iterator);
                this.stmtEle = stmtForParser.parseStmtFor();
                break;
            case SEMICN: // ';'
                this.iterator.unRead(1);
                StmtNullParser stmtNullParser = new StmtNullParser(this.iterator);
                this.stmtEle = stmtNullParser.pasreStmtNull();
                break;
            case IDENFR:
                caseIdenfr(first); // may Exp, may LVal
                break;
            case LBRACE: // '{'
                this.iterator.unRead(1);
                BlockParser blockParser = new BlockParser(this.iterator);
                this.stmtEle = blockParser.parseBlock();
                break;
            case LPARENT: case INTCON: case CHRCON: case PLUS: case MINU: case NOT:
                this.iterator.unRead(1);
                StmtExpParser stmtExpParser = new StmtExpParser(this.iterator);
                this.stmtEle = stmtExpParser.parseStmtExp();
                break;
            default:
                System.out.println("ARRIVE UNEXPECTED DEFAULT BRANCH");
        }
        Stmt stmt = new Stmt(this.stmtEle);
        return stmt;
    }

    private void caseIdenfr(Token first) {
        /* need to distinguish LVal = Exp, LVal = getint and [Exp] */
        int cnt = 1;
        int mode = 0; // 0:assign 1:input
        boolean flag = false; // LVal = Exp; || LVal = getint();
        Token token = first;
        while (!token.getTokenType().equals(TokenType.SEMICN)) {
            token = this.iterator.next();
            cnt += 1;
            if (token.getTokenType().equals(TokenType.ASSIGN)) {
                flag = true;
            }
            if (token.getTokenType().equals(TokenType.GETINTTK)) {
                mode = 1;
            } else if (token.getTokenType().equals(TokenType.GETCHARTK)) {
                mode = 2;
            }
        }
        this.iterator.unRead(cnt);
        if (flag) {
            if (mode == 0) {
                StmtAssignParser stmtAssignParser = new StmtAssignParser(this.iterator);
                this.stmtEle = stmtAssignParser.parseStmtAssign();
            } else if (mode == 1) {
                StmtGetintParser stmtGetIntParser = new StmtGetintParser(this.iterator);
                this.stmtEle = stmtGetIntParser.parseStmtGetInt();
            } else if (mode == 2) {
                StmtGetcharParser stmtGetCharParser = new StmtGetcharParser(this.iterator);
                this.stmtEle = stmtGetCharParser.parseStmtGetChar();
            } else {
                System.out.println("REACHED UNEXPECTED BRANCH");
            }
        } else {
            StmtExpParser stmtExpParser = new StmtExpParser(this.iterator);
            this.stmtEle = stmtExpParser.parseStmtExp();
        }
    }
}
