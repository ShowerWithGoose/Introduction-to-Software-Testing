package frontend.Parser.Stmt;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;

public class StmtReturnParser {
    private TokenListReader reader;
    private Token returnTk;
    private Exp exp;
    private Token semicn;
//| 'return' [Exp] ';'
    public StmtReturnParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtReturn parseStmtReturn() {
        this.returnTk = this.reader.getnextToken();
        ExpParser expParser = new ExpParser(this.reader);
        this.semicn = this.reader.getnextToken();
        if(!semicn.getType().equals(TokenType.SEMICN))
        {
            this.reader.backward(1);
            this.exp = expParser.parseExp();
            this.semicn = this.reader.getnextToken();
            return new StmtReturn(this.returnTk, this.exp,this.semicn);
        }else {
            return new StmtReturn(this.returnTk, this.semicn);
        }
    }



}
