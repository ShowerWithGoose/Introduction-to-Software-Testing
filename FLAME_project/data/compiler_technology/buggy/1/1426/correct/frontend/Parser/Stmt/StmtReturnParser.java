package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
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
        if(!this.semicn.getType().equals(TokenType.SEMICN))
        {
            if( this.semicn.getType().equals(TokenType.IDENFR) ||
                    this.semicn.getType().equals(TokenType.LPARENT) ||
                    this.semicn.getType().equals(TokenType.INTCON) ||
                    this.semicn.getType().equals(TokenType.CHRCON) ||
                    this.semicn.getType().equals(TokenType.PLUS) ||
                    this.semicn.getType().equals(TokenType.MINU) ||
                    this.semicn.getType().equals(TokenType.NOT) )
            {
                this.reader.backward(1);
                this.exp = expParser.parseExp();
                this.semicn = this.reader.getnextToken();
                if(!this.semicn.getType().equals(TokenType.SEMICN))
                {
                    // error!
                    ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
                    this.reader.backward(1);
                }
            }
            else{
                // error!
                ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
                this.reader.backward(1);
            }

            return new StmtReturn(this.returnTk, this.exp,this.semicn);
        }else {
            return new StmtReturn(this.returnTk, this.semicn);
        }
    }



}
