package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.Cond;
import frontend.Parser.Exp.CondParser;

public class StmtIfParser {
    private TokenListReader reader;

    private Token ifTk = null;
    private Token lparent = null;
    private Cond cond = null;
    private Token rparent = null;
    private Stmt stmt = null;
    private Token elseTk = null;
    private Stmt elseStmt = null;

    public StmtIfParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtIf parseStmtIf() {
        this.ifTk = this.reader.getnextToken();
        if (!this.ifTk.getType().equals(TokenType.IFTK)) {
            System.out.println("error: stmtif");
        }
        this.lparent = this.reader.getnextToken();
        if (!this.lparent.getType().equals(TokenType.LPARENT)) {
            System.out.println("error: stmtif");
        }
        CondParser condParser = new CondParser(this.reader);
        this.cond = condParser.parseCond();
        this.rparent = this.reader.getnextToken();
        if (!this.rparent.getType().equals(TokenType.RPARENT)) {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
            this.reader.backward(1);
        }
        StmtParser stmtParser = new StmtParser(this.reader);
        this.stmt = stmtParser.parseStmt();
        this.elseTk = this.reader.getnextToken();
        if (this.elseTk.getType().equals(TokenType.ELSETK)) {
            this.elseStmt = stmtParser.parseStmt();
            return new StmtIf(this.ifTk, this.lparent,
                    this.cond, this.rparent, this.stmt, this.elseTk, this.elseStmt);
        } else {
            this.reader.backward(1);
            return new StmtIf(this.ifTk, this.lparent, this.cond, this.rparent, this.stmt);
        }
    }

}
