package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;
import frontend.Parser.PriExp.LVal;
import frontend.Parser.PriExp.LValParser;
import frontend.TokenType;

public class StmtLvalExpParser {
    private TokenListReader reader;
    private LVal lval;
    private Token equal;
    private Exp exp;
    private Token semicn;

    public StmtLvalExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtLvalExp parseStmtLvalExp() {
        LValParser lvalParser = new LValParser(this.reader);
        this.lval = lvalParser.parseLVal();
        this.equal = this.reader.getnextToken();
        ExpParser expParser = new ExpParser(this.reader);
        this.exp = expParser.parseExp();
        this.semicn = this.reader.getnextToken();
        if(!this.semicn.getType().equals(TokenType.SEMICN))
        {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
            this.reader.backward(1);
        }
        return new StmtLvalExp(this.lval, this.equal, this.exp, this.semicn);
    }
}
