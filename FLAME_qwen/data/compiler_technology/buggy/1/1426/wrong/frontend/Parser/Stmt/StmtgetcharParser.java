package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.Parser.PriExp.LVal;
import frontend.Parser.PriExp.LValParser;
import frontend.TokenType;

public class StmtgetcharParser {
    private TokenListReader reader;
    private LVal lVal;
    private Token equal;
    private Token getchar;
    private Token lparent;
    private Token rparent;
    private Token semicn;

    public StmtgetcharParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Stmtgetchar parseStmtgetchar(){
        LValParser lvalParser = new LValParser(this.reader);
        this.lVal = lvalParser.parseLVal();
        this.equal = this.reader.getnextToken();
        this.getchar = this.reader.getnextToken();
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
        return new Stmtgetchar(this.lVal, this.equal, this.getchar, this.lparent, this.rparent, this.semicn);
    }


}
