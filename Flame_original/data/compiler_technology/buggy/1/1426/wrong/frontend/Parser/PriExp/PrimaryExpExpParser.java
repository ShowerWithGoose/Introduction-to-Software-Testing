package frontend.Parser.PriExp;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;
import frontend.TokenType;

//PrimaryExp â†’ '(' Exp ')'
public class PrimaryExpExpParser {
    private TokenListReader reader;
    private Token lparent;
    private Exp exp;
    private Token rparent;

    public PrimaryExpExpParser(TokenListReader reader) {
        this.reader = reader;
    }
    public PrimaryExpExp parsePrimaryExpExp(){
        this.lparent = this.reader.getnextToken();
        ExpParser expParser = new ExpParser(this.reader);
        this.exp = expParser.parseExp();
        this.rparent = this.reader.getnextToken();
        if(!this.rparent.getType().equals(TokenType.RPARENT))
        {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
            this.reader.backward(1);
        }
        PrimaryExpExp primaryExpExp = new PrimaryExpExp(this.lparent, this.exp, this.rparent);
        return primaryExpExp;
    }


}
