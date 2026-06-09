package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;
import frontend.TokenType;

public class StmtExpParser {
    private TokenListReader reader;
    private Exp exp;
    private Token semicn;

    public StmtExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtExp parseStmtExp() {
        ExpParser expParser = new ExpParser(this.reader);
        this.exp = expParser.parseExp();
        this.semicn = this.reader.getnextToken();
        if(!this.semicn.getType().equals(TokenType.SEMICN))
        {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
//            this.reader.backward(1);
        }
        return new StmtExp(this.exp, this.semicn);
    }
}
