package frontend.Parser.statement;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.block.ParserOfBlock;
import frontend.Parser.statement.stmt.*;

import java.util.ArrayList;

public class ParserOfStmt {
    private TokenListManager tokenListManager;
    private StmtPort stmtPort;
    private ArrayList<Error> errors;

    public ParserOfStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public Stmt parseStmt() {
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        switch (fir.getTokenType()) {
            case IFTK:
                tokenListManager.lookBackToken(1);
                ParserOfIfStmt parserIfStmt = new ParserOfIfStmt(tokenListManager);
                this.stmtPort = parserIfStmt.parseIfStmt();
                this.errors.addAll(parserIfStmt.getErrors());
                break;
            case FORTK:
                tokenListManager.lookBackToken(1);
                ParserOfForLoopStmt parserForStmt = new ParserOfForLoopStmt(tokenListManager);
                this.stmtPort = parserForStmt.parseForLoopStmt();
                this.errors.addAll(parserForStmt.getErrors());
                break;
            case BREAKTK:
                tokenListManager.lookBackToken(1);
                ParserOfBreakStmt parserBreakStmt = new ParserOfBreakStmt(tokenListManager);
                this.stmtPort = parserBreakStmt.parseBreakStmt();
                this.errors.addAll(parserBreakStmt.getErrors());
                break;
            case CONTINUETK:
                tokenListManager.lookBackToken(1);
                ParserOfContinueStmt parserContinueStmt = new ParserOfContinueStmt(tokenListManager);
                this.stmtPort = parserContinueStmt.parseContinueStmt();
                this.errors.addAll(parserContinueStmt.getErrors());
                break;
            case RETURNTK:
                tokenListManager.lookBackToken(1);
                ParserOfReturnStmt parserOfReturnStmt = new ParserOfReturnStmt(tokenListManager);
                this.stmtPort = parserOfReturnStmt.parseReturnStmt();
                this.errors.addAll(parserOfReturnStmt.getErrors());
                break;
            case PRINTFTK:
                tokenListManager.lookBackToken(1);
                ParserOfPrintfStmt parserOfPrintfStmt = new ParserOfPrintfStmt(tokenListManager);
                this.stmtPort = parserOfPrintfStmt.parsePrintfStmt();
                this.errors.addAll(parserOfPrintfStmt.getErrors());
                break;
            case LBRACE:
                tokenListManager.lookBackToken(1);
                ParserOfBlock parserOfBlock = new ParserOfBlock(tokenListManager);
                this.stmtPort = parserOfBlock.parseBlock();
                this.errors.addAll(parserOfBlock.getErrors());
                break;
            case LPARENT:
            case INTCON:
            case CHRCON:
            case PLUS:
            case MINU:
            case NOT:
            case SEMICN:
                tokenListManager.lookBackToken(1);
                ParserOfExpStmt parserOfExpStmt = new ParserOfExpStmt(tokenListManager);
                this.stmtPort = parserOfExpStmt.parseExpStmt();
                this.errors.addAll(parserOfExpStmt.getErrors());
                break;
            case IDENFR:
                dealIdentFirst(fir);
                break;
            default:
                System.out.println("not correct first token in Stmt");
        }
        Stmt stmt = new Stmt(this.stmtPort);
        return stmt;
    }

    /*
    LVal '=' Exp ';'
    LVal '=' 'getint''('')'';'
    LVal '=' 'getchar''('')'';'
    [Exp] ';'
     */
    private void dealIdentFirst(Token fir) {
        int preRead = 1;
        boolean assignFlag = false; //是否为赋值语句
        int assignType = 0; //0:=Exp 1:=getint 2:=getchar
        Token token = fir;
        int lineNumber = fir.getLineNo();
        while (!token.getTokenType().equals(TokenType.SEMICN) && token.getLineNo() == lineNumber) {
            if (token.getTokenType().equals(TokenType.ASSIGN)) {
                assignFlag = true;
            }
            if (token.getTokenType().equals(TokenType.GETINTTK)) {
                assignType = 1;
            }
            if (token.getTokenType().equals(TokenType.GETCHARTK)) {
                assignType = 2;
            }
            token = tokenListManager.getTokenAndMove();
            preRead++;
        }
        tokenListManager.lookBackToken(preRead);
        if (!assignFlag) {
            ParserOfExpStmt parserOfExpStmt = new ParserOfExpStmt(tokenListManager);
            this.stmtPort = parserOfExpStmt.parseExpStmt();
            this.errors.addAll(parserOfExpStmt.getErrors());
        } else {
            if (assignType == 0) {
                ParserOfAssignStmt parserOfAssignStmt = new ParserOfAssignStmt(tokenListManager);
                this.stmtPort = parserOfAssignStmt.parseAssignStmt();
                this.errors.addAll(parserOfAssignStmt.getErrors());
            } else if (assignType == 1) {
                ParserOfGetintStmt parserOfGetintStmt = new ParserOfGetintStmt(tokenListManager);
                this.stmtPort = parserOfGetintStmt.parseGetintStmt();
                this.errors.addAll(parserOfGetintStmt.getErrors());
            } else {
                ParserOfGetcharStmt parserOfGetcharStmt = new ParserOfGetcharStmt(tokenListManager);
                this.stmtPort = parserOfGetcharStmt.parseGetcharStmt();
                this.errors.addAll(parserOfGetcharStmt.getErrors());
            }
        }
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
