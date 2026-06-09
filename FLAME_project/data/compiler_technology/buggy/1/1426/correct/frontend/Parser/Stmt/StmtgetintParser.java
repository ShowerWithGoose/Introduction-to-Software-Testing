package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.Parser.PriExp.LVal;
import frontend.Parser.PriExp.LValParser;
import frontend.TokenType;

public class StmtgetintParser {
    private TokenListReader reader;
    private LVal lVal;
    private Token equal;
    private Token getint;
    private Token lparent;
    private Token rparent;
    private Token semicn;

    public StmtgetintParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Stmtgetint parseStmtgetint(){
        LValParser lvalParser = new LValParser(this.reader);
        this.lVal = lvalParser.parseLVal();
        this.equal = this.reader.getnextToken();
        this.getint = this.reader.getnextToken();
        this.lparent = this.reader.getnextToken();
        this.rparent = this.reader.getnextToken();
        if(!this.rparent.getType().equals(TokenType.RPARENT))
        {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
            this.reader.backward(1);
        }
        this.semicn = this.reader.getnextToken();
        if(!this.semicn.getType().equals(TokenType.SEMICN))
        {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
            this.reader.backward(1);
        }
        return new Stmtgetint(this.lVal, this.equal, this.getint, this.lparent, this.rparent, this.semicn);
    }



}
