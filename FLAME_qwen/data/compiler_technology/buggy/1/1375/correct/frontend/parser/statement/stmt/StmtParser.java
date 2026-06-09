package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.statement.BlockParser;

import java.util.ArrayList;

import static frontend.lexer.TokenType.IFTK;

public class StmtParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* Stmt Attributes */
    public StmtEle stmtEle = null;

    public StmtParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public Stmt parseStmt() {
        Token first = this.iterator.readNextToken();
        switch (first.type) {
            case IFTK: // 'if'
                this.iterator.unReadToken(1);
                StmtCondParser stmtCondParser = new StmtCondParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtCondParser.parseStmtCond();
                break;
            case FORTK: // 'for'
                this.iterator.unReadToken(1);
                StmtWhileParser stmtWhileParser = new StmtWhileParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtWhileParser.parseStmtWhile();
                break;
            case BREAKTK: // 'break'
                this.iterator.unReadToken(1);
                StmtBreakParser stmtBreakParser = new StmtBreakParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtBreakParser.parseStmtBreak();
                break;
            case CONTINUETK: // 'continue'
                this.iterator.unReadToken(1);
                StmtContinueParser stmtContinueParser = new StmtContinueParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtContinueParser.parseStmtContinue();
                break;
            case RETURNTK: // 'return'
                this.iterator.unReadToken(1);
                StmtReturnParser stmtReturnParser = new StmtReturnParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtReturnParser.parseStmtReturn();
                break;
            case PRINTFTK: // 'printf'
                this.iterator.unReadToken(1);
                StmtPrintParser stmtPrintParser = new StmtPrintParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtPrintParser.parseStmtPrint();
                break;
            case SEMICN: // ';'
                this.iterator.unReadToken(1);
                StmtNullParser stmtNullParser = new StmtNullParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtNullParser.pasreStmtNull();
                break;
            case IDENFR:
                caseIdenfr(first);
                break;
            case LBRACE: // '{' Block
                this.iterator.unReadToken(1);
                BlockParser blockParser = new BlockParser(this.iterator,this.error_tokens);
                this.stmtEle = blockParser.parseBlock();
                break;
            case LPARENT: case INTCON: case PLUS: case MINU:case CHRCON:
                this.iterator.unReadToken(1);
                StmtExpParser stmtExpParser = new StmtExpParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtExpParser.parseStmtExp();
                break;
            default:
                System.out.println("ARRIVE UNEXPECTED DEFAULT BRANCH");
        }
        Stmt stmt = new Stmt(this.stmtEle);
        return stmt;
    }

    public void caseIdenfr(Token first) {
        /* need to distinguish LVal = Exp, LVal = getint  LVal = getchar and [Exp] */
        int cnt = 1;
        int mode_int = 0; // 0:assign 1:input
        int mode_char = 0;
        boolean flag = false; // LVal = Exp; || LVal = getint();
        Token token = first;
        while (!token.type.equals(TokenType.SEMICN)) {
            token = this.iterator.readNextToken();
            cnt += 1;
            if (token.type.equals(TokenType.ASSIGN)) {
                flag = true;
            }
            if (token.type.equals(TokenType.GETINTTK)) {
                mode_int = 1;
            }
            if(token.type.equals(TokenType.GETCHARTK)){
                mode_char=1;
            }
        }
        this.iterator.unReadToken(cnt);
        if (flag) {
            if (mode_int == 0 && mode_char == 0) {
                StmtAssignParser stmtAssignParser = new StmtAssignParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtAssignParser.parseStmtAssign();
            } else if (mode_int == 1) {
                StmtGetIntParser stmtGetIntParser = new StmtGetIntParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtGetIntParser.parseStmtGetInt();
            } else if(mode_char == 1){
                StmtGetCharParser stmtGetCharParser = new StmtGetCharParser(this.iterator,this.error_tokens);
                this.stmtEle = stmtGetCharParser.parseStmtGetInt();
            }
        } else {
            StmtExpParser stmtExpParser = new StmtExpParser(this.iterator,this.error_tokens);
            this.stmtEle = stmtExpParser.parseStmtExp();
        }
    }
}
// exp的起始符号是'(' INTCON IDENFR CHRON '+' '-' '!'
// LVal的起始符号是 IDENFR