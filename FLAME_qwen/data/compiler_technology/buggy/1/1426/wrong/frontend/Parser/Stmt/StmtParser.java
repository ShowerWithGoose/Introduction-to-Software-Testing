package frontend.Parser.Stmt;

import frontend.TokenListReader;
import frontend.Token;
import frontend.TokenType;

public class StmtParser {
    private TokenListReader reader;
    private StmtInf stmtInf;

    public StmtParser(TokenListReader reader) {
        this.reader = reader;
    }
//Stmt â†’ LVal '=' Exp ';'
//| [Exp] ';'
//| Block
//| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
//| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
//| 'break' ';' | 'continue' ';'
//| 'return' [Exp] ';'
//| LVal '=' 'getint''('')'';'
//| LVal '=' 'getchar''('')'';'
//| 'printf''('StringConst {','Exp}')'';'
    public Stmt parseStmt(){
        Token first = this.reader.getnextToken();
        switch (first.getType()) {
            case IFTK:
                this.reader.backward(1);
                StmtIfParser stmtCondParser = new StmtIfParser(this.reader);
                this.stmtInf = stmtCondParser.parseStmtIf();
                break;
            case FORTK:
                this.reader.backward(1);
                StmtForParser stmtWhileParser = new StmtForParser(this.reader);
                this.stmtInf = stmtWhileParser.parseStmtFor();
                break;
            case BREAKTK:
                this.reader.backward(1);
                StmtBreakParser stmtBreakParser = new StmtBreakParser(this.reader);
                this.stmtInf = stmtBreakParser.parseStmtBreak();
                break;
            case CONTINUETK:
                this.reader.backward(1);
                StmtContinueParser stmtContinueParser = new StmtContinueParser(this.reader);
                this.stmtInf = stmtContinueParser.parseStmtContinue();
                break;
            case RETURNTK:
                this.reader.backward(1);
                StmtReturnParser stmtReturnParser = new StmtReturnParser(this.reader);
                this.stmtInf = stmtReturnParser.parseStmtReturn();
                break;
            case PRINTFTK:
                this.reader.backward(1);
                StmtprintfParser stmtPrintParser = new StmtprintfParser(this.reader);
                this.stmtInf = stmtPrintParser.parseStmtprintf();
                break;
            case SEMICN: // ';'
                this.reader.backward(1);
                StmtVoidParser stmtNullParser = new StmtVoidParser(this.reader);
                this.stmtInf = stmtNullParser.parseStmtVoid();
                break;
            case IDENFR:
                decide(first);
                break;
            case LBRACE:
                this.reader.backward(1);
                BlockParser blockParser = new BlockParser(this.reader);
                this.stmtInf = blockParser.parseBlock();
                break;
            case LPARENT: case INTCON: case CHRCON: case PLUS: case MINU: case NOT:
                this.reader.backward(1);
                StmtExpParser stmtExpParser = new StmtExpParser(this.reader);
                this.stmtInf = stmtExpParser.parseStmtExp();
                break;
            default:
                System.out.println("error: invalid Stmt 0");
        }
        Stmt stmt = new Stmt(this.stmtInf);
        return stmt;
    }
    public void decide(Token first){
        //System.out.println("IN DECIDE"+first.toString());
        int cnt = 1;
        int mode = 0;
        boolean flag = false;//LVal...
        Token token = first;
        while (!token.getType().equals(TokenType.SEMICN)) {
            token = this.reader.getnextToken();
            cnt = cnt + 1;
            if (token.getType().equals(TokenType.ASSIGN)) {
                flag = true;
            }
            if (token.getType().equals(TokenType.GETINTTK)) {
                mode = 1;
            }
            if (token.getType().equals(TokenType.GETCHARTK)) {
                mode = 2;
            }
        }
        this.reader.backward(cnt);
        if (flag) {
            //System.out.println("flag");
            if (mode == 0) {
                //System.out.println("mode = 0");
                StmtLvalExpParser stmtLvalExpParser = new StmtLvalExpParser(this.reader);
                this.stmtInf = stmtLvalExpParser.parseStmtLvalExp();
            } else if (mode == 1) {
                //System.out.println("mode = 1");
                StmtgetintParser stmtGetIntParser = new StmtgetintParser(this.reader);
                this.stmtInf = stmtGetIntParser.parseStmtgetint();
            }else if (mode == 2) {
                //System.out.println("mode = 2");
                StmtgetcharParser stmtGetCharParser = new StmtgetcharParser(this.reader);
                this.stmtInf = stmtGetCharParser.parseStmtgetchar();
            } else {
                System.out.println("error: stmt 1");
            }
        } else {
            StmtExpParser stmtExpParser = new StmtExpParser(this.reader);
            this.stmtInf = stmtExpParser.parseStmtExp();
        }
    }

}
