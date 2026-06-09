package frontend.Parser.Stmt;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.Cond;
import frontend.Parser.Exp.CondParser;

//'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class StmtForParser {
    private TokenListReader reader;
    private Token forTk;
    private Token lparent;
    private ForStmt forStmt1 = null;
    private Token semicn1;
    private Cond cond = null;
    private Token semicn2;
    private ForStmt forStmt2 = null;
    private Token rparent;
    private Stmt stmt;

    public StmtForParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtFor parseStmtFor(){
        this.forTk = this.reader.getnextToken();
        this.lparent = this.reader.getnextToken();
        this.semicn1 = this.reader.getnextToken();
        if(!this.semicn1.getType().equals(TokenType.SEMICN))
        {
            this.reader.backward(1);
            ForStmtParser parser1 = new ForStmtParser(this.reader);
            this.forStmt1 = parser1.parseForStmt();
            this.semicn1 = this.reader.getnextToken();
        }
        this.semicn2 = this.reader.getnextToken();
        if(!this.semicn2.getType().equals(TokenType.SEMICN))
        {
            this.reader.backward(1);
            CondParser parser2 = new CondParser(this.reader);
            this.cond = parser2.parseCond();
            this.semicn2 = this.reader.getnextToken();
        }
        this.rparent = this.reader.getnextToken();
        if(!this.rparent.getType().equals(TokenType.RPARENT))
        {
            this.reader.backward(1);
            ForStmtParser parser2 = new ForStmtParser(this.reader);
            this.forStmt2 = parser2.parseForStmt();
            this.rparent = this.reader.getnextToken();
        }
        StmtParser stmtParser = new StmtParser(this.reader);
        this.stmt = stmtParser.parseStmt();
        return new StmtFor(this.forTk, this.lparent, this.forStmt1, this.semicn1, this.cond, this.semicn2, this.forStmt2, this.rparent, this.stmt);
    }
}
