package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;
import frontend.Parser.solid.StringConst;

import java.util.ArrayList;

//| 'printf''('StringConst {','Exp}')'';'
public class StmtprintfParser {
    private TokenListReader reader;
    private Token printfTk = null;
    private Token lparent = null;
    private StringConst sc = null;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rparent = null;
    private Token semicn = null;

    public StmtprintfParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Stmtprintf parseStmtprintf() {
        this.printfTk = this.reader.getnextToken();
        this.lparent = this.reader.getnextToken();
        this.sc = new StringConst(this.reader.getnextToken());
        Token token = this.reader.getnextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            this.commas.add(token);
            ExpParser expParser = new ExpParser(this.reader);
            this.exps.add(expParser.parseExp());
            token = this.reader.getnextToken();
        }
        this.rparent = token;
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
        return new Stmtprintf(this.printfTk, this.lparent, this.sc, this.commas, this.exps, this.rparent, this.semicn);
    }

}
